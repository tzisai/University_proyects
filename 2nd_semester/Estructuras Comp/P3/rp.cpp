#include <iostream>
#include <string>

using namespace std;

void al_reves(int lenght, string cadena){
    if(lenght >= 0){
        cout << cadena[lenght];
        al_reves(lenght-1, cadena);
    }
    
}

int Sumatoria(int numero){
    if(numero != 0){
        numero += Sumatoria(numero - 1);
    }
    return numero;
}

int Fibonacci(int numero){
    int resultado;
    if(numero == 0 || numero == 1){
       return numero;
    }else{
        return Fibonacci(numero - 1) + Fibonacci(numero - 2);
    }
}

void mostrarMenu(int opcion) {
    cout << "\nMenú principal:" << endl;
    cout << "1. Cadena Inversa" << endl;
    cout << "2. Sumatoria Numeral" << endl;
    cout << "3. Serie Fibonacci (20 números)" << endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese su opción: ";
    cin >> opcion;

    switch (opcion) {
        case 1:{
            cout << "Opción 1 seleccionada" << endl;
            string cadena;
            int lenght;

            cout << "Ingrese la cadena de caracteres: ";
            getline(cin, cadena);
            lenght = cadena.length()-1;
            
            al_reves(lenght, cadena);
            break;
        }
        case 2:{
            cout << "Opción 2 seleccionada" << endl;
            int numero, sumota;

            cout << "Ingrese el número del cuál desea saber la sumatoria: ";
            cin >> numero;

            sumota = Sumatoria(numero);
            cout << "La sumatoria de " << numero << " es: " << sumota;
            break;
        }
        case 3:{
            cout << "Opción 3 seleccionada" << endl;
            cout << Fibonacci(20) << endl;
            for(int i = 0; i < 21; i++){
                cout << Fibonacci(i) << endl;
            }
            break;
        }
        case 4:{
            cout << "Saliendo del programa..." << endl;
            break;
        }
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
            mostrarMenu(0);
    }
}

int main() {
  int opcion;

  mostrarMenu(0);

  return 0;
}