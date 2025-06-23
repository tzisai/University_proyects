#include <iostream>
#define TAM 10

using namespace std;

struct queque{
	int dato;
	queque* siguiente;
};


void insertar(queque*& cola,int& frente,int& final,int tam){
	if(final==TAM){
		cout<<"no hay espacio ";
	}
	else{
		int input=0;
		cout<<"INGRESE EL DATO A INGRESAR:";
		cin>>input;
		fflush(stdin);
		queque *nuevonodo = new queque;
		nuevonodo->dato=input;
		nuevonodo->siguiente=cola;
		cola=nuevonodo;
		final++;
	}
	
}

void eliminar(queque*&,int& frente,int& final,int tam){
	
}


int main(){
	
	int chosse=0;
	
 	queque *cola1;
 	cola1=nullptr;	
 	
 	int frente=-1;
 	int final=-1;
 	int Ndatos=0;
 	int TAMres=TAM;


 	
 	do{
 		
 	cout<<"ElIJA OPORTUNAMENTE"<<endl;
 	cout<<"QUEQUE(1)"<<endl;
 	cout<<"UNQUEQUE(2)"<<endl;
 	cout<<"Salir(0)"<<endl;
 
 	cin>>chosse;

 	switch (chosse){
 		case 1:{
 			
 			do{
				system("cls");
				 		
				cout<<"Cuantos datos deseas ingresar?"<<endl;
				cin>>Ndatos;
			 	
			 	if(Ndatos>=TAMres){
			 		cout<<"se exede la capacidad de la queque"<<endl;
			 		system("pause");
				 	}
			else if(Ndatos<TAMres&&cola1!=nullptr){
				 	frente++;
				 	for(int i=0;i<Ndatos){
				 		insertar(cola1,frente,final,TAM);
					 }
					else{
					 for(int i=0;i<Ndatos){
				 	insertar(cola1,frente,final,TAM);
										 }	
						}
					 
				 }

	 }while(Ndatos>=TAM);
 			
			break;
		 }
		 case 2:{
		 	
			break;
		 }
		
	 }
	 	
 }while(chosee!=0)
 	
 	
 	

	
	
	
	
	return 0;
}