import sympy as sp
import numpy as np

# Paso 1: Definir la variable simbólica
x = sp.symbols('x')

# Paso 2: Solicitar la función al usuario
fx_str = input("Ingrese la función f(x): ")
fx = sp.sympify(fx_str)

# Paso 3: Calcular derivadas
f_prime = sp.diff(fx, x)
f_double_prime = sp.diff(f_prime, x)

# Paso 4: Convertir a funciones evaluables
f = sp.lambdify(x, fx, 'numpy')
f1 = sp.lambdify(x, f_prime, 'numpy')
f2 = sp.lambdify(x, f_double_prime, 'numpy')

# Paso 5: Solicitar valores iniciales
x0 = float(input("Ingrese el valor inicial x0: "))
max_iter = int(input("Ingrese el número máximo de iteraciones: "))
tol = float(input("Ingrese la tolerancia de error (%): "))

# Paso 6: Iteraciones con el método Newton-Raphson Modificado
print("\nIniciando iteraciones...\n")
for i in range(1, max_iter + 1):
    f_val = f(x0)
    f1_val = f1(x0)
    f2_val = f2(x0)
    
    denom = f1_val**2 - f_val * f2_val
    if denom == 0:
        print("División por cero en la iteración", i)
        break

    x1 = x0 - (f_val * f1_val) / denom
    error = abs((x1 - x0) / x1) * 100 if x1 != 0 else 0

    print(f"Iteración {i}: x = {x1:.6f}, error = {error:.6f}%")

    if error < tol:
        break

    x0 = x1

# Paso 7: Mostrar el resultado final
print(f"\nRaíz aproximada: {x1:.8f}")
print(f"f(raíz) = {f(x1):.8e}")
