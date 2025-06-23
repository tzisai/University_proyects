import numpy as np
import matplotlib.pyplot as plt
import sympy as smp

# Definimos la función f
def f(x):
    return (2*(x**2)) * np.cos(x) - 5*x
def dx(x):
    return 4*x*np.cos(x)-2*x*x*np.sin(x)-5
# Graficamos la función objetivo
figsize = (6,4)
dpi = 150
fig, ax = plt.subplots(1,1,figsize=figsize,dpi=dpi)

t1 = np.arange(-5.0, 5.0, 0.1)  # Rango de valores para el eje X

# Limites de la gráfica
ax.set_xlim(-5, 5)
ax.set_ylim(-45, 45)

# Graficamos la función
ax.plot(t1, f(t1), 'r-')  # 'r-' es para línea roja

# Puntos individuales
x = [-1.0]
y = [f(x[0])]
ax.plot(x, y, 'bo')  # 'bo' es para un punto azul

print("X = ", x)
print("Y = ", y)

# Mostrar la gráfica
plt.show()

# Función de gradiente descendente (visualización)
fig, ax = plt.subplots(1,1,figsize=figsize,dpi=dpi)

# Definimos nuevamente el rango de valores
t1 = np.arange(-5.0, 5.0, 0.1)

# Limites de la gráfica
ax.set_xlim(-5, 5)
ax.set_ylim(-45, 45)

# Graficamos la función otra vez
ax.plot(t1, f(t1), 'r-')

# Puntos individuales
x = [-1.0]
y = [f(x[0])]
ax.plot(x, y, 'bo')  # Punto azul

print("X = ", x)
print("Y = ", y)

# Mostrar la gráfica nuevamente
plt.show()

pendiente=dx(x[0])
eta=0.08


for i in range (0,20):
    x.append(x[i]-eta*pendiente)    
    y.append(f(x[i]-eta*pendiente))

    pendiente=dx(x[i])

    fig,ax=plt.subplots(1,1,figsize=figsize,dpi=dpi)
    ax.set_xlim(-5,5)
    ax.set_ylim(-45,5)
    ax.plot(t1,f(t1))
    ax.plot(x,y,'ro')
    plt.show()

