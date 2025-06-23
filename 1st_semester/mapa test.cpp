
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 50 //Maximo de varias matrices para su uso en funciones

using namespace std;

//Declaracion de variables para postfix
char stack [MAX];
char infix [MAX],postfix[MAX];
int top = -1;

//declaracion de funciones
void push(char);
char pop();
int isEmpty();
void inToPost();
int space(char);
void print();
int precedence(char);

int operaciones(char *string, char *string1,int[][MAX],int,int,int,int,int[]);

int operaciones(char propo[],char LetU[],int TaV[][MAX],int nc,int NLU,int contL,int contLind,int resAnt[]){
	map<char, int>letras;
	int operador1;
	int operador2;
	int resultado;
	//creacion de mapa
	/*se hace uso de solamente las variables positivias en caso de necesitar el
	valor negado esta se niega es decir se cambio de valor logico,
	*/
	 for (int i = 0; i < NLU; ++i) {
        letras[LetU[i]] = TaV[nc][i] ;
    }
    
    //si se llego al operador en mas de 3 lecturas de derecha a izquierda
    // pqr&
    // se tomara el de los ultimos 2 en caso contrario que sea en menos de 2 lecturas
    // 0r& siendo 0 un resultado ya obtenido
    //  | (sigue leyendo ahora con la letra que sigue ) 
    //se usara el resultado anterior obtenido
    
    if(contLind<4){
     operador1=letras[propo[contL-2]];
     operador2=letras[propo[contL-1]];	
	}
	else{
	 operador1=letras[propo[contL-2]];
     operador2=resAnt[nc-1];	
	}
    //switch de que operadores logico encontro
    	switch (propo[contL]){
    		//AND suma logica
			case '^':{
					resultado=operador1+operador2;
		        if (resultado==2){
		        	return 1;
				}
			    else{
			    	return 0;
				}
				break;
			}
		// Or multiplicacion logica
			case '*':{
				resultado=operador1*operador2;
    			return resultado;
				break;
			}
		//Implica si el segundo es verdad o los 2 son falsos =1		
			case '&':{
				if(operador2==1||(operador1&&operador2==0)){
			        	return 1;
					}
					else{
						return 0;
					}
				break;
			}
		//doble implicacion un And 2.0		  
			case '$':{
				resultado=operador1+operador2;
			        if (resultado==2){
			        	return 1;
					}
			    else{
			    	return 0;
				}
				break;
			}
		//XOR solo uno de los 2 debe ser verdadero			
			case '|':{
				if((operador1==1&&operador2==0)||(operador1==0&&operador2==1)){
					return 1;
				}
				else{
					return 0;
				}
				break;
			}
				
			//negacion el operador 2 es decir el que se aplica la negacion se le cambia el signo	
			case '~':{
				if(operador2==1){
					operador2=0;
				}
				else{
					operador2=1;
				}
				break;
			}
				
				
					
		}
        
        
    
    
}
	
int main(){
	char LetrasU[50];
	
	printf("dame la expresion logica:\n");
	gets(infix);
	
	inToPost();//pasa a posfijo
	print();//printeo de control
	
	
	const char* cstr = infix;
	
	std::string proposicion(cstr);//string de c a strin std para hacer la tabla de verdad

    // Eliminar espacios en blanco
    proposicion.erase(remove_if(proposicion.begin(), proposicion.end(), ::isspace), proposicion.end());

    // Contar el número de letras únicas
    int numLetrasUnicas = 0;
    vector<char> letrasUnicas;
	
	
	int i=0;
    for (char c : proposicion) {
        if (isalpha(c) && find(letrasUnicas.begin(), letrasUnicas.end(), c) == letrasUnicas.end()) {
            letrasUnicas.push_back(c);
            numLetrasUnicas++;
            LetrasU[i]=c;
            i++;
            cout<<c<<endl;
        }
    }

    // Crear la matriz de la tabla de verdad usando un array convencional usando como parametro numero de letras unicas
    const int numFilas = 1 << numLetrasUnicas;
    const int numColumnas = numLetrasUnicas * 2;

    int tablaVerdad[numFilas][MAX];
	//uso de bitmasking para crar la matriz
    for (int i = 0; i < numFilas; ++i) {
        for (int j = 0; j < numLetrasUnicas; ++j) {
            tablaVerdad[i][j] = (i & (1 << (numLetrasUnicas - 1 - j))) ? 1 : 0;
        }

        // Agregar los contrarios al final de la fila
        for (int j = 0; j < numLetrasUnicas; ++j) {
            tablaVerdad[i][numLetrasUnicas + j] = 1 - tablaVerdad[i][j];
        }
    }
    
    
   int resultadoFinal[(numLetrasUnicas * 2)];// resultado que se imprime al final de la fila
   //en la condicion es debido al numero de filas
	for(int j=0;j<(numLetrasUnicas * 2);j++){	
		int contLeidas=0;// no. de caracteres leidos
		int lindividuales=0;//no.caracteres leidos hasta encontrar un operador logico
		int resultOp[10];//resultado de operacion individual(compilado)
		int resultado;//lo mismo pero solo se usa para asignacion y se rescribe en la siguiente operacion
		//condicion debido a como quedo la expresion final en posfijo para que la lea toda
	for(int i=0;i<strlen(postfix-1);i++){
		cout<<postfix[i];
		
		//switch en caso de que encuentre un operador en base la lectura
		switch (postfix[i]){
			case '^':
			case '*':
			case '&':
			case '$':	
			case '|':
			case '~':
				//funcion de operaciones logicas
				resultado=operaciones(postfix,LetrasU,tablaVerdad,j,numLetrasUnicas,contLeidas,lindividuales,resultOp);
				//asignacion de el resultado a un vetor de todos los resultados
				resultOp[i]=resultado;
			lindividuales=0;//se reinicia el numero de lecturas hasta llegar al operador 				
		}
		
		contLeidas++;
		lindividuales++;
		resultadoFinal[j]=resultOp[i];//la ultima operacion guardada se asignara a los resultados 
									//finales que sera el que se imprima al final de la tabla	
	}

}
	

	


    // Imprimir la matriz de la tabla de verdad
    cout << "\nTabla de verdad:\n";
    for (int i = 0; i < numFilas; ++i) {
        for (int j = 0; j < numColumnas; ++j) {
            cout << tablaVerdad[i][j] << " |\t";
        }
        cout<<"\t"<<resultadoFinal[i];
        cout << endl;
    }
	
	
	
	
	
}
//funcion gerarquia de operaciones(mayor gerarquia, mayor retorno)
int precedence (char symbol){
	switch(symbol){
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
//funicion con stacks para pasar la expresion a postfijo
//misma logica que gerarquia y la funcion de operaciones pero hace funciones para crear stack
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
			 case '~':	
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
//funcion para saber si existe un espacio o no en la expresion y desecharlo
int space(char c){
	if(c == ' '|| c=='\t')
			return 1;
		else
			return 0;
	
}
//funcion push para el stack
void push (char c){
	if (top == MAX -1){
		printf("fin de la funcion\n");
		return;
	}
	top++;
	stack[top] = c;
}
//funcion pop(eliminar)
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
//la string esta vacia funcion
int isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
	
}
//funicion de impresion de la expresion de postfijo(funcion de control)
void print(){
	int i=0;
	while(postfix[i]){
		printf("%c", postfix[i++]);
	}
	printf("\n");
}

