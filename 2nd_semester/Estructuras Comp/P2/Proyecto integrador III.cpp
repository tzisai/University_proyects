#include <iostream>
#include <string.h>

using namespace std;

/* 
Proyecto integrador
Martin Isai Nuñez VIlleda 
Eduardo Isai Lopez Garcia
Jesus Yocsan Luevano Flores
Objetivo:
Simular una la lista en un arreglo para 10 posiciones, que te da la posibilidad de capturar hasta 10 elementos

*/

void menu(string playlist[],int bgin,int end){
	// funcion que despliega un menu, para seleccion de opciones
		
		cout<<"|||SONY WALKMAN DIGITAL MUSIC SYSTEM (Sony)|||"<<endl<<endl;
		
		if (bgin == end) {//cuando el inicio sea igual al final
	        cout << "REPRODUCCIONEDO: \t" << playlist[bgin] << endl << endl;
	        cout << "NEXT SONG: \t" << playlist[0] << endl << endl; 
	        cout << "PREVIOUS SONG: \t" << playlist[bgin-1] << endl << endl; 
	    }
	    else if (bgin == 0){//cuando el inicio sea igual a cero
	    	cout << "REPRODUCCIONEDO: \t" << playlist[bgin] << endl << endl;
	        cout << "NEXT SONG: \t" << playlist[(bgin + 1) % 10] << endl << endl; 
	        cout << "PREVIOUS SONG: \t" << playlist[end] << endl << endl; }
	        
		else {//Todos los casos distintos 
	        cout << "REPRODUCCIONEDO: \t" << playlist[bgin] << endl << endl;
	        cout << "NEXT SONG: \t" << playlist[(bgin + 1) % 10] << endl << endl; 
	        cout << "PREVIOUS SONG: \t" << playlist[(bgin + 9) % 10] << endl << endl; 
	    }
		cout<<"(1)\tMOSTRAR ULTIMA CANCION DE LA PLAYLIST"<<endl;
		cout<<"(2)\tSIGUIENTE CANCION"<<endl;
		cout<<"(3)\tCANCION ANTERIOR"<<endl;
		cout<<"(4)\tAGREGAR A LA COLA DE REPRODUCCION"<<endl;
		cout<<"(5)\tSALIR"<<endl<<endl;
		cout<<"SELECCIONE INGRESANDO EL NUMERO DE OPERACION"<<endl;
		
		if(end<10){
		cout<<"ESPACIO EN PLAYLIST RESTANTE: "<<(9-end)<<endl;
		}
		else{
		cout<<"ESPACIO EN PLAYLIST RESTANTE: PLAYLIST LLENA"<<endl;
		}
	return ;
	}
	
void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",0x1B,y,x);
}




int main(){
	string cola[10]={"Working for the weekend - Lover Boy","Missipi Queen - Mountain","We´re Not Gonna Take It - Twsited Sister ","You´re The Best - Joe Bean Esposito","Nothin´ But A Good TIme - Poison","Paranoid - Black Sabbath"};
	int inicio=0;
	int final=5;
	int choose=0;
	do{
		menu(cola,inicio,final);
		cin>>choose;// se pide una de las opciones 
		system("cls");// Se limpia la pantalla 
		

	
	switch(choose){
		case 1:{
			
			cout<<"CANCION AL FINAL DE LA COLA:"<<cola[final]<<endl; // Muestra la ultima cancion agrgaada 
							
		break;// rompe el case
		}
		case 2 :{
			if(inicio==final){// Pregunta si incio es igual a final y si, si se inicializa inicio igual a cero esto hace que de la vuelta a la cola 
				inicio=0;
			}
			else{
			inicio++;// Si no se le agrga a uno 
			}
			
			break;// Rompe el case 
		}
		case 3 :{
			if(inicio==0){// Si inicio es igual a cero osea al proncipio de la 
				inicio=final;
			}
			else{
			inicio--;// Se decrementa uno
			}
			break;
		}
		case 4 :{
			int Ncanciones=0;
			
			do{
				system("cls");// Se borra la pantalla 
				cout<<"¿Cuantas canciones deseas agregar a la cola?"<<endl;
				cin>>Ncanciones;
				if(Ncanciones>(9-final)){// Si la variable Ncanciones es mayor a 9 menos el final osea los espacios disponibles muetra un mensaje 
					cout<<"Numero de canciones que desea agregar sobrepasa la capacidad del reproductor intente otra cantidad"<<endl;
					system("pause");
				}
			}while(Ncanciones>(9-final));// Esto se repite mientras sea mayor la cantidad de canciones a los espacios disponibles 
			
			 cin.ignore();
			 
			for(int i=0;i<Ncanciones;i++){// Se cicla hasta el numero de canciones que se ingreso en un proncipio
					system("cls");
					cout<<"Ingresa la "<<i+1<<" cancion a la playlist:\n";//Indica que ingreses el numero de cancion
					getline(cin,cola[final+1]);// Lee la cancion ingresada
					final++;// Suma uno al final 
					cout<<"Cancion adicionada a la platlist!!!"<<endl;
					system("pause");
				}
				system("cls");// Limpia la pantalla
			break;
		}
	}
		}	while(choose!=5||(choose>5||choose<0));
		
	
		return 0;
		
}
	
	
	
	
	
	
	
	
