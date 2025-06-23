#include <iostream>
#include <string>

class Animal {    
protected:
    int edad;
    
public:
    Animal(int ed) : edad(ed) {}
    virtual ~Animal() {}
    virtual void comer() = 0; // Método virtual puro
};

class Humano: public Animal {
private:
    std::string nombre;
            
public:
    Humano(int ed, std::string nom) : Animal(ed), nombre(nom) {}
    void comer() override;
};

class Perro: public Animal {
private:
    std::string raza, nombre;
public:
    Perro(int ed, std::string raz, std::string nom) : Animal(ed), raza(raz), nombre(nom) {}
    void comer() override;
};

void Humano::comer() {
    std::cout << nombre << " el humano come con la cuchara\n";
    std::cout << "     _______     \n"
              << "    /       \\    \n"
              << "   /         \\   \n"
              << "  |           |  \n"
              << "  |           |  \n"
              << "  |           |  \n"
              << "  |           |  \n"
              << "  |___________|  \n"
              << "       | |       \n"
              << "       | |       \n"
              << "       | |       \n"
              << "       | |       \n"
              << "       | |       \n"
              << "       | |       \n"
              << "       | |       \n"
              << "       | |      \n"
              << "       | |      \n"
              << "         |||    \n";
}

void Perro::comer() {
    std::cout << nombre << " el " << raza << " El perro come en su plato" << std::endl;
    std::cout << "  / \\__\n"
              << " (    @\\___\n"
              << " /         O\n"
              << "/   (_____/\n"
              << "/_____/ U\n"
              << "             ||||||||||\n";
}

int main() {
    Perro p0(2, "Husky", "Otho");
    Humano H0(19, "Martin Isai Nunez Villeda");
    
    p0.comer();
    H0.comer();
    
    return 0;
}
