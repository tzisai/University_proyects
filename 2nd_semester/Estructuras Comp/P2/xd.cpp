#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int cont = 0;
    char palabra[27];

    cout << "Ingrese una palabra cualquiera: ";
    cin >> palabra;

    char *apunt = palabra;
    int i = 0;

    while (*(apunt + i) != '\0') {
        char letra = tolower(*(apunt + i)); // Convertir a minúscula
        switch (letra) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                cont++;
                break;
        }
        i++;
    }

    cout << "El numero de vocales en la palabra es: " << cont << endl;

    return 0;
}
