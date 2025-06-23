import cv2
import numpy as np

# Cargar la imagen completa
img = cv2.imread('assets\isa2.png')

# Obtener las dimensiones de la imagen
altura, ancho = img.shape[:2]

# Seleccionar la región inferior de la imagen (por ejemplo, la mitad inferior)
roi_inferior = img[altura//2:altura, 0:ancho]  # Desde la mitad de la imagen hacia abajo

# Convertir a escala de grises y aplicar suavizado
gray = cv2.cvtColor(roi_inferior, cv2.COLOR_BGR2GRAY)
gray_blurred = cv2.medianBlur(gray, 5)

# Detectar círculos en la región seleccionada
circulos = cv2.HoughCircles(gray_blurred, 
                            cv2.HOUGH_GRADIENT, dp=1.2, minDist=30, 
                            param1=50, param2=30, minRadius=15, maxRadius=50)

# Si se detectan círculos
if circulos is not None:
    # Convertir los valores de los círculos a enteros
    circulos = np.round(circulos[0, :]).astype("int")
    
    # Dibujar los círculos detectados
    for (x, y, r) in circulos:
        # Ajustar las coordenadas y añadir la posición de la región recortada
        # Sumar la altura para posicionarlos correctamente en la imagen completa
        cv2.circle(img, (x, y + altura//2), r, (0, 255, 0), 4)  # Ajustamos 'y'
        cv2.circle(img, (x, y + altura//2), 2, (0, 0, 255), 3)  # Dibujar el centro del círculo

# Mostrar el resultado final con los círculos detectados en la parte inferior
cv2.imshow("Detección de Círculos en la parte inferior", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
