#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Examen 3er Parcial
9 de Diciembre de 2024 

Martin Isai NUñez Villeda 

Crea un programa el cual dado un grafo, mediante el algoritmo de Krushkal
se cree el arbol de expansion minima 

Matriz de Adyacencia 


  A B C D E
A 0 3 1 0 0
B 3 0 7 5 1
C 1 7 0 2 0
D 0 5 2 0 7
E 0 1 0 7 0

*/



struct Arista {
    int origen, destino, peso;
};

struct Grafo {
    int V, E; // Número de vértices y aristas
    vector<Arista> aristas; // Lista de aristas
};


int encontrar(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return encontrar(parent, parent[i]);
}


void unir(int parent[], int rank[], int x, int y) {
    int xroot = encontrar(parent, x);
    int yroot = encontrar(parent, y);
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > yroot)
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}


void kruskal(Grafo& grafo) {
    vector<Arista> resultado; 
    int e = 0; // Contador de aristas
    int i = 0; // Índice para recorrer las aristas
    sort(grafo.aristas.begin(), grafo.aristas.end(), [](Arista a, Arista b) {
        return a.peso < b.peso;
    });

    int* parent = new int[grafo.V];
    int* rank = new int[grafo.V];

    for (int v = 0; v < grafo.V; ++v) {
        parent[v] = v;
        rank[v] = 0;
    }

    while (e < grafo.V - 1 && i < grafo.E) {
        Arista siguiente_arista = grafo.aristas[i++];
        int x = encontrar(parent, siguiente_arista.origen);
        int y = encontrar(parent, siguiente_arista.destino);

        if (x != y) {
            resultado.push_back(siguiente_arista);
            unir(parent, rank, x, y);
            e++;
        }
    }

    cout << "Arbol de Expansion Minima = {";
    for (auto& arista : resultado) {
        char origen = 'A' + arista.origen;
        char destino = 'A' + arista.destino;
        cout << "(" << origen << " -- " << destino << " == " << arista.peso << ") ";
    }
    cout << "}" << endl;

    delete[] parent;
    delete[] rank;
}

int main() {
    cout << "Este programa utiliza el algoritmo de Kruskal para encontrar el arbol de expansion minima de un grafo dado." << endl;
    cout << "La matriz de adyacencias del Grafo 1 es:" << endl;

    int matriz_adyacencia[5][5] = {
        {0, 3, 1, 0, 0},
        {3, 0, 7, 5, 1},
        {1, 7, 0, 2, 0},
        {0, 5, 2, 0, 7},
        {0, 1, 0, 7, 0}
    };

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << matriz_adyacencia[i][j] << " ";
        }
        cout << endl;
    }

    Grafo grafo;
    grafo.V = 5;
    grafo.E = 7;
    grafo.aristas = {
        {0, 1, 3},
        {0, 2, 1},
        {1, 2, 7},
        {1, 3, 5},
        {1, 4, 1},
        {2, 3, 2},
        {3, 4, 7}
    };

    kruskal(grafo);

    cout << "\nPresiona enter para salir..." << endl;
    cin.get();

    return 0;
}
