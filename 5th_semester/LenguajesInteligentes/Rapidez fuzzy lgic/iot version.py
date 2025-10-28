# motion_to_azure.py
import time
import json
import os
import cv2
import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl

# Azure imports
from azure.iot.device import IoTHubDeviceClient
from azure.storage.blob import BlobServiceClient

# RPi GPIO (keep if running on Pi; if developing on PC remove/guard this)
try:
    import RPi.GPIO as GPIO
    ON_PI = True
except Exception:
    ON_PI = False
    print("RPi.GPIO not available: running in non-Pi mode (GPIO disabled).")

# ---------------- CONFIGURATION (EDIT THESE) ----------------
IOTHUB_DEVICE_CONNECTION_STRING = os.environ.get("IOT_CONN_STR") or "HostName=MVPTorreta.azure-devices.net;DeviceId=TorretaTest;SharedAccessKey=XBuFs5FJVcnamiPJ56/AYYglwqlceLGw1Dz5r3GvJxs="
BLOB_CONN_STR = os.environ.get("BLOB_CONN_STR") or "<YOUR_STORAGE_CONNECTION_STRING>"  # optional
BLOB_CONTAINER = os.environ.get("BLOB_CONTAINER") or "pi-images"                     # optional

TELEMETRY_INTERVAL = 1.0        # seconds between telemetry messages
IMAGE_UPLOAD_THRESHOLD = 5000   # mov_val threshold to upload an image (tune this)
UPLOAD_MIN_INTERVAL = 30.0      # don't upload images more than once every X sec

# ---------------- GPIO SETUP ----------------
led_pins = [17, 27, 22]
if ON_PI:
    GPIO.setmode(GPIO.BCM)
    for pin in led_pins:
        GPIO.setup(pin, GPIO.OUT)

# ---------------- FUZZY LOGIC (same as your original) ----------------
velocidad = ctrl.Antecedent(np.arange(0, 409601, 1), 'movimiento')
leds = ctrl.Consequent(np.arange(0, 4, 1), 'leds')

velocidad['nula']  = fuzz.trimf(velocidad.universe, [0, 0, 1000])
velocidad['bajo']  = fuzz.trimf(velocidad.universe, [500, 5000, 10000])
velocidad['media'] = fuzz.trimf(velocidad.universe, [8000, 25000, 50000])
velocidad['alto']  = fuzz.trimf(velocidad.universe, [40000, 100000, 160000])

leds['ninguno'] = fuzz.trimf(leds.universe, [0, 0, 1])
leds['uno']     = fuzz.trimf(leds.universe, [0, 1, 2])
leds['dos']     = fuzz.trimf(leds.universe, [1, 2, 3])
leds['tres']    = fuzz.trimf(leds.universe, [2, 3, 3])

regla1 = ctrl.Rule(velocidad['nula'], leds['ninguno'])
regla2 = ctrl.Rule(velocidad['bajo'], leds['uno'])
regla3 = ctrl.Rule(velocidad['media'], leds['dos'])
regla4 = ctrl.Rule(velocidad['alto'], leds['tres'])
control_mov = ctrl.ControlSystem([regla1, regla2, regla3, regla4])
mov_sim = ctrl.ControlSystemSimulation(control_mov)

# ---------------- AZURE CLIENTS (connect once) ----------------
device_client = None
blob_service_client = None
container_client = None

if IOTHUB_DEVICE_CONNECTION_STRING and "YOUR_IOT_DEVICE_CONNECTION_STRING" not in IOTHUB_DEVICE_CONNECTION_STRING:
    device_client = IoTHubDeviceClient.create_from_connection_string(IOTHUB_DEVICE_CONNECTION_STRING)
    device_client.connect()
    print("Connected to IoT Hub.")

# ---------------- CAMERA SETUP ----------------
cap = cv2.VideoCapture(0)
if not cap.isOpened():
    print("Error: camera not found")
    if ON_PI:
        GPIO.cleanup()
    raise SystemExit(1)

ret, frame = cap.read()
if not ret:
    print("Error: couldn't read first frame")
    cap.release()
    if ON_PI:
        GPIO.cleanup()
    raise SystemExit(1)
ant = frame.copy()

# ---------------- MAIN LOOP ----------------
last_telemetry = 0.0
last_upload = 0.0

try:
    while True:
        ret, frame = cap.read()
        if not ret:
            print("Frame read error, breaking")
            break

        antgray = cv2.cvtColor(ant, cv2.COLOR_BGR2GRAY)
        actgray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        diferencia = cv2.absdiff(antgray, actgray)
        _, thresh = cv2.threshold(diferencia, 30, 255, cv2.THRESH_BINARY)

        mov_valor = int(np.sum(thresh > 0))
        mov_valor = min(mov_valor, 409600)

        # fuzzy evaluation
        mov_sim.input['movimiento'] = mov_valor
        mov_sim.compute()
        salida_leds = int(round(mov_sim.output['leds']))

        now = time.time()
        # send telemetry every TELEMETRY_INTERVAL seconds
        if device_client and (now - last_telemetry) >= TELEMETRY_INTERVAL:
            payload = {
                "timestamp": int(now),
                "movement": int(mov_valor),
                "leds": salida_leds
            }
            try:
                device_client.send_message(json.dumps(payload))
                print("Telemetry sent:", payload)
            except Exception as e:
                print("Telemetry send error:", e)
            last_telemetry = now

        # set LEDs on the Pi (same logic as before)
        if ON_PI:
            for i, pin in enumerate(led_pins):
                GPIO.output(pin, GPIO.HIGH if i < salida_leds else GPIO.LOW)

        ant = frame.copy()

        # show window for debugging (remove if running headless)
        cv2.imshow("Camera Feed", frame)
        if cv2.waitKey(1) & 0xFF in (ord('q'), 27):
            break

except KeyboardInterrupt:
    print("Interrupted by user")

finally:
    cap.release()
    cv2.destroyAllWindows()
    if ON_PI:
        GPIO.cleanup()
    if device_client:
        device_client.shutdown()
    print("Clean exit.")