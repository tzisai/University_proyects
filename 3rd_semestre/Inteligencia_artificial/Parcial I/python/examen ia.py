''' 
Equipo:
Martín Isaí Núñez Villeda
Dairon Tadeo García Medina 
Eduardo Isaí López García
Jesús Yocsan Luévano Flores
Alan Fernando Martinez Moreno
Pablo David Pérez López

9/19/24

Universidad Autonoma de Aguascalientes 
Depoartamento de Ciencias de la Computacion 
Carrera Ingenieria en Computacopn Inteligente 
Curso Inteligencia Artificial (McCollouc Pitts)
Maestro: Dr. Francisco Javier Luna Rosas 
semestre :Agosto_Diciembre del 2024 

'''




import numpy as np
# Función sigmoide
def sigmoide(x):
    return 1 / (1 + np.exp(-x))

# Derivada de la función sigmoide
def derivada_sigmoide(x):
    return x * (1 - x)

# Inicialización de pesos
w14, w15 = 0.2, -0.3
w24, w25 = 0.4, 0.1
w34, w35 = -0.5, 0.2
w46, w56 = -0.3, -0.2

# Bias
b4,b5,b6 = -0.4, 0.2, 0.1
# Patrones de entrada
x1,x2,x3 = 1,0,1
# Tasa de aprendizaje
l = 0.1
# Definir número de épocas
epocas = 1000000

# Target mamon
salida_esperada = 1

for epoca in range(epocas):
    # FORWARD PROPAGATION
    suma1 = (x1 * w14 + x2 * w24 + x3 * w34) + b4
    sigmoide1 = sigmoide(suma1)
    suma2 = (x1 * w15 + x2 * w25 + x3 * w35) + b5
    sigmoide2 = sigmoide(suma2)
    suma3 = (sigmoide1 * w46 + sigmoide2 * w56) + b6
    sigmoide3 = sigmoide(suma3)  # Salida de la neurona de la capa final

    # BACKPROPAGATION: Calcular el error en la salida y retropropagar
    errorSalida = derivada_sigmoide(sigmoide3) * (salida_esperada - sigmoide3)
    errorTotal1 = derivada_sigmoide(sigmoide1) * (errorSalida * w46)
    errorTotal2 = derivada_sigmoide(sigmoide2) * (errorSalida * w56)

    # Actualización de pesos y bias
    w46 += l * errorSalida * sigmoide1
    w56 += l * errorSalida * sigmoide2

    w14 += l * errorTotal1 * x1
    w24 += l * errorTotal1 * x2
    w34 += l * errorTotal1 * x3

    w15 += l * errorTotal2 * x1
    w25 += l * errorTotal2 * x2
    w35 += l * errorTotal2 * x3

    b6 += l * errorSalida
    b4 += l * errorTotal1
    b5 += l * errorTotal2

    # Imprimir la salida de la neurona de la capa final en cada época
    if epoca % 100 == 0:
        print(f"Época {epoca} - Salida de la neurona: {sigmoide3}, Error: {abs(salida_esperada - sigmoide3)}")

# Imprimir resultados finales
print(f"Pesos finales: w46={w46}, w56={w56}")
print(f"Bias final: b6={b6}")
