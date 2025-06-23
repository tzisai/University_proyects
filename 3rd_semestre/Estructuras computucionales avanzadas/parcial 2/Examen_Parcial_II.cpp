/* 
Martin Isai Nuñez VIlleda 
Realizar un codigo que dada la estructura de directorios de unix 
cree un arbol que a medida de que el usuario ingrese la etiquetas seleccionadas 
se cree el arbol correspondiente que se muestra.
Con el iuso de memoria dinamica para el arbol.

Los metodos requeridos son los siguientes 
recorrido de anchura del arbol 
y despliegue de arbol por cada uno de sus niveles en filas descendentes

*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>



using namespace std;



struct Nodo {
    string nombre;
    vector<Nodo*> hijos;

    Nodo(string n) : nombre(n) {}
};

void agregarHijo(Nodo* padre, const string& nombreHijo) {
    Nodo* nuevoHijo = new Nodo(nombreHijo);
    padre->hijos.push_back(nuevoHijo);
}


Nodo* buscarNodo(Nodo* raiz, const string& nombre) {
    if (raiz->nombre == nombre) return raiz;
    for (auto hijo : raiz->hijos) {
        Nodo* result = buscarNodo(hijo, nombre);
        if (result) return result;
    }
    return nullptr;
}


void recorridoEnAnchura(Nodo* raiz) {
    if (raiz == nullptr) return;

    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        int nivelSize = cola.size();
        while (nivelSize--) {
            Nodo* nodo = cola.front();
            cola.pop();
            cout << nodo->nombre << " ";
            for (auto hijo : nodo->hijos) {
                cola.push(hijo);
            }
        }
        std::cout << std::endl;
    }
}

void eliminarArbol(Nodo* nodo) {
    if (nodo == nullptr) return;
    for (auto hijo : nodo->hijos) {
        eliminarArbol(hijo);
    }
    delete nodo;
}

int contarNiveles(Nodo* raiz) {
    if (raiz == nullptr) return 0;

    int niveles = 0;
    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        int nivelSize = cola.size();
        while (nivelSize--) {
            Nodo* nodo = cola.front();
            cola.pop();
            for (auto hijo : nodo->hijos) {
                cola.push(hijo);
            }
        }
        niveles++;
    }
    return niveles;
}

void recomendacion(int nv){
	switch(nv){
		case 1:{
			cout<<"carpetas recomendadas:"<<endl<<"directorios de nivel 1 :dev/ etc/ sbin/ tmp/ Users/ usr/ var/"<<endl;
			break;
		}
		case 2:{
						cout<<"carpetas recomendadas:"<<endl<<"directorios de nivel 1 :dev/ etc/ sbin/ tmp/ Users/ usr/ var/"<<endl;
									cout<<"directorios de nivel 2 : cups/ httpd/ init.d/ postPx/ bmiller/ jmiller/ mysql/ bin/ lib/ local/ log/ spool/ yp/"<<endl;			
			break;
		}
	}
}

int main() {
    
    Nodo* raiz = new Nodo("/");

    int opcion;
    string etiquetaPadre, etiquetaHijo;

	cout<<"Programa hecho por Martin Isai Nuñez Villeda"<<endl;
	cout<<"El programa esta diseñado para que el usuario cree el sistema de directosiros de unix"<<endl;
	cout<<"El progrma cuenta con un pequeño menu hecho en terminal en donde podra seleccionar dentro de 3 funciones desplegar directorio,agregar directorio y salir"<<endl;
	cout<<"La raiz (/) ya esta inicializada de tal manera que no es necesario ingresarla desde un inicio "<<endl;
	cout<<"Cuando se quiera agregar un directorio se le pedira al usuario el nombre de la carpeta padre donde se almacenara el directorio y el nombre del nuevo directorio."<<endl;
	
	system("Pause");	




    while (true) {
    	system("cls");
        cout << "1. Agregar Directorio" << std::endl;
        cout << "2. Mostrar Arbol" << std::endl;
        cout << "3. Salir" << std::endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
            	int cont;
            	cont=contarNiveles(raiz);
            	recomendacion(cont);
                cout << "Ingrese la etiqueta del directorio padre: ";
                cin >> etiquetaPadre;
                cout << "Ingrese la etiqueta del nuevo directorio: ";
                cin >> etiquetaHijo;

                {
                    Nodo* nodoPadre = buscarNodo(raiz, etiquetaPadre);
                    if (nodoPadre) {
                        agregarHijo(nodoPadre, etiquetaHijo);
                        cout <<"Directorio agregado exitosamente." << std::endl;
                    } else {
                        cout<<"Directorio padre no encontrado." << std::endl;
                    }
                    system("pause");
                }
                break;

            case 2:
                cout << "arbol de directorios:" << std::endl;
                recorridoEnAnchura(raiz);
                system("PAUSE");
                break;

            case 3:
                eliminarArbol(raiz);
                cout << "Saliendo..." << std::endl;
                return 0;

            default:
                cout << "Opción no válida." << std::endl;
                system("pause");
                break;
        }
    }
}