/*
Examen 3er Parcial
9 de Diciembre de 2024 

Martin Isai NUñez Villeda 
Este programa utiliza el algoritmo de recorrido en anchura (BFS) para explorar un grafo dirigido. 
Primero, muestra la matriz de adyacencias del grafo, luego genera y despliega el árbol abarcador del grafo,
 y finalmente muestra el recorrido en anchura (BFS) del grafo.
A	B	C	D	E
0 	1 	0 	1 	0   	A
0 	0 	1 	1 	0   	B
0 	0 	0 	0 	1   	C
0 	0 	0 	0 	1   	D
0 	0 	0 	0 	0	 	E

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<int>>& adj, int inicio) {
    vector<bool> visitado(adj.size(), false);
    queue<int> cola;

    visitado[inicio] = true;
    cola.push(inicio);

    cout << "Recorrido en anchura: ";
    while (!cola.empty()) {
        int nodo = cola.front();
        cout << char(nodo + 'A') << " ";
        cola.pop();

        for (int i = 0; i < adj[nodo].size(); ++i) {
            if (adj[nodo][i] && !visitado[i]) {
                visitado[i] = true;
                cola.push(i);
            }
        }
    }
    cout << endl;
}

int main() {

    vector<vector<int>> adj = {
        {0, 1, 0, 1, 0},  // A
        {0, 0, 1, 1, 0},  // B
        {0, 0, 0, 0, 1},  // C
        {0, 0, 0, 0, 1},  // D
        {0, 0, 0, 0, 0}   // E
    };

    cout << "Este programa utiliza el algoritmo de recorrido en anchura para explorar un grafo dirigido." << endl;
    cout << "La matriz de adyacencias del Grafo 1 es:" << endl;

    for (int i = 0; i < adj.size(); ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }


    BFS(adj, 0);

    cout << "\nPresiona cualquier tecla para salir..." << endl;
    cin.get();

    return 0;
}
