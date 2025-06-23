#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

#define MAX 50

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
int operaciones(char, char[], int[][20], int, int, int, int, int);

int main() {
    char LetrasU[50];

    printf("Dame la expresion logica:\n");
    fgets(infix, MAX, stdin);

    inToPost();
    print();

    const char* cstr = infix;

    std::string proposicion(cstr);

    proposicion.erase(remove_if(proposicion.begin(), proposicion.end(), ::isspace), proposicion.end());

    int numLetrasUnicas = 0;
    vector<char> letrasUnicas;

    int i = 0;
    for (char c : proposicion) {
        if (isalpha(c) && find(letrasUnicas.begin(), letrasUnicas.end(), c) == letrasUnicas.end()) {
            letrasUnicas.push_back(c);
            numLetrasUnicas++;
            LetrasU[i] = c;
            i++;
            cout << c << endl;
        }
    }

    const int numFilas = 1 << numLetrasUnicas;
    const int numColumnas = numLetrasUnicas * 2;

    int tablaVerdad[numFilas][numColumnas];

    for (int i = 0; i < numFilas; ++i) {
        for (int j = 0; j < numLetrasUnicas; ++j) {
            tablaVerdad[i][j] = (i & (1 << (numLetrasUnicas - 1 - j))) ? 1 : 0;
        }

        for (int j = 0; j < numLetrasUnicas; ++j) {
            tablaVerdad[i][numLetrasUnicas + j] = 1 - tablaVerdad[i][j];
        }
    }

    int resultadoFinal[(numLetrasUnicas * 2)];

    for (int j = 0; j < (numLetrasUnicas * 2); j++) {
        int contLeidas = 0;
        int lindividuales = 0;
        int resultOp[10];
        int resultado;

        for (int i = 0; i < strlen(postfix) - 1; i++) {
            switch (postfix[i]) {
                case '^':
                case '*':
                case '&':
                case '$':
                case '|':
                case '~':
                    resultado = operaciones(postfix[i], LetrasU, tablaVerdad, j, contLeidas, lindividuales, resultadoFinal[j]);
                    resultOp[i] = resultado;
                    lindividuales = 0;
            }

            contLeidas++;
            lindividuales++;
            resultadoFinal[j] = resultOp[i];
        }
    }

    cout << "\nTabla de verdad:\n";
    for (int i = 0; i < numFilas; ++i) {
        for (int j = 0; j < numColumnas; ++j) {
            cout << tablaVerdad[i][j] << " |\t";
        }
        cout << "\t" << resultadoFinal[i];
        cout << endl;
    }

    return 0;
}

int precedence(char symbol) {
    switch (symbol) {
        case '~':
            return 4;
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
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while ((next = pop()) != '(')
                        postfix[j++] = next;
                    break;
                case '~':
                case '^':
                case '*':
                case '&':
                case '$':
                case '|':
                    while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
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
    return (c == ' ' || c == '\t');
}

void push(char c) {
    if (top == MAX - 1) {
        printf("fin de la funcion\n");
        return;
    }
    top++;
    stack[top] = c;
}

char pop() {
    char c;
    if (top == -1) {
        printf("fin de la funcion\n");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}

int isEmpty() {
    return (top == -1);
}

void print() {
    int i = 0;
    while (postfix[i]) {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

int operaciones(char symbol, char LetU[], int TaV[][20], int nc, int contLeidas, int lindividuales, int resAnt) {
    int operador1, operador2;
    int resultado;

    if (lindividuales < 4) {
        operador1 = TaV[nc][contLeidas - 2];
        operador2 = TaV[nc][contLeidas - 1];
    } else {
        operador1 = TaV[nc][contLeidas - 2];
        operador2 = resAnt;
    }

    switch (symbol) {
        case '^':
            resultado = operador1 + operador2;
            return (resultado == 2) ? 1 : 0;
        case '*':
            return operador1 * operador2;
        case '&':
            return (operador2 == 1 || (operador1 && operador2 == 0)) ? 1 : 0;
        case '$':
            resultado = operador1 + operador2;
            return (resultado == 2) ? 1 : 0;
        case '|':
            return ((operador1 == 1 && operador2 == 0) || (operador1 == 0 && operador2 == 1)) ? 1 : 0;
        case '~':
            return (operador2 == 1) ? 0 : 1;
        default:
            return 0;
    }
}
