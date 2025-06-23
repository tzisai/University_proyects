#include <iostream>

using namespace std;

int main() {
    int cola[10] = {0}; // Inicializa todos los elementos a 0
    int frente = 0;     // Inicializa frente a 0
    int final = 0;      // Inicializa final a 0
    int Ndatos = 0;
    int TAM = 10;
    int TAMres = TAM;
    int chosse;

    do {
        system("cls");
        cout << "ELIJA OPORTUNAMENTE" << endl;
        cout << "QUEQUE(1)" << endl;
        cout << "UNQUEQUE(2)" << endl;
        cout << "PRINT(3)" << endl;
        cout << "Salir(0)" << endl;

        cin >> chosse;

        switch (chosse) {
            case 1: {
                do {
                    system("cls");
                    cout << "Cuantos datos deseas ingresar?" << endl;
                    cin >> Ndatos;
                    if (Ndatos > TAMres) {
                        cout << "Los inputs rebasan la capacidad restante de la cola, elimine elementos o ingrese una cantidad menor\n";
                        system("pause");
                    }
                } while (Ndatos > TAMres);

                for (int i = 0; i < Ndatos; i++) {
                    int dato;
                    cin >> dato;
                    cola[final] = dato;
                    final = (final + 1) % TAM; // Avanza final con operador módulo
                    TAMres--;
                }

                break;
            }
            case 2: {
                if (frente == final) {
                    cout << "Cola vacia, no hay elementos para eliminar" << endl;
                } else {
                    frente = (frente + 1) % TAM; // Avanza frente con operador módulo
                    TAMres++;
                }
                break;
            }

            case 3: {
                int i = frente;
                if (frente == final) {
                    cout << "Cola vacia" << endl;
                } else {
                    while (i != final) {
                        cout << cola[i] << "\t";
                        i = (i + 1) % TAM; // Avanza i con operador módulo
                    }
                    cout << endl;
                }
                system("pause");
                break;
            }
        }
    } while (chosse != 0);

    return 0;
}
