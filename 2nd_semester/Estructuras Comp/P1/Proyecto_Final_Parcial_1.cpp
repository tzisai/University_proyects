/*
Realizado: 
Jesus Yocsan Luevano Flores, Martin Isai Nuñes Villeda, Pablo David  Perez Lopez 
Objetivo: Realizar un programa que pueda verificar si esta reguistrado o no de 
distintas formas.
fecha: 08/03/2024
*/

#include <iostream>
#include <windows.h>
#include <string.h>
#include <cctype>
using namespace std;


union identificador{
    char nif[8];
    char cif[9];
    char pasaporte[8];
    char nie[9];
    char nombre_de_usuario[40];
};

main(){
	int act=0;
    int opcion = 0;
    bool flag = false;
    union identificador identificadores[5];
	 
	char V_nif []="83762910B";
	char V_cif []="A15873695";  
	char pasaporte []="15AJFL3R";
	char V_nie []="A1597534J";
	char V_nombre []="Juan Perez";
    
    
    for(int j=0; j<5; j++){
        system("cls");
        cout << "#"<<j+1<<endl;
        cout << endl << "Ingrese la variable con la cual te gustaria identificarte" << endl;
        cout << endl << "Variables disponibles:" << endl;
        cout << "   1. Identificarse con NIF" << endl;
        cout << "   2. Identificarse con CIF" << endl;
        cout << "   3. Identificarse con Pasaporte" << endl;
        cout << "   4. Identificarse con NIE" << endl;
        cout << "   5. Identificarse con Username" << endl;
        cout << "   6. Salir" << endl;
        cin >> opcion;

        switch(opcion){
            case 1:{
                system("cls");
                do{
                	cout << "Persona #"<<j+1<<endl;
                    cout << "Ingrese el NIF con el cual se identificara: ";
                    cin >> identificadores[j].nif;
                    fflush(stdin);

                    if(isdigit(identificadores[j].nif[8])== 0){
                        for(int i = 0; i < 8; i++){
                            if(isdigit(identificadores[j].nif[i])==1){
                                flag = true;
                            }else{
                                flag = false;
                            }
                        }
                    }else{
                        flag = false;
                    }
                    
                   if(flag == true){
                        cout << "Entrada valida"<<endl<<endl;
                    }else{
                        cout << "ERROR: Existe un caracter incorrecto, intente de nuevo" << endl <<endl;
                    }
                }while(flag == false);
                
                if (strcmp(V_nif, identificadores[j].nif) == 0){//Hace la comparacion de que sea correcto lo ingresado con lo guardado
                	cout << "Validacion correcta" << endl;
				}else {
					cout << "El NIF no se encuentra en la base de datos"<<endl;
				}
                system("pause");// para mostrar y que no se salte de una,
                
                break;
            }
            case 2:{
                system("cls");
                do{
                	cout << "Persona #"<<j+1<<endl;
                    cout << "Ingrese el CIF con el cual se identificara: ";
                    cin >> identificadores[j].cif;

                    if(isalpha(identificadores[j].cif[0])==1||isalpha(identificadores[j].cif[0])==2){
                        for(int i = 1; i < 9; i++){
                            if(isdigit(identificadores[j].cif[i])==1){
                                flag = true;
                            }else{
                                flag = false;
                            }
                        }
                    }else{
                        flag = false;
                    }
                    
                    if(flag == true){
                        cout << "Entrada valida"<< endl << endl;
                        break;
                    }else{
                        cout << "ERROR: Existe un caracter incorrecto, intente de nuevo" << endl << endl;
                    }
                }while(flag == false);
                
                if (strcmp(V_cif, identificadores[j].cif) == 0){//Hace la comparacion de que sea correcto lo ingresado con lo guardado
                	cout << "Validacion correcta" << endl;
				}else {
					cout << "El CIF no se encuentra en la base de datos"<<endl;
				}
                
                system("pause");
                break;
            }
            case 3:{
                system("cls");
                do{
                	cout << "Persona #"<<j+1<<endl;
                    cout << "Ingrese el Numero de Pasaporte con el cual se identificara: ";
                    cin >> identificadores[j].pasaporte;

                    for(int i = 0; i < 8; i++){
                        if(isalpha(identificadores[j].pasaporte[i])==1 || isalpha(identificadores[j].pasaporte[i])==2 || isdigit(identificadores[j].pasaporte[i])==1){
                            flag = true;
                        }else{
                            flag = false;
                        }
                    }
                    
                    if(flag == true){
                        cout << "Entrada valida"<< endl <<endl;
                    }else{
                        cout << "ERROR: Existe un caracter incorrecto, intente de nuevo" << endl << endl;
                    }
                }while(flag == false);
                
                if (strcmp(pasaporte, identificadores[j].pasaporte) == 0){//Hace la comparacion de que sea correcto lo ingresado con lo guardado
                	cout << "Validacion correcta" << endl;
				}else {
					cout << "El Pasaporte no se encuentra en la base de datos"<<endl;
				}
                
                system("pause");
                break;
            }
            case 4:{
                system("cls");
                do{
                	cout << "Persona #"<<j+1<<endl;
                    cout << "Ingrese el NIE con el cuál se identificara: ";
                    cin >> identificadores[j].nie;

                    if((isalpha(identificadores[j].nie[8])==1 || isalpha(identificadores[j].nie[8])==2) && 
                    	(isalpha(identificadores[j].nie[0])==1 || isalpha(identificadores[j].nie[0])==2)
					){
                        for(int i = 1; i < 7; i++){
                            if(isdigit(identificadores[j].nie[i])==1){
                                flag = true;
                            }else{
                                flag = false;
                            }
                        }
                    }else{
                        flag = false;
                    }
                    
                    if(flag == true){
                        cout << "Entrada valida"<< endl << endl;
                    }else{
                        cout << "ERROR: Existe un caracter incorrecto, intente de nuevo" << endl <<endl;
                    }
                }while(flag == false);
                
                if (strcmp(V_nie, identificadores[j].nie) == 0){//Hace la comparacion de que sea correcto lo ingresado con lo guardado
                	cout << "Validacion correcta" << endl;
				}else {
					cout << "El NIE no se encuentra en la base de datos"<<endl;
				}
                
                system("pause");
                break;
            }
            case 5:{
                do{
                	system("cls");
                	cout << "Persona #"<<j+1<<endl;
                	char nombre[40];
                    cout << "Ingrese el nombre con el cual se identificara: ";
                    fflush(stdin);
                    cin.clear();
                    cin.getline(nombre,40);
                 
                    for(int i = 0; i <sizeof(nombre); i++){
                    	if((nombre[i] == '\0')){
                    		break;
						}
                        if((isalpha(nombre[i] )==1||isalpha(nombre[i])==2||nombre[i]=='\0') ){
                            flag = true;
                        }else{
                            flag = false;
                        }
                    }
                    
                    if(flag == true){
                        cout << "Entrada valida" << endl << endl ;
                        
                        for(int i=0;i<sizeof(nombre);i++){
                        	if((nombre[i] == '\0')){
                    		break;
						}
                        identificadores[j].nombre_de_usuario[i]=nombre[i];	
						}
						
						for(int i=0;i<sizeof(nombre);i++){
							if((nombre[i] == '\0')){
                    		break;
						}
                       cout<<identificadores[j].nombre_de_usuario[i];	
						}
						
                    }
					else{
                        cout << "ERROR: Existe un caracter incorrecto, intente de nuevo" << endl <<endl ;
                    }
                }while(flag == false);
                
                if (strcmp(V_nombre, identificadores[j].nombre_de_usuario) == 0){//Hace la comparacion de que sea correcto lo ingresado con lo guardado
                	cout << endl <<"Validacion correcta" << endl;
				}else {
					cout <<endl << "Nombre no encontrado en la base de datos, Pueden ser las mayusculas al inicio de cada nombre y apellido"<<endl;
				}
                
                system("pause");
                break;
            }
            case 6:{
                system("cls");
                int validacion = 0;

                do{
                    cout << "¿Está seguro de que quiere salir del programa? [1 si; 2 no] ";
                    cin >> validacion;

                    if(validacion == 1){
                        cout << "Perfecto, saliendo del programa..." << endl;
                        system("pause");
                        exit(0);
                    }else if(validacion != 2){
                        cout << "ERROR: Existe un caracter incorrecto, intente de nuevo" << endl;
                    }
                }while(validacion < 1 || validacion > 2);
                break;
            }
            default:
            system("cls");
                cout << "ERROR: Opcion ingresada invalida, intente de nuevo" << endl;
                //Sleep(3000);
                break;
        }
    }
}