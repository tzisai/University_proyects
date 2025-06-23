#include <iostream>
#include <cmath>

using namespace std;

class Figura {
protected:
    float area;
    float perimetro;

public:
    Figura();
    virtual ~Figura();
    virtual void CalcularArea() = 0;
    virtual void CalcularPerimetro() = 0;
    virtual void mostrar();
};

class Rectangulo : public Figura {
protected:
    float base;
    float altura;

public:
    Rectangulo(float, float);
    ~Rectangulo();
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
    float radio;

public:
    Circulo(float);
    ~Circulo();
    void CalcularArea();
    void CalcularPerimetro();
    void mostrar() override;
};

class Triangulo : public Figura {
protected:
    float lado1;
    float alturat;

public:
    Triangulo(float, float);
    ~Triangulo();
    void CalcularArea();
    void CalcularPerimetro();
    void mostrar();
};

Figura::Figura(){
	area = 0;
	perimetro = 0;
}

Figura::~Figura() {
    cout << "Destruyendo figura..." << endl;
}

void Figura::mostrar() {
    cout << "Área: " << area << endl;
    cout << "Perímetro: " << perimetro << endl;
}

Rectangulo::Rectangulo(float _base, float _altura) {
	base = _base;
	altura = _altura;
}

Rectangulo::~Rectangulo() {
    cout << "Destruyendo rectángulo..." << endl;
}

void Rectangulo::CalcularArea() {
    area = base * altura;
}

void Rectangulo::CalcularPerimetro() {
    perimetro = 2 * (base + altura);
}

void Rectangulo::mostrar() {
    cout << "Rectángulo:" << endl;
    Figura::mostrar();
}

Cuadrado::Cuadrado(float lado) : Rectangulo(lado, lado) {}

Cuadrado::~Cuadrado() {
    cout << "Destruyendo cuadrado..." << endl;
}

Circulo::Circulo(float r) : radio(r) {}

Circulo::~Circulo() {
    cout << "Destruyendo círculo..." << endl;
}

void Circulo::CalcularArea() {
    area = 3.1416 * radio * radio;
}

void Circulo::CalcularPerimetro() {
    perimetro = 2 * 3.1416 * radio;
}

void Circulo::mostrar() {
    cout << "Círculo:" << endl;
    Figura::mostrar();
}

Triangulo::Triangulo(float _lado1, float _alturat) {
	lado1 = _lado1;
	alturat = _alturat;
}

Triangulo::~Triangulo() {
    cout << "Destruyendo triángulo..." << endl;
}

void Triangulo::CalcularArea() {
    float s = (lado1 + lado1 + lado1) / 2;
    area = (lado1 * alturat) / 2;
}

void Triangulo::CalcularPerimetro() {
    perimetro = lado1 + lado1 + lado1;
}

void Triangulo::mostrar() {
    cout << "Triángulo:" << endl;
    Figura::mostrar();
}

int main() {
    int opcion;
    float lado, lado1, altura, radio, base;

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
            case 1: {
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
                cout << "Ingrese el lado del cuadrado: ";
                cin >> lado;
                Cuadrado cuadrado(lado);
                cuadrado.CalcularArea();
                cuadrado.CalcularPerimetro();
                cuadrado.mostrar();
                break;
			}
            case 3: {
            	cout << "Ingrese el radio del círculo: ";
                cin >> radio;
                Circulo circulo(radio);
                circulo.CalcularArea();
                circulo.CalcularPerimetro();
                circulo.mostrar();
                break;
			}
            case 4: {
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

