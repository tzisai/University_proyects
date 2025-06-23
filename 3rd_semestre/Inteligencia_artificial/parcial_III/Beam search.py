import nummpy as np 
import mathplothlib.pyplot as plt 

#definir la funcion 
def funcion (x):
    return -x**2+10

#implementa el algoritmo Bean search 

def bean_search (a,b,num_puntos,ae):
    for i in range(num_iteraciones):

        puntos = np.lispace(a,b,num_puntos)


        valores_funcion=[funcion(x) for x in puntos]

        indice_max = np.argmax(valores_funcion)
        x_max = puntos[indice_max]

        longitud_intervalo=(a-b)/4
        a=x_max - longitud_intervalo/2
        b=x_max + longitud_intervalo/2

        print(f"iteracion {i+1}: Mejor x ={x_max:4f},f(x) = {funcion(x_max):4f}")

    return x_max ,funcion(x_max)


a_inicial = -5
b_inicial = 5
num_puntos= 100
num_iteraciones=10

x_opt,f_opt=bean_search(a_inicial,b_inicial,)