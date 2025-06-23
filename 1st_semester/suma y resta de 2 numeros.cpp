#include <stdio.h>

/*MARTIN iSAI NUÑEZ VILLEDA
Ingenieria en computacion inteligente
1er semestre
1/04/23
OBJETIVO:Leer 2 numeros e imprimir la suma y resta entre ellas mismos.
*/

using namespace std;
int main (){
	
	float a,b,sum,res=0;
	
printf("dame 2 numeros \n");
scanf("%f%f",&a,&b);
sum=a+b;
res=a-b;
printf("la suma es: %f \n Y la resta da: %f",sum,res);

	return 0;
}