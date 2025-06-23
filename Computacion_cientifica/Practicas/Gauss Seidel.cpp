#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define N 3
#define TOLERANCIA 1e-6
#define MAX_ITERACIONES 100

void gaussSeidel(float A[N][N], float b[N], float x[N]) {
    float x_prev[N];
    int iter = 0;

    for (int i = 0; i < N; i++) {
        x[i] = 0;
    }

    cout << fixed << setprecision(6);
    cout << "Iteracion\t";
    for (int i = 0; i < N; i++) {
        cout << "x" << i << "\t\t";
    }
    cout << "\n------------------------------------------------------------\n";

    while (iter < MAX_ITERACIONES) {
        for (int i = 0; i < N; i++) {
            x_prev[i] = x[i];
        }

        for (int i = 0; i < N; i++) {
            float suma = b[i];

            for (int j = 0; j < N; j++) {
                if (j != i) {
                    suma -= A[i][j] * x[j];
                }
            }

            x[i] = suma / A[i][i];
        }

        cout << iter + 1 << "\t\t";
        for (int i = 0; i < N; i++) {
            cout << x[i] << "\t";
        }
        cout << endl;

        float error = 0;
        for (int i = 0; i < N; i++) {
            error += fabs(x[i] - x_prev[i]);
        }

        if (error < TOLERANCIA) {
            break;
        }

        iter++;
    }

    cout << "\nSolucion encontrada en " << iter + 1 << " iteraciones:\n";
    for (int i = 0; i < N; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
}

int main() {
    // Matriz aumentada 
    float aumentada[N][N + 1] = {
        {20.0, 1.0, -2.0, 17.0},
        {2.0, -3.0, 20.0, 25.0},
        {3.0, 20.0, -1.0, 18.0}
    };

    float A[N][N];
    float b[N];
    float x[N];

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = aumentada[i][j];
        }
        b[i] = aumentada[i][N];
    }

    gaussSeidel(A, b, x);

    return 0;
}
