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
    int nporC[6] = {0}; // Ajustado para el número máximo de clubes (6)
    int NporClub[6] = {0}; // Ajustado para el número máximo de corredores (6)
};

int main() {
	int i=0;
    Corredor corredores[6];
    Contadores contadores;

    for ( i = 0; i <2; i++) {
        cout << "Ingrese el nombre del aspirante " << i + 1 << ": ";
        getline(cin, corredores[i].nombre);

        cout << "Ingrese el club de procedencia: ";
        getline(cin, corredores[i].club);

        // Verificar si es el primer corredor del club
        bool nuevoClub = true;
        for (int j = 0; j < i; j++) {
            if (corredores[i].club == corredores[j].club) {
                contadores.NporClub[j]++; // Incrementar contador de corredores para el club
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
    }

    // Mostrar resultados
    cout << "\nResultados:\n";
    cout << "Número total de hombres: " << contadores.nh << endl;
    cout << "Número total de mujeres: " << contadores.nm << endl;
    cout << "Número total de corredores: " << i << endl; // Número fijo de corredores
    cout << "Número total de clubes: " << contadores.nC << endl;
    for (int i = 0; i < 6; i++) {
    	if(contadores.NporClub[i]>1){
    		cout << "El club " << corredores[i].club << " tiene "<<contadores.NporClub[i] << endl;
		}
    
    }

    return 0;
}