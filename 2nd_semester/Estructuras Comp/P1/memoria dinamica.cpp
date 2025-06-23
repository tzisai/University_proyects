#include<iostream>
#include<stdlib.h>
using namespace std;

 main(){
	
//memoria dinamica
	int N;
	int *vector;
//declaracion de punteros int 
	int *ptr;
	int *ptr2;

	ptr=(int*)malloc(30*sizeof(int));//redinicion de espacio en el puntero con el uso de malloc

	int vect [5]={5,7};
	vect [2];
	for(int i=0;i<2;i++){
		cout<<(*(ptr+i))<<endl;
	}
	
	
	
	
	return 1 ;
}