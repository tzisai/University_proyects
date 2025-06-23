#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <stack>

using namespace std;

int evaluatePostfix(const string& postfix) {
    stack<int> s;

    for (char c : postfix) {
        if (isalpha(c)) {
            // Si es una letra, asumimos que representa un valor booleano (1 o 0) y lo apilamos
            s.push(1);  // Puedes modificar esto según tus necesidades
        } else if (c == '1' || c == '0') {
            // Si es un número, apilamos su valor entero
            s.push(c - '0');
        } else if (c == '&' || c == '|' || c == '^') {
            // Operaciones lógicas binarias
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            if (c == '&') {
                s.push(operand1 & operand2);
            } else if (c == '|') {
                s.push(operand1 | operand2);
            } else if (c == '^') {
                s.push(operand1 ^ operand2);
            }
        } else if (c == '~') {
            // Operación lógica NOT
            int operand = s.top();
            s.pop();
            s.push(!operand);
        }
    }

    return s.top();
}

int main() {
    setlocale(LC_ALL, "");

    string proposicion;
    char negacion = '~';

    cout << "Dame la expresión lógica:\n";
    getline(cin, proposicion);

    int columnas = contarLetrasUnicas(proposicion);

    for (int row = 0; row < (1 << columnas); ++row) {
        cout << "|";
        for (int i = 0; i < columnas; ++i) {
            bitset<1> bit(i & (1 << (columnas - 1 - i)));
            cout << "   " << ((row & (1 << (columnas - 1 - i))) ? 1 : 0) << "        |";
        }
        if (proposicion.find(negacion) != string::npos) {
            for (int i = 0; i < columnas; ++i) {
                bitset<1> bit(i & (1 << (columnas - 1 - i)));
                cout << "   " << (!(row & (1 << (columnas - 1 - i))) ? 1 : 0) << "        |";
            }
        }

        cout << endl;
    }

    inToPost();
    print();

    int resultado = evaluatePostfix(postfix);
    cout << "Resultado de la expresión lógica: " << resultado << endl;

    return 0;
}
