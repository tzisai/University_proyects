#include <iostream>
#include <vector>



/* 
Martin Isai Nuñez Villeda
crea un algoritmo que mediante el algoritmo de Warshall recrea la construcción de trayectorias entre los nodos del grafo.
*/

using namespace std;

void imprimirMatriz(const std::vector<std::vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int val : fila) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void algoritmoWarshall(std::vector<std::vector<int>>& matriz) {
    int N = matriz.size();
    for (int k = 0; k < N; ++k) {
        cout << "Matriz después de considerar el nodo " << k << ":\n";
        imprimirMatriz(matriz);
        cout << std::endl;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                matriz[i][j] = matriz[i][j] || (matriz[i][k] && matriz[k][j]);
            }
        }
    }
}

int main() {

    vector<std::vector<int>> M_inic = {
        {0, 1, 0, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };


    cout << "Este programa utiliza el algoritmo de Warshall para encontrar las rutas de conexion\n"
              << "entre los nodos de un grafo dirigido representado por una matriz de adyacencia.\n"
              << "Desplegara cada una de las matrices booleanas generadas durante el proceso.\n" << std::endl;


    cout << "Matriz de Adyacencia inicial:\n";
    imprimirMatriz(M_inic);
    cout << std::endl;


    algoritmoWarshall(M_inic);


    cout << "Matriz de Cierre Transitivo Final:\n";
    imprimirMatriz(M_inic);

    cout << "\nLa última matriz (Cierre Transitivo) muestra si existe una ruta entre cualquier par de nodos.\n"
              << "Un valor de 1 en la posición (i, j) indica que hay una ruta del nodo i al nodo j.\n";

    return 0;
}
