//elaboro Martin Isai Nuñez Villeda
//Objetivo modficar el programa de structs anterior para ahora agregar contadores de ciertas caracteristicas como club, genero o categoria
//ademas de el uso de vectores en el struct 

#include<iostream>
#include<string>

using namespace std;

struct Corredor {
    string nombre;
    string club;
    string categoria;
    string genero;
    int edad;
};

struct Contadores {
    int nh = 0;
    int nm = 0;
    int nC = 0;
    int nporC[6] = {0}; 
    int NporClub[6] = {0}; 
};

int main() {
    int totalCorredores = 0;
    Corredor corredores[6];
    Contadores contadores;

    for (int i = 0; i < 6; i++) {
        cout << "Ingrese el nombre del aspirante " << i + 1 << ": ";
        getline(cin, corredores[i].nombre);

        cout << "Ingrese el club de procedencia: ";
        getline(cin, corredores[i].club);

        // Incrementar el contador de corredores para el club actual
        for (int j = 0; j <= i; j++) {
            if (corredores[i].club == corredores[j].club) {
                contadores.NporClub[i]++;
            }
        }

        // Verificar si es un nuevo club
        bool nuevoClub = true;
        for (int j = 0; j < i; j++) {
            if (corredores[i].club == corredores[j].club) {
                nuevoClub = false;
                break;
            }
        }
        if (nuevoClub) {
            contadores.nC++; // Incrementar contador de clubes únicos
        }

        cout << "Ingrese su edad: ";
        cin >> corredores[i].edad;

        // Limpia el búfer después de la entrada de edad
        cin.ignore();

        // Determinar categoría
        if (corredores[i].edad > 40) {
            corredores[i].categoria = "Veterano";
            contadores.nporC[0]++;
        } else if (corredores[i].edad >= 20) {
            corredores[i].categoria = "Adulto";
            contadores.nporC[1]++;
        } else {
            corredores[i].categoria = "Juvenil";
            contadores.nporC[2]++;
        }

        cout << "Ingrese su género (F/M): ";
        getline(cin, corredores[i].genero);

        // Incrementar contadores de género
        if (corredores[i].genero == "F" || corredores[i].genero == "f") {
            contadores.nm++;
        } else if (corredores[i].genero == "M" || corredores[i].genero == "m") {
            contadores.nh++;
        }
        
        totalCorredores++;
    }

    // Mostrar resultados
    cout << "\nResultados:\n";
    cout << "Número total de hombres: " << contadores.nh << endl;
    cout << "Número total de mujeres: " << contadores.nm << endl;
    cout << "Número total de corredores: " << totalCorredores << endl;
    cout << "Número total de clubes: " << contadores.nC << endl;
    for (int i = 0; i < 6; i++) {
        if (contadores.NporClub[i] > 0) {
            cout << "El club " << corredores[i].club << " tiene " << contadores.NporClub[i] << " corredor(es)." << endl;
        }
    }

    return 0;
}
