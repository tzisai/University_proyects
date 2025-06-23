#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>


#define MAX 100

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
    setlocale( LC_ALL, "" );

    string proposicion, prop;
    int len, columnas=0, count;

    getline(cin,proposicion);
    prop = proposicion;
  
	char infix [proposicion.length()];
	
	for (int index = 0; index < proposicion.length(); index++){
	    infix[index] = proposicion[index];
	}
	infix[proposicion.length()] = '\0';
    
    inToPost();
	printf("%s",postfix);
    
    proposicion.erase(remove_if(proposicion.begin(), proposicion.end(), ::isspace), proposicion.end());

    len = proposicion.length();
    cout<<len<<endl;

    for(int i = 0; i < len; i++){
        if(isalpha(proposicion[i])){
            columnas++;
        }
    }
    for(int i = 0; i < len; i++){
        count=1;
        for(int j = i+1; j < len; j++){
            if(isalpha(proposicion[i]) == proposicion[j]){
                count++;
                proposicion[j] = '0';
            }
        }
        if(count > 1 && proposicion[i] != '0'){
            columnas--;
        }
    }

    vector<vector<int>> truthTable(1 << columnas, vector<int>(2 * columnas));

    for (int row = 0; row < (1 << columnas); ++row) {
        for (int i = 0; i < columnas; ++i) {
            truthTable[row][i] = (row & (1 << (columnas - 1 - i))) ? 1 : 0;
            truthTable[row][i + columnas] = !(row & (1 << (columnas - 1 - i))) ? 1 : 0;
        }
    }

     // Imprimir la tabla de verdad
    for (int row = 0; row < (1 << columnas); ++row) {
        cout << "|";
        for (int i = 0; i < 2 * columnas; ++i) {
            cout << "   " << truthTable[row][i] << "        |";
        }
        cout<<endl;
    }
    
    
		
		
		


    return 0;
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
