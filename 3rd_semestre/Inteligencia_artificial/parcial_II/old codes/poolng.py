import cv2
import os
import numpy as np
import csv
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

# Función para aplicar el kernel y medir coincidencias morfológicas
def aplicar_kernel_y_mediciones(imagen, kernel):
    # Aplicar la operación morfológica (en este caso, la convolución con el kernel)
    resultado = cv2.filter2D(imagen, -1, kernel)
    
    # Medir coincidencias: podrías usar la media de los valores de la imagen procesada
    coincidencia = np.mean(resultado)
    
    return coincidencia

# Función para guardar resultados en un CSV
def guardar_resultados_csv(file_name, coincidencias, csv_file='resultados_firmas.csv'):
    with open(csv_file, mode='a', newline='') as file:
        writer = csv.writer(file)
        writer.writerow([file_name] + coincidencias)

# Ruta al directorio con las imágenes
#image_dir = 'assets/Trainingchqs'  # Usar "/" o "\\" para rutas
#image_dir = 'assets/yocs'  
image_dir = 'assets/Firmas_Alan'  
  

# Tamaño deseado para las imágenes antes de recortar
IMG_SIZE = (736, 337)

# Tamaño uniforme para las imágenes recortadas
uniform_size = (200, 200)

# Kernel básicos que puedes probar
kernels = [
    np.ones((3, 3), np.uint8),  # Kernel de 3x3 para detección básica
    cv2.getStructuringElement(cv2.MORPH_RECT, (5, 5)),  # Kernel rectangular
    cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 5)),  # Kernel elíptico
    cv2.getStructuringElement(cv2.MORPH_CROSS, (5, 5))  # Kernel cruzado
]

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
        
        # Aplicar cada kernel y medir coincidencias
        coincidencias = []
        for kernel in kernels:
            coincidencia = aplicar_kernel_y_mediciones(firma_recortada, kernel)
            coincidencias.append(coincidencia)
        
        # Guardar los resultados de coincidencias en un CSV
        guardar_resultados_csv(file_name, coincidencias)
        
        # Mostrar la imagen procesada (opcional)
        cv2.imshow('Firma Recortada', firma_recortada)
        cv2.waitKey(500)  # Mostrar cada imagen por 500ms

cv2.destroyAllWindows()

# Convertir la lista a un array numpy para su uso en la red
processed_images = np.array(processed_images)
print(f'Número de imágenes procesadas: {len(processed_images)}')
print(f'Dimensiones de las imágenes procesadas: {processed_images.shape}')

print("Procesamiento completado y resultados guardados en el CSV.")
