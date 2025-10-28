#include <vector>
#include <string>
#include <iostream>
using namespace std;
/*
Universidad Autonoma del estado de Aguascalientes 
Cienias basicas
Ciencias de la computacion 
Opotimizacion
Martin Isai Nuñez Villeda
Luis Fernando Gutierrez Marfileño

Algoritmo genetico que encuentra la solucion al problema de las 8 torres en un tablero sin chocar.
*/
struct Individuo{
	string genes;
	int fitnes;
};

vector<Individuo> crear_poblacion() {
    vector<Individuo> poblacion(poblacion_N);
    for (int i = 0; i <poblacion_N; i++) {
        Individuo ind;
        ind.genoma.resize(8);
        for (int j = 0; j < 8; j++) {
            ind.genoma[j] = rand() % 9; 
        }
        ind.aptitud = evaluacion(ind);
        poblacion[i] = ind;
    }
    return poblacion;
}

int evaluacion(Individuo &ind){
	int fitnes=24;
	for(int i=0;i<8;i++){
		for(int j=0;j<4){
		if(ind.genes[i]== ind.genes[j])
		fitnes--;
			}
		}
	}
	return fitnes;
}


Individuo torneo(vector<Individuo> &poblacion){
	int rand1 = rand()% 9;
	int rand2 = rand()% 9;
	
	if(poblacion(rand1).fitnes>=poblacion(rand2).fitnes){
		return poblacion[rand1];
	}
	else{
		return poblacion[rand2];
	}
}

string cruzamiento(vector<individuo> &poblacion){
	
	mejor_ind1=torneo(poblacion);
	mejor_ind2=torneo(poblacion);
	
	for (int i = 0;i<8;i++){
		
	}
	
}


int main (){
	
	int poblacion_N=50;
	
	int generaciones=10;
	int n_hijos=10;
	
	vector<individuo> poblacion=crear_poblacion();
	
	return 0;
}