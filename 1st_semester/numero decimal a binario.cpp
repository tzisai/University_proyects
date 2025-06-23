#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
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
cout<<"divB:"<<divB<<endl;
cout<<"resB:"<<resB<<endl;
InputB=divB;
iB++;


if(divB<2){
	break;	
	}
}
iB++;
Bina[iB]=divB;		



for(int i=0;i<iB+1;i++){
	if(i!=1){
	cout<<Bina[iB-i];	
	}
	
}
cout<<"\nquieres hacerlo de nuevo?\n";
cout<<"1 si// 0 no\n";
cin>>key;
	}
	return 0;
	
}