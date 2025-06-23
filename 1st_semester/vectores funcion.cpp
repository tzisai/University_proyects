//Martin Isai Nuñez Villeda ICI 1er semestre
//Programa que genera un vector de tamaño n y te indica que numero es mayor menor dentro del mismo (funciones).
//9 de noviembre de 2023
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void telefono(long long int tel[]){
		system("CLS");
		int i=0;
		printf("se debe ingresar 2 numeros de telefono de referencia\n");
		for(i=0;i<2;i++){
		printf("(sin 449))Ingrese el [%d] numero de telefono:\n",i+1);
		scanf("%d",&tel[i]);	
		}
}
int Edadmod(int&edad){
	system("CLS");
	printf("ingrese su edad:\n");
		scanf("%d",&edad);
		return edad;
}


void Cvect(int size, int vectoR[]){
		int i =0;
		for (i=0;i<size;i++){
			vectoR[i]= 0;
			vectoR[i]= rand() % 11;
			}
			
		for (i=0;i<size;i++){
			printf("valor generado en la %d posicion: \t[%d]\n",i+1,vectoR[i]);
		}
		printf("\n");
	}
	 
	void NumS(int VecT[]){
	
		
	}
	//sort de insercion 
void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++){
    	printf("%d ", arr[i]);	
	}
}

int main(){
	int chosse=0;
	printf("Elija oportunamente\n");
	printf("1.-Vector por referencia\n");
	printf("2.-programa de vector y variable normal por referenica\n");
	scanf("%d",&chosse);
	switch (chosse){
		case 1:{
				int tam=0;
	
	printf("ingrese de que tama%co de el vector \n",164);
	scanf("%d",&tam);
	int vect[tam];
	Cvect(tam,vect);
	int n = sizeof(vect)/ sizeof(vect[0]);
	
	insertionSort(vect,n);
	printArray(vect, n);
		printf("\n");
    printf("El valor mas peque%co en el vector es: %d \n",164,vect[0]);    
    printf("El valor mas grande en el vector es: %d \n",vect[tam-1]);  
			break;
		}
		
	case 2:{
		char nombre[40];
		long long int tele[40];
		int edadsota=0;
		int elec=0;
		printf("Registro Cartilla Nacional \n");
		printf("ingresa tu nombre(espacios remplazdos por '_' ): \n");
		scanf("%s",&nombre);
		telefono(tele);
		do{
		printf("el valor anterior ingresado es correcto?\n");
		printf("1.-si 0.-no\n");	
		scanf("%d",&elec);
		if(elec==0){
			telefono(tele);
		}
		}while(elec==0);
		
		edadsota=Edadmod(edadsota);
		do{
		printf("el valor anterior ingresado es correcto?\n");
		printf("1.-si 0.-no\n");	
		scanf("%d",&elec);
		if(elec==0){
			edadsota=Edadmod(edadsota);
		}
		}while(elec==0);
		
		printf("Registro exitoso\n");
		printf("Tu nombre es: %s\n",nombre);
		printf("Tu edad es: %d \n",edadsota);
		printf("Tus numeros de telefono de referencia son:  \n");
		printf("%d \n %d",tele[0],tele[1]);
		
		
		break;
	}
			
	}
		
  
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}