import cv2
import os
import numpy as np
import pandas as pd
from tensorflow import keras
from tensorflow.keras import layers
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

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

# Ruta al directorio con las imágenes
image_dir = 'assets/Trainingchqs'
#image_dir = 'assets\yocs'
IMG_SIZE = (736, 337)
uniform_size = (200, 200)

# Listas para almacenar imágenes procesadas y sus etiquetas
processed_images = []
labels = []
validity = []  # Lista para almacenar la validez de las firmas

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

# Convertir a arrays numpy
processed_images = np.array(processed_images)
labels = np.array(labels)
validity = np.array(validity)

# Normalizar imágenes
processed_images = processed_images.astype('float32') / 255.0

# Convertir etiquetas a categorías
unique_labels, labels_indices = np.unique(labels, return_inverse=True)

# Generar firmas no válidas a partir de una desviación estándar
num_invalid_signatures = len(labels)  # Puedes ajustar esto según necesites
invalid_images = []
invalid_labels = []
invalid_validity = []

for i in range(num_invalid_signatures):
    # Aquí generas la firma no válida (modifica según tus criterios)
    invalid_signature = processed_images[i] + np.random.normal(0, 0.1, processed_images[i].shape)  # Añadir ruido
    invalid_images.append(np.clip(invalid_signature, 0, 1))  # Asegurar que los valores estén entre 0 y 1
    invalid_labels.append(labels[i])  # Usar la misma etiqueta
    invalid_validity.append(0)  # Marca como no válida (0)

# Combinar imágenes válidas y no válidas
combined_images = np.concatenate((processed_images, invalid_images), axis=0)
combined_labels = np.concatenate((labels, invalid_labels), axis=0)
combined_validity = np.concatenate((validity, invalid_validity), axis=0)

# Guardar en CSV
df = pd.DataFrame({
    'label': combined_labels,
    'validity': combined_validity
})
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
    layers.Dense(2, activation='softmax')  # Cambiado para 2 clases: válido y no válido
])

# Compilar el modelo
model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])

# Entrenar el modelo
model.fit(X_train, y_train, epochs=10, validation_data=(X_val, y_val))

# Evaluar el modelo
loss, accuracy = model.evaluate(X_val, y_val)
print(f'Loss: {loss}, Accuracy: {accuracy}')

# Visualizar algunas predicciones
predictions = model.predict(X_val)
predicted_classes = np.argmax(predictions, axis=1)

# Mostrar algunas imágenes y sus predicciones
plt.figure(figsize=(12, 6))
for i in range(5):
    plt.subplot(2, 5, i + 1)
    plt.imshow(X_val[i])
    plt.title(f'Predicción: {"Válida" if predicted_classes[i] == 1 else "No Válida"}')
    plt.axis('off')

plt.show()
