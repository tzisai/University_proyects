#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
	int A [10][10],B[10][10],R[10][10];
	int columA,filA,columB,filB;
	int i,j,z;
	srand(time(NULL));
	do{
		printf("\nProporcina la dimesion de la matriz A, minimo 2 maximo 10, fila y columna, separadas por coma\n");
		scanf("%d,%d",&filA,&columA);
		printf("\nProporcina la dimesion de la matriz B, minimo 2 maximo 10, fila y columna, separadas por coma\n");
		scanf("%d,%d",&filB,&columB);
	}
	while(filA<2||filA>10||columA<2||columA>10||filB< 2||filB> 10||columB<2||columB>10||columA!=filB);
	//while(columA<2&&columA>10&&columB<2&&columB>10&&filA<2&&filA>10&&columA!=filB);
	printf(" MatrizA\n");
	for(int i=0;i<filA;i++){
	printf("\n");
	for(j=0;j<columA;j++){
	
		A[i][j]=rand()%9+1;
		printf("%d\t",A[i][j]);
	}
}

	cout<<"Matriz B"<<endl;
	for(i=0;i<columB;i++){
		printf("\n");
		for (j=0;j<columB;j++){
			B[i][j]=rand()%9+1;
			printf("%d\t",B[i][j]);
			}
	}

	cout<<"Matriz Resultante"<<endl;
for(i=0;i<filA;i++){
	for(j=0;j<columB;j++){
		R[i][j]=0;
		for(z=0;z<filB;z++){
		R[i][j]=R[i][j]+(A[i][z]*B[z][j]);	
		}
	}
}


for(i=0;i<filA;i++){
	printf("\n");
	for(i=0;j<columB;j++){
		printf("\t%d",R[i][j]);
	}
}

printf(" \n\n");
system("PAUSE");
return 0;
}