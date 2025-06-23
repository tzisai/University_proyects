/* 
Martin Isai Nuñez Villeda
4 de abril de 2024
Objetivo:Crear un programa que contenga un menu con las operaciones basicas de las pilas
(stacks) en base a arreglos.
*/

#include <iostream>
using namespace std;
void push(int pila[],int &top){
	
	if(top==4){
		cout<<"PILA LLENA NO PUEDES INGRESAR NADA"<<endl;
		system("pause");
		return;
	}
	int cant=0;
	int n=0;
	do{
		system("cls");
		cout<<"cuantos datos deseas ingresar?"<<endl;
		cin>>cant;
		if(cant>(4-top)){
			cout<<"el numero de valores exede la capacidad de la pila"<<endl;
			system("pause");
		}
	}while(cant>(4-top));
	
	for(int i=1;i<(cant+1);i++){
		//system("cls");
		cout<<"Escriba el "<<(i)<<" dato a ingresar"<<endl;
		cin>>n;
		
		pila[i+top]=n;

		cout<<"dato ingresado con exito!!"<<endl;	
	}
	top+=cant;
	system("pause");
}

void pop(int& top){
	system("cls");
	if(top==-1){
	cout<<"la lista esta vacia no hay que eliminar"<<endl;
	system("pause");
		return;
	}
	top--;
	cout<<"dato eliminado con exito!!"<<endl;
	system("pause");
}

void print(int pila[],int top){
	if(top==-1){
	cout<<"la lista esta vacia no hay que mostrar"<<endl;
	system("pause");
		return;
	}
	int num=0;
	for(int i=0;i<(top+1);i++){
		cout<<pila[i]<<"\t";
		num++;
	}
	cout<<endl;
	cout<<"la lista tiene "<<num<<" elementos"<<endl;
	system("pause");
}


int main(){
	const int max =5;
	int pilota[max];
	int elecc=0;
	int top=-1;
	do{
		system("cls");
	cout<<"menu perron"<<endl;
	cout<<"push(1)"<<endl;
	cout<<"pop(2)"<<endl;
	cout<<"print(3)"<<endl;
	cout<<"Vacio(4)"<<endl;
	cout<<"Salir(5)"<<endl;
	cout<<"seleccione oportunamente"<<endl;
	cin>>elecc;
	
	switch(elecc){
		case 1:{
			push(pilota,top);
			break;
		}
		case 2:{
			pop(top);
			break;
		}
		case 3:{
			print(pilota,top);
			break;
		}
		case 4:{
				if(top==-1){
						cout<<"la lista esta vacia"<<endl;
						system("pause");
							}
				else{
						cout<<"la lista contiene elementos,no esta vacia"<<endl;
						system("pause");	
					}
			break;
		}
	}
	
		
	}while(elecc!=5);
		
	return 0;
}