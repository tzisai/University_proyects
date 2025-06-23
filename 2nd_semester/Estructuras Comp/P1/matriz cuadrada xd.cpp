//Elaboro Martin Isai Nuñez Villeda
//Objetivo:elaborar un programa que cree una matriz(arreglo multidimensional) y determine si esta es una matriz cuadrada o no.
#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

int main(){
int tam,tam2;
int mat[10][10];
cout<<"ingrese el tamanio de la matriz {filas}( numero entero)"<<endl;
cin>>tam;	
cout<<"ingrese el tamanio de la matriz {columnas}( numero entero)"<<endl;
cin>>tam2;	
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam2;j++){
			mat[i][j]=rand() % 100 ;
		cout<<mat[i][j]<<"\t";	
		}
		cout<<endl;
	}
	
	if(tam==tam2){
		cout<<"la matriz es cuadrada"<<endl;
	}
	else{
		cout<<"la matriz no es cuadrada"<<endl;
	}
	
	
	
	
	
	
	
	
	return 0;
	
}