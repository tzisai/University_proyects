import numpy as np


def f(x,a,b):
    return (1-(x**2/a**2))*(b**2)

def pendiente(p1,p2):
    return (p2[1]-p1[1])/(p2[0]-p1[0])

def angulos(cord1,cord2):
    thta= np.arctan(pendiente(cord1,cord2)-pendiente(cord2,cord1)/(1+pendiente(cord1,cord2)*pendiente(cord2,cord1)))
    return thta

puntos_array = []

for i in range(0,200):
    x = i
    y = f(x,150,200)
    puntos = [x,y]
    puntos_array.append(puntos)

for j in range(0,200):
    