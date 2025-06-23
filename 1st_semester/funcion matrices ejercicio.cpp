//Martin Isai Nu;ez Villeda ICI 1er semestre 14 de noviembre de 2023.
//Multiplicacion de Matrices con valores ingresados por el usuario con funciones .
#include <cstdlib>
#include <ctime>
#include <stdio.h>

#define MAX 30
#define MAXC 30

void MaRe(int Matriz[][MAX],int cont,int colB,int filB){
	printf("Matriz B\n");
    for (int i=0;i<filB;++i) {
        for (int j=0; j<colB;++j) {
        	printf("Dame el valor de [%d][%d] de la %d matriz\n",i,j,cont);
            scanf("%d",&Matriz[i][j]);
        }
        printf("\n");
    }
}

void printMa(int Matriz2[][MAX],int cont,int colA,int filA){
	printf("Matriz %d\n",cont);
    for (int i= 0;i<filA;++i) {
        for (int j=0;j<colA;++j) {
            printf("%d \t",Matriz2[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int A[MAX][MAXC], B[MAX][MAXC], R[MAX][MAXC];
    int filA, columA, filB, columB;

    do {
    	
    		printf("Proporcione las dimensiones de la matriz A (filas y columnas separadas por espacio), minimo 2 maximo 10: \n");
        scanf("%d %d",&filA ,&columA);
		
        
    		printf("Proporcione las dimensiones de la matriz B (filas y columnas separadas por espacio), minimo 2 maximo 10: \n");
       	 scanf("%d %d",&filB ,&columB);
		
	
    } while (filA<2||filA>10||columA<2||columA>10||filB< 2||filB> 10||columB<2||columB>10||columA!=filB);
    
    MaRe(A,1,columA,filA);
    MaRe(B,2,columB,filB);

	printMa(A,1,columA,filA);
	printMa(B,2,columB,filB);

    printf("Matriz Resultante\n");
    for (int i=0;i<filA;++i) {
        for (int j=0;j<columB;++j) {
            R[i][j] = 0;
            for (int z=0;z<filB;++z) {
                R[i][j] += A[i][z] * B[z][j];
            }
            printf("%d \t",R[i][j]);
        }
        printf("\n");
    }

    return 0;
}
