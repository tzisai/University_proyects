#include <iostream>


struct nodo{
	int dato;
	nodo* derecha;
	nodo* izquierda;
}
nodo* raiz=nullptr;
void insertar_nodo(int input,nodo* nodon){
	
	 nodo *nuevo_nodo = new nodo();
	
	 nuevo_nodo->dato=input;
	 nuevo_nodo->izquierda=nullptr;
	 nuevo_nodo->derecha=nullptr;
	
	if (nodon==nullptr){
nodon= nuevo_nodo;
	}
	else{
		
	}
	
}


int main(){
	
	
	
	
	return 0;
}