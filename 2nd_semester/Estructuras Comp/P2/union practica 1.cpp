/*
Martin Idsi Nuñez Villeda ICI 2do semestre
Objetivo:Crea un programa que utilice structs y la estructura union.
haciendo una estructura de un alumno con datos generale y dependiendo de el tipo ingresado escane una cosa u otra.( haciendo uso de la union)
28 de febrero de 2024
*/


#include <iostream>
#include <string.h>

using namespace std;

union Beca{
char depo[40];
int beca;	
};

struct alumno{
int id;
int tipoB;
string nombre;
union Beca beca1;
};


int main(){
alumno alumno1[2];	
	for(int i=0;i<3;i++){
		
	
	cout<<"Ingrese su ID :"<<endl;
	cin>>alumno1[i].id;
	cout<<"ingrese au nombre: "<<endl;
	cin>>alumno1[i].nombre;
	do{
		system("cls");
	cout<<"ingrese el tipo de estudiante que es \n ingrese el numero segun corrsponda el caso (1) Deportista (2) Becario"<<endl;
	cin>>alumno1[i].tipoB;	
	if(alumno1[i].tipoB!=1||alumno1[i].tipoB!=2){
		cout<<"valor invalido ingrese alguno de los indicados"<<endl;
		system("PAUSE");
	}
	}while(alumno1[i].tipoB!=1 || alumno1[i].tipoB!=2);
	
	if(alumno1[i].tipoB==1){
		cout<<"ingrese el deporte que pratica"<<endl;
		cin>>alumno1[i].beca1.depo;
	}
	else{
		cout<<"Ingrese el porcentaje de beca que recibe(solo numero entero)"<<endl;
		cin>>alumno1[i].beca1.beca;
	}
}
	
	return 0;
}