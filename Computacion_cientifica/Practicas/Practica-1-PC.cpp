#include <iostream>
using namespace std;

int get_int(){
    int a;
    cout<<"Ingrese el numero entero"<<endl;
    cin>>a;
    return a;
}

int Euclides_iter(int a,int b){
    int r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int Euclides_rec(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return Euclides_rec(b,a%b);
    }
}


int main(){

int a=0;
int b=0;
char c;
bool cond=1;

while(cond==1){

system("cls");

cout<<"Bienvenido al programa de calculo de MCD"<<endl;
cout<<"Por favor ingrese el metodo que desea utilizar"<<endl;
cout<<"Type 'I'.-para Euclides iterativo"<<endl;
cout<<"'Type R'- para Euclides recursivo"<<endl;
cout<<"'Type Q'- para salir"<<endl;
cin>>c;

	    switch (c)
	                {
	                case 'R':
	                     a = get_int();
	                     b = get_int();
	                    cout<<"El MCD de "<<a<<" y "<<b<<" es: "<<Euclides_rec(a,b)<<endl;
	                    system("Pause");
	                break;
	
	                case 'I':
	                     a = get_int();
	                     b = get_int();
	                    cout<<"El MCD de "<<a<<" y "<<b<<" es: "<<Euclides_iter(a,b)<<endl;
	                    system("Pause");
	                break;
	
	                case 'Q':
	                    cond=0;
	                default:
	                    break;
	                }
				}

return 0;
}