/* 
Elaboro:Martin Isai Nuñez Villeda 397999

Objetivo:
Realizar la implementación de un programa usando montos de
ventas de 5 sucursales trimestrales de una empresa a lo largo de
los últimos 2 años(2022, 2023) y obtener lo siguiente.
a) Sucursal que más ha vendido en los 2 años
b) Promedio de ventas por año
c) Año con mayor promedio de ventas.

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	
	double empresa_n [2][5][4];
	double empresa_total [2][5];
	int MasV=0,suc;
	double vectComp[5];
	
	for(int i=0;i<2;i++){
		for(int j=0;j<5;j++){
			for(int k=0;k<4;k++){
				empresa_n[i][j][k]=rand() % 20000 + 2000 - 1;
			}
		}
	}
	
	
	
	
	for(int i=0;i<2;i++){
		for(int j=0;j<5;j++){
			for(int k=0;k<4;k++){
				empresa_total[i][j]+=empresa_n[i][j][k];
			}	
		}
	}
	
	
	for(int i=0;i<2;i++){
		for(int j=0;j<5;j++){
			int cont=j;
			cout<<"Sucursal:"<<cont+1<<"  |";
			for(int k=0;k<4;k++){
				cout<<empresa_n[i][j][k]<<"\t |";
			}
			cout<<"Total anual: "<<empresa_total[i][j]<<"\t |";
			cout<<"Total promedio trimestral "<<(empresa_total[i][j]/4)<<endl;
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	for(int i=0;i<1;i++){
		for(int j=0;j<5;j++){
			vectComp[j]=empresa_total[i][j]+empresa_total[i+1][j];
			cout<<"La venta total de los ultimos 2 anios de la sucursal "<<j+1<<" fue de "<<vectComp[j]<<endl;
			cout<<"Y su mayor anio de ventas fue el";
			if(empresa_total[i][j]>empresa_total[i+1][j]){
				cout<<" primero con $"<<empresa_total[i][j]<<" en ventas"<<endl;
			}
			else{
			cout<<" segundo con $"<<empresa_total[i][j]<<" en ventas"<<endl;	
			}
			cout<<endl;
		}
		cout<<endl;
	}

	for(int i=0;i<5;i++){
		if(MasV<vectComp[i]){
		MasV=vectComp[i];
		suc=i+1;	
		}
	}
	cout<<endl<<"La sucursal que mas vendio en 2 anios fue la sucursal "<<suc<<" con $"<<MasV<<" en ventas";
	
	return 0;
}