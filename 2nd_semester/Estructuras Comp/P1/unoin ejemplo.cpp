#include <iostream>

union capacidad{
	int no_personas;
	int tonelajel;
};

struct vehiculo{
	int nserie;
	int modelo ;
	int tipo;
	union capacidad capa1;
};



int main(){
struct vehiculo vehiculo1;
int tonelaje;

//captura de la estructura
std::cout<<"ingrese segun corresponda"<<std::endl;
std::cout<<"No.Serie"<<std::endl;
std::cin>>vehiculo1.nserie;
std::cout<<"Modelo"<<std::endl;
std::cin>>vehiculo1.modelo;
std::cout<<"Tipo"<<std::endl;
std::cin>>vehiculo1.tipo;
if(vehiculo1.tipo==1){
std::cout<<"Capacidad Pasajeros"<<std::endl;
std::cin>>vehiculo1.capa1.no_personas;
}
else{
	std::cout<<"Tonelaje"<<std::endl;
std::cin>>vehiculo1.capa1.tonelajel;
}




std::cout<<"tamanio de la estructura"<<sizeof(vehiculo1)<<std::endl;	
std::cout<<"tamanio de la union "<<sizeof(vehiculo1.capa1)<<std::endl;	
}