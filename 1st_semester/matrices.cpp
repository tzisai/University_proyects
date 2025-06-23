#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//Martin Isai Nuñez Villeda ICI 1er semestre 
//crear un progrma en el cual se entienda y explote las propiedades y fundamentos de el uso de matrices dentro del el lengaje C
//siguiendo los lineamientos que se requieran para la entrega.
int main(){
	int Mkey=1;
	
	while(Mkey==1){
	system("cls");
	int key=1;
	int choose=0;
	printf("Elija oprtunamente\n");
	printf("1.-Suma de los elementos de matriz de 4*4 con numeros enteros\n");
	printf("2.-Suma de los elementos de matriz de 4*4 con numeros enteros por fila\n");
	printf("3.-Suma de los elementos de matriz de 4*4 con numeros enteros por columna\n");
	printf("4.-Multiplicación de una matriz de n * n por un escalar\n");
	printf("5.-Suma de dos matrices cuadradas\n");
	printf("6.- Ordenar una matriz de mayor a menor\n");
	printf("7.- Ordenar una matriz de menor a mayor\n");
	printf("8.-Matriz identidad\n");
	printf("9.-Salir\n");
	scanf("%d",&choose);
	
	switch (choose){
		
		case 1:{
	key=1;
	while(key==1){
	int matriz[4][4];
		int acum=0;
		int sum1=0,sum2=0;
			for(int i=0;i<4;i++){
					for(int j=0;j<4;j++){
						printf("introduzaca el valor de [%d][%d]:",i+1,j+1);
						scanf("%d",&matriz[i][j]);
					}	
			}
			
			for(int sum1=0;sum1<4;sum1++){
				for(int sum2=0;sum2<4;sum2++){
				acum=acum+matriz[sum1][sum2];	
				}
			}
			for(int s =0;s<4;s++){
				for( int s1=0;s1<4;s1++){
					printf("[%d] \t",matriz[s][s1]);	
				}
				printf("\n");
			}
			
			printf("Los valores sumado de la matriz son: %d",acum);
			printf("\nQuieres hacer el proceso de nuevo? 1.y/2.n \n");
			scanf("%d",&key);
	}
		break;	
	}
		
	
	
	case 2:{
		key=1;
			while(key==1){
		int filas[4] = {0, 0, 0, 0};
		int matriz[4][4];
			int acum=0;
			int sum1=0,sum2=0;
				for(int i=0;i<4;i++){
						for(int j=0;j<4;j++){
							printf("introduzaca el valor de [%d][%d]:",i+1,j+1);
							scanf("%d",&matriz[i][j]);
						}		
				}
	for(int cont1 =0;cont1<4;cont1++){
		filas[cont1] = 0;
		for(int cont2 =0;cont2<4;cont2++){
			filas[cont1]=filas[cont1]+(matriz[cont1][cont2]);
		}
	}
	
	for(int s =0;s<4;s++){
				for( int s1=0;s1<4;s1++){
					printf("[%d] \t",matriz[s][s1]);	
				}
				printf("\n");
			}
				
				
		for(int f=0;f<4;f++){
			printf("\nla suma de los valores de la fila %d es: %d \n",f+1,filas[f]);
		}
			printf("\nQuieres hacer el proceso de nuevo? 1.y/2.n \n");
			scanf("%d",&key);		
	}
	break;
	}
	case 3:{
		key=1;
			while(key==1){
		int colum[4] = {0, 0, 0, 0};
		int matriz[4][4];
			int acum=0;
			int sum1=0,sum2=0;
				for(int i=0;i<4;i++){
						for(int j=0;j<4;j++){
							printf("introduzaca el valor de [%d][%d]:",i+1,j+1);
							scanf("%d",&matriz[i][j]);
						}	
				}	
	for(int cont1 =0;cont1<4;cont1++){
		colum[cont1] = 0;
		for(int cont2 =0;cont2<4;cont2++){
			colum[cont1]=colum[cont1]+(matriz[cont2][cont1]);
		}
	}
	for(int s =0;s<4;s++){
		for( int s1=0;s1<4;s1++){
			printf("\t [%d] \t",matriz[s][s1]);
			
		}
		printf("\n");
	}
		for(int f=0;f<4;f++){
			printf("la suma de los valores de la columna %d es: %d \n",f+1,colum[f]);
		}
			printf("\nQuieres hacer el proceso de nuevo? 1.y/2.n \n");
			scanf("%d",&key);	
			system("CLS");
	}
		
		break;
	}
	
	case 4:{
		key=1;
		while(key==1){
			int tam = 0,esca = 0,input=0;
		printf("ingrese de que tama%co quiere su matriz\n",164);
		scanf("%d",&tam);
		
		int matriz[tam][tam];
		int matriz2[tam][tam];
		printf("por que numero se va a multiplicar la matriz?\n");
		scanf("%d",&esca);
		
		for(int i=0;i<tam;i++){
			for(int j=0;j<tam;j++){
				printf("ingrese el valor de el valor [%d][%d] de la matriz",i+1,j+1);
				scanf("%d",&input);
				matriz[i][j]=input;
			}
		}
		
		for( int i = 0;i<tam;i++){
			for(int j = 0;j<tam;j++){
				matriz2[i][j]=(matriz[i][j]*esca);
			}
		}
		
		for(int s =0;s<4;s++){
			for( int s1=0;s1<4;s1++){
				printf("\t [%d] \t",matriz[s][s1]);	
			}
			printf("\n");
		}
		
		printf("\n");
		
		for(int s =0;s<4;s++){
			for( int s1=0;s1<4;s1++){
				printf("\t [%d] \t",matriz2[s][s1]);	
			}
			printf("\n");	
		}
		printf("\n");
		printf("el escalar por el que se multiplico la matriz fue: %d",esca);
		
		printf("\nQuieres hacer el proceso de nuevo? 1.y/2.n \n");
			scanf("%d",&key);	
			system("CLS");
		
	}
	break;	
	}
	
	case 5:{
		
		
		while(key==1){
				int tam = 0,input=0;
				printf("ingrese de que tama%co quiere su matriz\n",164);
				scanf("%d",&tam);
				int matriz[tam][tam];
				int matriz2[tam][tam];
				int matriz3[tam][tam];
				
				for(int i=0;i<tam;i++){
					for(int j=0;j<tam;j++){
						printf("ingrese el valor [%d][%d] de la 1er matriz",i+1,j+1);
						scanf("%d",&input);
						matriz[i][j]=input;
			}
		}
				printf("\n");
				
				for(int i=0;i<tam;i++){
					for(int j=0;j<tam;j++){
						printf("ingrese el valor [%d][%d] de la 2da matriz",i+1,j+1);
						scanf("%d",&input);
						matriz2[i][j]=input;
			}
		}
		
				printf("\nLa primer matriz: \n");
				
				for(int i=0;i<tam;i++){
					for(int j=0;j<tam;j++){
						matriz3[i][j]=0;
					matriz3[i][j]=(matriz[i][j]+matriz2[i][j]);		
			}
		}
		
				for(int s =0;s<tam;s++){
					for( int s1=0;s1<tam;s1++){
					printf("[%d] \t",matriz[s][s1]);	
			}
			printf("\n");		
		}
		
				printf("\nLa 2da matriz\n");
		
				for(int s =0;s<tam;s++){
					for( int s1=0;s1<tam;s1++){
						printf("[%d] \t",matriz2[s][s1]);	
			}
			printf("\n");
	}
			printf("\nLa 3er Matriz la suma de la 1era y la 2da es: \n");
		
				for(int s =0;s<tam;s++){
					for( int s1=0;s1<tam;s1++){
						printf("[%d] \t",matriz3[s][s1]);	
			}
						printf("\n");
	}
				printf("\n");
			
			printf("\nQuieres hacer el proceso de nuevo? 1.y/2.n \n");
			scanf("%d",&key);	
			system("CLS");
			
			
		break;
	
		}
	}
	
	
	case 6:{
			
				while(key==1){
				int Sacum=0,acum=0;	
				int tam = 0,input=0;
				int intercambio=0;
				printf("ingrese de que tama%co quiere su matriz\n",164);
				scanf("%d",&tam);
				int matriz[tam][tam];
				int matrizA[tam][tam];
				int vec[tam*tam];
				for(int i=0;i<tam;i++){
					Sacum=i*tam;
					
					for(int j=0;j<tam;j++){
						printf("ingrese el valor [%d][%d] de la matriz",i+1,j+1);
						scanf("%d",&input);						
						matriz[i][j]=input;
						
						vec[j+Sacum]=input;
						
				}
			}
			
			for(int i=0; i<tam*tam; i++){ //Ciclo para la evaluación de posiciones de números
	            for(int j=0; j<tam*tam; j++){ //Ciclo para contar el número de evaluaciones
	                if(vec[j]<vec[j+1]){
	                    intercambio=vec[j];
	                    vec[j]=vec[j+1];
	                    vec[j+1]=intercambio;
	
                }
            }
        }
		
		acum=0;
		for(int i =0;i<tam;i++){
			Sacum=acum*tam;
			acum++;
			for(int j =0;j<tam;j++){	
			matrizA[i][j]=vec[j+Sacum];
			}	
		}
	
	
	printf("La matriz original es:\n");
	for( int i =0; i<tam;i++){
		for(int j =0;j<tam;j++){
			printf("[%d] \t",matriz[i][j]);
		}
		printf("\n");
	}
	
	printf("La matriz ordenada queda\n");
	
	for( int a =0; a<tam;a++){
		for(int b =0;b<tam;b++){
			printf("[%d] \t",matrizA[a][b]);
		}
		printf("\n");
	}
	printf("\n");
			
			printf("\nQuieres hacer el proceso de nuevo? 1.y/2.n \n");
			scanf("%d",&key);	
			system("CLS");
			
}
break;
}

case 7:{
	while(key==1){
				int Sacum=0,acum=0;	
				int tam = 0,input=0;
				int intercambio=0;
				printf("ingrese de que tama%co quiere su matriz\n",164);
				scanf("%d",&tam);
				int matriz[tam][tam];
				int matrizA[tam][tam];
				int vec[tam*tam];
				for(int i=0;i<tam;i++){
					Sacum=i*tam;
					
					for(int j=0;j<tam;j++){
						printf("ingrese el valor [%d][%d] de la matriz",i+1,j+1);
						scanf("%d",&input);						
						matriz[i][j]=input;
						
						vec[j+Sacum]=input;
						
				}
			}
			
			for(int i=0; i<tam*tam; i++){ //Ciclo para la evaluación de posiciones de números
	            for(int j=0; j<tam*tam; j++){ //Ciclo para contar el número de evaluaciones
	                if(vec[j]>vec[j+1]){
	                    intercambio=vec[j];
	                    vec[j]=vec[j+1];
	                    vec[j+1]=intercambio;
	
                }
            }
        }
		
		acum=0;
		for(int i =0;i<tam;i++){
			Sacum=acum*tam;
			acum++;
			for(int j =0;j<tam;j++){	
			matrizA[i][j]=vec[j+Sacum];
			}	
		}
	
	
	printf("La matriz original es:\n");
	for( int i =0; i<tam;i++){
		for(int j =0;j<tam;j++){
			printf("[%d] \t",matriz[i][j]);
		}
		printf("\n");
	}
	
	printf("La matriz ordenada queda\n");
	
	for( int a =0; a<tam;a++){
		for(int b =0;b<tam;b++){
			printf("[%d] \t",matrizA[a][b]);
		}
		printf("\n");
	}
	printf("\n");
			
			printf("\nQuieres hacer el proceso de nuevo? 1.y/2.n \n");
			scanf("%d",&key);	
			system("CLS");
			
}
	break;
}

case 8:{
	key=1;
	while(key==1){
		int tam=0;
	printf("ingrese de que tama%co quiere su matriz\n",164);
				scanf("%d",&tam);
				int matriz[tam][tam];
				
				for(int i=0;i<tam;i++){
					for(int j=0;j<tam;j++){
						if(i==j){
						matriz[i][j]=1;	
						}
						else{
						matriz[i][j]=0;
						}
					}
				}
				
				printf("la matriz identidad queda como:\n");
				
							for( int a =0; a<tam;a++){
					for(int b =0;b<tam;b++){
						printf("[%d] \t",matriz[a][b]);
					}
					printf("\n");
				}
						printf("\nQuieres hacer el proceso de nuevo? 1.y/2.n \n");
				scanf("%d",&key);	
				system("CLS");	
					}
					break;
				}
				case 9:{
					Mkey=0;
					break;
				}
				default :{
					printf("ingrese un numero valido\n");
					system("PAUSE");
					break;
				}

		}

	}
return 0;
}