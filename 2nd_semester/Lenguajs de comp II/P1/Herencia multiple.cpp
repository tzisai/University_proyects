/*Herencia en POO
  Ejercicio 8: Realice un programa en C++, 
  que construya una solucion para la 
  jerarquia (herencia) de clase Persona - Empleado y Estudiante Universitario
*/
  
#include <iostream>
using namespace std;

class Persona   //Clase padre o superclase
{
	protected:	//Atributos
		string nombre;
		int edad;
	public:	//Metodos
		Persona(string, int);	
		~Persona(); //Destructor
		void mostrarPersona();
};

//Clase hija de la clase Persona y puede
//acceder a todo lo publico de la clase
//persona
class Empleado : public Persona
{
	private:	//Atributos
		float sueldo;
	public:  	//Metodos
		Empleado(string, int, float); //Constructor de la clase Alumno
			//primero lo de la clase padre y luego lo de la clase hija
		void mostrarEmpleado();	
};

class Estudiante : public Persona
{
	private:	//Atributos
		float notaFinal;
	public:  	//Metodos
		Estudiante(string, int, float); //Constructor de la clase Alumno
			//primero lo de la clase padre y luego lo de la clase hija
		void mostrarEstudiante();	
};

class Universitario : public Estudiante
{
	private:	//Atributos
		string carrera;
	public:  	//Metodos
		Universitario(string, int, float, string); //Constructor de la clase Alumno
			//primero lo de la clase padre y luego lo de la clase hija
		void mostrarUniversitario();	
};

//Constructor de la clase Persona (Clase Padre)
Persona::Persona(string nom, int ed)
{
	nombre = nom;
	edad = ed;
}
Persona::~Persona()
{
	cout<<"Borro: " << nombre<<endl;

}

//Constructor de la clase Empleado (clase hija)
Empleado::Empleado(string nom, int ed, float suel) : Persona(nom, ed)
{
	sueldo = suel;
}

//Constructor de la clase Estudiante (clase Hija - Padre)
Estudiante::Estudiante(string nom, int ed, float nFinal) : Persona(nom, ed)
{
	notaFinal = nFinal;
}

//Constructor de la clase Universitario (clase Hija)
Universitario::Universitario(string nom, int ed, float nFinal, string carre) : Estudiante(nom, ed, nFinal)
{
	carrera = carre;
}

void Persona::mostrarPersona()
{
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}

void Empleado::mostrarEmpleado()
{
	mostrarPersona();
	cout<<"Sueldo: "<<sueldo<<endl;
}

void Estudiante::mostrarEstudiante()
{
	mostrarPersona();
	cout<<"Nota Final: "<<notaFinal<<endl;
}

//Esta es una herencia multiple
void Universitario::mostrarUniversitario()
{
	mostrarEstudiante();
	cout<<"Carrera: "<<carrera<<endl;
}

int main()
{
	Empleado empleado1("Paty", 38, 20000);
	cout<<"== Empleado =="<<endl;
	empleado1.mostrarEmpleado();
	cout<<"\n";
	
	Estudiante estudiante1("Carlos", 19, 8.5);
	cout<<"== Estudiante =="<<endl;
	estudiante1.mostrarEstudiante();
	cout<<"\n";
	
	Universitario universitario1("Manuel", 20, 9.5, "ICI");
	cout<<"== Universitario =="<<endl;
	universitario1.mostrarUniversitario();
	cout<<"\n";
	
	//system("pause");	//Para pausar o detener la pantalla y que no se cierre
	return 0;
}