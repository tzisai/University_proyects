
T1 <- c(0, 0, 0, 0.4, 0, 0, 0.01)      
T2 <- c(cos(0.85), 0.44, -0.44, 0.85, 0, 1.6, 0.8)  
T3 <- c(0.2, -0.26, 0.23, 0.22, 0, 1.6, 0.07)   
T4 <- c(-0.15, 0.28, 0.26, 0.24, 0, 0.44, 0.09) 
T <- matrix(c(T1, T2, T3, T4), byrow=TRUE, ncol=7)
colnames(T) <- c("a11", "a12", "a21", "a22", "b1", "b2", "p")

# Inicialización
x <- c(0, 0)
xs <- x

# Matriz de reflexión en el eje x
reflection_x <- matrix(c(1, 0, 0, -1), nrow = 2, byrow = TRUE)

# Generar puntos reflejados en el eje x
for (i in 1:10000) {
    k <- sample(1:nrow(T), 1, prob=T[, "p"])
    a <- matrix(T[k, 1:4], byrow=TRUE, ncol=2)
    b <- matrix(T[k, 5:6], ncol=1)
    x <- a %*% x + b
    
    # Aplicar la reflexión en el eje x
    x <- reflection_x %*% x
    
    xs <- cbind(xs, x)
}

# Dibujar el helecho reflejado en el eje x
par(bg = "black")
plot(t(xs), pch=20, col="white", xlab="X", ylab="Y", axes=FALSE)
