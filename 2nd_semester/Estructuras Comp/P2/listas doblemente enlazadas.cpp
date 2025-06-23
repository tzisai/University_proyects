#include <iostream>
using namespace std;

/* 
fecha viernes 29 de marzo de 2024

Elaboro Martin Isai Nuñez Villeda
		Eduardo Lopez Garcia 
		Jesus Yocsan Luevano Flores
	

	Objetivo:
	
	Implementar operaciones de una lista doblemente enlazada o ligada que posea las siguientes cualidades
	
	1)inserción
	2)eliminación
	3)búsqueda
	4)recorrido
	5)revisar si la lista esta vacía
	6)salir
	
*/

struct nodo{
	int datote;
	nodo* siguiente;
	nodo* anterior;
};

void insertar(nodo*& lista,int input){
	//creacion nuevo nodo 
	nodo *nuevo_nodo= new nodo();
	
	//asignacion de valir al nodo
	nuevo_nodo->datote=input;
	
	//enlazamiento de la lista y el nuevo nodo en alguno de los 2 casos
	//lista==NULL o lista!=null
	
	if (lista==nullptr){
		nuevo_nodo->siguiente=nullptr;
		nuevo_nodo->anterior=nullptr;
		lista=nuevo_nodo;
	}
	else{
		nuevo_nodo->siguiente=lista;
		lista->anterior=nuevo_nodo;
		nuevo_nodo->anterior=nullptr;
		lista=nuevo_nodo;
	}
	return;
}

void recorrer(nodo* lista,int act){
	int comp=0;
	if(lista==nullptr){
		cout<<"la lista esta vacia no hay que recorrer";
		return;
	}
	else{
		nodo *recorrer=new nodo();
		recorrer=lista;
		do{
			comp++;
			cout<<recorrer->datote<<"  ";
			if(comp<act){
		recorrer= recorrer->siguiente;	
			}
			else{
				recorrer=recorrer->anterior;
			}
		
		}while(recorrer!=nullptr);
		
	//	cout<<"papas"<<endl; <-cout de control
		
		/*
		   // Restablecer recorrer al último nodo
        while(recorrer->anterior != nullptr){
            recorrer = recorrer->anterior;
        }
          // Recorrido hacia atrás
        while(recorrer != nullptr){
            cout << recorrer->datote << " ";
            recorrer = recorrer->anterior; // Debes avanzar en la dirección opuesta
        }
    
        */
        
        /*
		recorrer=recorrer->anterior;
		cout<<recorrer->datote;
		*/
		
		/*do{
		cout<<recorrer->datote<<"  ";
		recorrer=recorrer->anterior;	
		}while(recorrer!=nullptr);*/
		
    }
		
	system("pause");
	return;
		
	}


void busqueda(nodo* lista){
	int acum=0;
	int busq=0;
	if(lista==nullptr){
		cout<<"la lista esta vacia no hay que buscar"<<endl;
		system("pause");
		return;
	}
	else{
			do{
		 		cout<<"ingrese el dato que desea buscar\n";
		 		cin>>busq;
			 }
			 while(busq<0||busq>100000);
			 
		nodo *buscar = new nodo();
		buscar=lista;
		do{
			acum++;
			if(buscar->datote==busq){
				cout<<"Dato encontrado!!!"<<endl;	
				cout<<"El dato se encuentra en la posicion "<<acum<<" de derecha a izquierda"<<endl;
				system("pause");
				return;
			}
			buscar=buscar->siguiente;
			if(buscar==nullptr){
				cout<<"el dato no se encontro"<<endl;
				system("pause");
			}
		}while(buscar!=nullptr);
	}
}


