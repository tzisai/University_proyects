#include <stdio.h>
#include<stdbool.h>
#define pi 3.1416//pi usando define
main(){
	//declaracion de variables
	const float Pi=3.1416;						//pi en int cons
	float 	rad=0,area=0,Rad=0,cm=0,pulgadas=0;
	float 	libro=100,cuadernos=15.50,plumas=2.35;
	float 	librosV=0,cuadernosV=0,plumasV=0,todo=0;
	int 	edad1=0,edad2=0,mes=0,numR=0;
	int 	chosse=0,acum=0,acuM=0,passwrd=0;
	bool 	key=0,Mkey=0;
	char 	nombre1[10],nombre2[10];
	const char *const rojo = "\033[1;31m"; 	//constante color rojo claro
	const char *const cyan = "\033[1;36m"; 	//constante color cyan claro
	const char *const normal = "\033[0m"; 	//constante color default
	const char *const verde = "\033[0;32m"; //constante color verde
	
	//menu de eleccion con iteracion y seleccion de salir para acabar iteracion
	do{
	system("CLS");
	printf("%sElige oportunamente\n%s",cyan,normal);
	printf("1.Area de un circulo con define\n");
	printf("2.Area de un circulo con const\n");
	printf("3.pulgadas a centimetros\n");
	printf("4.Monto tienda de libros\n");
	printf("5.Comparador de edades entree 2 personas \n");
	printf("6.Meses de el a%co\n",164);
	printf("7.covertidor numeros a romano\n");
	printf("8.comparador de edades entre 10 personas\n");
	printf("9.Contrase%ca\n",164);
	printf("10.Salir\n");
	scanf("%d",&chosse);
	switch(chosse){
	//programa area de un circulo usando define para PI
    case 1:
    	 system ("CLS");
	    printf("ingrese el radio de el circulo\n");
	    scanf("%f",&rad);
	    area=pi*(rad*rad);
	    printf("%s el area de el circulo es de: %f%s\n",verde,area,normal);
	    system ("PAUSE");
	    system ("CLS");
    break;
    //programa area de un circulo usando int cons para PI
	case 2:	
		system ("CLS");	
		printf("dame el radio de el circulo\n");
		scanf("%f",&Rad);
		area=Pi*(Rad*Rad);
		 printf("%s el area de el circulo es de: %f%s\n",verde,area,normal);
		system ("PAUSE");
	    system ("CLS");	
    break;
    //convertidor de pulgadas a centimetros
	case 3:
		 system ("CLS");
		printf("dame las pulgadas para pasarlo a cm\n");
		scanf("%f",&pulgadas);
		cm=pulgadas*2.54;
		printf("%s la equivalencia es igual a %f%s\n",verde,cm,normal);
		system ("PAUSE");
	    system ("CLS");
    break;
    //programa que calcula los montos totales de articulos individuales y el total
	case 4:
		 system ("CLS");
		printf("cuantos libros vas a comprar?\n");
		scanf("%f",&librosV);
		printf("Cuantos cuadernos vas a comprar?\n");
		scanf("%f",&cuadernosV);
		printf("Cuantas plumas vas a comprar?\n");
		scanf("%f",&plumasV);
		librosV=libro*librosV;
		cuadernosV=cuadernos*cuadernosV;
		plumasV=plumas*plumasV;
		todo=librosV+cuadernosV+plumasV;
		printf("%sel total acumulado de libros es de: %f\n",verde,librosV);
		printf("el total acumulado de cuadernos es de: %f\n",cuadernosV);
		printf("el total acumulado de plumas es de: %f\n",plumasV);
		printf("el total acumulado de todo es :%f%s\n",todo,normal);
		system ("PAUSE");
	    system ("CLS");
    break;
    //programa que compara 2 personas su edad y te dice cual es mayor y menor
	case 5:
		 system ("CLS");
		printf("Ingresa el nombre del primer individuo: \n");
		scanf("%s",&nombre1);
		printf("Ingresa la edad de el primer individuo: \n");
		scanf("%d",&edad1);
			printf("Ingresa el nombre del sengundo individuo: \n");
		scanf("%s",&nombre2);
		printf("Ingresa la edad de el segundo individuo: \n");
		scanf("%d",&edad2);
		
		if (edad1==edad2){
		printf("%s Ambos tiene la misma edad ninguno es mayor o menor%s",verde,normal);	
		}
		if (edad1>edad2){
		printf("%s %s es mayor y su edad es de %d%s \n",verde,nombre1,edad1,normal);
		printf("%s %s es mayor y su edad es de %d%s \n",verde,nombre2,edad2,normal);
		}
		else{
		printf("%s %s es mayor y su edad es de %d%s \n",verde,nombre2,edad2,normal);
		printf("%s %s es mayor y su edad es de %d%s \n",verde,nombre1,edad1,normal);	
		}
		system ("PAUSE");
    	system ("CLS");

    break;
    //Convertidor de meses en formato numerio a decimal 
	case 6:
		 system ("CLS");
		printf("Dame un numero del 1 al 12 y te dire que mes es:\n");
		do{
		mes=0;
		scanf("%d",&mes);
		if(mes<=12&&mes>=1){
			key=1;
		}
		else{
			printf("%sValor invalido ingrese uno valido\n%s",rojo,normal);
		}
		}
		while(key==0);
		printf("%s",verde);
		switch(mes){
			case 1 : 
			printf("Enero\n");
			break;
			case 2 : 
			printf("febrero\n");
			break;
			case 3 : 
			printf("Marzo\n");
			break;
			case 4 : 
			printf("Abril\n");
			break;
			case 5 : 
			printf("Mayo\n");
			break;
			case 6 : 
			printf("Junio\n");
			break;
			case 7 : 
			printf("Julio\n");
			break;
			case 8 : 
			printf("Agosto\n");
			break;
			case 9 : 
			printf("Septiembre\n");
			break;
			case 10 : 
			printf("Octubre\n");
			break;
			case 11 : 
			printf("Noviembre\n");
			break;
			case 12 : 
			printf("Diciembre\n");
			break;
			
	
		}
		system("PAUSE");
		printf("%s",normal);
		system ("CLS");
		key=0;	
    break;
	//convertidor numeros del 1 ak 10 de numero arabico a romano	
    case 7:
    	system ("CLS");
    	do{
    	printf("Dame el numero arabico a transformar a romano (1 al 10)\n%s",verde);
    	scanf("%d",&numR);
    	if (numR>=1&&numR<=10){
    	key=1;	
		}
		else{
		printf("%sValor incorrecto ingresa uno valido (1 al 10)%s\n",rojo,normal);
		system ("PAUSE");
		}
		system("CLS");
    	}
    	while(key==0);
    	switch(numR){
    		case 1 :
    		printf("tu numero en romano es: ");
    		printf("I\n");	
    		break;
    		case 2 :
    		printf("tu numero en romano es: ");
    		printf("II\n");	
    		break;
    		case 3 :
    		printf("tu numero en romano es: ");
    		printf("III\n");	
    		break;
    		case 4 :
    		printf("tu numero en romano es: ");
    		printf("IV\n");	
    		break;
    		case 5 :
    		printf("tu numero en romano es: ");
    		printf("V\n");	
    		break;
    		case 6 :
    		printf("tu numero en romano es: ");
    		printf("VI\n");	
    		break;
    		case 7 :
    		printf("tu numero en romano es: ");
    		printf("VII\n");	
    		break;
    		case 8 :
    		printf("tu numero en romano es: ");
    		printf("IIX\n");	
    		break;
    		case 9 :
    		printf("tu numero en romano es: ");
    		printf("IX\n");	
    		break;
    		case 10 :
    		printf("tu numero en romano es: ");
    		printf("X\n");	
    		break;
					}
					printf("%s",normal);
					system("PAUSE");
					system ("CLS");
    break;
    //contador de numero de personas mayores de edad y menores de edad
	case 8:
		system ("CLS");
		printf("dame la edad de 10 personas\n");
		for (int i=0;i<10;i++){
		scanf("%d",&edad1);
		if(edad1>=18){
		acuM++;
		}
		else{
		acum++;
		}
		}
		printf("%sEl numero de personas mayores de edad es de %d%s\n",verde,acuM,normal);
		printf("%sEl numero de personas menores de edad es de %d%s\n",verde,acum,normal);
		printf("%s",normal);
		system("PAUSE");
		system ("CLS");
    break;
    //comprobacion de password
	case 9:
		do{
		system ("CLS");
		printf("Dame la contrase%ca\n",164);
		scanf("%d",&passwrd);
		if(passwrd==12345){
		key=1;
		printf("%scontrase%ca correcta%s\n",verde,164,normal);
		system("PAUSE");
		system ("CLS");
		}
		else{
			printf("%scontrase%ca incorrecta\n%s",rojo,164,normal);
			system("PAUSE");
			key=0;
			system ("CLS");
		}
	}while(key==0);
	
    break;
	//opcion de salir terminacion de ciclo principal.	
	case 10:
	Mkey=1;
    break;
	default:
	printf("%sOpcion Incorrecta seleccoine una opcion valida%s\n",rojo,normal);
	system("CLS");
	break;
}	
}while(Mkey==0);
return (0);
}