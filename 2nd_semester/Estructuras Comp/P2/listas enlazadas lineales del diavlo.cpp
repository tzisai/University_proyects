#include<iostream>
/* 
Elaboró:Martín Isaí Nuñez Villeda
Objetivo:Crear un progrma que tenga dentro de sus menus las operaciones básicas de ls listas enlazadas lineales
fecha:19 de marzo de 2024
*/
using namespace std;
/*
como implementar lista
 */
 
 struct nodo{
 int datote;
 nodo *siguiente; 	
 };
 
  //procedimiento de declaracion y asignacion de valor a los nodos.
 void declaracion(nodo*& lista,int input){
 	
 	
 	
	nodo *nuevo_nodo = new nodo();
	
	if(nuevo_nodo!=NULL){//checar si el nodo esta vacio
	//3)asignar a un nodo un valor
	nuevo_nodo->datote=input;
	//4)enlazar las lista
	nuevo_nodo->siguiente=lista;
	//5)lista apunta a la cabecera
	lista=nuevo_nodo;
	}
	else{
		cout<<"no hay espacio suficiente";
		system("pause");
	}
	
	
 	return;
 }
 
  //recorrer funcion
 void impresion(nodo* lista){
 
 if(lista==NULL){
 	cout<<"la lista esta vacia, no hay que imprimir\n";
 }
 else{
 	nodo *recorrer = new nodo();
 	
 	recorrer=lista;
 	int acum=1;
			 	do{
			 		cout<<"datote "<<acum<<"es igual a :"<<recorrer->datote;
			 		cout<<endl;
			 		acum++;
			 		recorrer=recorrer->siguiente;
				 }while(recorrer!=NULL);
 	
 		}
		 system("pause");		
 
 	}
 	
 	
 //busqueda de n cosa
 void busqueda(nodo* lista,int cant){
 if(lista==NULL){
 	cout<<"la lista esta vacia, no hay datos que buscar buscar\n";
 }
 else{
 	int datoBus=0;
 	int acum=0;
		 		do{
		 	cout<<"ingrese el dato que desea buscar\n";
		 	cin>>datoBus;
			 }while(datoBus<0||datoBus>100000);
	 
	 nodo *busqueda = new nodo();
	 busqueda=lista;
	 
	 do{
		 	acum++;
		 if(busqueda->datote==datoBus){
		 	cout<<"se ha encontrado el dato!!!\n";
		 	cout<<"en la posicion "<<acum<<" de derecha a izquierda\n";
		 	system("pause");
		 	break;
			 }
			 busqueda=busqueda->siguiente;
			 if(acum>cant){
			 	cout<<"no se a encontrado el dato\n";
			 	system("pause");
			 	break;
			 }
	 	}while(busqueda!=NULL);
	}
 
 }
 
 //eliminacion de nodo
 
void eliminacion(nodo*& lista, int input, int act) {
    nodo* nodo_ant = nullptr;
    nodo* nodo_act = lista;

    if (lista != nullptr) {
        int acum = 0;
        while (nodo_act != nullptr) {
            if (acum > act) {
                cout << "No se encontro el dato a eliminar\n";
                system("Pause");
                break;
            }

            if (nodo_act->datote == input) {
                cout << "Se encontro el dato a eliminar\n";
                if (nodo_ant != nullptr) {
                    nodo_ant->siguiente = nodo_act->siguiente; // ajuste del puntero del nodo anterior
                } else {
                    lista = nodo_act->siguiente; // si el nodo a eliminar es el primero, actualizamos la cabeza de la lista
                }
                delete nodo_act; // liberar la memoria del nodo a eliminar
                system("Pause");
                break;
            }

            nodo_ant = nodo_act;
            nodo_act = nodo_act->siguiente;
            acum++;
        }
    } else {
        cout << "La lista esta vacía, no hay elementos que eliminar\n";
    }
}

int main(){
	//variables de control
	int key=1;
	int chosse;
	int cant=0;
	//crear lista vacia 
	int input;
	nodo *lista;
	lista=NULL; //<- pq esta vacia a wea.
	
	do{
		system("cls");
	cout<<"\t operaciones de listas lineales"<<endl;
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
					declaracion(lista,input);
					}
			break;
		}
		case 2:{
			impresion(lista);	
			break;
		}
		case 3:{
			busqueda(lista,cant);
		break;
		}
		case 4:{
				cout<<"Que elemento desea eliminar? (ingresa el numero a buscar)"<<endl; 	
			 	cin>>input;
				eliminacion(lista,input,cant);
			break;
		}
		case 5:{
				if(lista==NULL){
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
 	
 	//reservar espacio para nuevo nodo
//Metooo I
	//nodo *nuevo_nodo;
	//nuevo_nodo new(nodo);
	
	//o
	
//Metodo II