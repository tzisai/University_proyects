#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 100

using namespace std;

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void push(char);
char pop();
int isEmpty();
void inToPost();
int space(char);
void print();
int precedence(char);

int main() {

    cout << "Ingrese la expresion logica:\n";
    cin.getline(infix, MAX);

    inToPost();
    print();

		
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
		
		        // Agregar los contrarios al final de la fila
		        for (int j = 0; j < numLetrasUnicas; ++j) {
		            fila.push_back(1 - fila[j]);
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

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '*':
        case '|':
            return 2;
        case '&':
        case '$':
            return 1;
        default:
            return 0;
    }
}

void inToPost() {
    int i, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        if (!space(symbol)) {

            switch (symbol) {
                case '(': {
                    push(symbol);
                    break;
                }
                case ')': {
                    while ((next = pop()) != '(')
                        postfix[j++] = next;
                    break;
                }
                case '^':
                case '*':
                case '&':
                case '$':
                case '|':
                    while (!isEmpty() && precedence(stack[top] >= precedence(symbol)))
                        postfix[j++] = pop();
                    push(symbol);
                    break;
                default:
                    postfix[j++] = symbol;
            }
        }
    }
    while (!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int space(char c) {
    if (c == ' ' || c == '\t')
        return 1;
    else
        return 0;

}

void push(char c) {
    if (top == MAX - 1) {
        cout << "fin de la funcion\n";
        return;
    }
    top++;
    stack[top] = c;
}

char pop() {
    char c;
    if (top == -1) {
        cout << "fin de la funcion\n";
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}

int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

void print() {
    int i = 0;
    while (postfix[i]) {
        cout << postfix[i++];
    }
    cout << endl;
}
