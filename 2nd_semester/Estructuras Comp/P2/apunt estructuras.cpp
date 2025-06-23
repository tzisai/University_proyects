#include<iostream>
using namespace std;

//Elaboró:Martin Isai Nuñez Villeda 
//Objetivo:Crea un programa que use la estructura struct y que con el uso de un apuntador del mismo tipo se acceda a un vector de structs
//tomando como ejemplo sencillo un hipotetico caso de un nombre y matricula de un alumno. 

struct alumno{
	char nombre[26];
	int matricula;
}alumno1[2];



int main(){
	struct alumno *aptr;
	aptr=alumno1;
	for(int i=0;i<2;i++){
	cout<<"ingresa el nombre del "<<i+1<<" alumno"<<endl;
	cin.getline(	(*(aptr + i)).nombre,26);
	fflush(stdin);
		cout<<"ingresa la matricula del "<<i+1<<" alumno"<<endl;
	cin>>(*(aptr+i)).matricula;
	fflush(stdin);
	}
	
	for(int j=0;j<2;j++){
		cout<<"alumno: "<<(*(aptr + j)).nombre;
		cout<<endl;
		cout<<"matricula: "<<(*(aptr + j)).matricula;
		cout<<endl;
		cout<<endl;
	}
	return 0;
}