#include <iostream>
#include <string.h>

using namespace std;

/* 
Proyecto integrador
Martin Isai Nuñez VIlleda 
Eduardo Isai Lopez
Yocsan Luevano Flores
Objetivo:
Simular una la lista en un arreglo para 10 posiciones, que te da la posibilidad de capturar hasta 10 elementos

*/

void menu(string playlist[],int bgin,int end){

	
		
		cout<<"|||SONY WALKMAN DIGITAL MUSIC SYSTEM (Sony)|||"<<endl;
		
		if (bgin == end) {
	        cout << "REPRODUCCIONEDO: \t" << playlist[bgin] << endl;
	        cout << "NEXT SONG: \t" << playlist[0] << endl; 
	        cout << "PREVIOUS SONG: \t" << playlist[bgin-1] << endl; 
	    }
	    else if (bgin == 0){
	    	cout << "REPRODUCCIONEDO: \t" << playlist[bgin] << endl;
	        cout << "NEXT SONG: \t" << playlist[(bgin + 1) % 10] << endl; 
	        cout << "PREVIOUS SONG: \t" << playlist[end] << endl; }
	        
		else {
	        cout << "REPRODUCCIONEDO: \t" << playlist[bgin] << endl;
	        cout << "NEXT SONG: \t" << playlist[(bgin + 1) % 10] << endl; 
	        cout << "PREVIOUS SONG: \t" << playlist[(bgin + 9) % 10] << endl; 
	    }
		cout<<"(1)\tMOSTRAR ULTIMA CANCION DE LA PLAYLIST"<<endl;
		cout<<"(2)\tSIGUIENTE CANCION"<<endl;
		cout<<"(3)\tCANCION ANTERIOR"<<endl;
		cout<<"(4)\tAGREGAR A LA COLA DE REPRODUCCION"<<endl;
		cout<<"(5)\tSALIR"<<endl;
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
		cin>>choose;
		system("cls");
		

	
	switch(choose){
		case 1:{
			
			
			cout<<"CANCION AL FINAL DE LA COLA:"<<cola[final]<<endl;
							
		break;
		}
		case 2 :{
			if(inicio==final){
				inicio=0;
			}
			else{
			inicio++;
			}
			
			break;
		}
		case 3 :{
			if(inicio==0){
				inicio=final;
			}
			else{
			inicio--;
			}
			break;
		}
		case 4 :{
			int Ncanciones=0;
			
			do{
				system("cls");
				cout<<"¿Cuantas canciones deseas agregar a la cola?"<<endl;
				cin>>Ncanciones;
				if(Ncanciones>(9-final)){
					cout<<"Numero de canciones que desea agregar sobrepasa la capacidad del reproductor intente otra cantidad"<<endl;
					system("pause");
				}
			}while(Ncanciones>(9-final));
			
			 cin.ignore();
			 
			for(int i=0;i<Ncanciones;i++){				
					system("cls");
					cout<<"Ingresa la "<<i+1<<" cancion a la playlist:\n";
					getline(cin,cola[final+1]);
					final++;
					cout<<"Cancion adicionada a la platlist!!!"<<endl;
					system("pause");
				}
				system("cls");
			break;
		}
	}
		}	while(choose!=5||(choose>5||choose<0));
		
	
		return 0;
		
}
	
	
	
	
	
	
	
	
