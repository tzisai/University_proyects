#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//Martin Isai Nuñez Villeda
//2do semestre 13 de mayo de 2024 
/*Menu de infix a postfix y viceversa */

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string infixToPostfix(const string& expression) {
    stack<char> operators;
    string postfix;

    for (char c : expression) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Elimina el paréntesis izquierdo '(' de la pila
        } else {
            while (!operators.empty() && operators.top() != '(' && isOperator(operators.top()) && (isOperator(c) && c <= operators.top())) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

string postfixToInfix(const string& expression) {
    stack<string> operands;

    for (char c : expression) {
        if (isalnum(c)) {
            string operand(1, c);
            operands.push(operand);
        } else if (isOperator(c)) {
            string operand2 = operands.top();
            operands.pop();
            string operand1 = operands.top();
            operands.pop();
            string result = "(" + operand1 + c + operand2 + ")";
            operands.push(result);
        }
    }

    return operands.top();
}

int main() {
    char option;
    string expression;

    cout << "Bienvenido al conversor de expresiones aritmeticas!" << endl;

    do {
        cout << "\nElija una opcion:" << endl;
        cout << "1. Convertir una expresion aritmetica de infix a postfix" << endl;
        cout << "2. Convertir una expresion aritmetica de postfix a infix" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> option;

        switch (option) {
            case '1':
                cout << "\nIngresa la expresion aritmetica en notacion infix: ";
                cin.ignore(); // Ignora el salto de línea en el buffer de entrada
                getline(cin, expression);
                cout << "Expresion aritmetica en notacion postfix: " << infixToPostfix(expression) << endl;
                break;
            case '2':
                cout << "\nIngresa la expresion aritmetica en notacion postfix: ";
                cin.ignore(); // Ignora el salto de línea en el buffer de entrada
                getline(cin, expression);
                cout << "Expresion aritmetica en notacion infix: " << postfixToInfix(expression) << endl;
                break;
            case '3':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }

    } while (option != '3');

    return 0;
}
