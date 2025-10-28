import cv2
import numpy as np
import RPi.GPIO as GPIO
import skfuzzy as fuzz
from skfuzzy import control as ctrl

# ---------------- CONFIGURACIÓN GPIO ----------------
led_pins = [17, 27, 22]  # Pines GPIO para los LEDs
GPIO.setmode(GPIO.BCM)
for pin in led_pins:
    GPIO.setup(pin, GPIO.OUT)

# ---------------- VARIABLES DIFUSAS ----------------
# Universo de movimiento: 0 a 409600 (640x640 píxeles)
velocidad = ctrl.Antecedent(np.arange(0, 409601, 1), 'movimiento')

# Universo de salida: 0 a 3 LEDs
leds = ctrl.Consequent(np.arange(0, 4, 1), 'leds')

# Funciones de membresía para velocidad (entrada)
velocidad['nula'] = fuzz.trimf(velocidad.universe, [0, 0, 1000])
velocidad['bajo'] = fuzz.trimf(velocidad.universe, [500, 5000, 10000])
velocidad['media'] = fuzz.trimf(velocidad.universe, [8000, 25000, 50000])
velocidad['alto'] = fuzz.trimf(velocidad.universe, [40000, 100000, 160000])

# Funciones de membresía para LEDs (salida)
leds['ninguno'] = fuzz.trimf(leds.universe, [0, 0, 1])
leds['uno']     = fuzz.trimf(leds.universe, [0, 1, 2])
leds['dos']     = fuzz.trimf(leds.universe, [1, 2, 3])
leds['tres']    = fuzz.trimf(leds.universe, [2, 3, 3])

# ---------------- REGLAS DIFUSAS ----------------
regla1 = ctrl.Rule(velocidad['nula'], leds['ninguno'])
regla2 = ctrl.Rule(velocidad['bajo'], leds['uno'])
regla3 = ctrl.Rule(velocidad['media'], leds['dos'])
regla4 = ctrl.Rule(velocidad['alto'], leds['tres'])

# Sistema difuso
control_mov = ctrl.ControlSystem([regla1, regla2, regla3, regla4])
mov_sim = ctrl.ControlSystemSimulation(control_mov)

# ---------------- CAPTURA DE VIDEO ----------------
cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print("Error: NO se encontró la cámara")
    GPIO.cleanup()
    exit()

# Capturar primer frame para referencia
ret, frame = cap.read()
ant = frame

# ---------------- BUCLE PRINCIPAL ----------------
try:
    while True:
        ret, frame = cap.read()
        if not ret:
            print("Error: No se pudo capturar el frame")
            break

        # Convertir a escala de grises
        antgray = cv2.cvtColor(ant, cv2.COLOR_BGR2GRAY)
        actgray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # Diferencia entre frames
        diferencia = cv2.absdiff(antgray, actgray)
        _, thresh = cv2.threshold(diferencia, 30, 255, cv2.THRESH_BINARY)

        # Contar píxeles cambiados (movimiento detectado)
        mov_valor = np.sum(thresh > 0)
        mov_valor = min(mov_valor, 409600)  # Limitar al universo

        # Evaluar con fuzzy logic
        mov_sim.input['movimiento'] = mov_valor
        mov_sim.compute()
        salida_leds = round(mov_sim.output['leds'])

        print(f"Movimiento: {mov_valor} -> Encender {salida_leds} LED(s)")

        # Mostrar cámara
        cv2.imshow("Camera Feed", frame)

        # Encender LEDs según salida
        for i, pin in enumerate(led_pins):
            GPIO.output(pin, GPIO.HIGH if i < salida_leds else GPIO.LOW)

        # Guardar frame actual como anterior
        ant = frame.copy()

        # Salir con 'q' o ESC
        if cv2.waitKey(1) & 0xFF in (ord('q'), 27):
            break

except KeyboardInterrupt:
    print("Interrumpido por el usuario")

finally:
    # Liberar recursos
    cap.release()
    cv2.destroyAllWindows()
    GPIO.cleanup()
