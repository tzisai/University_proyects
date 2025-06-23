#include <stdio.h>

/*MARTIN iSAI NUÑEZ VILLEDA
Ingenieria en computacion inteligente
1er semestre
1/04/23
OBJETIVO:Pedir al usuario 5 numeros y su matricula para despues entregarle su promedio con su matricula.
*/

using namespace std;
int main (){
	
	float a,b,c,d,e,prom=0;
	int id=0;
printf("dame tu id: \n");
scanf("%i",&id);
printf("dame tus 5 calificaciones separadas por u espacio : \n");
scanf("%f%f%f%f%f",&a,&b,&c,&d,&e);
prom=(a+b+c+d+e)/5;
printf("tu id es %i tu promedio es de %f",id,prom);
	
	
	
	return 0;
}