
        #include<stdio.h>
        #include<math.h>
        
/*MARTIN iSAI NUÑEZ VILLEDA
Ingenieria en computacion inteligente
1er semestre
1/04/23
OBJETIVO:Leer 2 numeros e imprimir el resultado de la formula planteada.
*/

using namespace std;

int main()
{
int A,B,sum,powA=0;
	float Res,res=0;
	printf("dame el valor de A:\n");
	scanf("%d",&A);
	printf("dame el valor de B:\n");
	scanf("%d",&B);
	sum=A+B;
	powA=pow(sum,2 );
	Res=powA/3.0;
	printf("El resultado es: %f",Res);



    return 0;
}