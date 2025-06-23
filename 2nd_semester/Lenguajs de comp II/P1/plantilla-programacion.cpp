#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

int main(){
	
	int vectmulti[10][3];
	 
	 for(int i=0;i<10;i++){
	 		for(int j=0;j<2;j++){
		vectmulti[i][j]=rand() % 100 + 20-1 ;
		} 
 	cout<<vectmulti[i][0]<<"+"<<vectmulti[i][1]<<"="<<(vectmulti[i][0]+vectmulti[i][1])<<endl;
	
 }
 
	return 0;
	
}