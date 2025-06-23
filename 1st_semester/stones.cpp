#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n,acum;
	string stone;
	char comp;
	cin>>n;
	cin>>stone;
	
	for (int i=0;i<n;i++){
		comp=(stone[i+1]);
		
		if(stone[i]==comp){
			acum++;
		}
	}
	
	cout<<acum;		                          
	exit (0);        
}