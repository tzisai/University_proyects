#include <stdio.h>
#include <math.h>

/*MARTIN iSAI NUÑEZ VILLEDA
Ingenieria en computacion inteligente
1er semestre
1/04/23
OBJETIVO:Leer 1 numero y calcular su cubo y cuadrado.
*/

using namespace std;
int main (){
	
	float input,cu,cua=0;
	
	printf("dame el numero a calcular:\n");
	scanf("%f",&input);
	cua=pow(input,2);
	cu=pow(input,3);
	printf("el cuadrado de el nuemro es %.1f y su cubo es de %.1f",cua,cu);
	return 0;
}
