import cv2
import os
import numpy as np
import pandas as pd
from tensorflow import keras
from tensorflow.keras import layers
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

# Función para eliminar el archivo csv
def borrar_archivo():
    try:
        os.remove("firmas_dataset.csv")
    except OSError:
        print("No se pudo borrar el archivo")

# Función para detectar la firma y recortar la imagen
def detectarFirma(imagen, margen):
    imagen_borrosa = cv2.GaussianBlur(imagen, (5, 5), 0)
    _, umbral = cv2.threshold(imagen_borrosa, 165, 255, cv2.THRESH_BINARY_INV)
    contornos, _ = cv2.findContours(umbral, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    if contornos:
        contorno_principal = max(contornos, key=cv2.contourArea)
        x, y, w, h = cv2.boundingRect(contorno_principal)
        x = max(0, x - margen)
        y = max(0, y - margen)
        w += 2 * margen
        h += 2 * margen
        return imagen[y:y+h, x:x+w]
    return None

# Función para extraer sólo la firma sin fondo
def extraerFirma(imagen, margen):
    imagen_borrosa = cv2.GaussianBlur(imagen, (5, 5), 0)
    _, umbral = cv2.threshold(imagen_borrosa, 165, 255, cv2.THRESH_BINARY_INV)
    contornos, _ = cv2.findContours(umbral, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    if contornos:
        contorno_principal = max(contornos, key=cv2.contourArea)
        # Crear una máscara binaria para la firma
        mascara = np.zeros_like(umbral)
        cv2.drawContours(mascara, [contorno_principal], -1, 255, thickness=cv2.FILLED)
        
        # Aplicar la máscara a la imagen original
        firma_extraida = cv2.bitwise_and(imagen, imagen, mask=mascara)
        
        # Recortar la imagen para que sólo se vea la firma
        x, y, w, h = cv2.boundingRect(contorno_principal)
        x = max(0, x - margen)
        y = max(0, y - margen)
        w += 2 * margen
        h += 2 * margen
        firma_recortada = firma_extraida[y:y+h, x:x+w]
        
        # Convertir el fondo a blanco (opcional, para asegurarnos que no queden restos)
        firma_recortada[mascara[y:y+h, x:x+w] == 0] = 255
        
        return firma_recortada
    return None

# Función para aplicar kernels y contar coincidencias
def contar_coincidencias(imagen, kernels):
    coincidencias = []
    for kernel in kernels:
        resultado = cv2.filter2D(imagen, -1, kernel)
        count = np.sum(resultado > 0)
        coincidencias.append(count)
    return coincidencias

# Define algunos kernels
kernels = [
    np.array([[1, 0, -1], [1, 0, -1], [1, 0, -1]]),
    np.array([[1, 1, 1], [0, 0, 0], [-1, -1, -1]]),
    np.array([[0, 1, 0], [1, -4, 1], [0, 1, 0]]),
    np.array([[1, 1, 1], [1, 1, 1], [1, 1, 1]])
]

# Ruta al directorio con las imágenes
#image_dir = 'assets/Trainingchqs'
#image_dir = 'assets/yocs'
#image_dir = 'assets/pabs'
image_dir = 'assets/Firmas_Alan'
#image_dir = 'assets/Firmas_Lalo'
#image_dir = 'assets/Firmas_Dairon'
IMG_SIZE = (736, 337)
uniform_size = (200, 200)

# Listas para almacenar imágenes procesadas y sus etiquetas
processed_images = []
labels = []
validity = []
coincidencias_list = []

# Borrar el archivo CSV
borrar_archivo()

# Recorrer todas las imágenes en el directorio
for file_name in os.listdir(image_dir):
    file_path = os.path.join(image_dir, file_name)
    img = cv2.imread(file_path)
    if img is not None:
        img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        resized_img = cv2.resize(img_gray, IMG_SIZE)
        firma_recortada = detectarFirma(resized_img, margen=10)
        if firma_recortada is not None:
            firma_recortada = cv2.resize(firma_recortada, uniform_size)
            processed_images.append(firma_recortada)
            label = file_name.split('.')[0]
            labels.append(label)
            validity.append(1)  # Marca como válida (1)
            coincidencias = contar_coincidencias(firma_recortada, kernels)
            coincidencias_list.append(coincidencias)
            output_filename = f"firma_extraida_{file_name.split('.')[0]}.png"
            cv2.imwrite(output_filename, firma_recortada)
            print(f"Firma guardada en {output_filename}")

# Convertir a arrays numpy
processed_images = np.array(processed_images)
labels = np.array(labels)
validity = np.array(validity)
coincidencias_list = np.array(coincidencias_list)

# Normalizar imágenes
processed_images = processed_images.astype('float32') / 255.0

# Generar firmas no válidas a partir de una desviación estándar
num_invalid_signatures = len(labels)
invalid_images = []
invalid_labels = []
invalid_validity = []
invalid_coincidencias = []

for i in range(num_invalid_signatures):
    invalid_signature = processed_images[i] + np.random.normal(0, 0.1, processed_images[i].shape)
    invalid_images.append(np.clip(invalid_signature, 0, 1))
    invalid_labels.append(labels[i])
    invalid_validity.append(0)
    coincidencias = contar_coincidencias(invalid_images[-1], kernels)
    invalid_coincidencias.append(coincidencias)

# Combinar imágenes válidas y no válidas
combined_images = np.concatenate((processed_images, invalid_images), axis=0)
combined_labels = np.concatenate((labels, invalid_labels), axis=0)
combined_validity = np.concatenate((validity, invalid_validity), axis=0)
combined_coincidencias = np.concatenate((coincidencias_list, invalid_coincidencias), axis=0)

# Convertir la lista de coincidencias a un DataFrame
coincidencias_df = pd.DataFrame(combined_coincidencias, columns=[f'coincidencias_kernel_{i+1}' for i in range(len(kernels))])

# Guardar en CSV
df = pd.DataFrame({
    'label': combined_labels,
    'validity': combined_validity
})

# Unir el DataFrame de coincidencias con el DataFrame principal
df = pd.concat([df, coincidencias_df], axis=1)
df.to_csv('firmas_dataset.csv', index=False)

# Dividir el dataset en entrenamiento y validación
X_train, X_val, y_train, y_val = train_test_split(combined_images, combined_validity, test_size=0.2, random_state=42)

# Definir el modelo de red neuronal convolucional
model = keras.Sequential([
    layers.Conv2D(32, (3, 3), activation='relu', input_shape=(uniform_size[0], uniform_size[1], 1)),
    layers.MaxPooling2D(pool_size=(2, 2)),
    layers.Conv2D(64, (3, 3), activation='relu'),
    layers.MaxPooling2D(pool_size=(2, 2)),
    layers.Conv2D(128, (3, 3), activation='relu'),
    layers.Flatten(),
    layers.Dense(128, activation='relu'),
    layers.Dense(2, activation='softmax')  # 2 clases: válido y no válido
])

# Compilar el modelo
model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])

# Entrenar el modelo
model.fit(X_train, y_train, epochs=25, validation_data=(X_val, y_val))

# Evaluar el modelo
loss, accuracy = model.evaluate(X_val, y_val)
print(f'Loss: {loss}, Accuracy: {accuracy}')

# Visualizar algunas predicciones y extraer firmas válidas
predictions = model.predict(X_val)
predicted_classes = np.argmax(predictions, axis=1)

# Crear una carpeta para guardar las firmas exitosamente reconocidas
if not os.path.exists("firmas_reconocidas"):
    os.makedirs("firmas_reconocidas")

# Extraer y guardar las firmas reconocidas como válidas
for i in range(len(X_val)):
    if predicted_classes[i] == 1:  # Firma reconocida como válida
        firma_recortada = (X_val[i] * 255).astype(np.uint8)
        output_filename = f"firmas_reconocidas/firma_reconocida_{i}.png"
        cv2.imwrite(output_filename, firma_recortada)
        print(f"Firma reconocida guardada en {output_filename}")

plt.show()
