#include <bits/stdc++.h>
using namespace std;

/*
Universidad Autonoma del estado de Aguascalientes 
Ciencias basicas
Ciencias de la computacion 
Optimizacion
Martin Isai Nuñez Villeda
Luis Fernando Gutierrez Marfileño

Algoritmo genetico que encuentra la solucion al problema de las 8 torres en un tablero sin chocar.
*/

struct Individuo {
    vector<int> genes; 
    int fitnes;        
};


int evaluacion(Individuo &ind) {
    int fitnes = 28;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (ind.genes[i] == ind.genes[j] || abs(ind.genes[i] - ind.genes[j]) == abs(i - j)) {
                fitnes--;
            }
        }
    }
    return fitnes;
}


vector<Individuo> crear_poblacion(int poblacion_N) {
    vector<Individuo> poblacion(poblacion_N);
    for (int i = 0; i < poblacion_N; i++) {
        Individuo ind;
        ind.genes.resize(8);
        vector<int> columnas = {0, 1, 2, 3, 4, 5, 6, 7};
        random_shuffle(columnas.begin(), columnas.end()); 
        ind.genes = columnas;
        ind.fitnes = evaluacion(ind);
        poblacion[i] = ind;
    }
    return poblacion;
}


Individuo torneo(vector<Individuo> &poblacion) {
    int k = 5;
    Individuo mejor = poblacion[rand() % poblacion.size()];
    for (int i = 1; i < k; i++) {
        Individuo candidato = poblacion[rand() % poblacion.size()];
        if (candidato.fitnes > mejor.fitnes) {
            mejor = candidato;
        }
    }
    return mejor;
}


Individuo cruzamiento(Individuo &padre1, Individuo &padre2) {
    Individuo hijo;
    hijo.genes.resize(8);
    for (int i = 0; i < 4; i++) {
        hijo.genes[i] = padre1.genes[i];
    }
    for (int i = 4; i < 8; i++) {
        hijo.genes[i] = padre2.genes[i];
    }
    hijo.fitnes = evaluacion(hijo);
    return hijo;
}


void mutacion(Individuo &ind) {
    int pos1 = rand() % 8;
    int pos2 = rand() % 8;
    swap(ind.genes[pos1], ind.genes[pos2]);
    ind.fitnes = evaluacion(ind);
}

int main() {
    srand(time(0));
    int opcion;
    do {
        int poblacion_N = 50; 
        int generaciones = 10;
        int n_hijos = 10;

        vector<Individuo> poblacion = crear_poblacion(poblacion_N);

        cout << "primera poblacion: " << endl;
        cout << "cromosoma: ";
        for (int gen : poblacion[0].genes) {
            cout << gen << " ";
        }
        cout << " | fitnes: " << poblacion[0].fitnes << endl;

        for (int gen = 0; gen < generaciones; gen++) {
            vector<Individuo> nueva_poblacion;

            for (int i = 0; i < n_hijos; i++) {
                Individuo padre1 = torneo(poblacion);
                Individuo padre2 = torneo(poblacion);
                Individuo hijo = cruzamiento(padre1, padre2);
                nueva_poblacion.push_back(hijo);
            }
            
            int indice_mutado = rand() % nueva_poblacion.size();
            mutacion(nueva_poblacion[indice_mutado]);
            poblacion = nueva_poblacion;
        }
        cout << "ultima poblacion: " << endl;
        cout << "cromosoma: ";
        for (int gen : poblacion[0].genes) {
            cout << gen << " ";
        }
        cout <<" | Fitness: " << poblacion[0].fitnes << endl;
        cout <<"\n re ejecutar (1:Si, 0:No): ";
        cin >> opcion;
    } while (opcion == 1);
    cout << "programa finalizado" << endl;
    return 0;
}