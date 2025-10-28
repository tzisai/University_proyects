import PIL
import matplotlib.pyplot as plt
import numpy as np
from PIL import Image

# Cargar la imagen
img = Image.open(r"sonic.jpg")

# Separar los canales
r, g, b = img.split()

# Convertir cada canal a un array de NumPy
r_array = np.asarray(r)
g_array = np.asarray(g)
b_array = np.asarray(b)

# # --- CORRECCIÓN AQUÍ ---
# # Aplanar las matrices 2D a arrays 1D y graficar los histogramas

# # Para que se vean bien juntos, usamos 'alpha' para darles transparencia
# plt.figure(figsize=(10, 6)) # Opcional: hacer la figura más grande
# plt.hist(r_array.flatten(), bins=256, range=[0, 256], color='red', alpha=0.5, label='Rojo')
# plt.hist(g_array.flatten(), bins=256, range=[0, 256], color='green', alpha=0.5, label='Verde')
# plt.hist(b_array.flatten(), bins=256, range=[0, 256], color='blue', alpha=0.5, label='Azul')

# plt.title('Histograma de Canales de Color (RGB)')
# plt.xlabel('Intensidad del Píxel')
# plt.ylabel('Frecuencia (Cantidad de Píxeles)')
# plt.legend() # Muestra las etiquetas 'Rojo', 'Verde', 'Azul'
# plt.grid(True, linestyle='--', alpha=0.6) # Opcional: añade una cuadrícula
# plt.show()




#cada celda es un plot
#(numerofilas),(num columnas),(tamaño figura),(compartir eje x(booleano))
fig,axes= plt.subplots(3,1,figsize=(8,10),sharex=True)
# ^ se maneja como arreglo

#Grafico 1,1
axes[0].hist(r_array.flatten(),bins=256,range=[0,256],color='red')
axes[0].set_title('Canal Rojo')
axes[0].set_ylabel('Frecuencia')

#Grafico 2,1
axes[1].hist(g_array.flatten(),bins=256,range=[0,256],color='green')
axes[1].set_title('Canal verde')
axes[1].set_ylabel('Frecuencia')

#Grafica 3,1

axes[2].hist(b_array.flatten(),bins=256,range=[0,256],color='blue')
axes[2].set_title('Canal azul')
axes[2].set_ylabel('Frecuencia')