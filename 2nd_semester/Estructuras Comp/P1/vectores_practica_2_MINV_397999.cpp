//Martin Isai Nuñez Villeda ICI 2do semestre
//8 de febrero de 2024
//Objetivo:crea un programa que al ingresar un numero del 1 al 12 te diga que mes es y cuantos dias tiene.
#include <iostream>
#include <string>

using namespace std;

int main() {
    string meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    int dias[3] = {30, 31,28 };
    int input = 0;
    int res = 0;

    do {
        cout << "Ingresa un numero entre 1 y 12 (unicamente enteros)" << endl;
        cin >> input;
    } while (input <= 0 || input > 12);

    if (input <= 7) {
        if (input ==2 ) {
            cout << "Tu mes es " << meses[input - 1] << " y tiene " << dias[2] << " dias." << endl;
        } 
		else {
            res = input % 2;
            cout << "Tu mes es " << meses[input - 1] << " y tiene " << dias[res] << " dias." << endl;
        	}
        }
    

    if (input >= 8) {
        if (input % 2 == 0) {
            cout << "Tu mes es " << meses[input - 1] << " y tiene " << dias[1] << " dias." << endl;
        } 
		else {
            cout << "Tu mes es " << meses[input - 1] << " y tiene " << dias[0] << " dias." << endl;
        }
    }

    return 0;
}
