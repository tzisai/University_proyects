#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int input,num[50],numc,acum,comp;
	cin>>input;
	
	for (int i=0;i<=input;i++){
		cin>>num[i];
		numc=num[i]-1;
	
		do {
				if (num[i]&numc==0){
			cout<<'1';
		}
		comp=num[i]&numc;
		
		acum++;
		}
		while(num[i]&numc!=0);
		cout<<acum<<endl;
	}
	
	
	
	
	exit (0);
}