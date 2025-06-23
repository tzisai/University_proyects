import cv2
import os
import numpy as np
from matplotlib import pyplot as plt

# Función de neurona (placeholder)
def neuron(weights, bias, input):
    a = "a" 
    # Aquí irá el código de la neurona para la red convolucional

# Función para detectar la firma y recortar la imagen
def detectarFirma(imagen, margen):
    imagen_borrosa = cv2.GaussianBlur(imagen, (5, 5), 0)    # Desenfoque gaussiano para reducir ruido
    _, umbral = cv2.threshold(imagen_borrosa, 165, 255, cv2.THRESH_BINARY_INV)  # Umbral para detectar firma

    contornos, _ = cv2.findContours(umbral, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)  # Encontrar contornos
    contorno_principal = max(contornos, key=cv2.contourArea)  # Contorno con mayor área

    # Obtener límites del rectángulo que encierra la firma
    x, y, w, h = cv2.boundingRect(contorno_principal)

    # Añadir el margen a la imagen resultante
    x = max(0, x - margen)
    y = max(0, y - margen)
    w += 2 * margen
    h += 2 * margen
    
    # Recortar la imagen con la firma
    imagen_recortada = imagen[y:y+h, x:x+w]
    
    return imagen_recortada

# Ruta al directorio con las imágenes
image_dir = 'assets/Trainingchqs'  # Usar "/" o "\\" para rutas

# Tamaño deseado para las imágenes antes de recortar
IMG_SIZE = (736, 337)

# Tamaño uniforme para las imágenes recortadas
uniform_size = (200, 200)

# Listas para almacenar imágenes procesadas
processed_images = []

# Recorrer todas las imágenes en el directorio
for file_name in os.listdir(image_dir):
    file_path = os.path.join(image_dir, file_name)
    
    # Cargar la imagen
    img = cv2.imread(file_path)
    
    if img is not None:
        # Convertir la imagen a escala de grises
        img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        
        # Redimensionar la imagen antes del recorte
        resized_img = cv2.resize(img_gray, IMG_SIZE)
        
        # Aplicar la función de detección de firma
        firma_recortada = detectarFirma(resized_img, margen=10)

        # Redimensionar la firma recortada a un tamaño fijo
        firma_recortada = cv2.resize(firma_recortada, uniform_size)
        
        # Añadir la imagen recortada a la lista
        processed_images.append(firma_recortada)
        
        # Mostrar la imagen procesada (opcional)
        cv2.imshow('Firma Recortada', firma_recortada)
        cv2.waitKey(500)  # Mostrar cada imagen por 500ms

cv2.destroyAllWindows()

# Convertir la lista a un array numpy para su uso en la red
processed_images = np.array(processed_images)
print(f'Número de imágenes procesadas: {len(processed_images)}')
print(f'Dimensiones de las imágenes procesadas: {processed_images.shape}')
