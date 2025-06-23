#include <iostream>
#include <string.h>
using namespace std;

class Animal{	

	protected:		
	int edad;
	
	public:
	Animal(int);//constructor
	~Animal();//destructor	
	virtual void comer();
};	

//Herencia HUMANO
class Humano: public Animal{
	private:
	string nombre;
			
	public:
		//metodos
	Humano(int,string);
	void comer();
};
//HERENCIA PERRO
class Perro: public Animal{
	private:
		//atributos
	string raza;
	string nombre;
	public:
		//metodos
	Perro(int ,string ,string);
	void comer();
};


Animal::Animal(int ed){
	edad=ed;
}

Animal::~Animal(){
cout<<"se extinguio la wea"<<endl;
}

void Animal::comer(){
}

Humano::Humano (int ed,string nom) : Animal(ed){
	nombre=nom;
}


void Humano::comer(){
	Animal::comer();
	cout<<nombre<<"El  humano come con la cuchara\n";
	std::cout << "     _______     \n";
    std::cout << "    /       \\    \n";
    std::cout << "   /         \\   \n";
    std::cout << "  |           |  \n";
    std::cout << "  |           |  \n";
    std::cout << "  |           |  \n";
    std::cout << "  |           |  \n";
    std::cout << "  |___________|  \n";
    std::cout << "       | |       \n";
    std::cout << "       | |       \n";
    std::cout << "       | |       \n";
    std::cout << "       | |       \n";
    std::cout << "       | |       \n";
    std::cout << "       | |       \n";
    std::cout << "       | |       \n";
    std::cout << "       | |      \n";
    std::cout << "       | |      \n";
    std::cout << "    	 |||   \n";
}

Perro::Perro (int ed,string raz,string nom): Animal(ed){
	raza=raz;
	nombre=nom;
}

void Perro::comer(){
	Animal::comer();
	cout<<nombre<<" el "<<raza<<" El perro come en su plato"<<endl;
	cout << "  / \\__\n";
    cout << " (    @\\___\n";
    cout << " /         O\n";
  	cout << "/   (_____/\n";
    cout << "/_____/ U\n";
    cout <<"				|||||||||||\n";
}

int main(){
	
	Perro p0(2,"Husky","Otho");
	Humano H0(19,"Martin Isai Nunez Villeda");
	
	p0.comer();
	H0.comer();
	
	return 0;
}

	
