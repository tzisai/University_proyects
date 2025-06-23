

##Universidad Autonoma de Aguascalientes 
##Depoartamento de Ciencias de la Computacion 
##Carrera Ingenieria en Computacopn Inteligente 
##Curso Inteligencia Artificial (McCollouc Pitts)
##Maestro: Dr. Francisco Javier Luna Rosas 
##Alumno: Martin Isai Nuñez Villeda 
##semestre :Agosto_Diciembre del 2024

##Practica 1 


#Importar librerias Necesarias

import numpy as np

#definicion de funcion del OR lógico

def mccllouch_pitts_OR (x1,x2):
    #pesos de entrada
    w1,w2=1,1

    #umbral
    teta=1

    #suma ponderada de entradas 
    weight_sum=x1*w1 +x2*w2

    #salida de la celula 
    if weight_sum>=teta:
        return 1
    else:
        return 0
    
print(mccllouch_pitts_OR(0,0))
print(mccllouch_pitts_OR(0,1))
print(mccllouch_pitts_OR(1,0))
print(mccllouch_pitts_OR(1,1))
