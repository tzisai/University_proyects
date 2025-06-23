##Universidad Autonoma de Aguascalientes 
##Depoartamento de Ciencias de la Computacion 
##Carrera Ingenieria en Computacopn Inteligente 
##Curso Inteligencia Artificial (McCollouc Pitts)
##Maestro: Dr. Francisco Javier Luna Rosas 
##Alumno: Martin Isai Nuñez Villeda 
##semestre :Agosto_Diciembre del 2024
##Practica No.6
"""Se cargan dos clases de flores de iris(setosa y Versicolor). Las caracteristicas que tomaremos en cuenta
son :longitud del petalo y el del sefalo"""

import numpy as np
import os
import pandas as pd
from sklearn.linear_model import Perceptron

#cargamos el dataset
os.chdir("C:\\Users\\Isai Nuñez\\Documents\\3er semestres\\primer parcial\\Inteligencia artificial\\Extras")  
df = pd.read_csv('iris.csv', delimiter=';', decimal='.')
print(df.shape)
print(df.head())
"""Extraemos el largo sepal y el largo del petalo en las columnas 0 y 2. Usaremos solo Setosa y Versicolor."""
X = df.iloc[0:100, [0, 2]].values
print(X)
"""Seleccionamos Setosa y Versicolor."""
y = df.iloc[0:100, 4].values
print(y)
"""Convertimos etiquetas a numeros."""
y = np.where(y == "setosa", -1, 1)
print(y)
"""Creamos el perceptron y lo entrenamos para la flor de iris"""
perceptron = Perceptron()
perceptron.fit(X, y)
"""Predecimos el tipo de flor"""
perceptron.predict([[5.7, 4.1], [5.1, 1.4]])

"""Creamos un perceptron desdela libreria sklearn, lo alimentamos con un data set porporcinado entrenamos y clasificamos a los tipos de flor de iris de manera satisfacrtoria """