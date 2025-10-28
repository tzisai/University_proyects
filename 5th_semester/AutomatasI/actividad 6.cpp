#include <bits/stdc++.h>
using namespace std;

void transicion1(char entrada, short int &edo_){
	
	switch(edo_){
		case 0:{
			switch(entrada){
				case'0':{
					edo_=2;
					break;
				}
				case'1':{
					edo_=1;
					break;
				}
			}
			break;
		}
		case 1:{
			switch(entrada){
				case'0':{
					edo_=3;
					break;
				}
				case'1':{
					edo_=0;
					break;
				}
			}
			break;
		}
		case 2:{
			switch(entrada){
				case'0':{
					edo_=0;
					break;
				}
				case'1':{
					edo_=3;
					break;
				}
			}
			break;
		}
		case 3:{
			switch(entrada){
				case'0':{
					edo_=1;
					break;
				}
				case'1':{
					edo_=2;
					break;
				}
			}
			break;
		}
	}

}

void transicion2(char entrada,short int &edo_){
	
	switch(edo_){
		case 0:{
			switch(entrada){
				case'0':{
					cout<<"valor invalido para este estado \n";
					break;
				}
				case'1':{
					edo_=1;
					return;
					break;
				}
			}
			break;
		}
		case 1:{
			switch(entrada){
				case'0':{
						cout<<"valor invalido para este estado \n";
						return;
					break;
				}
				case'1':{
					edo_=2;
					break;
				}
			}
			break;
		}
		case 2:{
			switch(entrada){
				case'0':{
				edo_=3;
					break;
				}
				case'1':{
				edo_=2;
					break;
				}
			}
			break;
		}
		case 3:{
			switch(entrada){
				case'0':{
					edo_=3;
					break;
				}
				case'1':{
					edo_=4;
					break;
				}
			}
			break;
		}
		
	case 4:{
		switch(entrada){
		case '0':{
			edo_=3;
			break;
		}
		case'1':{
			edo_=2;
			break;
		}
		}
		break;
	}
	}
	
}

string edoact(short int edo_){
	string edos [6]={"q0","q1","q2","q3","q4"};
	
  return edos[edo_];
}

int main(){
	
	
	bool flag2,flag;
	char elect;
	
	short int global_state=0;
	char input;
	
	do{

	cout<<"Seleccione el Automata a probar"<<endl;
	
	cout<<"Ingrese 1 para el automata del ejercicio 1"<<endl;
	cout<<"Ingrese 2 para el automata del ejercicio 3"<<endl;
	cout<<"ingrese X para salir"<<endl;
	
	cin>>elect;
	
	switch(elect){
		case '1':{
			do{
				flag2=true;
				cout<<"Automata inciso 1"<<endl;
				cout<<"Entradas recurrentes '1','0'('x'para salir)"<<endl;
				cout<<"El estado actual del automata es:"<<edoact(global_state)<<endl;
				cout<<"type una entrada:"<<endl;
				cin>> input;
				if(input=='x'){
				flag2=false;	
				}
				else{
				transicion1(input,global_state);	
				} 
				}while(flag2==true);
			break;
		}
		
		case'2':{
				flag2=true;
				cout<<"Automata inciso 2"<<endl;
				cout<<"Entradas recurrentes '1','0'('x'para salir)"<<endl;
				cout<<"El estado actual del automata es:\t"<<edoact(global_state)<<endl;
				cout<<"type una entrada:"<<endl;
				cin>> input;
				if(input=='x')flag2=false;
				else transicion2(input,global_state);
				}while(flag2==true)
			break;
		
		
		case 'X':{
			flag=false;
			break;
			}
		}
	}while(flag==true);
	return 0;
}