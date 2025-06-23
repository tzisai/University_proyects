//Elaboro Martrin Isai Nunez Villeda 397999
//23 de febrero de 2024
//Objetivo:Construya un programa que realice las siguientes operaciones:
/*• Listar el numero y nombre del empelado que tuvo las mayores ventas durante el trimestre. Valor 2
puntos
• Incrementar un 10% del salario de todos los empleados que tuvieron ventas superiores a $10,000y
liste el número y nombre de dichos empleados. Valor 2 puntos
• Liste el número y nombre de los empleados que en el mes de febrero tuvieron ventas inferiores a
$3,000. Valor 1 punto
*/
#include <iostream>
#include <string.h>

using namespace std;

struct empleados{
	
	int num;
	string nom;
	float ventas [3];
	float salario;
	int salariosTotal;
}emp1[10];


int main (){
	
	int Sbajos[10];
	int Saltos[10];
	
	int Nemp=0;
	do {
	cout<<"ingrese el numero de empleados(No mayor a 10)"<<endl;
	cin>>Nemp;
	}while((Nemp>12)||(Nemp<=0));
	
	
	for(int i=0; i<Nemp;i++){
		system("CLS");
		cout<<"ingrese el numero de reconocimiento de el empleado(ID)"<<endl;
		cin>>emp1[i].num;
		fflush(stdin);
		cout<<"ingrese el nombre de el empleado"<<endl;
		getline(cin,emp1[i].nom);
		
		for(int j=0;j<3;j++){
			cout<<"ingresa la "<<j<<" venta"<<endl;
			do{
			cin>>emp1[i].ventas[j];	
			}while(emp1[i].ventas[j]<=0);
		}
		cout<<"ingrese el salario de el empleado"<<endl;
	do{
		cin>>emp1[i].salario;
	}while(emp1[i].salario<=0);

	}
	
	for(int i=0;i<Nemp;i++){
		int j=0;
		emp1[i].salariosTotal=emp1[i].ventas[j]+emp1[i].ventas[j+1]+emp1[i].ventas[j+2];
	}
	

	
int bajos;
int altos;
	for(int i=0;i<+Nemp;i++){
		
				if(emp1[i].salariosTotal>=30000){
						Saltos[i]=i;
						altos++;
				}
				else if(emp1[i].salariosTotal<=3000){
					
						Sbajos[i]=i;
						bajos++;
				}
		}			

}

for(int i=0;i<bajos:i++){
cout<<"las ventas mas bajas fueron:"<<endl;
	emp1[Saltos[i]].num<<" "<<emp1[Saltos[i]].salariosTotal<<endl;
}

for(int i=0;i<altos:i++){
cout<<"las ventas mas bajas fueron:"<<endl;
	emp1[Sbajos[i]].num<<" "<<emp1[Saltos[i]].salariosTotal<<endl;
}	
	
	
	
	
	
	
}