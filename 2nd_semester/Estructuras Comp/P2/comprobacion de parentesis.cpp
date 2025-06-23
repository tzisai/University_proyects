#include<iostream>
#include<string.h>

using namespace std;

void push(char pila[],int &top){
	
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

int main(){


string opr;
int top =-1;

cout<<"ingresa la operacion"<<endl;
cin>>opr; fflush(stdin);

char pila [(sizeof(opr)/2)];

for(int i=0;i<sizeof(opr);i++){
	if(opr[i]=='(' ){
		push(opr,top);
	}
	if(opr[i]==')' ){
		pop(top);
	}
}
	
}

