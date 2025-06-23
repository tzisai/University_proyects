##Universidad Autonoma de Aguascalientes 
##Depoartamento de Ciencias de la Computacion 
##Carrera Ingenieria en Computacopn Inteligente 
##Curso Inteligencia Artificial (McCollouc Pitts)
##Maestro: Dr. Francisco Javier Luna Rosas 
##Alumno: Martin Isai Nuñez Villeda 
##semestre :Agosto_Diciembre del 2024

##Practica 2 :Crear una inteligencia artificial y entrenar de manera que se copmorte como una compuerta NAD de dos entradas 
#importar librerias necesarias 
import numpy as np

def mcolluch_pitts_AND (x1,x2):
    w1,w2=1,1

    #Umbral
    teta=2

    #suma ponderada de las entradas 
    weight_Sum= x1*w1 + x2*w2

    #salida de la celula
    if weight_Sum>=teta:
        return 1
    else:
        return 0
    
    ##Probar la neurona de McColluch-PItts


    print(mcolluch_pitts_AND(0,0)) #salida 0
    print(mcolluch_pitts_AND(0,1)) #salida 0
    print(mcolluch_pitts_AND(1,0)) #salida 0
    print(mcolluch_pitts_AND(1,1)) #salida 1

    ##Conclusiones 
    #En esta practica entrenamos una neurona Mcoloumb pitts entrenamos una neurona de manera que se comporte como jna compouerta logica
    #AND de 2 entradas.
    #Los pesos (w) fueren elegidos y teta fueron elegidos totalmente aleatorios. al probar la netuona de mccolucc-Pitts par el
    #and logico ,demostramos como se ouede resolver cualquier problema aritmetico logico
    

