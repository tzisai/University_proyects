import cv2
import numpy as np
from matplotlib import pyplot as plt

def detectarFirma(imagen_path, margen):
    
    imagen = cv2.imread(imagen_path, cv2.IMREAD_GRAYSCALE)  # Se convierte la imagen original a escala de grises

    imagen_borrosa = cv2.GaussianBlur(imagen, (5, 5), 0)    # Se le aplica un desenfoque "gaussiano" para asi reducir el ruido de la imagen

    _, umbral = cv2.threshold(imagen_borrosa, 127, 255, cv2.THRESH_BINARY_INV)  # Se aplica un umbral para detectar la firma (127 fue como mejor se acomodo, igualmente puede ajustarse)

    contornos, _ = cv2.findContours(umbral, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE) # Se encuentran los contornos en la imagen "umbralizada" ඞ
    
    contorno_principal = max(contornos, key=cv2.contourArea)    # Se obtiene el contorno con la mayor área posible

    x, y, w, h = cv2.boundingRect(contorno_principal)   # Se obtienen los límites del rectángulo que encierra la firma

    # Añadir el margen a la imagen resultante 
    x = max(0, x - margen)
    y = max(0, y - margen)
    w += 2 * margen
    h += 2 * margen
    
    imagen_recortada = imagen[y:y+h, x:x+w] # Recortar la imagen con la firma

    
    # Mostrar la imagen original y la firma recortada
    plt.figure(figsize=(10, 5))
    plt.subplot(1, 2, 1)
    plt.title("Imagen Original")
    plt.imshow(imagen, cmap='gray')
    plt.subplot(1, 2, 2)
    plt.title("Imagen Recortada")
    plt.imshow(imagen_recortada, cmap='gray')
    plt.show()
    
    return imagen_recortada

# Se carga la ruta de la imagen del cheque y se manda a llamar la funcion, ademas se define el tamaño del margen
imagen_path = "assets/Trainingchqs/isa9.png" #Ruta del Cheque firmado (cuidado con poner la imagen en una ruta muy larga xd)
imagen_firma = detectarFirma(imagen_path, margen = 10) #Valor del tamaño del margen (alch aumentar/reducir el valor es solo si no se quiere que este el borde este pegado a la firma)
