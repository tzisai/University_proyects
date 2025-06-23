/* Martin Isai Nunez Villeda ICI 1er semestre 
Objetivo:Un programa que pueda leer el salario de 10 empleados e imprimir el resultado.
Fecha:18 de septiembre 2023
*/
#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int Sueldo,acumS=0;
	for(int i=0;i<10;i++){
		scanf("%d",&Sueldo);
		acumS=acumS+Sueldo;
	}
printf("El total a pagar es de %d",acumS);


	
	
	exit (0);
}