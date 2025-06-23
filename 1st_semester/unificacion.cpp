#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int count_unique_letters(char* str) {
    int freq[26] = {0};
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            freq[str[i] - 'a']++;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            freq[str[i] - 'A']++;
        }
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            count++;
        }
    }
    return count;
}

int main(){
	
	printf("dame la expresion logica:\n");
	gets(infix);

	inToPost();
	print();
	int count = count_unique_letters(postfix);
	printf("%d",count);
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
