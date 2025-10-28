#include<bits/stdc++.h>
using namespace std;


void Transicion(short int &edo_ ,char input){
	
	switch(edo_){
		case 0:{
		
		if(input=='X'){
			edo_=1;
		}
		else if(input=='Y'){
			edo_=2;
		}
		else{
			cout<<"ingresaste un valor invalido intenta de nuevo \n";
		}
		break;
		}
		case 1:{
			if(input=='A'){
			edo_=3;
		}
		else if(input=='B'){
			edo_=4;
		}
		else{
			cout<<"ingresaste un valor invalido intenta de nuevo \n";
		}

		break;
		}
		case 2:{
			if(input=='B'){
				edo_=4;
		}
		else if(input=='A'){
				edo_=5;
		}
		else{
			cout<<"ingresaste un valor invalido intenta de nuevo \n";
		}

		break;
		}
		
		default:
			cout<<"no deberias estar aqui "<<endl;
	}
	
	
	
}

void Estado_(short int &edo_){
	switch(edo_){
		
		case 0 :{
				cout<<"Tu aguacate esta por ser evaluado(q0)"<<endl;	
			break;
		}
		
		case 1:{
				cout<<"Tu aguacate es premium no se sabe el peso(q1)"<<endl;
			break;
		}
		
		case 2:{
				cout<<"Tu aguacate es estandar no se sabe el peso(q2)"<<endl;
			break;
		}
		
		case 3:{
				cout<<"Tu aguacate es premium peso bajo (q3)"<<endl;
			break;
		}
		
		case 4:{
				cout<<"Tu aguacate es premium(q4)"<<endl;
			break;
		}
		
		case 5:{
				cout<<"Tu aguacate es sera descartado(q5)"<<endl;
			break;
		}
		
	}
}

int main(){
	
	char elect='p';
	char input=' ';
	bool flag=true;
	short int edo=0;

	do{
		system("cls");
cout<<"HOLA!!! Bienvenido al Clasificador de Aguacates"<<endl;
cout<<"-El estado incial es q0"<<endl;
cout<<"-Entradas validas:"<<endl;
cout<<"-'X' = Calidad premium"<<endl;
cout<<"-'Y' = Calidad estandar"<<endl;
cout<<"-'A' = Peso Alto"<<endl;
cout<<"-'B' = Peso bajo"<<endl;
cout<<"- Estados disponibles:"<<endl;
cout<<"- q0,q1,q2,q3,q4,q5"<<endl;

cout<<"El estado actual es:";
Estado_(edo);
cout<<endl;

cout<<"ingrese 'F' y presione enter para ingresar los valores en la funcion de transicion"<<endl;
cout<<"ingrese 'R' y presione enter para reiniciar la evaluacion"<<endl;
cout<<"ingrese 'S' y presione enter para Salir"<<endl;

cin>>elect;

if(elect=='F'){
	cout<<"Ingrese una entrada de las mencionadas en la parte superior"<<endl;
	cin>>input;
	Transicion(edo,input);
}
if(elect=='R'){
		edo=0;
}
if(elect=='S'){
		flag=false;
}


}while(flag!=false);


return 0;
	
};