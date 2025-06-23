#include<stdio.h> 
#include<string.h> 
#include<conio.h> 
#include <stdlib.h>
#include <time.h>
#define MAX 60

const char *const rojo = "\033[1;31m"; //constante color rojo claro
const char *const normal = "\033[0m"; //constante color default
const char *const cyan = "\033[1;36m"; //constante color cyan claro
const char *const verde = "\033[0;32m"; //constante color verde
const char *const verde_claro = "\033[1;32m"; //constante color verde claro

char validar();

void mostrar_base(int numero, int array1[],char matriz1[][MAX],float array2[]){
    int i;
	for(i=0;i<numero;i++){
		if(array1[i] != -1)
   			printf("%d   %s   $%.2f\n",array1[i],matriz1[i],array2[i]);
   }
}

int main(){
	srand(time(NULL));
	int n=0, num = 10, i=0, j, al=0, clave, arrClaves [30];
	int elec=0,elec1=0;
	//Declaracion de la matriz de nombres para depues genar la base de datos aleatoria :)
	char saver[60];	int saver2=0;
	float saver1=0;
	char completo [60];	char completo2 [60];
	char completo3 [60];char nombre [10];
	float sueldo, arrSueldos [30];
	char sueldos[7];char data_base [10][60];
	char nombres [10][15]= {"Martin", "Yocsan", "Alan","Eduardo", "Juan", "Pablo", "Jesus","Alexis","Guadalupe","Omar" };
	char apellidos_1 [10][15]={"Hernandez","Garcia","Martinez", "Lopez","Gonzalez","Rodriguez","Perez","Sanchez","Ramirez","Torres"};
	char apellidos_2 [10][15]={"Flores","Gomez","Diaz","Vazquez","Cruz","Morales","Reyes","Ortiz","Jimenez","Aguilar"};
	char nombre_finales [30][60];
    char c;
	for(i=0;i<10;i++){
		
				//Genera de forma aletaoria el numero de la clave 
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
        system("cls");
		printf("              MENU              \n");
        printf("********************************\n");
        printf("      1- Mostrar Registros      \n");
        printf("--------------------------------\n");
        printf("       2- Buscar Registro       \n");
        printf("--------------------------------\n");
        printf("      3- Insertar Registro      \n");
        printf("--------------------------------\n");
        printf("      4- Eliminar Registro      \n");
        printf("--------------------------------\n");
        printf("      5-Modificar Registro      \n");
        printf("--------------------------------\n");
        printf("            6- Salir            \n");
        printf("--------------------------------\n\n");
        printf("Ingrese el la opcion que desee realizar: ");
        fflush(stdin);
		scanf("%d",&elec1);
		switch (elec1){
			case 1:{
				i=0;
				system("CLS");
				mostrar_base(num,arrClaves,nombre_finales,arrSueldos);
				system("pause");
				break;
			}
            case 2:{
                while(1){
                    i=0;
                    elec = 3;
                    c = 'k';
                    while (elec > 2){
                        system("cls");
                        printf("1 - Buscar por clave\n");
                        printf("2 - Buscar por nombre\n\n");
                        printf("Ingresa el numero del metodo de busqueda: ");
                        fflush(stdin);
                        scanf("%d", &elec);
                        if(elec > 2)
                            printf("%sERROR, opcion no valida\n%s", rojo, normal);
							system("pause");
                    }
                    while((c != 'y' && c != 'Y') && (c != 'n' && c != 'N')){
                        system("cls");
                        printf("Desea ver la base de datos antes de buscar algun registro?? (y/n)\n");
                        fflush(stdin);
                        scanf("%c", &c);
                        if((c != 'y' && c != 'Y') && (c != 'n' && c != 'N')){
                            printf("%sERROR, opcion no valida\n%s", rojo, normal);
                            system("pause");
						}
                    }
					system("cls");
                    if(c == 'Y' || c == 'y')
                        mostrar_base(num,arrClaves,nombre_finales,arrSueldos);
                    switch (elec){
                        case 1:{
							j=1;
							printf("Ingresa la clave de 4 digitos del trabajador: ");
							fflush(stdin);
							scanf("%d", &clave);
							for(i=0; i<num; i++){
								if(arrClaves[i] == clave){
									j = 0;
									break;
								}
							}
							if(j==1){
								printf("Clave no existe en la base de datos\n");
								system("pause");
							}else{
								printf("%d   %s   $%.2f\n",arrClaves[i],nombre_finales[i],arrSueldos[i]);
							}
	                        break;
                        }
                        case 2:{
							j=0;
							printf("\n\nIngresa el nombre completo del registro a buscar: ");
							fflush(stdin);
							gets(completo);
							for(i=0; i<num; i++){
								if(strcmp(completo, nombre_finales[i])==0){										printf("%d   %s   $%.2f\n",arrClaves[i],nombre_finales[i],arrSueldos[i]);
									j = 1;
									break;
								}
							}
							if(j==0){
								printf("Nombre no coincide con los existentes en la base de datos\n");
							}
                            break;
                        }
                        default:{
							printf("ERROR, opcion invalida\n");
                            break;
                        }
                    }
                    c = validar();
                    if(c == 'n' || c == 'N')
                        break;
                }
				break;
			}
            case 3:{
				while(1){
					j = 1;
					system("cls");
					while(j == 1){
						printf("Ingresa la clave de 4 digitos del trabajador: ");
						fflush(stdin);
						scanf("%d", &arrClaves[num]);
						for(i=0; i<num; i++){
							if(arrClaves[i] == arrClaves[num]){
								printf("ERROR, clave repetida, ingrese otra clave");
								j = 1;
								break;
							}
							else
								j = 0;
						}
					}
					printf("Ingresa el apellido paterno del trabajador (sin acentos): ");
					fflush(stdin);
					scanf("%s", completo2);
					printf("Ingresa el apellido materno del trabajador (sin acentos): ");
					fflush(stdin);
					scanf("%s", completo3);
					printf("Ingresa el primer nombre del trabajador (sin acentos): ");
					fflush(stdin);
					scanf("%s", completo);
					sprintf(nombre_finales[num],"%s %s",completo,completo2);
					sprintf(nombre_finales[num],"%s %s",nombre_finales[num],completo3);
					printf("Ingresa el sueldo del trabajador: ");
					fflush(stdin);
					scanf("%f", &arrSueldos[num]);
					num = num + 1;
					printf("\n\nRegistro agregado con exito...\n");
					c = validar();
                    if(c == 'n' || c == 'N')
                        break;
				}
				break;
			}
            case 4:{
				while(1){
					i=0;
					elec=3;
					while (elec > 2){
                        system("cls");
                        printf("1 - Eliminar por clave\n");
                        printf("2 - Eliminar por nombre\n\n");
                        printf("Ingresa el numero del metodo de eliminacion: ");
                        fflush(stdin);
                        scanf("%d", &elec);
                        if(elec > 2)
                            printf("%sERROR, opcion no valida\n%s", rojo, normal);
                    }
					switch(elec){
						case 1:{
							j=1;
							while(j == 1){
								mostrar_base(num,arrClaves,nombre_finales,arrSueldos);
								printf("\n\nIngresa la clave de 4 digitos del trabajador: ");
								fflush(stdin);
								scanf("%d", &clave);
								for(i=0; i<num; i++){
									if(arrClaves[i] == clave){
										j = 0;
										break;
									}
								}
								if(j==1){
									printf("ERROR, clave no existe en la base de datos\n");
									break;
								}else{
									system("cls");
									printf("El registro:\n");
									printf("%d   %s   $%.2f",arrClaves[i],nombre_finales[i],arrSueldos[i]);
									printf(" ha sido eliminado con exito");
									arrClaves[i] = -1;
									break;
								}
							}
							break;
						}
						case 2:{
							j=1;
							while(j == 1){
								mostrar_base(num,arrClaves,nombre_finales,arrSueldos);
								printf("\n\nIngresa el nombre completo del trabajador: ");
								fflush(stdin);
								gets(completo);
								for(i=0; i<num; i++){
									if(strcmp(completo, nombre_finales[i]) == 1){
										j = 0;
										break;
									}
								}
								if(j==1){
									printf("ERROR, nombre no existe en la base de datos\n");
									break;
								}else{
									system("cls");
									printf("El registro:\n");
									printf("%d   %s   $%.2f",arrClaves[i],nombre_finales[i],arrSueldos[i]);
									printf(" ha sido eliminado con exito");
									arrClaves[i] = -1;
									break;
								}
							}
							break;
						}
					}
                    c = validar();
                    if(c == 'n' || c == 'N')
                        break;
				}
				break;
			}
			case 5:{
                while(1){
                    i=0;
					elec = 4;
                    j=1;
                    while(j == 1){
						system("cls");
						mostrar_base(num,arrClaves,nombre_finales,arrSueldos);
						printf("\n\nIngresa la clave de 4 digitos del trabajador: ");
						fflush(stdin);
						scanf("%d", &clave);
						for(i=0; i<num; i++){
							if(arrClaves[i] == clave){
								j = 0;
								break;
							}
						}
						if(j==1){
							printf("ERROR, clave no existe en la base de datos\n");
							system("pause");
							system("cls");
						}else{
							printf("%d   %s   $%.2f\n",arrClaves[i],nombre_finales[i],arrSueldos[i]);
						}
					}
					while (elec > 3){
                        printf("Modificacion de datos\n");
                        printf("1 - Modificar clave\n");
                        printf("2 - Modificar nombre\n");
                        printf("3 - Modificar sueldo\n\n");
                        printf("Ingresa el numero de modificacion a realizar: ");
                        fflush(stdin);
                        scanf("%d", &elec);
                        if(elec > 3)
                            printf("%sERROR, opcion no valida\n%s", rojo, normal);
							system("pause");
                    }
                    switch (elec){
                        case 1:{
                            printf("\n\nIngresa la nueva clave del trabajador (4 digitos): ");
                            fflush(stdin);
                            scanf("%d",&clave);
							printf("\nClave de trabajador %s cambiada con exito de: %d a: ", nombre_finales[i], arrClaves[i]);
							arrClaves[i] = clave;
							printf("%d\n", clave);
                            break;
                        }
                        case 2:{
                        	printf("\n\nIngresa el nuevo nombre completo del trabajador: ");
                            fflush(stdin);
                            gets(completo);
							printf("\nNombre de trabajador con clave %d cambiado con exito de: %s a: ", arrClaves[i], nombre_finales[i]);
							strcpy(nombre_finales[i], completo);
							printf("%d\n", completo);
                            break;
                        }
                        case 3:{
                            printf("\n\nIngresa el nuevo sueldo del trabajador: ");
                            fflush(stdin);
                            scanf("%f",&sueldo);
							printf("\nSueldo de trabajador %s cambiada con exito de: %.2f a: ", nombre_finales[i], arrClaves[i]);
							arrSueldos[i] = sueldo;
							printf("%.2f\n", sueldo);
                            break;
                        }
                    }
					c = validar();
                    if(c == 'n' || c == 'N')
                        break;
			    }
				break;
	        }
			case 6:{
				exit(0);
				break;
			}
			default:{
				printf("ERROR, opcion no especificada.\n");
				system("pause");
				break;
			}		
		}
    }while(1==1); 
}

char validar(){
    int com = 'k';
    while((com != 'y' && com != 'Y') && (com != 'n' && com != 'N')){
        printf("\n%sDesea volver a usar esta operacion?? [y/n]: %s", cyan, normal);
        fflush(stdin);
        scanf("%c", &com);
        if((com != 'y' && com != 'Y') && (com != 'n' && com != 'N'))
            printf("%sERROR, opcion no valida\n%s", rojo, normal);                                
    }
    return com;
}
