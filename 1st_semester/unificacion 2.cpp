
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 50

char stack [MAX];
char infix [MAX],postfix[MAX];
int top = -1;

void push(char);
char pop();
int isEmpty();
void inToPost();
int space(char);
void print();
int precedence(char);
using namespace std;
int main(){
	
	printf("dame la expresion logica:\n");
	gets(infix);
	
	inToPost();
	print();
	
	const char* cstr = infix;
	
	std::string proposicion(cstr);

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

    // Crear la matriz de la tabla de verdad usando un array convencional
    const int numFilas = 1 << numLetrasUnicas;
    const int numColumnas = numLetrasUnicas * 2;

    int tablaVerdad[numFilas][numColumnas];

    for (int i = 0; i < numFilas; ++i) {
        for (int j = 0; j < numLetrasUnicas; ++j) {
            tablaVerdad[i][j] = (i & (1 << (numLetrasUnicas - 1 - j))) ? 1 : 0;
        }

        // Agregar los contrarios al final de la fila
        for (int j = 0; j < numLetrasUnicas; ++j) {
            tablaVerdad[i][numLetrasUnicas + j] = 1 - tablaVerdad[i][j];
        }
    }

    // Imprimir la matriz de la tabla de verdad
    cout << "\nTabla de verdad:\n";
    for (int i = 0; i < numFilas; ++i) {
        for (int j = 0; j < numColumnas; ++j) {
            cout << tablaVerdad[i][j] << " ";
        }
        cout << endl;
    }
	
	
	
	
	
}
int precedence (char symbol){
	switch(symbol){
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

void inToPost(){
	int i,j=0 ;
	char symbol, next;
	for(i=0; i<strlen(infix); i++){
		symbol = infix[i];
		
		if(!space(symbol)){
		
		switch (symbol){
			case '(':{
				push(symbol);
				break;
			}
			 case ')':{
			 	while((next=pop()) != '(')
			 		postfix[j++] = next;
				break;
			 }
			// case '~':{	break;}	
			 case '^':
			 case '*':
			 case '&':
			 case '$':	
			 case '|':
			 	while(!isEmpty() && precedence(stack[top] >= precedence(symbol)))
			 		postfix[j++] = pop();
			 	push(symbol); 
				 break;
			default:
				postfix[j++]= symbol;
		}	
	}
}
	while(!isEmpty())
		postfix[j++] = pop();
	postfix[j] = '\0' ;
}

int space(char c){
	if(c == ' '|| c=='\t')
			return 1;
		else
			return 0;
	
}

void push (char c){
	if (top == MAX -1){
		printf("fin de la funcion\n");
		return;
	}
	top++;
	stack[top] = c;
}

char pop(){
	char c;
	if(top ==-1){
		printf("fin de la funcion\n");
		exit(1);
	}
	c= stack[top];
	top = top-1;
	return c;
}

int isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
	
}

void print(){
	int i=0;
	while(postfix[i]){
		printf("%c", postfix[i++]);
	}
	printf("\n");
}

