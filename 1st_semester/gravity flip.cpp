#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n,p=0;
	int a[100];
               
               cin>>n;
               for(int i=0;i<n;i++){
               	cin>>a[i];
			   }
			   
    // p = sizeof(a) / sizeof(a[0]);
     p=n;
	 sort(a,a + p);
	 
	  for (int j = 0; j < n; ++j){
	  	cout << a[j] << " ";
	  }
        
	
	
		             
					              
	exit (0);        
}