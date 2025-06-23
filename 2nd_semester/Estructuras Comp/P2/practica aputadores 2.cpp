#include <iostream>

using namespace std;

int main(){
	
	int lista[5];
	int *apunt;
	
	apunt=lista;
	
	for(int i=0;i<5;i++){
		cout<<"ingrese un numero xfa es pa una tarea"<<endl;
		cin>>*(apunt+i);
		
	}
	
		cout<<"las direcciones de memoria usadas fueron"<<endl;
	for(int j=0;j<5;j++){
		cout<<(apunt+j)<<"con el valor"<<*(apunt+j)<<endl;
	}
	
	
	
	return 0;
}