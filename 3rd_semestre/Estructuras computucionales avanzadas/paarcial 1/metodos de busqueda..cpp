#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <stack>
#include <algorithm> 

/*

a. Universidad Autonoma delEstado de Aguascalientes
b. Ingenieria en Computacion Inteligente
c. Inteligencia Artificial

d. 	Martin Isai Nuñez VIlleda		Alan Fernando Martinez Moreno 
	Pablo David Perez Lopez 		Eduardo Isai Lopez Garcia
	Jesus Yocsan LUevano Flores		Dairon Tadeo Garcia Medina	
	
e. Profesor Francisco Javier Luna Rosas
f. En base en un mapa de ciudades representado en un grafo poner en practica los metodos de busqueda vistos en clase 
		informados y no informados.

*/

using namespace std;


double heuristica(string ciudad1, string ciudad2) {
    // Ejemplo simple: usando una función que devuelva una estimación constante.
    // En realidad, podrías implementar la distancia Euclidiana si tienes las coordenadas.
    return 0.9; // Esta es solo una muestra, ajusta según tu estimación.
}


class Nodo {
public:
    string nombre;
    unordered_map<Nodo*, int> vecinos;

    Nodo(string nombre) : nombre(nombre) {}

    void agregarVecino(Nodo* vecino, int distancia) {
        vecinos[vecino] = distancia;
    }
};

class Grafo {
public:
    unordered_map<string, Nodo*> nodos;

    Nodo* agregarNodo(string nombre) {
        Nodo* nodo = new Nodo(nombre);
        nodos[nombre] = nodo;
        return nodo;
    }

    Nodo* obtenerNodo(string nombre) {
        return nodos[nombre];
    }

    ~Grafo() {
        for (auto& par : nodos) {
            delete par.second;
        }
    }

	void AEstrella(string inicio, string objetivo) {
    if (nodos.find(inicio) == nodos.end() || nodos.find(objetivo) == nodos.end()) {
        cout << "Uno de los nodos no existe en el grafo." << endl;
        return;
    }

    Nodo* nodoInicio = obtenerNodo(inicio);
    Nodo* nodoObjetivo = obtenerNodo(objetivo);

    priority_queue<pair<double, Nodo*>, vector<pair<double, Nodo*>>, greater<>> frontera;
    frontera.push({0.0, nodoInicio});

    unordered_map<Nodo*, double> g;
    unordered_map<Nodo*, Nodo*> cameFrom;

    g[nodoInicio] = 0.0;

    while (!frontera.empty()) {
        Nodo* actual = frontera.top().second;
        frontera.pop();

        if (actual == nodoObjetivo) {
            // Reconstruir el camino
            vector<string> path;
            while (actual != nullptr) {
                path.push_back(actual->nombre);
                actual = cameFrom[actual];
            }
            reverse(path.begin(), path.end());
            cout << "Camino encontrado: ";
            for (const string& ciudad : path) {
                cout << ciudad << " ";
            }
            cout << endl;
            return;
        }

        for (auto& vecino : actual->vecinos) {
            double nuevoCosto = g[actual] + vecino.second;
            if (g.find(vecino.first) == g.end() || nuevoCosto < g[vecino.first]) {
                g[vecino.first] = nuevoCosto;
                double prioridad = nuevoCosto + heuristica(vecino.first->nombre, objetivo);
                frontera.push({prioridad, vecino.first});
                cameFrom[vecino.first] = actual;
            }
        }
    }

    cout << "No se encontró un camino desde " << inicio << " hasta " << objetivo << "." << endl;
}

	

