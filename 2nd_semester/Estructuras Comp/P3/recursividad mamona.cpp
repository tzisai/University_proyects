#include <iostream>
#include <string.h>
using namespace std;

/* 
Martin Isai Nuñez VIlleda
Objetivo unifica los ejercicios de recursividad en un menu
fecha 17-5-24
*/


void recur(string cad,int n){
	
	cout<<cad[n];
	n--;
	
	if(n!=-1){
		recur(cad,n);
	}
	else{
		return;
	}
	
}

int sumota(int inicial,int sumatoria){
	sumatoria+=inicial;
	inicial--;
	if(inicial!=0){
		sumota(inicial,sumatoria);
	}
	else{
		return sumatoria;
	}
}
int main (){
	int chosse;
	cout<<"----------Seleccione oportunamente\n";
	cout<<"---Palabra alrevez(1)\n";
	cout<<"---Sumatoria(2)\n";
	cin>>chosse;
	switch(chosse){
		case 1:{
				string cadena;
				cout<<"Ingrese la palabra a invertir\n";
				cin>>cadena;
				int n=(sizeof(cadena)-1);
				recur(cadena,n);
			break;
		}
		case 2:{
			int N=0;
			int suma=0;
			cout<<"Ingrese el numero a calcular\n";
			cin>>N;
			suma=sumota(N,suma);
			cout<<"La sumatoria de "<<N<<" es "<<suma;
			break;
		}
		case 3:{
			
			break;
		}
	}
	
	
	
	
	
	
	
	
	return 0;
}