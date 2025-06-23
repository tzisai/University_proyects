//Martin Isai Nuñez Villeda 
//ejercicio sintaxis de parentesis
#include <iostream>
#include <string>

using namespace std;

void push(int pila[], int &top, int item) {
	top++;
    pila[top] = item;
}

void pop(int &top) {
    top--;
}

int main() {
    string opr;
    int top = -1;

    cout << "ingresa la operacion" << endl;
    cin >> opr;

    int pila[5]; 

    for (int i = 0; i < opr.length(); i++) {
        if (opr[i] == '(') {
            push(pila, top, opr[i]);
        }
        if (opr[i] == ')') {
            pop(top);
        }
    }
	
	if(top==-1){
		cout<<"Syntaxis correcta\n";
	}
	else{
		cout<<"Syntaxis incorrecta\n";
	}
    return 0;
}