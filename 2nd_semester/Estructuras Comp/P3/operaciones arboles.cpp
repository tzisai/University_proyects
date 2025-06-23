#include <iostream>
#include <cstdlib>

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"


/*
Martin Isai Nuñez Villeda
Eduardo Isai Lopez Garcia
Jesus Yocsan Luevano Flores
2do semestre Ingenieria en Computacion Inteligente
8 de junio de 2024 
Objetivo:Relizar un programa que cree arboles binarios y haga sus operaciones basicas.
 */

using namespace std;

struct arbol{
    int dato;
    arbol* izquierda;
    arbol* derecha;
};

arbol* raiz = nullptr;

void recorrido(arbol* arbolaux, int cont) {
    if (arbolaux == nullptr) {
        cout << "El arbol esta vacio no hay que mostrar" << endl;
        return;
    }
    
    if (arbolaux->derecha != nullptr) {
        recorrido(arbolaux->derecha, cont + 1);
    }
    
    for (int i = 0; i < cont; i++) {
        cout << "\t";
    }
    cout << arbolaux->dato << endl;
    
    if (arbolaux->izquierda != nullptr) {
        recorrido(arbolaux->izquierda, cont + 1);
    }
    
}

void busqueda(int input, arbol* arbolaux) {
    arbol* arbolreco = arbolaux;

    if (arbolreco == nullptr) {
        cout << "El arbol esta vacio no hay que buscar" << endl;
        return;
    }

    while (arbolreco != nullptr) {
        if (input == arbolreco->dato) {
            cout << ANSI_COLOR_GREEN << arbolreco->dato << ANSI_COLOR_RESET << "\t";
            system("pause");
            return;
        }
        cout << arbolreco->dato << "\t";
        if (input >= arbolreco->dato) {
            arbolreco = arbolreco->derecha;
        } else {
            arbolreco = arbolreco->izquierda;
        }
    }
    cout << "No se encontró el valor en el árbol." << endl;
}

void insercion(int input, arbol*& arbolaux) {
    arbol* nueva_hoja = new arbol;
    nueva_hoja->dato = input;
    nueva_hoja->izquierda = nullptr;
    nueva_hoja->derecha = nullptr;

    if (arbolaux == nullptr) {
        arbolaux = nueva_hoja;
    } else {
        arbol* arbolcopia = arbolaux;
        arbol* padre = nullptr;

        while (arbolcopia != nullptr) {
            padre = arbolcopia;
            if (input >= arbolcopia->dato) {
                arbolcopia = arbolcopia->derecha;
            } else {
                arbolcopia = arbolcopia->izquierda;
            }
        }

        if (input >= padre->dato) {
            padre->derecha = nueva_hoja;
        } else {
            padre->izquierda = nueva_hoja;
        }
    }
}

arbol* encontrarMinimo(arbol* nodo) {
    while (nodo->izquierda != nullptr) {
        nodo = nodo->izquierda;
    }
    return nodo;
}

void eliminarNodo(arbol*& nodo, int dato) {
    if (nodo == nullptr) {
        return;
    }

    if (dato < nodo->dato) {
        eliminarNodo(nodo->izquierda, dato);
    } else if (dato > nodo->dato) {
        eliminarNodo(nodo->derecha, dato);
    } else {
        if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
            delete nodo;
            nodo = nullptr;
        } else if (nodo->izquierda == nullptr) {
            arbol* temp = nodo;
            nodo = nodo->derecha;
            delete temp;
        } else if (nodo->derecha == nullptr) {
            arbol* temp = nodo;
            nodo = nodo->izquierda;
            delete temp;
        } else {
            arbol* temp = encontrarMinimo(nodo->derecha);
            nodo->dato = temp->dato;
            eliminarNodo(nodo->derecha, temp->dato);
        }
    }
}

int main() {
    int elec = 0;
    int conta = 0;
    int value = 0;
	int n = 0;
    do {
    	system("cls");
        cout << "ARBOLES BINARIOS" << endl;
        cout << "(1) Recorrido" << endl;
        cout << "(2) Insercion" << endl;
        cout << "(3) Eliminacion" << endl;
        cout << "(4) Busqueda" << endl;
        cout << "(5) Salir" << endl;
        cin >> elec;

        switch (elec) {
            case 1: {
                recorrido(raiz, conta);
                system("pause");
                break;
            }
            case 2: {
            	cout<<"Cuantos datos desea insertar?"<<endl;
            	cin>>n;
            	for(int i =0;i<n;i++){
            	cout << "Que dato deseas insertar?" << endl;
                cin >> value;
                insercion(value, raiz);	
				}
                break;
            }
            case 3: {
                cout << "Que dato deseas eliminar?" << endl;
                cin >> value;
                eliminarNodo(raiz, value);
                break;
            }
            case 4: {
                cout << "Que dato deseas buscar?" << endl;
                cin >> value;
                busqueda(value, raiz);
                break;
            }
            case 5: {
                cout << "Saliendo..." << endl;
                break;
            }
            default: {
                cout << "Ingrese una opcion valida" << endl;
                break;
            }
        }

    } while (elec != 5);

    return 0;
}
