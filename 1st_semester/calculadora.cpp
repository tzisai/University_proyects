//Martin Isai Nuñez Villeda ICI 1er semestre 22 de oct de 2023
//Objetivo: hacer una calculadora con menu haciendo uso de las 4 tipos de funciones.





#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

long double factorial(int n){
					if (n==0) return 1;
					return n*factorial(n-1);
					}
					
int lecturanum(int e){
		int input=0;
		printf("dame el %d numero a operar\n",e+1);
		scanf("%d",&input);
		return(input);	
	}
int numV(){
	int veces=0;
	printf("cuantos numeros vas a ingresar para tu operacion?\n");
	scanf("%d",&veces);
	return(veces);
}
int resultado(float op){
	printf("El resultado es: %f",op);
	getchar();
}

int again(){
	int ch=0;
	printf("quieres hacer el proceso de nuevo?\n");
	printf("1.-si 0.-no\n");
	scanf("%d",&ch);
	return (ch);
}

void menu(){
	system("CLS");
	printf("~~~Calculadora~~~\n");
	 printf("Escriba el simbolo que corresponda dentro de las barras~~~\n");	
	printf("~~~suma o resta |$|\n");		
	printf("~~~multiplicacion |*|\n");
	printf("~~~division |/|\n");
	printf("~~~residuo |%|(solo 2 numeros)\n");
	printf("~~~potencia |^|(1 numero)\n");
	printf("~~~factorial |!|(numero max 12+1)    \n");
	printf("~~~salir|#|				 	 \n");
}

int main(){
	int Mkey=1,key=0;
	int i=0;
	char choose=' ';
	while(Mkey==1){
		menu();
		scanf("%c",&choose);
	switch (choose){
		
	
		case '$':{
			key=1;
			while(key==1){
				int suma=0;
				int n=numV();
				int vect[n];
					for(i=0;i<n;i++){
						vect[i]=lecturanum(i);
					suma=suma+ vect[i];
				}
			resultado(suma);
			key=again();	
			}
			break;
		}
		case '%':{
		int vect[3];			
			for(i=0;i<2;i++){
						vect[i]=lecturanum(i);
				}
		 int res=vect[0]%vect[1];
		 resultado(res);
		 key=again();
			
			break;
		}
		case '*':{
			key=1;
			while(key==1){
				int mult=1;
				int n=numV();
				int vect[n];
					for(i=0;i<n;i++){
						vect[i]=lecturanum(i);
					mult=mult * vect[i];
				}
			resultado(mult);
			key=again();	
			}
			
			break;
		}
		case '/':{
			key=1;
			while(key==1){
				float div=1;
				int n=numV();
				int vect[n];
					for(i=0;i<n;i++){
						vect[i]=lecturanum(i);
					div=div / vect[i];
				}
			resultado(div);
			key=again();	
			}
			break;
		}
		
		case '^':{
			int vect[3];
			key=1;
			int potencia=0;
			while(key==1){
					printf("a que potencia vas a elevar el numero?\n");
					scanf("%d",&potencia);
					printf("ingrese el numero a elevar:\n");
					scanf("%d",&vect[0]);
					int pot=pow(vect[0],potencia);	
			resultado(pot);
			key=again();	
			}
			break;
		}
		
		case'!':{
			key=1;
			while(key==1){
				int num=0;
			printf("Que factorial quieres obtener? escribelo:\n");
			scanf("%d",&num);
			int fact=factorial(num);
			resultado(fact);
			key=again();	
			}		
			break;
		}
		case '#':{
			exit(0);
			break;
		}
	
	default:{
		printf("ingresa un caracter valido\n");
		printf("Presione enter para continuar\n");
		getchar();
		break;
	}
}
}

return 0;	
}
