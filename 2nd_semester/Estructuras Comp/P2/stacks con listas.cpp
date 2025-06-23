/* 
Martin Isai Nuñez Villeda
4 de abril de 2024
Objetivo:Crear un programa que contenga un menu con las operaciones basicas de las pilas
(stacks) en base a listas enlazadas.
*/

#include <iostream>
struct nodo{
	int dato;
	nodo *siguiente;
};

using namespace std;
void push(nodo *& stack,int &top,int input){
	
	/*if(top==4){
		cout<<"PILA LLENA NO PUEDES INGRESAR NADA"<<endl;
		system("pause");
		return;
	} */
	nodo *nuevo_nodo = new nodo(); 
	
	if(nuevo_nodo!=NULL){//checar si el nodo esta vacio
	//3)asignar a un nodo un valor
	nuevo_nodo->dato=input;
	//4)enlazar las lista
	nuevo_nodo->siguiente=stack;
	//5)lista apunta a la cabecera
	stack=nuevo_nodo;
	}
	else{
		cout<<"no hay espacio suficiente";
		system("pause");
	}
	
	top++;
 	return;
}

void pop(nodo *& stack,int& top){
	
	nodo *elim = new nodo();
	nodo *elimaux = new nodo();
	elim=stack;
	elimaux=nullptr;
	
	system("cls");
	if(top==-1){
	cout<<"la lista esta vacia no hay que eliminar"<<endl;
	system("pause");
		return;
	}
	for(int i=0;i<=top;i++){
	if(i==top){
		elimaux->siguiente=nullptr;
	}
	elimaux=elim;
	elim=elim->siguiente;
	}
	delete elim;
	delete elimaux;
	cout<<"dato eliminado con exito!!"<<endl;
	system("pause");
	top--;
}

void print(nodo* stack,int top){
	
	int num=0;
	
	if(top==-1){
	cout<<"la lista esta vacia no hay que mostrar"<<endl;
	system("pause");
		return;
	}
	nodo *print= new nodo();
	print=stack;
	while(print!=nullptr){
		cout<<print->dato<<"\t";
		print=print->siguiente;
		num++;	
	};
	
	cout<<endl;
	cout<<"La lista tiene "<<num<<" elementos"<<endl;
	system("pause");
}


int main(){

	nodo *stack;



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
			int cant=0;
			int n=0;
			
				system("cls");
				cout<<"cuantos datos deseas ingresar?"<<endl;
				cin>>cant;
				
					for(int i=0;i<cant;i++){
				//system("cls");
				cout<<"Escriba el "<<(i+1)<<" dato a ingresar"<<endl;
				cin>>n;
				push(stack,top,n);
		
				cout<<"dato ingresado con exito!!"<<endl;	
			}
			system("pause");
			break;
		}
		case 2:{
			pop(stack,top);
			break;
		}
		case 3:{
			print(stack,top);
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