#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string proposicion;

    // Leer la proposición lógica
    cout << "Ingrese la proposición lógica: ";
    getline(cin, proposicion);

    // Eliminar espacios en blanco
    proposicion.erase(remove_if(proposicion.begin(), proposicion.end(), ::isspace), proposicion.end());

    // Contar el número de letras únicas
    int numLetrasUnicas = 0;
    vector<char> letrasUnicas;

    for (char c : proposicion) {
        if (isalpha(c) && find(letrasUnicas.begin(), letrasUnicas.end(), c) == letrasUnicas.end()) {
            letrasUnicas.push_back(c);
            numLetrasUnicas++;
        }
    }

    // Crear la matriz de la tabla de verdad
    vector<vector<int>> tablaVerdad;

    for (int i = 0; i < (1 << numLetrasUnicas); ++i) {
        vector<int> fila;

        for (int j = 0; j < numLetrasUnicas; ++j) {
            fila.push_back((i & (1 << (numLetrasUnicas - 1 - j))) ? 1 : 0);
        }

        tablaVerdad.push_back(fila);
    }

    // Imprimir la matriz de la tabla de verdad
    cout << "\nTabla de verdad:\n";
    for (const auto& fila : tablaVerdad) {
        for (int valor : fila) {
            cout << valor << " ";
        }
        cout << endl;
    }

    return 0;
}
