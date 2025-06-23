#include <iostream>
using namespace std;

class Perro
{
	private:
		string nombre, raza;
	public:
		Perro(string, string); //Constructor
		~Perro(); //Destructor
		void mostrarDatos();
		void jugar();
};
//Constructor
Perro::Perro(string nom, string raz)
{
	nombre = nom;
	raza = raz;
}

//Destructor
Perro::~Perro()
{
      cout<<"Eliminando a "<<nombre<<" de raza "<<raza<<endl;
}

void Perro::mostrarDatos()
{
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Raza: "<<raza<<endl;
}

void Perro::jugar()
{
	cout<<"El perro "<<nombre<<" esta jugando"<<endl;
}

int main()
{
	Perro perro1("Droopy", "Koker");
	
	perro1.mostrarDatos();
	perro1.jugar();
	 //Al declarar un destructor, se destruye el objeto, no es necesario ponerlo
	//Autom?ticamente se destruye el objeto
	
	cout<<"\n";
	
	//system("pause");	//Para pausar o detener la pantalla y que no se cierre
	return 0;
}