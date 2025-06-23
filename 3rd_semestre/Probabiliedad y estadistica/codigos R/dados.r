#la funcion dado que crea un dado que en si es una lista con dos argumentos que alamacena las caras del ddo y el nombre que se adjudicará en las graficas
dado<-function(caras,nombre){
   d<-list("caras"=caras,"nom"=nombre)
   class(d)<-"dado"
   return(d)
   }
#funcion que imprime un dado supongo que en consola y dependiendo de las caras imprime estas
print.dado<-function(d){
   cat(d$nom,"\n")
   nc<-length(d$caras)
   cat("╔",rep("═╦",nc-1),"═╗\n",sep="")
   for(i in 1:nc) cat("║",d$caras[i],sep="")
   cat("║\n")
   cat("╚",rep("═╩",nc-1),"═╝\n",sep="")
   }
#funcion que "lanza" el dado y el resultado lo devuelve en forma de tabla
tirar<-function(d,n=1){
   s<-sample(d$caras,size=n,replace=TRUE)
   t<-sum(s)
   r<-list("s"=s,"t"=t,"nom"=d$nom)
   return(r)
   }
#funcion que determina que gano gano en base a un if & ifelse de los resultados obtenidos en las tiradas 
gana<-function(s1,s2){
   res<-ifelse(s1$t<s2$t,s2$nom,
	ifelse(s1$t>s2$t,s1$nom,"white"))
   return(res)
   }

#--------------------t
#Comienza simulación
#--------------------

#se instancias los dados con la funcion dado
dado1<-dado(c(4,4,4,4,0,0),"red")
dado2<-dado(c(3,3,3,3,3,3),"blue")
dado3<-dado(c(6,6,2,2,2,2),"green")
dado4<-dado(c(5,5,5,1,1,1),"azure")

#se declara las variables vs que se refieren a la comparacion de resultado de victorias entre dados
res1vs2 <- numeric()
res1vs3 <- numeric()
res2vs3 <- numeric()
res1vs4 <- numeric()

#ciclo for para generar y almacenar las tiradas
for(i in 1:10000){
    #se lanza el dado (dado,numero_tiradas) y se almacena en una variable temporal
	s1 <- tirar(dado1,1)
	s2 <- tirar(dado2,1)
	s3 <- tirar(dado3,1)
    s4 <- tirar(dado4,1)

    #En base a los resultados de las tiradas se usa la funcion gana para determinar el ganador
	r1vs2 <- gana(s1, s2)
	r1vs3 <- gana(s1, s3)
	r2vs3 <- gana(s2, s3)
    r1vs4 <- gana(s4,s1)

    #se almacena el resultado de la victoria en la variables resvs
	res1vs2<-c(res1vs2, r1vs2)
	res1vs3<-c(res1vs3, r1vs3)
	res2vs3<-c(res2vs3, r2vs3)
    res1vs4<-c(res1vs4,r1vs4)

    #se siguen estos pasos para cada iteracion del ciclo para simular las n tiradas y observar el comportamiento de los dados transitivos
}

#se pasa el resultado de las tiradas (res_vs_) a una variable tipo tabla para poder ser desplegada en una grafica 
t1vs2 <- table(res1vs2)
t1vs3 <- table(res1vs3)
t2vs3 <- table(res2vs3)
t1vs4 <- table(res1vs4)

#imprimo el dado para ver las caras y que efectivamente esta funcionando el codigo hasta este punto(es que me dio error hace rato xd)
print.dado(dado1)
print.dado(dado2)
print.dado(dado3)
print.dado(dado4)

#divido el ouput grafico en 4 segmentos para ver los dados y sus resultados de sus comparaciones
par(mfrow=c(1,4))

#se usa bar plot para cada uno de los casos(enfrentamientos) y visualizar su comportamiento 

barplot(t1vs2,xlab="Ganador",ylab="Frecuencia",
    main="Resultado de dado 1 vs dado 2",
    col=c("blue", "red", "white"))

barplot(t1vs3,xlab="Ganador",ylab="Frecuencia",
    main="Resultado de dado 3 vs dado 1",
    col=c("green", "red", "white"))

barplot(t2vs3,xlab="Ganador",ylab="Frecuencia",
    main="Resultado de dado 2 vs dado 3",
    col=c("blue", "green", "white"))

barplot(t1vs4,xlab="Ganador",ylab="Frecuencia",
    main="Resultado de dado 2 vs dado 3",
    col=c("azure2", "red", "white"))