void eliminacion(nodo*& lista,int& act){
	
	nodo *auxact = new nodo();
	nodo *auxant = new nodo();
	
	int acum=0;
	int busq=0;
	
	if(lista==nullptr){
		cout<<"la lista esta vacia no hay que eliminar"<<endl;
		system("pause");
		return;
	}
	else{
			do{
		 		cout<<"ingrese el dato que desea eliminar\n";
		 		cin>>busq;
			 }
			 while(busq<0||busq>100000);
			 
		nodo *buscar = new nodo();
		buscar=lista;
		do{
			acum++;
			if(buscar->datote==busq){
				act--;
				cout<<"Dato encontrado!!!"<<endl;	
				cout<<"El dato se encuentra en la posicion "<<acum<<" de derecha a izquierda"<<endl;
				
				auxact=buscar->siguiente;
				auxant=buscar->anterior;
				cout<<"papas"<<endl;
				if(buscar->siguiente==nullptr && buscar->anterior!=nullptr){//ULTIMO ELEMENTO
					buscar=auxant;
					buscar->siguiente=nullptr;
					cout<<"papas Ult"<<endl;
				}
				if(buscar->siguiente!=nullptr && buscar->anterior==nullptr){//PRIMER ELEMENTO
					
					lista=buscar->siguiente;
					buscar=auxact;
					buscar->anterior=nullptr;
									cout<<"papas primer"<<endl;
				}
				if(buscar->siguiente!=nullptr && buscar->anterior!=nullptr){//ELEMENTO INTERMEDIO
					
				buscar=auxant;
				buscar->siguiente=auxact;
				
				buscar=auxact;
				buscar->anterior=auxant;
				
				cout<<"papas inter"<<endl;
				}
				
				
				
				cout<<"el Dato se elimino con exito"<<endl;
				system("pause");
				return;
			}
			buscar=buscar->siguiente;
			if(buscar==nullptr){
				cout<<"el dato no se encontro"<<endl;
				system("pause");
			}
		}while(buscar!=nullptr);
			delete buscar; // liberar la memoria del nodo a eliminar
			delete auxact; // liberar la memoria del nodo a eliminar
			delete auxant; // liberar la memoria del nodo a eliminar
        	system("Pause");
	}
	
	
	return;
}

void ordenarBurbuja(nodo*& lista) {
  if (lista == nullptr || lista->siguiente == nullptr) {
    return; // Lista vacía o con un solo elemento
  }

  bool swapped = true;
  nodo* actual = lista;
  nodo* anterior = nullptr;

  while (swapped) {
    swapped = false;

    while (actual->siguiente != nullptr) {
    	
      if (actual->datote > actual->siguiente->datote) {
        // Intercambiar nodos
        
        if (anterior == nullptr) {
          lista = actual->siguiente;
        } 
		else {
          anterior->siguiente = actual->siguiente;
        }
        actual->siguiente->anterior = anterior;
        anterior = actual;
        nodo* temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        temp->siguiente = actual;
        actual = temp;
        swapped = true;
      } 
	  else {
        anterior = actual;
        actual = actual->siguiente;
      }
    }

    // Reiniciar el recorrido desde el principio de la lista
    anterior = nullptr;
    actual = lista;
  }
}

int main (){
	

	
		//variables de control
	int key=1;
	int chosse;
	int cant=0;
	//crear lista vacia 
	int input;
	nodo *lista;
	lista=NULL; //<- pq esta vacia a wea.
	
	do{
	//	ordenarBurbuja(lista); <- nos rompio el codigo y no se pq 
	//	ordenacion(lista);
		system("cls");
	cout<<"\t operaciones de listas doblemente enlazadas"<<endl;
	cout<<"Elija opcion oportunamente"<<endl;
	cout<<"Insertar Nodo(1)"<<endl;
	cout<<"Recorrer//Imprimir nodos(2)"<<endl;
	cout<<"Busqueda de Nodo(3)"<<endl;
	cout<<"Eliminar Nodo(4)"<<endl;
	cout<<"Comprobacion de vacio(5)"<<endl;
	cout<<"Salir(6)"<<endl;
	cout<<""<<endl;
	
	cin>>chosse;
	
	switch(chosse){
		case 1:{
				int n;
			 	cout<<"cuantos datos desea ingresar?";
			 	cin>>n;
			 	cant+=n;
			 	
				for(int i=0;i<n;i++){
					cout<<"dame un valor entero para el nodo\n";
					cin>>input;
					insertar(lista,input);
					}
					
			break;
		}
		case 2:{
			recorrer(lista,cant);	
			break;
		}
		case 3:{
			busqueda(lista);
		break;
		}
		case 4:{
				eliminacion(lista,cant);
			break;
		}
		case 5:{
				if(lista==nullptr){
					cout<<"la lista esta vacia"<<endl;
					system("pause");
				}
				else{
					cout<<"la lista no esta vacia"<<endl;
					system("pause");
				}
			break;
		}
		case 6:{
			key=0;
			break;
		}
	}
		
	}while(key==1);
	
	
	
	
	
	
	
	
	return 0;
}