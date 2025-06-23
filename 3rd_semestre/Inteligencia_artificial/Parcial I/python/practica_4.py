
##Universidad Autonoma de Aguascalientes 
##Depoartamento de Ciencias de la Computacion 
##Carrera Ingenieria en Computacopn Inteligente 
##Curso Inteligencia Artificial (McCollouc Pitts)
##Maestro: Dr. Francisco Javier Luna Rosas 
##Alumno: Martin Isai Nuñez Villeda 
##semestre :Agosto_Diciembre del 2024

import numpy as np
import matplotlib.pyplot as plt

personas = np.array ([[0.3, 0.4], [0.4, 0.3],
                    [0.3, 0.2], [0.4, 0.1],
                    [0.5, 0.4], [0.4, 0.8],
                    [0.6, 0.8], [0.5, 0.6],
                    [0.7, 0.6], [0.8,0.5]])

clases =np.array([0,0,0,0,0,1,1,1,1,1])

##definir la funcinon de activacion 
def activacion (pesos,x,b):
    z=pesos * x
    if z.sum() + b >0:
        return 1
    else:
        return 0
##generamos los pesos y el bias 
pesos=np.random.uniform(-1,1,size=2)
b = np.random.uniform(-1,1)
pesos,b,activacion(pesos,[0.5,0.6],b)

##insertamos algoritmo de perceptron 
pesos = np.random.uniform(-1,1,size=2)
b = np.random.uniform(-1,1)
tasa_aprend=0.1
epocas = 100

for epoca in range (epocas):
    error_total=0
    for i in range (len(personas)):
        prediccion = activacion(pesos,personas[i],b)
        error = clases [i] - prediccion
        error_total+= error**2

        pesos[0]+=tasa_aprend*personas[i][0]*error
        pesos[1]+=tasa_aprend*personas[i][1]*error

        b+= tasa_aprend*error

    print(error_total,end=" ")


##Paso numero 7 
#corremos el algoritmo 

pesos,b,activacion(pesos,[0.3,0.4],b)
#pesos,b,activacion(pesos,[ 0.8 , 0.5 ],b)





