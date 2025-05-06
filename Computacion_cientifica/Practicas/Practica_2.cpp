#include <bits/stdc++.h>
using namespace std;

const float gravedad = 9.81;

double aprox(float gravedad, float masa, float coe, float increm, int i) {
    double v_prev = (i == 0) ? 0 : aprox(gravedad, masa, coe, increm, i - 1);
    double res = (gravedad - (coe * v_prev / masa)) * increm + v_prev;
    return res;
}

double exact(float gravedad, float masa, float coe, float increm, int i) {
    double t = increm * i;
    double res = (gravedad * masa / coe) * (1 - exp(-coe / masa * t));
    return res;
}

int main() {
    float coe = 0;
    int iter = 0;
    float masa = 0;
    float increm = 0;

    cout << "Ingresa la masa del paracaidista: " << endl;
    cin >> masa;

    cout << "Ingresa el coeficiente de resistencia al aire: " << endl;
    cin >> coe;

    cout << "Ingresa el incremento de segundos por iteracion: " << endl;
    cin >> increm;

    cout << "Cuantas iteraciones quieres realizar?" << endl;
    cin >> iter;
    system("cls");

    cout << "Aproximada\tExacta\t\tError" << endl;

    for (int i = 0; i <= iter; i++) {
        double aprox_val = aprox(gravedad, masa, coe, increm, i);
        double exact_val = exact(gravedad, masa, coe, increm, i);
        double error = abs(aprox_val - exact_val);
        cout << fixed << setprecision(4) << aprox_val << "\t\t" << exact_val << "\t\t" << error << endl;
    }

    return 0;
}
