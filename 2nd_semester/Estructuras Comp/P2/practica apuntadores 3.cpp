/* 
Martin Isai Nuñez Villeda
objetivo:crea un programa con id y estatura aleatoria imprimirlas y decir si la estatura es mayor o menor al promedio.
*/
#include <iostream>
using namespace std;


struct alea{
	int id,estatura;
};

constexpr int FLOAT_MIN = 10;
constexpr int FLOAT_MAX = 100;

int main(){
	struct alea alea1[100];
	struct alea *apuntAlea;
	int acum;
	apuntAlea=alea1;
	
	
	
	 
	
	for(int i=0;i<101;i++){
		(apuntAlea+i)->id = 1 + rand()%1000;
		(apuntAlea+i)->estatura =1 + rand()%200;
	}
	
	
	for(int j=0;j<101;j++){
	acum+=(apuntAlea+j)->estatura;	
	}
	acum/=100;
	
		for(int i=0;i<101;i++){
		cout<<"no. alumno"<<i<<endl;
		cout<<"Id: "<<(apuntAlea+i)->id<<endl;
		cout<<"Estatura: "<<(apuntAlea+i)->estatura<<endl;	
		if((apuntAlea+i)->estatura<acum){
		cout<<"Su estatura es menor al promedio"<<endl;
		}
		else{
		cout<<"Su estatura es mayor al promedio"<<endl;
		}
		cout<<endl;
	}
	
	
	
	
	
	
	
	
}