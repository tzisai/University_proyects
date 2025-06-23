//Trabajo hecho por martin Isai Nuñez Villeda y Pablo David Perez Lopez 
//ICI 1er semestre 4 de octubre de 2023 
#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int chosse=0,Mkey=1,key=1;
	while(Mkey==1){
	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Elija oportunamente: \n");
	printf("1._10 n%cmeros pares maximo y minimo\n",163);
	printf("2._10 numeros, 2 a comparar y que posicion estan.\n");
	printf("3._10 numeros menor a mayor\n");
	printf("4._10 numeros mayor a menor\n");
	printf("5._10 numeros elevados al cuadrado\n");
	printf("6._8 numeros multiplicados por 2.\n");
	printf("7._8 numeros sumados con otros 8 numeros\n");
	printf("8._8 numeros restados con otros 8 numeros\n");
	printf("9._8 numeros multiplicarlos con otros 8 numeros\n");
	printf("10._8 numeros dividirlos con otros 8 numeros\n");
	printf("11._salir");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	scanf("%d",&chosse);
	switch(chosse){
	case 1:{
		while(key==1){
		
			int entero[10];
			int acumP=0,comp=0,pos=0,pos2=0,comp2=0;
			
			for (int i=0;i<10;i++){
			printf("Dame un numero:");
			scanf("%d",&entero[i]);
			if(entero[i]%2==0){
			acumP++;
				}
			}
			comp=entero[0];
			comp2=entero[0];
			for(int e=0;e<10;e++){
			if(entero[e]>=comp){
				comp=entero[e];
				pos=e+1;
			}
			if(entero[e]<=comp2){
				comp2=entero[e];
				pos2=e+1;
			}	
			}
			for(int j =0;j<10;j++){
				
			printf("	 %d",entero[j]);
			}
			printf("\n%d son pares.",acumP);
			printf("\n El numero mas grande es %d su posicion es %d y el mas peque%co es %d y su posicion es %d.\n",comp,pos,164,comp2,pos2);
			printf("Quieres ejecutar de nbuevo el proceso?\n");
			printf("1.-si 0.-no\n");	
			scanf("%d",&key);
			system("PAUSE");
			system ("CLS");
	}
	break;
	}
		
	
	case 2:{
		while(true){
        system("cls");
        float vector[10];
        int i;
        bool bandera1, bandera2;
        printf("Proporcione 10 n%cmeros\n", 163);
        for(i=0; i<10; i++){
            printf("N%cmero %d: ", 163, i+1);
            scanf("%f", &vector[i]);
        }
        float numeros[2];
        printf("Proporcione 2 n%cmeros m%cs: \n", 163, 160);
        for(i=0; i<2; i++){
            printf("N%cmero extra %d: ", 163, i+1);
            scanf("%f", &numeros[i]);
        }
        int pos_rep1,pos_rep2;
        for(i=0; i<10; i++){
            if(numeros[0]==vector[i]){
                pos_rep1=i;
                printf("%.2f se encuentra en el primer vector, en la posici%cn %d\n", numeros[0], 162, pos_rep1+1);
                bandera1=true;
                break;
            }else{
                bandera1=false;
            }
        }
        for(i=0; i<10; i++){
            if(numeros[1]==vector[i]){
                pos_rep2=i;
                printf("%.2f se encuentra en el primer vector, en la posici%cn %d\n", numeros[1], 162, pos_rep2+1);
                bandera2=true;
                break;
            }else{
                bandera2=false;
            }
        }
        if(bandera1==false){
        printf("\nEl n%cmero %f no se encontr%c", 163, numeros[0], 162);
        }
        if(bandera2==false){
            printf("\nEl n%cmero %f no se encontr%c", 163, numeros[1], 162);
        }
        char eleccion;
        printf("\n%cQuiere repetir el programa? [y/n] ");
        while(true){
            scanf("%c", &eleccion);
            if(eleccion=='y' || eleccion=='n'){
                break;
            }else{
                printf("\nSeleccione una opci%Cn v%clida: ", 162, 160);
            }
        }
        if(eleccion=='n'){
            break;
        }
    }
		  
		break;
	}
	case 3:{
		key=1;
		while(key==1){
			printf("cuantos numeros vas a ingresar?\n");
				int n,p=0;
				int a[100];
               scanf("%d",&n);
               for(int i=0;i<n;i++){
               	scanf("%d",&a[i]);
			   }
			   
			     p=n;
				 sort(a,a + p);
				 
				  for (int j = 0; j < n; ++j){
				  	printf("%d ",a[j]);
				  }
				  	printf("Quieres ejecutar de nuevo el proceso?\n");
			printf("1.-si 0.-no\n");	
			scanf("%d",&key);
			system("PAUSE");
			system ("CLS");
			fflush(stdin); 
	}
	break;
}

	case 4:{
		while(true){
        system("cls");
        float numeros[10], intercambio=0;
        int i, j;
        printf("Proporcione 10 n%cmeros:\n", 163);
        for(i=0; i<10; i++){
            printf("N%cmero %d: ", 163, i+1);
            scanf("%f", &numeros[i]);
        }
        for(i=0; i<9; i++){ //Ciclo para la evaluación de posiciones de números
            for(j=0; j<9-i; j++){ //Ciclo para contar el número de evaluaciones
                if(numeros[j]<numeros[j+1]){
                    intercambio=numeros[j];
                    numeros[j]=numeros[j+1];
                    numeros[j+1]=intercambio;
                }
            }
        }
        printf("El vector ordenado queda como:\n");
        for(i=0; i<10; i++){
            printf("%.2f\t", numeros[i]);
        }
        char eleccion;
        printf("\n%cQuiere repetir el programa? [y/n] ");
        while(true){
            scanf("%c", &eleccion);
            if(eleccion=='y' || eleccion=='n'){
                break;
            }else{
                printf("\nSeleccione una opci%Cn v%clida: ", 162, 160);
            }
        }
        if(eleccion=='n'){
            break;
        }
    }
		break;
	}
	case 5:{
		key=1;
		while(key==1){
		
		int Ainput[10],Asqur[10];
		printf("dame 10 numeros:\n");
		for(int i=0;i<=10;i++){
		scanf("%d",&Ainput[i]);
		Asqur[i]=pow(Ainput[i],2);
		}
		for(int i=0;i<10;i++){
			printf("%d ",Asqur[i]);
		}
			printf("Quieres ejecutar de nuevo el proceso?\n");
			printf("1.-si 0.-no\n");	
			scanf("%d",&key);
			system("PAUSE");
			system ("CLS");
			fflush(stdin); 
	}
	break;
	}
	case 6:{
	while(true){
        system("cls");
        float numeros[8], multiplicacion[8];
        int i;
        printf("Proporcione los 8 n%cmeros que desee multiplicar:\n", 163);
        for(i=0; i<8; i++){
            printf("N%cmero %d: ", 163, i+1);
            scanf("%f", &numeros[i]);
        }
        for(i=0; i<8; i++){
            multiplicacion[i]=numeros[i]*2;
        }
        printf("\nLos primeros 8 n%cmeros que proporcion%c fueron:\n", 163, 162);
        for(i=0; i<8; i++){
            printf("%.2f\t", numeros[i]);
        }
        printf("\nLos 8 n%cmeros multiplicados por 2 son:\n", 163);
        for(i=0; i<8; i++){
            printf("%.2f\t", multiplicacion[i]);
        }
        char eleccion;
        printf("\n%cQuiere repetir el programa? [y/n] ");
        while(true){
            scanf("%c", &eleccion);
            if(eleccion=='y' || eleccion=='n'){
                break;
            }else{
                printf("\nSeleccione una opci%Cn v%clida: ", 162, 160);
            }
        }
        if(eleccion=='n'){
            break;
        }
    }
            break;
        }
    
		break;
	
	case 7:{
		while(key==1){
		
		int Arnum8[8],Arnum82[8],ResNum[8];
		printf("dame 8 numeros: \n");
		for (int i=0;i<8;i++){
			scanf("%d",&Arnum8[i]);
		}
		printf("dame otros 8 numeros: \n");
		for (int i=0;i<8;i++){
			scanf("%d",&Arnum82[i]);
			ResNum[i]=Arnum8[i]+Arnum82[i];
		}
		printf("El resultado de las sumas son:\n");
		for(int i=0;i<8;i++){
			printf("%d ",ResNum[i]);
		}
		printf("\nQuieres ejecutar de nbuevo el proceso?\n");
			printf("1.-si 0.-no\n");	
			scanf("%d",&key);
			system("PAUSE");
			system ("CLS");
		break;
	}
}
	case 8:{
		while(true){
        //system("cls");
        float vector1[8], vector2[8], resta[8];
        int i;
        printf("Proporcione los primeros 8 n%cmeros:\n", 163);
        for(i=0; i<8; i++){
            printf("N%cmero %d: ", 163, i+1);
            scanf("%f", &vector1[i]);
        }
        printf("Proporcione los 8 n%cmeros a restar:\n", 163);
        for(i=0; i<8; i++){
            printf("N%cmero %d: ", 163, i+1);
            scanf("%f", &vector2[i]);
        }
        for(i=0; i<8; i++){
            resta[i]=vector1[i]-vector2[i];
        }
        printf("La resta de\n");
        for(i=0; i<8; i++){
            printf("%.2f  ", vector1[i]);
        }
        printf("\ny\n");
        for(i=0; i<8; i++){
            printf("%.2f  ", vector2[i]);
        }
        printf("\nes:\n");
        for(i=0; i<8; i++){
            printf("%.2f  ", resta[i]);
        }
        char eleccion;
        printf("\n%cQuiere repetir el programa? [y/n] ");
        while(true){
            scanf("%c", &eleccion);
            if(eleccion=='y' || eleccion=='n'){
                break;
            }else{
                printf("\nSeleccione una opci%Cn v%clida: ", 162, 160);
            }
        }
        if(eleccion=='n'){
            break;
        }
    }
	break;
	}
	case 9:{
		while(key==1){
		
		float Arnum8[8],Arnum82[8],ResNum[8];
		printf("dame 8 numeros: \n");
		for (int i=0;i<8;i++){
			scanf("%f",&Arnum8[i]);
		}
		printf("dame otros 8 numeros: \n");
		for (int i=0;i<8;i++){
			scanf("%f",&Arnum82[i]);
			ResNum[i]=Arnum8[i]*Arnum82[i];
	}
		for(int i=0;i<8;i++){
			printf("%f ",ResNum[i]);
		}
	printf("Quieres ejecutar de nbuevo el proceso?\n");
			printf("1.-si 0.-no\n");	
			scanf("%d",&key);
			system("PAUSE");
			system ("CLS");
	}
}
	case 10:{
	while(true){
        system("cls");
        float vector1[8], vector2[8], resta[8];
        int i;
        printf("Proporcione los primeros 8 n%cmeros:\n", 163);
        for(i=0; i<8; i++){
            printf("N%cmero %d: ", 163, i+1);
            scanf("%f", &vector1[i]);
        }
        printf("Proporcione los 8 n%cmeros a restar:\n", 163);
        for(i=0; i<8; i++){
            printf("N%cmero %d: ", 163, i+1);
            scanf("%f", &vector2[i]);
        }
        for(i=0; i<8; i++){
            resta[i]=vector1[i]-vector2[i];
        }
        printf("La resta de\n");
        for(i=0; i<8; i++){
            printf("%.2f  ", vector1[i]);
        }
        printf("\ny\n");
        for(i=0; i<8; i++){
            printf("%.2f  ", vector2[i]);
        }
        printf("\nes:\n");
        for(i=0; i<8; i++){
            printf("%.2f  ", resta[i]);
        }
        char eleccion;
        printf("\n%cQuiere repetir el programa? [y/n] ");
        while(true){
            scanf("%c", &eleccion);
            if(eleccion=='y' || eleccion=='n'){
                break;
            }else{
                printf("\nSeleccione una opci%Cn v%clida: ", 162, 160);
            }
        }
        if(eleccion=='n'){
            break;
        }
    }
		break;	
}
	case 11:{
		exit(0);
		break;
	}
		
	default:{
		printf("valor invalido ingrese uno valido\n");
		system("PAUSE");
		system("CLS");
	}

	
	}
		
}
exit (0); 
}
	
	
	
	
	
	
