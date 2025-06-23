//elaboro Martin Isai Nuñez Villeda
//Objetivo crear un struct que capture los datos de el un corredor y se desplieguen en pantalla.
#include<iostream>
#include<string.h>

using namespace std;

int main(){
	
	struct corredor{
		string nombre;
		string club;
		string categoria;
		string genero;
		int edad;
	}corr1;
	
	cout<<"ingrese el nombre del aspirante:"<<endl;
	getline(cin,corr1.nombre);
//cout<<corr1.nombre;
	cout<<"ingrese el club de procedencia"<<endl;
	getline(cin,corr1.club);	
	
	cout<<"Ingrese su edad"<<endl;
	cin>>corr1.edad;
	
	if(corr1.edad>40){
		corr1.categoria="Veterano";
	}
	else if (corr1.edad<40||corr1.edad>19){
	 corr1.categoria="Adulto";
	}
	else{
	  corr1.categoria="Juvenil";
	}
	cout<<"ingrese su genero"<<endl;
	cout<<"(F) Femenino (M)masculino"<<endl;
	fflush(stdin);
	getline(cin,corr1.genero);
	
	cout<<corr1.nombre<<endl;
	cout<<corr1.club<<endl;
	cout<<corr1.edad<<endl;
	cout<<corr1.genero<<endl;
	cout<<corr1.categoria<<endl;
	
	
	
	
	
	return 0;
}