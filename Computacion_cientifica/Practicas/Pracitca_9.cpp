// _Martin Isai Nuñez Villeda_
// Newton-Raphson Method

#include <iostream>
#include <cmath>

using namespace std;

double equiserre(double xi, double Fxi, double Fdxi) {
    return xi - (Fxi / Fdxi);
}

/*double fdx(double x) {
    return pow(x, 4) - 6 * pow(x, 3) + 12 * pow(x, 2) - 10 * x + 3;
}*/
/*
double fprimdx(double x) {
    return 4 * pow(x, 3) - 18 * pow(x, 2) + 24 * x - 10;  // Corrected derivative
}
*/

double fdx(double x) {
    return pow(x,10)-1;
}

double fprimdx(double x) {
    return 10*pow(x,9);
}


double NR(double X0, double Es, int imax) {
    double xr = X0, Fxi = 0, Fdxi = 0, xr_old = 0;
    int iter = 0;
    double Ea = 100;  

    cout << "Iter\t\txr\t\t\txr_old\t\t\tEa(%)\n";

    do {
        xr_old = xr;

        Fxi = fdx(xr_old);
        Fdxi = fprimdx(xr_old);

        if (Fdxi == 0) {
            cout << "Derivative is zero. Stopping iteration." << endl;
            return xr_old;
        }

        xr = equiserre(xr_old, Fxi, Fdxi);
        iter++;

        if (xr != 0) {
            Ea = abs((xr - xr_old) / xr) * 100;
        }

        cout << iter << "\t\t" << xr << "\t\t" << xr_old << "\t\t" << Ea << "%\n";

        if (Ea < Es || iter >= imax) {
            break;
        }

    } while (true);

    cout << "\nLa raiz es: " << xr << endl;
    return xr;
}

int main() {
    double Es = 0.01; 
    int itermax = 100;

    double raiz = NR(1.1, Es, itermax);
    
    return 0;
}
