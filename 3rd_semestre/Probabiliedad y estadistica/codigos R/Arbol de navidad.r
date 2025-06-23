# Parámetros para las transformaciones del árbol de Navidad
T1 <- c(0.9, 0, 0, 0.7, 0, -0.1, 0.4)     # Rama principal
T2 <- c(0.8, 0, 0, 0.8, -0.05, -0.25, 0.25)  # Rama izquierda
T3 <- c(0.8, 0, 0, 0.8, 0.05, -0.25, 0.25)   # Rama derecha
T4 <- c(0.5, 0, 0, 0.5, 0, 0.3, 0.6)   # Base del tronco
T5 <- c(0.1, 0, 0, 0.4, 0, 0, 0.001)   # Tronco visible más grande

T <- matrix(c(T1, T2, T3, T4, T5), byrow=TRUE, ncol=7)
colnames(T) <- c("a11", "a12", "a21", "a22", "b1", "b2", "p")

# Inicialización de puntos
x <- c(0, 0)
xs <- x

# Generar puntos
for (i in 1:50000) {
    k <- sample(1:nrow(T), 1, prob=T[, "p"])
    a <- matrix(T[k, 1:4], byrow=TRUE, ncol=2)
    b <- matrix(T[k, 5:6], ncol=1)
    x <- a %*% x + b
    xs <- cbind(xs, x)
}

# Dibujar el árbol de Navidad
plot(t(xs), pch=20, col="forestgreen", xlab="X", ylab="Y", axes=FALSE)
