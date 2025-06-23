#include <stdio.h>

/*MARTIN iSAI NUÑEZ VILLEDA
Ingenieria en computacion inteligente
1er semestre
1/04/23
OBJETIVO:Leer la altura y base de un rectangulo, calcular e imprimir las resultados de su perimetro y area.
*/

using namespace std;

int main(){
	int base,altura,area,perimetro=0;
	printf("ingresa la base y la altura separada por un espacio respectivamente: \n");
	scanf("%d%d",&base,&altura);
	
	area=base*altura;
	perimetro=2*(base+altura);
	
	printf("el area del rectangulo es de %d y su perimetro es de %d",area,perimetro);
	
	return 0;
	
}