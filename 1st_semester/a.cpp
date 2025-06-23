#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
int n=0,comp=0,menor=0,mayor=0,key=1,stw=0,it=0;
int nVec[n];
cin>>n;
for(int i=0;i<n;i++){
cin>>nVec[i];
//cout<<nVec[i];
}

for(int j=0;j<n;j++){
comp=nVec[j];
key=1;
while(key==1){
	menor=0;
	mayor=0;
	if(nVec[j]<nVec[j+1]){
menor++;
}
else{
mayor++;	
}
if(mayor==1&&menor==1){
	stw=stw+1;
	key=0;
}
if()
it++;
}

}

cout<<"a";	
	
	
	return 0;
	
}