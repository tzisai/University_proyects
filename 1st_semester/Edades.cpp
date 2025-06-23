#include<stdio.h>
//Martin Isai Nunez Villeda ICI 1ersemestre sabado 10 de septiembre de 2023.

int main(){
	
	int edad=0;
	
	printf("Ingresa tu edad:\n");
	scanf("%d",&edad);
	if(edad<=10){
		printf("Ni%co",164);
	}
	else{
		if(edad<65&&edad>10){
			printf("Adulto");
		}
		else{
			if(edad>65){
			printf("Jubilado");
		}
	  }
	}
	
	
	
	
	
	return 0;
}