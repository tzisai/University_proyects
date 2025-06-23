#include <stdio.h>

/*MARTIN iSAI NUÑEZ VILLEDA
Ingenieria en computacion inteligente
1er semestre
1/04/23
OBJETIVO:Leer precio y pago del usuario y regresar su cambio o mensaje correspondiente segun sea el caso.
(le puse cosas de mas para evitar que me tronaran el programa)
*/

using namespace std;

int main(){
	int prepago,pago,cambio,faltante=0;
	
	printf("ingrese el precio de el producto\n");
	scanf("%d",&prepago);
	printf("ingrese su pago: \n");
	scanf("%d",&pago);
	
	cambio=pago-prepago;
	faltante=cambio*-1;
	if(pago==prepago){
				printf("Gracias por tu compra");
	}
	else if(pago>prepago){
				printf("gracias por tu compra tu cambio es de %d ",cambio);
	}
	else{
				printf("no tienes el suficiente dinero te hace falta %d ",faltante);
	}
	
	
	
	
	return 0;
}