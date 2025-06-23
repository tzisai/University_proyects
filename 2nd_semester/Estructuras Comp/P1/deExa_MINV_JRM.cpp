//Jorge Reyes Medina
//Martin Isai Nuñez Villeda
//22 de febrero de 2024
//Objetivo:
/* 
Por parejas, construya un programa con POO en C++ que obtenga el área y el perímetro de un Rectángulo, un Cuadrado, un Circulo y un Triángulo. 
(Realice un menú para que el usuario indique cuál figura desea y la ultima opción que sea Salir del menú).

No olvide que debe incluir todos o la mayoría de los conceptos vistos en clases: 
clase, atributos, métodos, método constructor, método destructor, sobrecarga de constructores, objeto (s), get, set, herencia, polimorfismo.
(se uso casi todos)
*/

#include <iostream>
#include <cmath>

using namespace std;

class Figura {
//clase padre que heredara a los demas figuras
protected://atributos propios a heredar a las clases hijas.
    float area;
    float perimetro;

public:
    Figura();//constructor
    virtual ~Figura();//destructor
    //Metodos calculo y mostrar resultados
    virtual void CalcularArea() = 0;
    virtual void CalcularPerimetro() = 0;
    virtual void mostrar();
};

class Rectangulo : public Figura {
protected:
	//atributos propios.
    float base;
    float altura;

public:
    Rectangulo(float, float);//constructor
    ~Rectangulo();//destructor
    //metodos
    void CalcularArea();
    void CalcularPerimetro();
    void mostrar() override;
};

class Cuadrado : public Rectangulo {
public:
    Cuadrado(float);
    ~Cuadrado();
};

class Circulo : public Figura {
protected:
    float radio;//atributos propio solo necesitara este puesto que pi se usara como cons y no se necesita mas

public:
    Circulo(float);//constructor
    ~Circulo();//destructor
    //metodos
    void CalcularArea();
    void CalcularPerimetro();
    void mostrar() override;
};

class Triangulo : public Figura {
protected:
	//atributos propios.
    float lado1;
    float alturat;

public:
    Triangulo(float, float);//constructor
    ~Triangulo();//destructor
    //metodos
    void CalcularArea();
    void CalcularPerimetro();
    void mostrar();
};


//constructor clase a padre
Figura::Figura(){
	area = 0;
	perimetro = 0;
}
//destructor clase padre
Figura::~Figura() {
    cout << "Destruyendo figura..." << endl;
}
//Inicio de declaracion de metodos de figura que se heredará.
void Figura::mostrar() {
    cout << "Área: " << area << endl;
    cout << "Perímetro: " << perimetro << endl;
}
//constructor rectangulo
Rectangulo::Rectangulo(float _base, float _altura) {
	base = _base;
	altura = _altura;
}
//destructor rectangulo
Rectangulo::~Rectangulo() {
    cout << "Destruyendo rectángulo..." << endl;
}
//Inicializacion metodos rectangulo
void Rectangulo::CalcularArea() {
    area = base * altura;
}
//meotodo calculo de perimetro de rectangulo
void Rectangulo::CalcularPerimetro() {
    perimetro = 2 * (base + altura);
}
//metodo mostrar los datos obtenidos
void Rectangulo::mostrar() {
    cout << "Rectángulo:" << endl;
    Figura::mostrar();
}

//constructor cuadrado

Cuadrado::Cuadrado(float lado) : Rectangulo(lado, lado) {}

//destructor cuadrado
Cuadrado::~Cuadrado() {
    cout << "Destruyendo cuadrado..." << endl;
}
//constructor circulo
Circulo::Circulo(float r) : radio(r) {}//constructor de linea especial automatico
//destructor de objeto circulo
Circulo::~Circulo() {
    cout << "Destruyendo círculo..." << endl;
}
//meotodo calcular Area cirulo
void Circulo::CalcularArea() {
    area = 3.1416 * radio * radio;
}
//metodo calcular Area cirulo
void Circulo::CalcularPerimetro() {
    perimetro = 2 * 3.1416 * radio;
}
//mostrar datos obtenidos del circulo
void Circulo::mostrar() {
    cout << "Círculo:" << endl;
    Figura::mostrar();
}
//constructor de el triangulo 
Triangulo::Triangulo(float _lado1, float _alturat) {
	lado1 = _lado1;
	alturat = _alturat;
}
//destructor de triangulo
Triangulo::~Triangulo() {
    cout << "Destruyendo triángulo..." << endl;
}
//meotodo calculara area triangulo
void Triangulo::CalcularArea() {
    float s = (lado1 + lado1 + lado1) / 2;
    area = (lado1 * alturat) / 2;
}
//meotodo calcular perimetro de el triangulo
void Triangulo::CalcularPerimetro() {
    perimetro = lado1 + lado1 + lado1;
}
//mostrar datos del triangulo
void Triangulo::mostrar() {
    cout << "Triángulo:" << endl;
    Figura::mostrar();
}

int main() {
	//declaracion de variables para menu, y las necesarias para asignacion
    int opcion;
    float lado, lado1, altura, radio, base;

    	//menu de seleccion
    do {
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Calcular área y perímetro de Rectángulo" << endl;
        cout << "2. Calcular área y perímetro de Cuadrado" << endl;
        cout << "3. Calcular área y perímetro de Círculo" << endl;
        cout << "4. Calcular área y perímetro de Triángulo" << endl;
        cout << "5. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        	//METODOLOGIA GENERAL PARA TODAS LAS FIGURAS
        	//metodologia de registro de variables pasar a constructor 
        	//Usar metodo de calculos 
        	//Muestro
            case 1: {
            	//caso rectangulo.
                cout << "Ingrese la base del rectángulo: ";
                cin >> base;
                cout << "Ingrese la altura del rectángulo: ";
                cin >> altura;
                Rectangulo rectangulo(base, altura);
                rectangulo.CalcularArea();
                rectangulo.CalcularPerimetro();
                rectangulo.mostrar();
                break;
			}
            case 2: {
            	//caso cuadrado
                cout << "Ingrese el lado del cuadrado: ";
                cin >> lado;
                Cuadrado cuadrado(lado);
                cuadrado.CalcularArea();
                cuadrado.CalcularPerimetro();
                cuadrado.mostrar();
                break;
			}
            case 3: {
    			//caso circulo
            	cout << "Ingrese el radio del círculo: ";
                cin >> radio;
                Circulo circulo(radio);
                circulo.CalcularArea();
                circulo.CalcularPerimetro();
                circulo.mostrar();
                break;
			}
            case 4: {
            		//caso triangulo
				cout << "Ingrese el lado del triángulo: ";
			    cin >> lado1;
			    cout << "Ingrese la altura del triángulo: ";
			    cin >> altura;
			    Triangulo triangulo(lado1, altura);
			    triangulo.CalcularArea();
			    triangulo.CalcularPerimetro();
			    triangulo.mostrar();
			    break;
			}                
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}

