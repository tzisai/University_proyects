
import numpy as np
import cv2
 
# Creamos una matriz de unos de 100 filas y 100 columnas
imagen1 = np.ones((300, 300, 3), dtype="uint8") #alto, ancho

# Mostramos la imagen
cv2.imshow("Lienzo", imagen1)

# Mostramos la imagen
imagen1[:] = 0,255,0
cv2.imshow("Mi primer imagen verde", imagen1)



# ================================== BANDERAS ==============================================
 
# Imagen polonia
imagen2 = np.zeros((400, 600, 3), dtype="uint8") #alto, ancho
imagen2[:200, :] = 255,255,255
imagen2[200:, :] = 0,0,210
cv2.imshow("Polonia", imagen2)

# Imagen Irlanda
imagen3 = np.zeros((400, 600, 3), dtype="uint8") #alto, ancho
imagen3[:, 0:200] = 98,155,22
imagen3[:, 200:400] = 255,255,255
imagen3[:, 400:600] = 62,136,255
cv2.imshow("Irlanda", imagen3)

# Rectangulo
imagen4 = np.zeros((400, 600, 3), dtype="uint8") #alto, ancho
imagen4 = cv2.rectangle(imagen4, (5,5), (100,100), (255, 0, 0), thickness = 2)
cv2.imshow("Rectangulo", imagen4)

# Circulo
imagen5 = np.zeros((400, 600, 3), dtype="uint8") #alto, ancho
imagen5[:, :] = 255,255,255
cv2.circle(imagen5, (imagen5.shape[1]//2,imagen5.shape[0]//2),100,(0,0,210),thickness=-1)
cv2.imshow("Circulo", imagen5)
"""
# Guardamos la imagen en la carpeta images
cv2.imwrite("imagenes creadas/"+ "Mi_primer_bandera.jpg", imagen3)

# #  Francia, Costa Rica, Mexico, Colombia, Alemania, Republica Dominicana, Bulgaria, Suiza, Noruega

# # Barras degradadas
# imagen[:, :] = 255,255,255
# div = 16
# gap = mt.floor(600/div)
# div_c = 255/div
# for i in range(0,div):
#     a = gap*i
#     b = a + gap*i
#     i = i + 1
#     # imagen[:, a:b] = mt.floor(255-div_c*i),mt.floor(255-div_c*i),mt.floor(255-div_c*i)
#     # imagen[:, a:b] = mt.ceil(255-(i*255/div)),mt.ceil(255-(i*255/div)),mt.ceil(255-(i*255/div))
#     imagen[:, a:b] = mt.floor(255-i*div_c),mt.floor(255-i*div_c),mt.floor(255-i*div_c)
# cv.imshow("Barras", imagen)


# # Circulo
# imagen[:, :] = 255,255,255
# cv.circle(imagen, (imagen.shape[1]//2,imagen.shape[0]//2),100,(0,0,210),thickness=-1)
# cv.imshow("Circulo", imagen)

# # RAF, roundels of france, italian republic, iberian union, romania

# # Circulos concentricos
# imagen[:, :] = 255,255,255
# for j in range(1,100):
#     r = 400-5*j
#     if r <= 0:
#         break
#     else: 
#         if (j % 2) == 0:
#             cv.circle(imagen, (imagen.shape[1]//2,imagen.shape[0]//2),r,(0,0,0),thickness=-1)
#         else:
#             cv.circle(imagen, (imagen.shape[1]//2,imagen.shape[0]//2),r,(256,256,256),thickness=-1)
# cv.imshow("Circulos", imagen)





# # Guardamos la imagen en la carpeta images
# # cv2.imwrite("imagenes creadas/"+ "Mi_primer_bandera.jpg", imagen)

# print ("press a key inside the image to exit")
# cv.waitKey(0)                                     #Mantiene hasta que apriete cualquier tecla 

# cv.destroyAllWindows()  # Cierra todas las ventanas abiertas


# ================================ IMAGENES DESCARGADAS ==========================================



# Loading an image 
img = cv2.imread("imagenes descargadas/Imagen_1.jpg")
cv2.imshow("Imagen Original", img)

# Image size
img = cv2.imread("imagenes descargadas/imagen_1.jpg")
cv2.imshow("Imagen Original", img)
print("El alto de la imagen original es: " + str(img.shape[0]) + " pixeles")
print("El ancho de la imagen original es: " + str(img.shape[1]) + " pixeles")
print("La imagen tiene " + str(img.shape[2]) + " canales")

# Changing to grey scale 
imgGrey = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
cv2.imshow("Imagen Gris", imgGrey)

# Changing to HSV
imgHSV = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
cv2.imshow("Imagen HSV", imgHSV)

# Changing to L*a*b
imgLAB = cv2.cvtColor(img,cv2.COLOR_BGR2LAB)
cv2.imshow("Imagen L*A*B", imgLAB)

# Splitting channels
b,g,r = cv2.split(img)
cv2.imshow("Azul", b)
cv2.imshow("Verde", g)
cv2.imshow("Rojo", r)

# Modifying channels
factor = 1.2 
rr = cv2.multiply(r,np.array([factor]))
fusion = cv2.merge([b,g,rr])
cv2.imshow("Imagen Modificada", fusion)

# Blurring
imgBlur = cv2.GaussianBlur(img, (5,5), 0)
cv2.imshow("Imagen Borrosa", imgBlur)

# Edges
imgCanny = cv2.Canny(img,200,200)
cv2.imshow("Imagen bordes", imgCanny)

# threshold (Binary Image)
ret, imgthresh = cv2.threshold(imgGrey, 125, 255, cv2.THRESH_BINARY)
cv2.imshow("Imagen Binaria", imgthresh)

# Resize
img = cv2.imread("imagenes descargadas/imagen_1.jpg")
resized_image = cv2.resize(img, (0, 0), fx=0.5, fy=0.5)
cv2.imshow('Imagen al 50', resized_image)

# # Resize
# img = cv.imread("imagenes descargadas/imagen_1.jpg")
# cv.imshow("Imagen Original", img)
# print("El alto de la imagen original es: " + str(img.shape[0]) + " pixeles")
# print("El ancho de la imagen original es: " + str(img.shape[1]) + " pixeles")
# print("La imagen tiene " + str(img.shape[2]) + " canales")
# imgRS = cv.resize(img,(2*img.shape[1],2*img.shape[0]))
# print("El alto de la imagen escalada es: " + str(imgRS.shape[0]) + " pixeles")
# print("El ancho de la imagen escalada es: " + str(imgRS.shape[1]) + " pixeles")
# print("La imagen tiene " + str(imgRS.shape[2]) + " canales")
# cv.imshow("Imagen Grande", imgRS)

# Cropping
imgcrop = img[100:300, 200:400]
cv2.imshow("Imagen Recortada", imgcrop)

# Imagen aumentada interpolada
imginter =  cv2.resize(img,(2*img.shape[1],2*img.shape[0]), interpolation=cv2.INTER_CUBIC)
cv2.imshow('Imagen al doble', imginter)

# Adding a green square
imgsquare = cv2.rectangle(img, (55,60), (185,220),(0,255,0),thickness=2)
imgtext = cv2.putText(imgsquare,"Mujer",(70,55),cv2.FONT_HERSHEY_TRIPLEX,0.8,(0,255,0),2)
cv2.imshow('Imagen con cuadro', imgsquare)

"""
cv2.waitKey(0)
cv2.destroyAllWindows()





