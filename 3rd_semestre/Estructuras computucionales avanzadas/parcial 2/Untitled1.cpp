#include <iostream>
using namespace std;

// Definición del nodo del árbol binario
struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;
};

// Función para crear un nuevo nodo
Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    nuevoNodo->izquierdo = nullptr;
    nuevoNodo->derecho = nullptr;
    return nuevoNodo;
}

// Función para insertar un nodo en el árbol binario
Nodo* insertar(Nodo* raiz, int dato) {
    if (raiz == nullptr) {
        return crearNodo(dato);
    }
    if (dato < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, dato);
    } else if (dato > raiz->dato) {
        raiz->derecho = insertar(raiz->derecho, dato);
    }
    return raiz;
}

// Función para buscar un nodo en el árbol binario
bool buscar(Nodo* raiz, int dato) {
    if (raiz == nullptr) {
        return false;
    }
    if (raiz->dato == dato) {
        return true;
    } else if (dato < raiz->dato) {
        return buscar(raiz->izquierdo, dato);
    } else {
        return buscar(raiz->derecho, dato);
    }
}

// Función para encontrar el nodo con el valor mínimo en el árbol (útil para eliminación)
Nodo* minimoValor(Nodo* nodo) {
    Nodo* actual = nodo;
    while (actual && actual->izquierdo != nullptr) {
        actual = actual->izquierdo;
    }
    return actual;
}

// Función para eliminar un nodo en el árbol binario
Nodo* eliminar(Nodo* raiz, int dato) {
    if (raiz == nullptr) {
        return raiz;
    }

    if (dato < raiz->dato) {
        raiz->izquierdo = eliminar(raiz->izquierdo, dato);
    } else if (dato > raiz->dato) {
        raiz->derecho = eliminar(raiz->derecho, dato);
    } else {
        // Caso 1 y 2: Nodo con un hijo o sin hijos
        if (raiz->izquierdo == nullptr) {
            Nodo* temp = raiz->derecho;
            delete raiz;
            return temp;
        } else if (raiz->derecho == nullptr) {
            Nodo* temp = raiz->izquierdo;
            delete raiz;
            return temp;
        }

        // Caso 3: Nodo con dos hijos
        Nodo* temp = minimoValor(raiz->derecho);
        raiz->dato = temp->dato;
        raiz->derecho = eliminar(raiz->derecho, temp->dato);
    }
    return raiz;
}

// Funciones para recorrer el árbol en Preorden, Inorden y Postorden
void recorridoPreorden(Nodo* raiz) {
    if (raiz != nullptr) {
        cout << raiz->dato << " ";
        recorridoPreorden(raiz->izquierdo);
        recorridoPreorden(raiz->derecho);
    }
}

void recorridoInorden(Nodo* raiz) {
    if (raiz != nullptr) {
        recorridoInorden(raiz->izquierdo);
        cout << raiz->dato << " ";
        recorridoInorden(raiz->derecho);
    }
}

void recorridoPostorden(Nodo* raiz) {
    if (raiz != nullptr) {
        recorridoPostorden(raiz->izquierdo);
        recorridoPostorden(raiz->derecho);
        cout << raiz->dato << " ";
    }
}

int main() {
    Nodo* raiz = nullptr;

    // Insertar nodos en el árbol
    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 70);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 80);

    // Recorridos
    cout << "Recorrido en Preorden: ";
    recorridoPreorden(raiz);
    cout << endl;

    cout << "Recorrido en Inorden: ";
    recorridoInorden(raiz);
    cout << endl;

    cout << "Recorrido en Postorden: ";
    recorridoPostorden(raiz);
    cout << endl;

    // Buscar un elemento
    int datoBuscar = 40;
    cout << "Buscar " << datoBuscar << ": " << (buscar(raiz, datoBuscar) ? "Encontrado" : "No encontrado") << endl;

    // Eliminar un nodo
    int datoEliminar = 20;
    cout << "Eliminar " << datoEliminar << endl;
    raiz = eliminar(raiz, datoEliminar);

    cout << "Recorrido en Inorden después de eliminar: ";
    recorridoInorden(raiz);
    cout << endl;

    return 0;
}
