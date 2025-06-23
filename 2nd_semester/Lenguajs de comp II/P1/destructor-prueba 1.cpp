#include <iostream>
using namespace std;

class parangatirimicuaro{
private:
    int tamanio, edad;
    string nombre;
public:
    parangatirimicuaro(int, int, string);
    ~parangatirimicuaro();
    void parangatiricuarizar();
    void volar();
    void stats();
};

parangatirimicuaro::parangatirimicuaro(int tam, int ed, string nom){
    tamanio = tam;
    edad = ed;
    nombre = nom;
}

parangatirimicuaro::~parangatirimicuaro(){
    cout << "los parangatirimicuaros se estan desparangatirimicuarisando los pobres ya no podra parangatirimicuarizar una pena para los pararangatirimucuaros\n";
}

void parangatirimicuaro::parangatiricuarizar(){
    cout << nombre << " el parangatirimicuaro esta parangatirimicuarizando cuidado podrian parangatiricuarizar a todo el mundo!!!\n";
}

void parangatirimicuaro::volar(){
    cout << nombre << " esta volando mira que majestuoso se ve \n";
}

void parangatirimicuaro::stats(){
    cout << nombre << " mide: " << tamanio << " cm de largo y tiene " << edad << " meses de edad" << endl;
}

int main(){
    parangatirimicuaro p1(37, 16, "Isa");
    parangatirimicuaro p2(26, 10, "Eli");

    p1.stats();
    p1.volar();
    p1.parangatiricuarizar();

    p2.stats();
    p2.volar();
    p2.parangatiricuarizar();

    system("pause");
    return 0;
}