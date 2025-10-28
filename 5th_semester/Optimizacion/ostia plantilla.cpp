#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;


const int TAM_POBLACION = 20;    // Tamaño de la población
const int TAM_GENOMA = 10;       // Número de genes por individuo
const int GENERACIONES = 50;     // Número de generaciones
const double TASA_MUTACION = 0.05; // Probabilidad de mutación


struct Individuo {
    vector<int> genoma;  
    double aptitud;      
};

double evaluar(const Individuo &ind) {
    double puntaje = 0.0;
    for (int gen : ind.genoma) puntaje += gen;
    return puntaje;
}


vector<Individuo> inicializar_poblacion() {
    vector<Individuo> poblacion(TAM_POBLACION);
    for (int i = 0; i < TAM_POBLACION; i++) {
        Individuo ind;
        ind.genoma.resize(TAM_GENOMA);
        for (int j = 0; j < TAM_GENOMA; j++) {
            ind.genoma[j] = rand() % 2; 
        }
        ind.aptitud = evaluar(ind);
        poblacion[i] = ind;
    }
    return poblacion;
}


Individuo seleccion_torneo(const vector<Individuo> &poblacion) {
    int i1 = rand() % TAM_POBLACION;
    int i2 = rand() % TAM_POBLACION;
    return (poblacion[i1].aptitud > poblacion[i2].aptitud) ? poblacion[i1] : poblacion[i2];
}


pair<Individuo, Individuo> cruce(const Individuo &p1, const Individuo &p2) {
    int punto = rand() % TAM_GENOMA;
    Individuo h1, h2;
    h1.genoma.resize(TAM_GENOMA);
    h2.genoma.resize(TAM_GENOMA);

    for (int i = 0; i < TAM_GENOMA; i++) {
        if (i < punto) {
            h1.genoma[i] = p1.genoma[i];
            h2.genoma[i] = p2.genoma[i];
        } else {
            h1.genoma[i] = p2.genoma[i];
            h2.genoma[i] = p1.genoma[i];
        }
    }
    return {h1, h2};
}


void mutar(Individuo &ind) {
    for (int i = 0; i < TAM_GENOMA; i++) {
        if ((double)rand() / RAND_MAX < TASA_MUTACION) {
            ind.genoma[i] = 1 - ind.genoma[i]; // cambiar 0 ↔ 1
        }
    }
}


void algoritmo_genetico() {
    vector<Individuo> poblacion = inicializar_poblacion();

    for (int gen = 0; gen < GENERACIONES; gen++) {
        vector<Individuo> nueva_poblacion;

        // Crear nueva generación
        while ((int)nueva_poblacion.size() < TAM_POBLACION) {
            Individuo padre1 = seleccion_torneo(poblacion);
            Individuo padre2 = seleccion_torneo(poblacion);

            auto [hijo1, hijo2] = cruce(padre1, padre2);

            mutar(hijo1);
            mutar(hijo2);

            hijo1.aptitud = evaluar(hijo1);
            hijo2.aptitud = evaluar(hijo2);

            nueva_poblacion.push_back(hijo1);
            if ((int)nueva_poblacion.size() < TAM_POBLACION)
                nueva_poblacion.push_back(hijo2);
        }

        poblacion = nueva_poblacion;

        // Mejor individuo de la generación
        auto mejor = *max_element(poblacion.begin(), poblacion.end(),
                                 [](const Individuo &a, const Individuo &b) {
                                     return a.aptitud < b.aptitud;
                                 });

        cout << "Generacion " << gen
             << " -> Mejor aptitud: " << mejor.aptitud << endl;
    }
}


int main() {
    srand(time(0));
    algoritmo_genetico();
    return 0;
}
