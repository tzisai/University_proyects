

##Universidad Autonoma de Aguascalientes 
##Depoartamento de Ciencias de la Computacion 
##Carrera Ingenieria en Computacopn Inteligente 
##Curso Inteligencia Artificial (McCollouc Pitts)
##Maestro: Dr. Francisco Javier Luna Rosas 
##Alumno: Martin Isai Nuñez Villeda 
##semestre :Agosto_Diciembre del 2024

##Practica 2


#Importar librerias Necesarias

import numpy as np

#definicion de funcion del NOT lógico

def mccllouch_pitts_NOT (x1):
    #pesos de entrada
    w1=1

    #umbral
    teta=0

    #suma ponderada de entradas 
    weight_sum=x1*w1 

    #salida de la celula 
    if weight_sum<=teta:
        return 1
    else:
        return 0
    
print(mccllouch_pitts_NOT(1))
print(mccllouch_pitts_NOT(0))

