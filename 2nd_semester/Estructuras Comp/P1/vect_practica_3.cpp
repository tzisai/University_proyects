/*

Martin Isai Nuñez Villeda 2do semestre 
Ingenieria en computacion inteligente
Objetivo: Hacer un programa con vectores en el cual despliegue un menu con las siguientes opciones:

		Acceder a un dato
		Insercion a un dato
		Modificacion a un dato
		Eliminacion de un dato
		
Obviamente funcional y como se pidio en clase con recorrimiento de caracteres dentro de el vector al eliminar
Y los primeros 10 numeros pares aleatorios con generacion en base al rango espécificado por el usuario. 
10 de febrero de 2024

*/

#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

int main(){
	int chosse=0,chosse2=0;
	int vectnum[20];
	int i=0,index=0,max=0,min=0;
	int act=9,ndatos=0,control=0,numdes=0;
	//insercion de datos para el vector por parte de el usuario insertando rangos
	cout<<"Bienvenido, porfavor inserte el maximo valor posible el cual que puede tomar un dato (numero entero positivo) \n";
	cin>>max;
	cout<<"Ahora inserte el valor minimo el cual que puede tomar un dato (numero entero positivo) \n";
	cin>>min;
	max*=2;
	min*=2;
	//generacion de numero aleatorios pares
	for(i=0;i<10;i++){
		vectnum[i]=rand() % max + min-1 ;
		vectnum[i]=trunc(vectnum[i]/2) ;
		if(vectnum[i]%2==1){
			vectnum[i]+=1;
		}
	}
	//impresion de primeros numeros generados(no en el programa final)
	/*for(i=0;i<10;i++){
		cout<<vectnum[i]<<endl;
	}
	
	system("pause");*/
	
	do{
		system("CLS");
		cout<<"~~~ELIJA OPORTUNAMENTE~~~\n";
		cout<<"~~~Acceder a un dato(1)~~~\n";
		cout<<"~~~Insercion a un dato(2)~~~\n";
		cout<<"~~~Modificacion a un dato(3)~~~\n";
		cout<<"~~~Eliminacion de un dato(4)~~~\n";
		cout<<"~~~Salir(5)~~~\n";
	do{
		cin>>chosse;
		if(chosse<0||chosse>6){
			cout<<"Eleccion invalida por favor insertar una valida"<<endl;
			system("pause");
		}
	}
	while(chosse<0||chosse>6);//menu y validacion de datos validos
	
	
	system("cls");
	switch(chosse){
					case 1:{
							system("CLS");
							cout<<"~~~ELIJA OPORTUNAMENTE~~~\n";
							cout<<"~~~Acceder a un dato individualmente(1)~~~\n";
							cout<<"~~~Imprimir base de datos(2)~~~\n";
							do{
									cin>>chosse2;
							  }
							while(chosse<0||chosse>3);//validacion de datos
							
							switch(chosse2){
								case 1:{
										do{
											system("cls");
											cout<<"A que dato desea acceder?(inserte el indice)\n";
											cin>>index;
											if(index>act||index<0){
																	cout<<"Indice inexistente por favor ingrese uno valido\n";	
																	system("pause");
											}
										}while(index>act||index<0);
										cout<<"El dato al cual accedio fue: "<<vectnum[index]<<endl;
										system("pause");
									break;
								}
								case 2:{
										for(i=0;i<=act;i++){
												cout<<vectnum[i]<<endl;
											}
										system("pause");
										break;
										}
						}
						break;
					}
					case 2:{
						ndatos=0;
						control=0;
						cout<<"Cuantos datos insertaras?\n";
						cin>>ndatos;
						control=act+ndatos;
						if(control>=20){
						 cout<<"Lo siento, no es posible insertar el numero de datos solicitado, este sobrepasa el limite \n";
						 system("pause");
						}
						else{
							for(i=0;i<ndatos;i++){
							cout<<"Tipea el "<<i<<" dato a insertar(numero entero)\n";
							 cin>>vectnum[act+1];
							 act++;	
							}
		 				cout<<"Insercion lograda con exito\n";
						}
						
						break;
					}
					case 3:{
						do{
							system("cls");
								cout<<"A que dato desea acceder y modificar?(inserte el indice)\n";
								cin>>index;
								
								if(index>act||index<0){
												cout<<"Indice inexistente por favor ingrese uno valido\n";
												system("pause");	
											}
										}while(index>act||index<0);
								cout<<"El dato al cual accedio fue: "<<vectnum[index]<<" con el numero de indice "<<index<<endl;
								cout<<"Inserte el nuevo dato para remplazar:\n";
								cin>>control;
								vectnum[index]=control;
								cout<<"Cambio realizado con exito!!!\n";
								system("pause");
						break;
					}
					case 4:{
						do{
							system("cls");
								cout<<"A que dato desea acceder y eliminar?(inserte el indice)\n";
								cin>>index;
								if(index>act||index<0){
												cout<<"Indice inexistente por favor ingrese uno valido\n";
												system("pause");	
											}
										}while(index>act||index<0);
								cout<<"El dato al cual elimino fue: "<<vectnum[index]<<" con el numero de indice "<<index<<endl;
								numdes=act-index;
								if(index!=act){
											for(i=0;i<numdes;i++){
												vectnum[index+i]=vectnum[index+1+i];
											}
											act--;
								}
								else{
								act--;
								}
								system("pause");
						break;
					}	
}			
	}while(chosse!=5);
	
return 0;
}