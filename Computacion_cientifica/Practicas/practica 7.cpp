#include <iostream>
#include <math.h>
using namespace std;

// _Martin Nuñez Villeda_


float fdx(float x){
	return (666.4/x)*(1-exp(-0.1470588235*x))-40;
}

float error_aprox(float xu,float xl){
	return (abs((xu-xl)/(xu+xl))*100);
}

int main(){
	int 	iter=0;
	float 	xl=12,xu=16;
	
	float	xlF=0,xuF=0,xa=0,er=0;

	cout<<"Bienvenido a el metodo de biseccion \n";
	cout<<"Cuantas iteraciones deseas ejecutar \n";
	cin>>iter;
	
		cout<<"xl \t"<<"xu \t"<<"xa \t"<<"er \t"<<endl;
	
	for(iter=0;iter<20;iter++){
		
	xa=(xu+xl)/2;
	er=error_aprox(xu,xl);
	
	xlF=fdx(xl);
	xuF=fdx(xu);
		
	if(xlF*xuF<0){
		xu=xa;
	}
	else if(xlF*xuF>0){
		xl=xa;
	}
	else if(xlF*xuF==0||er<0.1){
		break;	
	}
	
	cout<<xl<<"\t"<<xu<<"\t"<<xa<<"\t"<<er<<"\t"<<endl;
		
	}
	
	
	
	return 0;
}