/* Martin Isai Nunez Villeda ICI 1er semestre 
Objetivo:Un prgrama que recre un menu que en funcion de lo seleccionado por el usuario  imprima lo que el selecciono
Fecha:18 de septiembre 2023
*/
#include <stdio.h>
 main(){
int chosse=0;
int ciclo=1;
while(ciclo==1){
printf("elige oprtunamente\n");
printf("1.Matematicas\n");
printf("2.-Espa%col\n",164);
printf("3.Historia\n");
printf("4.-Salir\n");
scanf("%d",&chosse);
switch (chosse){
	case 1:
	printf("Matematicas\n");
	break;
	case 2:
	printf("Espa%col\n",164);	
	break;
	case 3:
	printf("Historia\n");	
	break;
	case 4:
	return (0);
	break;
	
	default:
		printf("Opcion incorrecta ingrese OPORTUNAMENTE");
	break;
}

}
	
	
	return (0);
}