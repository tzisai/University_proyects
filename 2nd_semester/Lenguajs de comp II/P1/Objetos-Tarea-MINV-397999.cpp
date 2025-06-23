//Martin Isai Nuñez Villeda ICI 2do semestre
//8 de febrero de 2024
//Objetivo:crea un programa en dogma de POO que regrese la area y el perimetro de un rectangulo.
#include <iostream>

using namespace std;
//creacion de clase
class rectangular{
	private://atributos
		int base;
		int altura;
	
	public://metodos
		rectangular(int,int);//constructor
		void area(int,int);
		void perimetro(int,int);
	
};
//constructor e inicializacion
rectangular::rectangular(int basesota,int alturota){
	base=basesota;
	altura=alturota;
}
//metodo area(calcula el area de el rectangulo).
void rectangular::area(int B,int A){
		int base=B;
		int altura=A;
		int	AreA=base*altura;
		cout<<"La base de el rectangulo es de: "<<AreA<<endl;
}
//metodo perimetro (calcula el perimetro de el rectangulo).
void rectangular::perimetro(int B,int A){
		int base=B;
		int altura=A;
		int Perimetro=(base*2)+(altura*2);
		cout<<"El perimetro del rectangulo es de: "<<Perimetro<<endl;
}

int main(){
	//pedido de datos al usario.
	int bas,alt;
	cout<<"Ingresa la base de el cuadrado:\n";
	cin>>bas;
	cout<<"Ingresa la altura de el cuadrado:\n";
	cin>>alt;
	//construccion de objeto
	rectangular rectangulo1 (bas,alt);
	//uso de metodos
	rectangulo1.area(bas,alt);
	rectangulo1.perimetro(bas,alt);
	
	system("Pause");
	
	return 0;
}