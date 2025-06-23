#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int CDC(int&cambio){
	cout<<"la cantidad original de quesadillas es de : "<<cambio<<endl;
	cout<<"Ingrese la nueva cantidad a comprar: ";
	cin>>cambio;
}
	
void areaC(int rad){
	float PI=3.1416;
	float area=0;
	
	area=(PI*(rad*rad));
	
	cout<<"el area de el circulo es de : "<<area<<endl<<".";
	
}

int main(){	
int key=1;
do{	

int choose=0;
cout<<"elija oportunamente"<<endl;
cout<<"1.-Programa con paso de parametros con valor"<<endl;
cout<<"2.-Programa con paso de parametros por referencia"<<endl;
cout<<"3.-salir"<<endl;
cin>>choose;

switch(choose){
	case 1:{
					float radio=0;
			cout<<"ingrese el radio de el circulo\n";
			cin>>radio;
			areaC(radio);
			cout<<"Y su radio es de :"<<radio<<endl;
			system("PAUSE");
					break;
	}
	
	
	case 2:{
		int elec=0;
		int queso=0;
		printf("Fonda do%ca Pelos\n",164);
		cout<<"Cuantas quesadillas te vas a comprar?\n";
		cin>>queso;
		cout<<"es correcta la cantidad de quesadiilas que pidio?\n";
		cout<<"1.-si 2.-no\n";
		cin>>elec;
		if(elec==1){
		cout<<"compra confirmada su compra final es de "<<queso<<" quesadillas\n";
		system("PAUSE");
		}
		else{
		CDC(queso);	
		cout<<"compra confirmada su compra final es de "<<queso<<" quesadillas\n";
		system("PAUSE");
		}
		break;
		}
		case 3:{
			key=0;
			break;
		}
	}
system("CLS");
} 
while(key==1);



	
	
	
	
	









	return 0;
	
}