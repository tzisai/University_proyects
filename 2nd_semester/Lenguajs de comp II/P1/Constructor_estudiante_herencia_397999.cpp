/*  
Martin Isai nuñez Villeda ICI 2do semestre 
Carlos Sebastian Yañez Solano

obejtivo:crea una clase padre con 2 clases hijas 

15 de febrero de 2024

*/
#include <locale.h>
#include <iostream>
using namespace std;

class Persona   //Clase padre o superclase
{
	private:	//Atributos
		string nombre;
		int edad;
		float peso,altura;
		
	public:	//Metodos
	
		Persona(string,int,float,float);	//Metodo Constructor de la clase padre Persona
		void mostrarPersona();
};

class empleado:public Persona{
	private:
		float salario; 
		string puesto;
	public:
		empleado(string,int,float,float,float,string);
		void mostrar_empleado();
		~empleado();
};

class estudiante:public Persona{
	private:
		string carrera;
		float promedio;
	public:
		estudiante(string,int,float,float,string,float);
 		void mostrar_alumno();
		~estudiante(); 
};

estudiante::~estudiante(){
	cout << "Eliminado el estudiante" << endl;
}

empleado::~empleado(){
	cout << "Eliminado el empleado" << endl;
}

Persona::Persona(string nom, int eda, float pes, float alt){
	
	nombre=nom;
	edad=eda;
	peso=pes;
	altura=alt;

}

empleado::empleado(string nom, int eda, float pes, float alt,float sal,string pue):Persona(nom,eda,pes,alt){
	
salario=sal;
puesto=pue;

}

estudiante::estudiante(string nom, int eda, float pes, float alt,string carr,float prom):Persona(nom,eda,pes,alt){
carrera=carr;
promedio=prom;

}

void Persona::mostrarPersona(){
	cout << "Nombre : " << nombre << endl;
	cout << "Edad : " << edad << endl;
	cout << "Peso : " << peso  << " kg"<< endl;
	cout << "Altura : " << altura << " m" << endl;
}

void empleado::mostrar_empleado(){
	
	cout << "\t\tEmpleado"<< endl;
	cout << "Puesto : " << puesto << endl;
	cout << "Salario : " << salario <<" mxn"<< endl;
	mostrarPersona();
	
}

void estudiante::mostrar_alumno(){
	
	cout << "\t\tEstudiante"<< endl;
	cout << "Carrera : " << carrera << endl;
	mostrarPersona();
	cout << "Promedio : " << promedio << endl;
	
}

int main(){
	setlocale(LC_ALL," ");
	estudiante est ("Martin Isai Nuñez",19,56.78,1.73,"ICI",9.0);
	est.mostrar_alumno();
	system("pause");
	system("cls");
	
	empleado emp ("Carlos Sebastian Yañez Solano", 18, 75.6, 1.86, 9000,"Vigilante");
	emp.mostrar_empleado();
	system("pause");
	system("cls");
	
	return 0;
}
