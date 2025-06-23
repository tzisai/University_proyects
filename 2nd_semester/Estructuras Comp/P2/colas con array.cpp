#include <iostream>

using namespace std;

int main(){
	
	int cola[10]={0};
 	int frente=0;
 	int final=0;
 	
 	int Ndatos=0;
 	int TAM=10;
 	int TAMres=TAM;
 	
	int chosse;

 	
 	do{
 		system("cls");
	 	cout<<"ElIJA OPORTUNAMENTE"<<endl;
	 	cout<<"QUEQUE(1)"<<endl;
	 	cout<<"UNQUEQUE(2)"<<endl;
	 	cout<<"PRINT(3)"<<endl;
	 	cout<<"Salir(0)"<<endl;
 
 		cin>>chosse;

 	switch (chosse){
 		case 1:{
 			
 			do{
				system("cls");
				 		
				cout<<"Cuantos datos deseas ingresar?"<<endl;
				cin>>Ndatos;
				if(Ndatos>TAMres){
					cout<<"los input's rebasan la capacidad restante de la cola, elimine elementos o ingrese una cantidad menor\n";
					system("pause");
				}
			}while(Ndatos>TAMres);
			
			 	if(frente!=-1){
	
			 		TAMres-=Ndatos;
			 		
			 		for(int i=0;i<Ndatos;i++){
			 			if(final==10){
						final=0;
					}
			 			cin>>cola[final];
			 			final++;
					 }
					
			 		
				 }
				 else{
				 	
				 	frente++;
				 	TAMres-=Ndatos;
				 	
				 	for(int i=0;i<Ndatos;i++){
				 		if(final==10){
						final=0;
					}
			 			cin>>cola[final];
			 			final++;
					 }
					//final+=Ndatos;
				 	
				 }

			break;
		 }
		 case 2:{
		 	if(cola[frente]==NULL){
		 		cout<<"cola vacia no hay que eliminar \n";
		 		system("pause");
			 }
			 else{
			 	cola[frente]=NULL;
			 	frente++;
				TAMres++;
			 }
			break;
		 }
		 
		 case 3:{
		 	int auxp=0;
		 	if(cola[10]==NULL){
		 		for(auxp=0;auxp<final;auxp++){
		 		cout<<cola[auxp]<<"\t";
			 }
			 system("pause");	
			 }
			 else{
			 for(auxp=0;auxp<TAM;auxp++){
		 		cout<<cola[auxp]<<"\t";
			 }
			 system("pause");	
			 }
		 	
			break;
		 }
		
	 }
	 	
 }while(chosse!=0);
	
	
	return 0;
}