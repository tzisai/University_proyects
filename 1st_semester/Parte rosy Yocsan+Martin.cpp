#include<stdio.h> 
#include<string.h> 
#include<conio.h> 
#include <stdlib.h>
#include <time.h>
#define MAX 40
void mostrar_base(int i, int array1[],char matriz1[][MAX],float array2[]){
	for(i=0;i<10;i++){
   	printf("indice:%d.-%d %s $ %.2f\n",i+1,array1[i],matriz1[i],array2[i]);
   }
}

int main(){
	int n=0 , i=0, j, al=0, clave, arrClaves [10];
	int elec=0,elec1=0;
	//Declaracion de la matriz de nombres para depues genar la base de datos aleatoria :)
	char saver[40];	int saver2=0;
	float saver1=0;
	char completo [40];	char completo2 [40];
	char completo3 [40];char nombre [10];
	float sueldo, arrSueldos [10];
	char sueldos[7];char data_base [10][40];
	char nombres [10][10]= {"Martin ", "Yocsan ", "Alan ","Eduardo ", "Juan ", "Pablo ", "Jesus ","Alexis ","Guadalupe ","Omar "};
	char apellidos_1 [10][20]={"Hernández ","García ","Martínez ", "López ","González ","Rodrígez ","Pérez ","Sánchez ","Ramírez ","Torres "};
	char apellidos_2 [10][15]={"Flores","Gómez","Díaz","Vázquez","Cruz","Morales","Reyes","Reyes","Ortiz","Jiménez","Aguilar"};
	char nombre_finales [10][40];
	
	for(i=0;i<10;i++){
		
				//Genra de forma aletaoria el numero de la clave 
			clave = (rand() % (9999-1000+1))+1000;
			arrClaves[i]=clave; 
			
			//printf("%d \n",arrClaves[i]);
			
			// Esto genera el 1er nombre completo de la persona aleatoriamnte 
			al=rand() % 10+0;
			strcpy(completo,nombres [al]);
			//printf("%s \n",completo);
			
				// genera otro numero para el primer apellido 
			al=rand() % 10+0;
			strcpy(completo2,apellidos_1 [al]);
			//printf("%s \n",completo2);
						
			  sprintf(nombre_finales[i],"%s %s",completo,completo2);
			//printf("%s \n",nombre_finales[i]);
			// genra otro numero para el segundo apellido
			al=rand() % 10+0;
			strcpy(completo3,apellidos_2 [al]);
			
			sprintf(nombre_finales[i],"%s %s",nombre_finales[i],completo3);
			//printf("%s",nombre_finales[i]);	
				
				// Generacion de salarios tomando en cuenta el salario minimo en mexico por quincena 1244.88 de hay para adelante 
			sueldo = (rand() % 99999+1245)/.99;
			arrSueldos[i]= sueldo;
			//printf("%d %s $ %.2f\n",arrClaves[i],nombre_finales[i],arrSueldos[i]);
			
	}
	for(i=0;i<10;i++){
      for(j=i+1;j<10;j++){
         if(strcmp(nombre_finales[i],nombre_finales[j])>0){
         	
            strcpy(saver,nombre_finales[i]);
            strcpy(nombre_finales[i],nombre_finales[j]);
            strcpy(nombre_finales[j],saver);
            
            saver2 = arrSueldos[i];
            arrSueldos[i]=arrSueldos[j];
            arrSueldos[j]=saver2;
            
            saver1=arrClaves[i];
            arrClaves[i]=arrClaves[j];
            arrClaves[j]=saver1;
            
         }
      }
   }
   do{
   	printf("Tecle el numero acertivamente\n");
   printf("1.-Mostrar base de datos\n");
   printf("2.-modificar Datos\n");
   printf("3.-Salir\n");
   scanf("%d",&elec1);
   switch (elec1){
   
   	case 1:{
   		i=0;
   		 mostrar_base(i,arrClaves,nombre_finales,arrSueldos);
   	system("pause");
   	system("CLS");
		break;
	   }
	   case 2:{
	   	system("CLS");
	   	i=0;
	   	 mostrar_base(i,arrClaves,nombre_finales,arrSueldos);
	   	 
	   		printf("Ingrese el indice del trabajador a modificar\n");
	   		fflush(stdin);
	   		scanf("%d",&n);
   			system("CLS");
	   		printf("Elige oportunamente el numero segun corresponda\n");
   printf("1.-Modificar nombre\n");
   printf("2.-Modificar Clave\n");
   printf("3.-Modificar Salario\n");
   scanf("%d",&elec);
switch(elec){
   			case 1:{
   					printf("El trabajador que elijio fue %s\n",nombre_finales[n-1]);
   				  printf("Ingrese el nuevo nombre\n");
                    fflush(stdin);
                    gets(nombre_finales[n-1]);
                    printf("%d %s $ %.2f\n",arrClaves[n-1],nombre_finales[n-1],arrSueldos[n-1]);
                    printf("Nombre Modificado con exito\n");
				break;
			   }
			case 2:{
				printf("El trabajador que elijio fue %s\n",nombre_finales[n-1]);
				 printf("Ingrese la nueva clave\n");
                    fflush(stdin);
                   scanf("%d",&arrClaves[n-1]);
                    printf("%d %s $ %.2f\n",arrClaves[n-1],nombre_finales[n-1],arrSueldos[n-1]);
                    printf("clave modicada con exito\n");
				break;
			}
			case 3:{
				printf("El trabajador que elijio fue %s\n",nombre_finales[n-1]);
				printf("Ingrese el nuevo sueldo\n");
                    fflush(stdin);
                   scanf("%f",&arrSueldos[n-1]);
                    printf("%d %s $ %.2f\n",arrClaves[n-1],nombre_finales[n-1],arrSueldos[n-1]);
                    printf("Sueldo modificado con exito\n");
			}
			default:{
				printf("Ingrese un numero valido\n");
				break;
			}
		   }
		break;
	   }
	   case 3:{
	   	exit(0);
		break;
	   }
   
		   
   }
   }while(1==1);
   
}

	

	
	
	
