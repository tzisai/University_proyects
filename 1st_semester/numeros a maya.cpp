 //programa maya a decimal 
#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
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

}while(key==1);
	return 0;
}

