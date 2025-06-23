#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
1.`CONVERSIÓN DE DECIMAL A MAYA - MARTIN
2. CONVERSIÓN DE DECIMAL A BINARIO - MARTIN
3. CONVERSIÓN DE DECIMAL A OCTAL - YOCSAN
4. CONVERSIÓN DE DECIMAL A HEXADECIMAL - PABLO
5. CONVERSIÓN DE BINARIO A DECIMAL - LALO
6. CONVERSIÓN DE BINARIO A OCTAL - YOCSAN
7. CONVERSIÓN DE BINARIO A HEXADECIMAL - ALAN
8. PERMUTACIONES ORDINARIAS - PABLO
9. PERMUTACIONES CON DOS ASPECTOS - LALO
10. PRINCIPIO DEL PALOMAR - LALO
11. COMBINACIONES - ALAN
*/

int main(){
    char v1 = 'y', v2, v3;
    int opc1, opc2, opc3;
	while(v1 == 'y'){
        cout << "\n\n Ingresa el tipo de operacion que desee realizar: \n";
        cout << "**************************************************\n\n";
        cout << "    1- Conversiones entre sistemas numericos      \n";
        cout << "--------------------------------------------------\n";
        cout << "          2- Tecnicas de combinatoria             \n";
        cout << "--------------------------------------------------\n";
        cout << "                   3- Salir                       \n";
        cout << "--------------------------------------------------\n\n";
        cin >> opc1;
        //system("pause");
        switch(opc1){
            case 1:
                v2 = 'y';
                while(v2 == 'y'){
                    //fflush( stdin );
                    //system("cls");
                    cout << "\n\n      Conversiones entre sistemas numericos:      \n";
                    cout << "**************************************************\n\n";
                    cout << "               1- Decimal a maya                  \n";
                    cout << "--------------------------------------------------\n";
                    cout << "              2- Decimal a binario                \n";
                    cout << "--------------------------------------------------\n";
                    cout << "               3- Decimal a octal                 \n";
                    cout << "--------------------------------------------------\n";
                    cout << "            4- Decimal a hexadecimal              \n";
                    cout << "--------------------------------------------------\n";
                    cout << "               5- Binario a decimal               \n";
                    cout << "--------------------------------------------------\n";
                    cout << "                6- Binario a octal                \n";
                    cout << "--------------------------------------------------\n";
                    cout << "             7- Binario a hexadecimal             \n";
                    cout << "--------------------------------------------------\n";
                    cout << "               8- Regresar al menu                \n";
                    cout << "--------------------------------------------------\n\n";
                    cin >> opc2;
                    //system("cls");
                    switch(opc2){
                        case 1: //dentro de este case trabaja Martin
				{
				int key=1;
	do{
	system("CLS");
	int divM=0, num=0,pos[10],acum=0,resM=0,siz=0;
	int lineas,puntos=0;
cout<<"Ingresa un numero a transformar numero a maya\n";
cin>>num;
cout<<endl;
if(num<0){
	num*=-1;
}
divM=num;
do{
divM=trunc(num/20);
resM=num%20;
num=divM;
pos[acum]=resM;
acum++;

if(divM<=19){
	break;
}
}
while(true);

acum+=1;
pos[acum]=divM;	

for (int i =0;i<=acum;i++){	

lineas=trunc(pos[acum-i]/5);
puntos=pos[acum-i]%5;

if(i!=1){

if(lineas==0&&puntos==0){
	cout<<" (@)";
}
cout<<" ";
for(int p = 0;p<puntos;p++){
	cout<<"*";
}
cout<<endl;
for (int l=0;l<lineas;l++){
	cout<<" ~~~~~\n";
}
}
cout<<"\n\n";
	}


cout<<"quieres hacerlo de nuevo?\n";
cout<<"1 si// 0 no\n";
cin>>key;
system("CLS");

}while(key==1);	
				}
				break;
                        case 2: //dentro de este case trabaja Martin
				{
					int key=1;
	while(key==1){
		system("CLS");
		int divB=0,resB=0,InputB=0,iB=0;
int Bina[40];

cout<<"ingrese el numero a transformar a binario"<<endl;
cin>>InputB;

divB=InputB;
while(true){
	
resB=InputB%2;
Bina[iB]=resB;
divB=trunc(InputB/2);
InputB=divB;
iB++;


if(divB<2){
	break;	
	}
}
iB++;
Bina[iB]=divB;		


cout<<"El numero en binario es: ";
for(int i=0;i<iB+1;i++){
	if(i!=1){
	cout<<Bina[iB-i];	
	}
	
}
cout<<"\nquieres hacerlo de nuevo?\n";
cout<<"1 si// 0 no\n";
cin>>key;
system("CLS");
	}	
				}
                            	break;
                        case 3: //dentro de este case trabaja Yocsan
                            cout<<"";
                            break;
                        case 4: //dentro de este case trabaja Pablo el torta de aguacate 
                            cout<<"";
                            break;
                        case 5: //dentro de este case trabaja Lalo
                            cout<<"";
                            break;
                        case 6: //dentro de este case trabaja Yocsan
                            cout<<"";
                            break;
                        case 7: //dentro de este case trabaja Alan
                            cout<<"";
                            break;
                        case 8:
                            v2 = 'n';
                            break;
                        default:
                            cout<<"ERROR, Opcion no especificada\n\n";
                            break;
                    }
                }
                cout<<"Regresando al menu anterior...\n\n";
                break; 
            case 2:
                v3 = 'y';
                while(v3 == 'y'){
                    cout << "\n\n            Tecnicas de Combinatoria:             \n";
                    cout << "**************************************************\n\n";
                    cout << "           1- Permutaciones Ordinarias            \n";
                    cout << "--------------------------------------------------\n";
                    cout << "         2- Permutaciones con 2 aspectos          \n";
                    cout << "--------------------------------------------------\n";
                    cout << "             3- Principio del Palomar             \n";
                    cout << "--------------------------------------------------\n";
                    cout << "                 4- Combinaciones                 \n";
                    cout << "--------------------------------------------------\n";
                    cout << "                5- Regresar al menu               \n";
                    cout << "--------------------------------------------------\n";
                    cin >> opc3;
                    //system("cls");
                    switch(opc3){
                        case 1: //dentro de este case trabaja Pablo el torta de aguacate 
                            cout<<"";
                            break;
                        case 2: //dentro de este case trabaja Lalo
                            
                            break;
                        case 3: //dentro de este case trabaja Lalo
                            cout<<"";
                            break;
                        case 4: //dentro de este case trabaja Alan
                            cout<<"";
                            break;
                        case 5:
                            v3 = 'n';
                            break;
                        default:
                            cout<<"ERROR, Opcion no especificada\n\n";
                            break;
                    }
                }
                cout<<"Regresando al menu anterior...\n\n";
                break;
            case 3:
                v1 = 'n';
                break;
            default:
                cout<<"ERROR, Opcion no especificada\n\n";
                break;
        }
    }
    cout<<"\nPrograma finalizado con exito... \n";
    system("pause");
	return 0;
}
