#include <iostream>

using namespace std;

class persona{
	private: 
		string nombre;
		int edad;
		float peso;
		float altura;
	public:
		persona(string, int, float, float);
		void mostrarPersona();
	
};

class empleado : public persona
{
	private:
		string puesto;
		float salario;
	public:
		empleado(string, int, float, float, string, float);
		void mostrarempleado();			
};

class estudiante : public persona{
	private:
		string carrera;
		float promedio;
	public:
		estudiante(string, int, float, float, string, float);
		void mostrarestudiante();
};

persona::persona(string nom, int ed, float pes, float alt){
	nombre = nom;
	edad = ed;
	peso = pes;
	altura = alt;
}

empleado::empleado(string nom, int ed, float pes, float alt, string pues, float salar) : persona(nom, ed, pes, alt){
	puesto = pues;
	salario = salar;
}

estudiante::estudiante(string nom, int ed, float pes, float alt, string car, float prom) : persona(nom, ed, pes, alt){
	carrera = car;
	promedio = prom;
}

void persona::mostrarPersona(){
	cout << "Nombre: " << nombre << endl;
	cout << "Edad: " << edad << endl;
	cout << "Peso: " << peso  << " kg"<< endl;
	cout << "Altura: " << altura << " m" << endl;
}

void empleado::mostrarempleado(){
	mostrarPersona();
	cout << "Puesto: " << puesto << endl;
	cout << "Salario: $" << salario << endl;
}

void estudiante::mostrarestudiante(){
	mostrarPersona();
	cout << "Carrera: " << carrera << endl;
	cout << "Promedio: " << promedio << endl;
}

int main(){
	empleado empleado1("Carlos Sebastian Yañez Solano", 18, 75.6, 1.86, "Vigilante", 9000);
	empleado1.mostrarempleado();
	system("pause");
	system("cls");
	estudiante estudiante1("Martin Isai Nuñez Villeda", 18, 65.3, 1.73, "Ingenieria en Computacion Inteligente", 9.5);
	estudiante1.mostrarestudiante();
	system("pause");
	return 0;
}

	

