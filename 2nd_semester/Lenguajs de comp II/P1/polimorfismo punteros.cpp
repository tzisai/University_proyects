#include <iostream>
using namespace std;

class Persona  //Clase Padre
{
	protected:
		string nombre;
		int edad;
	public:
		Persona(string, int); //Constructor
		~Persona(); //Destructor
		virtual void mostrar(); 
		//Con virtual indicas que usaras polimorfismo
		//y solo se escribe una vez en la clase Padre
		
};
//Herencia (clase hija)
class Alumno : public Persona/* Metodos constructores y modificadores (Get y Set)
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

{
	private:
			float notaFinal;
	public:
			Alumno(string, int, float); //Constructor
			void mostrar();  //Polimorfismo
};

class Profesor : public Persona
{
	private:
			string materia;
	public:
			Profesor(string, int, string); //Constructor (nombre, edad y materia)
			void mostrar();  //Polimorfismo
};

Persona::Persona(string name, int age)
{
	nombre = name;
	edad = age;
}
/*Persona::~Persona()
{
	cout<<"Borro: "<<nombre<<endl;
	
}*/
void Persona::mostrar()
{
	cout<<"Nombre :"<<nombre<<endl;
	cout<<"Edad :"<<edad<<endl;
}

//Constructor de Alumno de una clase hija
Alumno::Alumno(string name, int age, float nFinal) : Persona(name, age)
{
	notaFinal = nFinal;
}

//Polimorfismo: Metodo mostrar de Alumno
void Alumno::mostrar()
{
	Persona::mostrar();
	cout<<"Nota Final: "<<notaFinal<<endl;
}
//Constructor de Profesor
Profesor::Profesor(string name, int age, string subject) : Persona(name, age)
{
	materia = subject;
}
//Polimorfismo: Metodo mostrar de Profesor
void Profesor::mostrar()
{
	Persona::mostrar();
	cout<<"Materia: "<<materia<<endl;
}
Persona::~Persona()
{
	cout<<"Borro: "<<nombre<<endl;
	
}
int main()
{
	//El polimorfismo se trabaja con punteros
	Persona *vector[3];
	
				//Alumno deriva de Persona
	vector[0] = new Alumno("Carlos", 29, 8.9);
	vector[1] = new Alumno("Cristy", 17, 9.5);
	vector[2] = new Profesor("Alex", 52, "Algoritmos");
	
	vector[0] -> mostrar(); //le indico que con el vector[0] utilice el m?todo mostrar
							//y se gu?a porque arriba estamos usando la clase Alumno (en el new)	
	//con struct usabamos nomstruct.campo
	//con punteros usamos -> en lugar de .
	
	cout<<endl;
	vector[1] -> mostrar();
	cout<<endl;
	vector[2] -> mostrar(); //Vector 2 es de la clase Profesor
	
	//Para que funcione el destructor
	for(int i=0; i<3; i++)
	{
		delete vector[i];
		cout<<endl;
	}
	//system("pause");	//Para pausar o detener la pantalla y que no se cierre
	return 0;
}
