

library(jpeg)

# Cargar la imagen y mostrar la imagen original
ruta<-file.choose("C:\\Users\\ALUMNO.E52-COMP14\\Downloads\\ImagPrueba")
img <- readJPEG(ruta)
plot(0:1, 0:1, type='n', axes=FALSE, xlab="", ylab="")
rasterImage(img, 0, 0, 1, 1)
readline(prompt = "Presiona Enter para continuar...")
hist(img, breaks=256, col='gray', main='Histograma de imagen sin correccion de canal')
readline(prompt = "Presiona Enter para continuar...")

factor <- 0.2  # Disminuye el canal seleccionado
img_modificada <- img
img_modificada[,,1] <- img[,,1] * factor
plot(0:1, 0:1, type='n', axes=FALSE, xlab="", ylab="")
rasterImage(img_modificada, 0, 0, 1, 1)
readline(prompt = "Presiona Enter para continuar...")
hist(img_modificada, breaks=256, col='gray', main='Histograma con canal Corregido')
readline(prompt = "Presiona Enter para continuar...")

# Convertir a escala de grises
# Usando una ponderación estándar: 0.299*R + 0.587*G + 0.114*B
img_gris <- 0.299 * img_modificada[,,1] + 0.587 * img[,,2] + 0.114 * img[,,3]


T <- function(x){
  #Algunas operaciones estan comentadas por que probe varios tipos de 
  r <- sum(img_modificada <= x) / (nrow(img_modificada) * ncol(img_modificada))
  # r <- sum(img_modificada <= x) / length(img_modificada)
   #r<-sum(img<=x)/(nrow(img_modificada)*ncol(img_modificada))
    # r<-x**2
    return(r)
}


# Modificar la ecualizacion de grises
factor_iluminacion <-T(0.7)  # Factor para aumentar la ecualizacion
img_iluminada <- img_gris * factor_iluminacion

# Asegurarse de que los valores estén en el rango [0, 1]
img_iluminada[img_iluminada > 1] <- 1

# Mostrar la imagen en escala de grises con iluminación modificada
plot(0:1, 0:1, type='n', axes=FALSE, xlab="", ylab="")
rasterImage(img_iluminada, 0, 0, 1, 1)
readline(prompt = "Presiona Enter para continuar...")


# Histograma de la imagen en escala de grises con iluminación modificada
hist(img_iluminada, breaks=256, col='gray', main='Histograma con Ecualizacion para grises')
readline(prompt = "Presiona Enter para continuar...")
dev.off()
