#include <iostream>
#include <string>
using namespace std;


void conversor_binario(int cont){
	int aux;
	aux=cont%2;
	int tabla_bin=aux;
	cout<<"\t"<<aux;
	cont/=2;
	conversor_binario(cont);
	
}

int Isin(){
	
	
}



int main (){
	
	string strinput;

	cout<<"ingresa el conjunto a calcular con la siguiente sintaxis"<<endl;
	cout<<"abc\tabcde"<<endl;
	
	cin>>strinput;
	
	int tams=sizeof(strinput);
	cout<<"¤\t";
	
		for(int j=0;j<tams;j++){
			cout<<"0";
		}
	
	for(int i=0;i<sizeof(strinput);i++){
		cout<<strinput[i]<<endl;
		for(int j=-1;j<i;j++){
			cout<<"0";
		}
		cout<<endl;
	}
	
	
	
	
return 0;	
}