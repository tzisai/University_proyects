/* Metodos constructores y modificadores (Get y Set)
	Set sirve para dar o establecer valores a los atributos
	Get sirve para mostrar o dar la informaci?n que tienen almacenados nuestros atributos.
	Sirven para manejar o manipular los atributos de la clase porque como estan encapsulados nadie mas los puede manipular.
*/

#include <iostream>
using namespace std;

class Punto
{
	private: //Atributos
		int x,y;
	public:  //Metodos
		//Punto();
		void setPunto(int, int);
		int getPuntoX();
		int getPuntoY();
};
/*
Punto::Punto()
{
}
*/

//Sirve para establecer valores a los atributos 
void Punto::setPunto(int vx, int vy)
{
	x = vx;
	y = vy;
}

int Punto::getPuntoX()
{
	return x;
}

int Punto::getPuntoY()
{
	return y;
}

int main()
{
	Punto punto1;
	
	punto1.setPunto(15,10);
	cout<<"x = "<<punto1.getPuntoX()<<endl;
	cout<<"y = "<<punto1.getPuntoY()<<endl;
	
	//punto1.x= 15; Esto no se puede hacer porque el atributo x esta encapsulado
	//               solo puede ser modificado por los metodos de la clase
	//cout<<punto1.x<<endl; Tampoco se puede hacer esto
	//				porque esta encapsulado y solo se puede manejar con los
	//				metodos de la clase.
	//system("pause");	//Para pausar o detener la pantalla y que no se cierre
	return 0;
}
