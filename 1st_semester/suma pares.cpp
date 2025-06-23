/* Martin Isai Nunez Villeda ICI 1er semestre 
Objetivo:Un prgrama que obtenga la suma de los numeros pares del 1 al 100.
Fecha:18 de septiembre 2023
*/
#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
int acum=0;

for(int i=0;i<=100;i++){
	
	if(i%2==0){
	acum=acum+i;
	}

}
printf("La suma de los numeros pares es igual a:");
cout<<acum;


	
	
return 0;
}