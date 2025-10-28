#include <iostream>
#include <string.h>
using namespace std;

void transicion(char &edo_,bool &final,char input){
	
	switch(edo_){
		case 'A':{
			switch(input){
				case'a':{
					final=false;
					edo_='B';
					break;
				}
				case'b':{
					final=false;
					edo_='C';
					break;
				}
			}
			break;
		}
		case 'B':{
			switch(input){
				case'a':{
					final=false;
					edo_='B';
					break;
				}
				case'b':{
					final=true;
					edo_='E';
					break;
				}
			}
			break;
		}
		case 'C':{
			switch(input){
				case'a':{
					final=false;
					edo_='B';
					break;
				}
				case'b':{
					final=false;
					edo_='C';
					break;
				}
			}
			break;
		}
		case 'D':{
			switch(input){
				case'a':{
					final=false;
					edo_='B';
					break;
				}
				case'b':{
					final=false;
					edo_='C';
					break;
				}
			}
			break;
		}
		case 'E':{
			switch(input){
				case'a':{
					final=false;
					edo_='B';
					break;
				}
				case'b':{
					final=false;
					edo_='D';
					break;
				}
			}
			break;
		}
	}
	if(edo_=='E'){
	final=true;
	} 
	else {
	final=false;
	}
	
}

void aceptador_cadenas(string input,int tamCad,bool &final,char &edo_){
	for(int i=0;i<tamCad;i++){
		transicion(edo_,final,input[i]);
	}
	if(final==true){
		cout<<"cadena aceptada"<<endl;
	}
	else{
		cout<<"estado actual: "<<edo_<<" ,cadena no aceptada craniele mas mi pa"<<endl;
	}
}


int main(){
	char global_state='A';
	string input=" ";
	char mini_input=' ';
	short int elec=0;
	bool final=false;
	bool flag=true;
	
	do{
		system("cls");
		cout<<"Examen Parcial 1 Ejercicio Practico"<<endl;
		cout<<"Estados Posibles A,B,C,D,E"<<endl;
		cout<<"Alfabeto {a,b}"<<endl;
		cout<<"Estado actual:"<<global_state<<endl;
		
		cout<<"seleccione oportunamente: "<<endl;
		cout<<"(1) ingreso de cadena directa"<<endl;
		cout<<"(2) ingreso de estado y entrada"<<endl;
		cout<<"(3) salir"<<endl;
		
		cin>>elec;
		
		switch(elec){
			case 1:{
				system("cls");
				cout<<"Estados Posibles A,B,C,D,E"<<endl;
				cout<<"Alfabeto {a,b}"<<endl;
				cout<<"Estado actual:"<<global_state<<endl;
				
				cout<<"ingrese la cadena de cambios de estado"<<endl;
				cin>>input;
				
				aceptador_cadenas(input,input.length(),final,global_state);
				system("pause");
				break;
			}
			case 2:{
				system("cls");
				
				cout<<"Estados Posibles A,B,C,D,E"<<endl;
				cout<<"Alfabeto {a,b}"<<endl;
				cout<<"Estado actual:"<<global_state<<endl;
				
				cout<<"ingrese el Estado:"<<endl;
				cin>>global_state;
				cout<<"ingrese la entrada" <<endl;
				cin>>mini_input;
				
				cout<<global_state<<"->";
				transicion(global_state,final,mini_input);
				cout<<global_state;
				system("pause");
				break;
			}
			case 3:{
				flag=false;
				break;
			}
		}
		
	}while(flag==true);
	
	
	
	
	return 0;
}