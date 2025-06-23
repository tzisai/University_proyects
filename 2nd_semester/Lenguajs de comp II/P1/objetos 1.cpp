#include<iostream>

using namespace std;

class Persona
{
	private:	 //atributos
		int edad;
		string nombre;
	public:		//metodos
		Persona(int,string);	//constructor
		void leer();
		void correr();		
};
//constructor sirve para inicializar los atributos
Persona::Persona(int ed,string nom)
{
	edad=ed;
	nombre=nom;
}

void Persona::leer()
{
	cout<<"Soy "<<nombre<<", tengo "<<edad<<"anios"<<" y estoy leyendo un libro "<<endl;
}


void Persona::correr()
{
	cout<<"Soy "<<nombre<<", tengo "<<edad<<"anios"<<" y estoy leyendo corriendo"<<endl;
}
int main(){
	//hay 2 formas de instanciar objetos
	//p1 va a ser el objeto
	//1)Persona(18,"Cristy");
	//2) Persona p1(18,Cristy);
	
	Persona p1 (18,"Cristy");
	Persona p2 (22,"Alex");
	Persona p3 (70,"Gaby");
	
	p1.correr();
	p1.leer();
	
	p2.leer();
	p2.correr();
	
	p3.leer();
	p3.correr();
	
	//system("pause");
	return 0;
}

