/* Polimorfismo.
   Es la cualidad que tienen los objetos para actuar de diferente manera ante el mismo mensaje.
   Ejemplo anterior. Humano, perro y vaca y los tres van a comer.	
   Ejercicio: Mostrar los datos de alumnos y maestros con igual numero de parametros
*/
#include <iostream>
using namespace std;

class Persona  //Clase Padre
{
	protected:
		string nombre;
		int edad;
	public:
		Persona(string, int); //Constructor
		~Persona(); //?Destructor
		virtual void mostrar(); 
		//Con virtual indicas que usaras polimorfismo
		//y solo se escribe una vez en la clase Padre
		
};
//Herencia (clase hija)
class Alumno : public Persona
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

Persona::~Persona()
{
	cout<<"Borro: "<<nombre<<endl;
	
}
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

int main()
{
	//El polimorfismo se trabaja con punteros
	
	Alumno al1("Carlos", 29, 8.9);
	Alumno al2("Cristy", 17, 9.5);
	Profesor p1("Alex", 52, "Algoritmos");
	
	
	
	al1.mostrar();
	cout<<endl;
	al2.mostrar();
	cout<<endl;
	p1.mostrar();
	
	
	//system("pause");	//Para pausar o detener la pantalla y que no se cierre
	return 0;
} 