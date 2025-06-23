//Martin Isai Nuñez Villeda 
//Objetivo Hacer un programa que cuente el nuemro de silabas en una palabra
//(usando apuntadores)
//4 de marzo de 2024


#include <iostream>
#include <string.h>
using namespace std;

int main(){
	
	int cont=0;
	char *apunt;
	char palabra[27];
	cout<<"ingrese una palabra cualesquiera:";
	cin>>palabra;
	apunt=palabra;
	int i=0;
		
	do{
		char letra = tolower(*(apunt + i));
		switch (letra){
		
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				cont++;
		}
		i++;
	}while(*(apunt+i)!='\0');
	cout<<"La palabra ingresada tiene: "<<cont;
	
}