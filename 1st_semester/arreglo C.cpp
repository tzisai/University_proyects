#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
//vectores apunes sintaxis C

int entero[5];
int comp,pos,pos2,comp2=0;

for (int i=0;i<5;i++){
printf("Dame un numero:");
scanf("%d",&entero[i]);
}
comp=entero[0];
comp2=entero[0];
for(int e=0;e<5;e++){
if(entero[e]>=comp){
	comp=entero[e];
	pos=e+1;
}
if(entero[e]<=comp2){
	comp2=entero[e];
	pos2=e+1;
}	
}
for(int j =0;j<5;j++){
	
printf("	 %d",entero[j]);
}
printf("\n El numero mas grande es %d su posicion es %d y el mas peque%co es %d y su posicion es %d.\n",comp,pos,164,comp2,pos2);	

	
	
	
return 0;
}