    void BFS(string raiz, string objetivo) {
        if (nodos.find(raiz) == nodos.end()) {
            cout << "El nodo raíz " << raiz << " no existe en el grafo." << endl;
            return;
        }

        Nodo* nodoRaiz = obtenerNodo(raiz);
        queue<Nodo*> cola;
        unordered_set<string> visitados;
        vector<string> recorrido;

        cola.push(nodoRaiz);
        visitados.insert(nodoRaiz->nombre);

        cout << "Recorrido BFS desde " << raiz << ":" << endl;

        while (!cola.empty()) {
            Nodo* actual = cola.front();
            cola.pop();
            recorrido.push_back(actual->nombre);

            if (actual->nombre == objetivo) {
                cout << "Nodo objetivo " << objetivo << " encontrado." << endl;
                cout << "Recorrido realizado: ";
                for (const string& nodo : recorrido) {
                    cout << nodo << " ";
                }
                cout << endl;
                return;
            }

            for (auto& vecino : actual->vecinos) {
                if (visitados.find(vecino.first->nombre) == visitados.end()) {
                    cola.push(vecino.first);
                    visitados.insert(vecino.first->nombre);
                }
            }
        }

        cout << "Nodo objetivo " << objetivo << " no encontrado." << endl;
        cout << "Recorrido realizado: ";
        for (const string& nodo : recorrido) {
            cout << nodo << " ";
        }
        cout << endl;
    }

    void DFS(string raiz, string objetivo) {
        if (nodos.find(raiz) == nodos.end()) {
            cout << "El nodo raíz " << raiz << " no existe en el grafo." << endl;
            return;
        }

        Nodo* nodoRaiz = obtenerNodo(raiz);
        stack<Nodo*> pila;
        unordered_set<string> visitados;
        vector<string> recorrido;

        pila.push(nodoRaiz);

        cout << "Recorrido DFS desde " << raiz << ":" << endl;

        while (!pila.empty()) {
            Nodo* actual = pila.top();
            pila.pop();

            if (visitados.find(actual->nombre) == visitados.end()) {
                recorrido.push_back(actual->nombre);
                visitados.insert(actual->nombre);

                if (actual->nombre == objetivo) {
                    cout << "Nodo objetivo " << objetivo << " encontrado." << endl;
                    cout << "Recorrido realizado: ";
                    for (const string& nodo : recorrido) {
                        cout << nodo << " ";
                    }
                    cout << endl;
                    return;
                }

                for (auto& vecino : actual->vecinos) {
                    if (visitados.find(vecino.first->nombre) == visitados.end()) {
                        pila.push(vecino.first);
                    }
                }
            }
        }

        cout << "Nodo objetivo " << objetivo << " no encontrado." << endl;
        cout << "Recorrido realizado: ";
        for (const string& nodo : recorrido) {
            cout << nodo << " ";
        }
        cout << endl;
    }
};

