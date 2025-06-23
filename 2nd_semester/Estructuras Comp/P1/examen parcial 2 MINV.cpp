#include <iostream>
#include <cstdlib>

/* 

Martin Isai Nuñez Villeda ICI 
2do semestre 9 de abrril de 2024
examen practico 2: Vagones.

*/

using namespace std;


void imprimir(int pila[],int top){
	
	if(top==-1){
		cout<<"La lista esta vacia no hay vagones"<<endl;
		system("pause");
		return ;
	}
	
	for(int i =0;i<=top;i++){
		cout<< " | "<<pila[i]<<"|"<<"\t";
	}
	cout<<endl;
	for(int i =0;i<=top;i++){
	cout<< " 0 "<<"___"<<"0"<<"\t";
	}
	cout<<endl;
	if(top==14){
		cout<<"El trenecito esta lleno"<<endl;
	}
	else{
		cout<<"El tren aun tiene capacidad le quedan "<<(14-top)<<" vagones disponibles"<<endl;
	}
	system("pause");
}

void push(int pila[],int &top){
	
	
	
	if((top+5)>15){
		cout<<"no se pudieron ingresar los 5 vagones"<<endl;
		system("pause");
		return ;
	}
	else{
		
		
		for(int i=1;i<6;i++){
		
		pila[top+i]= rand() % 99 + 10-1 ;
		
		}
		
		
		cout<<endl;
		
		top+=5;
	}
	imprimir(pila,top);
}

void pop(int pila[],int &top){
	if(top==-1){
	cout<<"no hay vagones que eliminar"<<endl;
	system("pause");
		return;
	}
	
	cout<<"se ha eliminado un vagon!!"<<endl;
	system("pause");
	top--;
	imprimir(pila,top);
	system("cls");
	
}






int main(){
	int pila [15];
	int elec;
	int	top=-1;
	
	do{
		system("cls");
		
		cout<<"Elija oportunamente"<<endl;
		cout<<"ingresar vagones (1)"<<endl;
		cout<<"eliminar vagones(2)"<<endl;
		cout<<"salir(3)"<<endl;

		cin>>elec;
		
		
		switch(elec){
			case 1:{
				push(pila,top);
				break;
			}
			
			case 2:{
				pop(pila,top);
				break;
			}
			
			case 3:{
				imprimir(pila,top);
				break;
			}
		}
		
		
		
		
		
		
	}while(elec!=3);
	

	return 0;
}