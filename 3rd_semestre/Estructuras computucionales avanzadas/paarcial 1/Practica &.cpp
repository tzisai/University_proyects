#include <iostream>
using namespace std;


/*

a. Universidad Autonoma delEstado de Aguascalientes
b. Ingenieria en Computacion Inteligente
c. Estructuras Computacionales Avanzadas
d. Martin Isai Nuñez VIlleda	Alan Fernando Martinez Moreno	Alan Torres
e. Luis Fernando Gutierrez Marfileño
f. Dado el tamano del grafo y generada la matriz de adyacencia se detertmina si el grado es un bosque o no.

*/


void Crear_Matriz(int grafo[][10], int i, int j, int input) {
    grafo[i][j] = input;
    grafo[j][i] = input; 
}

int main() {
    int MAX, cont = 0, cond, ciclo = 0;
    do {
        cout << "Ingresa el numero de nodos del grafo (Maximo 10): ";
        cin >> MAX;
        if (MAX <= 0 || MAX > 10) {
            cout << "Valor invalido. El valor debe ser maximo de 10 y no menor a 1.\n";
            cond = 1;
        } else {
            cond = 0;
        }
    } while (cond == 1);

    int input, grafo_dado[10][10] = {};
    for (int i = 0; i < MAX; i++) {
        for (int j = i; j < MAX; j++) {
            cout << "Asignacion matriz de adyacencia del nodo " << i + 1 << " hacia el nodo " << j + 1 << ":\n";
            cout << "Ingresa '1' si existe una conexion en la matriz de adyacencia, en caso contrario '0': ";
            cin >> input;
            if (input == 1) cont++;
            if (i == j && input == 1) ciclo = 1;
            Crear_Matriz(grafo_dado, i, j, input);
            cout << "¿Existen mas aristas? - si (1) no (0): ";
            cin >> cond;
            if (cond == 0) break;
        }
        if (cond == 0) break;
    }

    if (ciclo == 1 || cont > MAX - 1) cout << "El grafo no es un arbol.\n";
    else cout << "El grafo es un arbol.\n";

    return 0;
}
