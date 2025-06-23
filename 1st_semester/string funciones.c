#include <string.h>
#include <stdio.h>
#include <conio.h>
//Martín Isaí Nuñez Villeda 
// JESUS YOCSAN LUEVANO FLORES
//Alan Fernando Martinez Moreno
//ICI 1er Semestre 
//Programa donde se hace uso de strings y las funciones vistas en clase mas una extra investigadas.
//En este programa strrev inverte el contenido de una funcion.

main(){
	char cadena1[40];	char cadena2[40];	char nomC1[80];	char nomR1[80];
	char cadena3[40];	char cadena4[40];	char nomC2[80]; char nomR2[80];
	int elec=0;
	 
	printf("Pero.. son carnales o no?\n");
	printf("Ingrese el nombre 1\n");
	gets(cadena1);
	printf("Ingrese los apellidos\n");
	gets(cadena2);
	strlwr(cadena2);
	
	printf("Ingrese el nombre 2\n");
	gets(cadena3);
	printf("Ingrese los apellidos\n");
	gets(cadena4);
	strlwr(cadena4);
	
	sprintf(nomC1,"%s %s",cadena1,cadena2);
	sprintf(nomC2,"%s %s",cadena3,cadena4);
	
	printf("%s y %s",nomC1,nomC2);
	
	if (strcmp(cadena2,cadena4)==0){
	printf(" son hermanos");
	}
	else {
	printf(" no son hermanos");	
	}
	
	printf("\nQuieres ver un truco?\n");
	printf("1.-si	0.-no	\n");
	scanf("%d",&elec);
	
	if(elec==1){
		strcpy(nomR1,nomC1);
		strcpy(nomR2,nomC2);
		strrev(nomR1);
		strrev(nomR2);
		printf("Mira!!! %s se escribe al revez \n %s\n",nomC1,nomR1);
		printf("Mira!!! %s se escribe al revez \n %s\n",nomC2,nomR2);
		
	}
	
	
	
	
	return(0);
}