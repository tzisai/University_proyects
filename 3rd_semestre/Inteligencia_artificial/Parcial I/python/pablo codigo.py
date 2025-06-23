
import numpy as np
#patrones de entrada
x1,x2,x3=1,0,1
#pesos sinopticos
w14,w15=0.2,-0.3
w24,w25=0.4,0.1
w34,w35=-0.5,0.2

w46,w56=-0.3,-0.2

#bias
b4,b5,b6=-0.4,0.2,0.1

suma1 = (x1 * w14 + x2 * w24 + x3 * w34) + b4
sigmoide1 = 1 / (1 + np.exp(-1*suma1))

suma2 = (x1 * w15 + x2 * w25 + x3 * w35) + b5
sigmoide2 = 1 / (1 + np.exp(-1*suma2))

suma3 = (sigmoide1 * w46 + sigmoide2 * w56) + b6
sigmoide3 = 1 / (1 + np.exp(-1*suma3))

print(sigmoide1)
print(sigmoide2)
print(sigmoide3)

error1 = (sigmoide1 * (1 - sigmoide1)) * (1 - sigmoide1) 
error2 = (sigmoide2 * (1 - sigmoide2)) * (1 - sigmoide2)
errorSalida = (sigmoide3 * (1 - sigmoide3)) * (1 - sigmoide3)

errorTotal1 = ((sigmoide1 * (1 - sigmoide1)) * (errorSalida * w46))
errorTotal2 = ((sigmoide2 * (1 - sigmoide2)) * (errorSalida * w56))
print(errorSalida)
print(errorTotal1)
print(errorTotal2)

l = 0.1

cambioPeso_46 = l * errorSalida * error1
w46 = w46 + cambioPeso_46
cambioPeso_56 = l * errorSalida * error2
w56 = w56 + cambioPeso_56

cambio_bias_6 = l * errorSalida
b6 = b6 + cambio_bias_6

print(w46)
print(w56)

print(b6)
