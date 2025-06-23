#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	string input ="";	int comp=97; int siz=0;
    int i=0; int mov=0; bool y =0; int inv=1; int fin=1;

cin>>input;
siz=input.size();
do{
	if(y==0){
if(input[i]!=comp){
	if(input[i]<comp){
	
comp=comp+1;
mov+=1;
}
}
}
else{
	i++;
	y=1;
	fin+=1;
}
if(y==1){
if(input[i]>comp){
if(input[i]!=comp){
	comp=comp-1;
	mov+=1;
}
i++;
y=0;
fin+=1;
}
	
}

	
}
while (fin!=siz);
cout<<mov;
return 0;
}