int main() {
    Grafo grafo;
	int elecct;
    vector<string> nombresCiudades = {
        "International Falls", "Grand Forks", "Bemidji", "Duluth", "Fargo", 
        "St. Cloud", "Minneapolis", "Wausau", "Green Bay", "Sioux Falls", 
        "Rochester", "Dubuque", "LaCrosse", "Madison", "Milwaukee", 
        "Chicago", "Rockford"
    };

    for (const string& nombre : nombresCiudades) {
        grafo.agregarNodo(nombre);
    }

    grafo.obtenerNodo("International Falls")->agregarVecino(grafo.obtenerNodo("Grand Forks"), 278);
    grafo.obtenerNodo("International Falls")->agregarVecino(grafo.obtenerNodo("Bemidji"), 166);
    grafo.obtenerNodo("International Falls")->agregarVecino(grafo.obtenerNodo("Duluth"), 224);
	
    grafo.obtenerNodo("Grand Forks")->agregarVecino(grafo.obtenerNodo("International Falls"), 278);
    grafo.obtenerNodo("Grand Forks")->agregarVecino(grafo.obtenerNodo("Bemidji"), 169);
    grafo.obtenerNodo("Grand Forks")->agregarVecino(grafo.obtenerNodo("Fargo"), 118);
	
    grafo.obtenerNodo("Bemidji")->agregarVecino(grafo.obtenerNodo("Grand Forks"), 169);
    grafo.obtenerNodo("Bemidji")->agregarVecino(grafo.obtenerNodo("International Falls"), 166);
    grafo.obtenerNodo("Bemidji")->agregarVecino(grafo.obtenerNodo("Duluth"), 223);
    grafo.obtenerNodo("Bemidji")->agregarVecino(grafo.obtenerNodo("St. Cloud"), 2440);
	
    grafo.obtenerNodo("Duluth")->agregarVecino(grafo.obtenerNodo("International Falls"), 224);
    grafo.obtenerNodo("Duluth")->agregarVecino(grafo.obtenerNodo("Bemidji"), 223);
    grafo.obtenerNodo("Duluth")->agregarVecino(grafo.obtenerNodo("Minneapolis"), 220);

    grafo.obtenerNodo("Fargo")->agregarVecino(grafo.obtenerNodo("Grand Forks"), 118);
    grafo.obtenerNodo("Fargo")->agregarVecino(grafo.obtenerNodo("St. Cloud"), 2471);
    grafo.obtenerNodo("Fargo")->agregarVecino(grafo.obtenerNodo("Sioux Falls"), 370);
	
    grafo.obtenerNodo("St. Cloud")->agregarVecino(grafo.obtenerNodo("Bemidji"), 2440);
    grafo.obtenerNodo("St. Cloud")->agregarVecino(grafo.obtenerNodo("Minneapolis"), 2140);
    grafo.obtenerNodo("St. Cloud")->agregarVecino(grafo.obtenerNodo("Fargo"), 2471);
	
    grafo.obtenerNodo("Minneapolis")->agregarVecino(grafo.obtenerNodo("Duluth"), 220);
    grafo.obtenerNodo("Minneapolis")->agregarVecino(grafo.obtenerNodo("St. Cloud"), 2140);
    grafo.obtenerNodo("Minneapolis")->agregarVecino(grafo.obtenerNodo("Rochester"), 1265);
    grafo.obtenerNodo("Minneapolis")->agregarVecino(grafo.obtenerNodo("LaCrosse"), 995);
    grafo.obtenerNodo("Minneapolis")->agregarVecino(grafo.obtenerNodo("Wausau"), 286);
	
    grafo.obtenerNodo("Wausau")->agregarVecino(grafo.obtenerNodo("Green Bay"), 137);
    grafo.obtenerNodo("Wausau")->agregarVecino(grafo.obtenerNodo("Minneapolis"), 286);
	
    grafo.obtenerNodo("Green Bay")->agregarVecino(grafo.obtenerNodo("Wausau"), 137);
    grafo.obtenerNodo("Green Bay")->agregarVecino(grafo.obtenerNodo("Milwaukee"), 164);
    grafo.obtenerNodo("Green Bay")->agregarVecino(grafo.obtenerNodo("LaCrosse"), 991);
	
    grafo.obtenerNodo("Sioux Falls")->agregarVecino(grafo.obtenerNodo("Fargo"), 330);
    grafo.obtenerNodo("Sioux Falls")->agregarVecino(grafo.obtenerNodo("Rochester"), 1543);
	
    grafo.obtenerNodo("Rochester")->agregarVecino(grafo.obtenerNodo("Minneapolis"), 1265);
    grafo.obtenerNodo("Rochester")->agregarVecino(grafo.obtenerNodo("Sioux Falls"), 1543);
    grafo.obtenerNodo("Rochester")->agregarVecino(grafo.obtenerNodo("Dubuque"), 1065);
    grafo.obtenerNodo("Rochester")->agregarVecino(grafo.obtenerNodo("LaCrosse"), 1447);
	
    grafo.obtenerNodo("Dubuque")->agregarVecino(grafo.obtenerNodo("Rochester"), 1065);
    grafo.obtenerNodo("Dubuque")->agregarVecino(grafo.obtenerNodo("LaCrosse"), 721);
    grafo.obtenerNodo("Dubuque")->agregarVecino(grafo.obtenerNodo("Rockford"), 132);
	
    grafo.obtenerNodo("LaCrosse")->agregarVecino(grafo.obtenerNodo("Minneapolis"), 995);
    grafo.obtenerNodo("LaCrosse")->agregarVecino(grafo.obtenerNodo("Rochester"), 1447);
    grafo.obtenerNodo("LaCrosse")->agregarVecino(grafo.obtenerNodo("Dubuque"), 721);
    grafo.obtenerNodo("LaCrosse")->agregarVecino(grafo.obtenerNodo("Madison"), 804);
    grafo.obtenerNodo("LaCrosse")->agregarVecino(grafo.obtenerNodo("Green Bay"), 991);
	
    grafo.obtenerNodo("Madison")->agregarVecino(grafo.obtenerNodo("LaCrosse"), 804);
    grafo.obtenerNodo("Madison")->agregarVecino(grafo.obtenerNodo("Milwaukee"), 120);
    grafo.obtenerNodo("Madison")->agregarVecino(grafo.obtenerNodo("Rockford"), 93);
	
    grafo.obtenerNodo("Milwaukee")->agregarVecino(grafo.obtenerNodo("Green Bay"), 164);
    grafo.obtenerNodo("Milwaukee")->agregarVecino(grafo.obtenerNodo("Madison"), 120);
    grafo.obtenerNodo("Milwaukee")->agregarVecino(grafo.obtenerNodo("Chicago"), 131);
	
    grafo.obtenerNodo("Chicago")->agregarVecino(grafo.obtenerNodo("Milwaukee"), 131);
    grafo.obtenerNodo("Chicago")->agregarVecino(grafo.obtenerNodo("Rockford"), 128);
	
    grafo.obtenerNodo("Rockford")->agregarVecino(grafo.obtenerNodo("Dubuque"), 132);
    grafo.obtenerNodo("Rockford")->agregarVecino(grafo.obtenerNodo("Madison"), 93);
    grafo.obtenerNodo("Rockford")->agregarVecino(grafo.obtenerNodo("Chicago"), 128);

 	 /*
 	 esta madre la hize pa ver que los pinches vecinos si jalaran pero pues xd 
    grafo.obtenerNodo("Bemidji")->mostrarVecinos();
    grafo.obtenerNodo("Duluth")->mostrarVecinos();
    grafo.obtenerNodo("Minneapolis")->mostrarVecinos();
    */ 
    
    
    do{
    	system("cls");
    cout<<"Elija oportunamente"<<endl;
    cout<<"Busqueda en Anchura(1)"<<endl;
    cout<<"Busqueda en Profunduidad(2)"<<endl;
    cout<<"Hill Climbing(3)"<<endl;
    cout<<"Best-First(4)"<<endl;
    cout<<"Beam search(5)"<<endl;
    cout<<"A*(6)"<<endl;
    cout<<"Salir(7)"<<endl;
    
    cin>>elecct;
    string start,goal;	
    switch(elecct){
    	case 1:{
    	cout<<"Ingresa que ciudad será el punto de partida"<<endl;
    	cin>>start;
		cout<<"Ingresa la ciudad destino"<<endl;	
		cin>>goal;
		grafo.BFS("International Falls", "Chicago");
		system("PAUSE");
			break;
		}
    		
    	case 2:{
    		cout<<"Ingresa que ciudad será el punto de partida"<<endl;
    	cin>>start;
		cout<<"Ingresa la ciudad destino"<<endl;	
		cin>>goal;
		grafo.DFS(start, goal);
		system("PAUSE");
			break;
		}
    	
    	case 3:{
    		
			break;
		}
		
		case 4:{
			
			break;
		}
		
		case 5:{
			
			break;
		}
		
		case 6:{
		    cout << "Ingresa que ciudad será el punto de partida" << endl;
		    cin >> start;
		    cout << "Ingresa la ciudad destino" << endl;
		    cin >> goal;
		    grafo.AEstrella(start, goal);
		    system("PAUSE");
		    break;
		}

		case 7:{
			exit(0);
			break;
		}
    	
	    
	    default:{
		cout<<"Ingresa una opcion valida"<<endl;	
			break;
		}
		
	}	
	
	}while(elecct<7||elecct>1);
    
    return 0;
}
