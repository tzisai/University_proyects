
/*ICI Ingenieria en computacion Inteligete 2do Semestre
Martin Isai Nuñez Villeda 
(tu nombre aqui omar)

Objetivo:crea un programa que use la sobrecarga de constructores get & set
fecha 13 de febrero de 2024 
*/
#include <iostream>
using namespace std;

class telefono{
private://atributos
	string marca,modelo,owner;
	int numero,nserie,precio;	
public://metodos
	telefono(string,string,int,int);//info vendedor
	telefono(string,string,string,int,int);//info cliente
	~telefono();

	//metodos
	void prope_Da();
	void getspecs();
	void venta();
	void devolucion();

	 // metodos set
    void setMarca(string);
    void setModelo(string);
    void setOwner(string);
    void setNumero(int);
    void setNSerie(int);
    void setPrecio(int);

    // mwtodos get
    string getMarca();
    string getModelo();
    string getOwner();
    int getNumero();
    int getNSerie();
    int getPrecio();


};

// Implementación de métodos set
void telefono::setMarca(string m) {
    marca = m;
}

void telefono::setModelo(string m) {
    modelo = m;
}

void telefono::setOwner(string o) {
    owner = o;
}

void telefono::setNumero(int n) {
    numero = n;
}

void telefono::setNSerie(int ns) {
    nserie = ns;
}

void telefono::setPrecio(int p) {
    precio = p;
}

// Implementación de métodos get
string telefono::getMarca() {
    return marca;
}

string telefono::getModelo() {
    return modelo;
}

string telefono::getOwner() {
    return owner;
}

int telefono::getNumero() {
    return numero;
}

int telefono::getNSerie() {
    return nserie;
}

int telefono::getPrecio() {
    return precio;
}

//constructor info vendedor
telefono::telefono(string brand,string model,int nser,int price){
	
	marca=brand;
	modelo=model;
	nserie=nser;
	precio=price;
	
	
}
//constructor cliente
telefono::telefono(string due,string brand,string model,int num,int price){
	
	marca=brand;
	owner=due;
	modelo=model;
	numero=num;
	precio=price;
	
}


//destructor
telefono::~telefono(){
	cout<<"\ntramites finalizados con exito!!";

}

//info de telefonos vendidos
void telefono::prope_Da(){
	
cout<<"Comprador: "<<owner<<endl;
cout<<"Modelo comprado: "<<modelo<<endl;
cout<<"Precio de venta: "<<precio<<endl;
cout<<"Numero de telefono: "<<numero<<endl;
}


//Datos de telefono en inventarios
void telefono::getspecs(){
	cout<<"Telefono en venta\n";
	cout<<"MODELO:"<<modelo<<endl;
	cout<<"MARCA:"<<marca<<endl;
	cout<<"NO SERIE: "<<nserie<<endl;
	cout<<"Precio: "<<precio<<endl;
}


int main(){
	int elec;
	
	do{
	system("pause");
	system("CLS");
	string modelo,marca;
	int nserie=0,precio=0;
	
	cout<<"Terminal venta de telefonos CHAFATEL S.A de C.V"<<endl;
	cout<<"que desea hacer ? Seleccione el numero en parentesis oportunamente"<<endl;
	
	cout<<"~~~registrar venta(1)~~~~"<<endl;
	cout<<"~~~inventario(2)~~~~"<<endl;
	cout<<"~~~ventas(3)~~~"<<endl;
	cout<<"~~~Salir(4)~~~"<<endl;
	
	cin>>elec;
	switch(elec){
	case 1:{
		
		telefono V1("a","c",1,9);
		
		cout<<"Ingrese el modelo de la venta\n";
		cin>>modelo;
		V1.setModelo(modelo);
		cout<<"Ingrese la marca de la venta\n";
		cin>>marca;
		V1.setMarca(marca);
		cout<<"Ingrese el no.serie de la venta\n";
		cin>>nserie;
		V1.setNSerie(nserie);
		cout<<"Ingrese el total de la venta\n";
		cin>>precio;
		V1.setPrecio(precio);
		
		V1.getspecs();
		
		break;
		}
	case 2:{
		telefono Inventario1("LG","Lg prime 2",234223,8900);
		Inventario1.getspecs();
		
				break;
	}
	case 3:{
			telefono compra1("Pepe","Motorola","Moto G +",349845,4500);
			cout<<"comprador: "<<compra1.getOwner()<<endl<<"Marca: "<<compra1.getMarca()<<endl<<"Modelo: "<<compra1.getModelo()<<endl<<"numero telefono: "<<compra1.getNumero()<<endl<<"Precio: "<<compra1.getPrecio();
			
		break;
	}
	case 4:{
		break;
		}	
	}
}while(elec!=4);

	return 0;
}