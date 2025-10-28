import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl
import matplotlib.pyplot as plt

# ---------------- VARIABLES DIFUSAS ----------------
# Universo de movimiento: 0 a 409600 (640x640 píxeles)
movimiento = ctrl.Antecedent(np.arange(0, 409601, 1000), 'movimiento')

# Universo de salida: 0 a 3 LEDs
leds = ctrl.Consequent(np.arange(0, 4, 1), 'leds')

# Funciones de membresía para movimiento (entrada)
movimiento['nula'] = fuzz.trimf(movimiento.universe, [0, 0, 1000])
movimiento['bajo'] = fuzz.trimf(movimiento.universe, [500, 5000, 10000])
movimiento['media'] = fuzz.trimf(movimiento.universe, [8000, 25000, 50000])
movimiento['alto'] = fuzz.trimf(movimiento.universe, [40000, 100000, 160000])

# Funciones de membresía para LEDs (salida)
leds['ninguno'] = fuzz.trimf(leds.universe, [0, 0, 1])
leds['uno']     = fuzz.trimf(leds.universe, [0, 1, 2])
leds['dos']     = fuzz.trimf(leds.universe, [1, 2, 3])
leds['tres']    = fuzz.trimf(leds.universe, [2, 3, 3])

# ---------------- GRAFICAR FUNCIONES ----------------
# Graficar las funciones de membresía de entrada
movimiento.view()

# Graficar las funciones de membresía de salida
leds.view()

plt.show()
