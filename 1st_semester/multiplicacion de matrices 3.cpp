//Martin Isai Nu;ez Villeda ICI 1er semestre 4 de noviembre de 2023.
//Multiplicacion de Matrices con valores ingresados por el usuario .
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int A[10][10], B[10][10], R[10][10];
    int filA, columA, filB, columB;

    srand(time(NULL));

    do {
        cout << "Proporcione las dimensiones de la matriz A (filas y columnas separadas por espacio), minimo 2 maximo 10: ";
        cin >> filA >> columA;
        cout << "Proporcione las dimensiones de la matriz B (filas y columnas separadas por espacio), minimo 2 maximo 10: ";
        cin >> filB >> columB;
    } while (filA<2||filA>10||columA<2||columA>10||filB< 2||filB> 10||columB<2||columB>10||columA!=filB);

    cout << "Matriz A" << endl;
    for (int i= 0;i<filA;++i) {
        for (int j=0;j<columA;++j) {
            printf("Dame el valor de [%d][%d] de la 1er matriz\n",i,j);
			cin>>A[i][j];
        }
        cout << endl;
    }

    cout << "Matriz B" <<endl;
    for (int i=0;i<filB;++i) {
        for (int j=0; j<columB;++j) {
        	printf("Dame el valor de [%d][%d] de la 2da matriz\n",i,j);
            cin>>B[i][j];
        }
        cout << endl;
    }

cout << "Matriz A" << endl;
    for (int i= 0;i<filA;++i) {
        for (int j=0;j<columA;++j) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

	cout << "Matriz B" <<endl;
    for (int i=0;i<filB;++i) {
        for (int j=0; j<columB;++j) {
            cout <<B[i][j]<< "\t";
        }
        cout << endl;
    }

    cout << "Matriz Resultante" << endl;
    for (int i=0;i<filA;++i) {
        for (int j=0;j<columB;++j) {
            R[i][j] = 0;
            for (int z=0;z<filB;++z) {
                R[i][j] += A[i][z] * B[z][j];
            }
            cout<<R[i][j]<<"\t";
        }
        cout << endl;
    }

    return 0;
}
