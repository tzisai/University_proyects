/* Martin Isai Nunez Villeda ICI 1er semestre 
Objetivo:Un prgrama queobtenga la suma de los nuemros pares e impares de el 100 al 400
Fecha:18 de septiembre 2023
*/
#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
int acum,acum2=0;

for(int i=100;i<=400;i++){
	
	if(i%2==0){
	acum=acum+i;
	}
else{
	acum2=acum2+i;
}
}
printf("La suma de los numeros pares es igual a:");
cout<<acum<<endl;
printf("La suma de los numeros impares es igual a:");
cout<<acum2;



	
	
	exit (0);
}