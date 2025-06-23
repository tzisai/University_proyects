#include <stdio.h>
#include <limits.h> 
#define N 8 //esta madre es el tamaño del grafo


int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < N; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}


void printSolution(int dist[], int parent[]) {
    printf("Nodo\tDistancia desde A\tCamino\n");
    for (int i = 0; i < N; i++) {
        if (i == 7) { // Nodo H
            printf("H\t%d\t\t\t", dist[i]);
            int j = i;
            while (parent[j] != -1) {
                printf("%c <- ", 'A' + j);
                j = parent[j];
            }
            printf("A\n");
        }
    }
}


void dijkstra(int graph[N][N], int src) {
    int dist[N]; 
    int sptSet[N]; 
    int parent[N]; 

    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX; 
        sptSet[i] = 0;
        parent[i] = -1; 
    }
    dist[src] = 0; 

    for (int count = 0; count < N - 1; count++) {
        int u = minDistance(dist, sptSet); 
        sptSet[u] = 1; 

        for (int v = 0; v < N; v++) {
            // Actualiza la distancia si hay un camino más corto
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Guarda el nodo predecesor
            }
        }
    }
    printSolution(dist, parent); // Imprime la distancia y el camino al nodo H
}

int main() {
    int graph[N][N] = {
        {0, 2, 4, 0, 0, 0, 0, 0},
        {2, 0, 1, 7, 0, 0, 0, 0},
        {4, 1, 0, 3, 5, 0, 0, 0},
        {0, 7, 3, 0, 4, 0, 0, 0},
        {0, 0, 5, 4, 0, 2, 0, 3},
        {0, 0, 0, 0, 2, 0, 1, 6},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 3, 6, 1, 0}
    };
    int choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Calcular la distancia más corta entre A y H\n");
        printf("2. Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                dijkstra(graph, 0); 
                break;
            case 2:
                printf("Saliendo\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (choice != 2);
    return 0;
}
