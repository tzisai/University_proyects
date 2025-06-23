/* Martin Isai Nunez Villeda ICI 1er semestre 
Objetivo:Un prgrama que en funcion de el precio de un producto y el pago de el usuario se le imprima en pantalla las respuestas correspondientes.
Fecha:18 de septiembre 2023
*/
#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int precio,pago,faltante=0;
printf("Dame el precio de el producto\n");
scanf("%d",&precio);
printf("Dame el tu pago\n");
scanf("%d",&pago);
faltante=(pago-precio)*-1;
if(pago==precio){
	printf("Gracias por tu compra\n");
}
if(pago<precio){
	printf("Tu pago es insuficiente te hace falta %d",faltante);
}
if(pago>precio){
	faltante=faltante*-1;
	printf("Tu cambio es de %d",faltante);
}	
	
	exit (0);
}