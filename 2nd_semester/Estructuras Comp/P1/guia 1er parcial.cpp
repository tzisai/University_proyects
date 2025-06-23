#include <iostream>
#include <string.h>
using namespace std;


void bblsort(int vect[], int act) {
    int intercambiador = 0;
    for (int i = 0; i <= act; i++) {
        for (int j = 0; j <= act - 1; j++) { 
            if (vect[j] > vect[j + 1]) { 
                intercambiador = vect[j]; 
                vect[j] = vect[j + 1];
                vect[j + 1] = intercambiador; 
            }
        }
    }
}

int busqueda(int vec[],int act,int input){
	int ind=-1;
	for(int j=0;j<=act;j++){
		
				if(input==vec[j]){
					return ind=j;
				}
				else{
					return ind=-1;
				}
		}			

}



struct Persona{
	int edad;
	float estatura;
	string nombre;
	char faccion [25];		
	}Persona1={18,1.60,"Elizabeth"}; //definicion de variable y de tipo constante dentro de el mismo struct.
	

int main(){

	//formas de definicion de variable
	struct Persona Persona2;
	Persona Persona3;

	
	//lectura de datos struct
	/* 
	si es de tipo string se usara la funcion y la sintaxis
	 getline(cin, Nombrestruct.Variable);
	
	de otro modo se usaria 
	
	cin>>Nombrestruct.Variable;
	Por ejemplo:
	*/
	
	cin>> Persona2.edad;
	cin>> Persona2.estatura;
	
	// Limpia el búfer después de la entrada de edad
        cin.ignore();
	
	getline(cin,Persona2.nombre);	
	
	cin>>Persona2.faccion;//sin espacios y con char 
	
	
	cout<<Persona2.edad<<endl;
	cout<<Persona2.estatura<<endl;
	cout<<Persona2.nombre<<endl;
	cout<<Persona2.faccion<<endl;
	
	int filas=10,columnas=10,Paginas=10;
	int indice=0;
	//Vectores(ARREGLOS) TIPO IDENTIFICADOR [TAMAÑO] 
	int VectEnteros[indice]={1,2,3,4,5,6,7,8,9,10};//inicializacion de elementos.(vector constante)
	//Llenado y despliegue con ciclos for 
	      
	
	int Matriz [filas][columnas];
	int ArregloTridimensional[Paginas][filas][columnas];
	
	
	//Llenado con la herramienta rand y ciclos for.(puedes usar la mismo para imprimir.
	for(int i=0;i<Paginas;i++){
		for(int j=0;j<filas;j++){
			for(int k=0;k<columnas;k++){
			ArregloTridimensional[i][j][k]=rand() % 20000 + 2000 - 1;
			}
		}
	}
	
	return 0;
}