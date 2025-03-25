#include <iostream>
#include <cmath> 
using namespace std;

double fdx(double x) {
    return pow(x,10)-1;
}


double FPM(double xl, double xu, double Es, int imax) {
    int iter = 0;
    double xr = xl;  
    double old_xr, fr, test, iu = 0, il = 0;
    double fl = fdx(xl);
    double fu = fdx(xu);
    double Ea = 100.0; 

    if (fl * fu > 0) {  
        cout << "No root exists within the given interval." << endl;
        return -1;  
    }

    do {
        old_xr = xr;
        xr = xu - (fu * (xl - xu)) / (fl - fu);  
        fr = fdx(xr);
        iter++;

        if (xr != 0) {
            Ea = abs((xr - old_xr) / xr) * 100;
        }

        test = fl * fr;

        if (test < 0) {
            xu = xr;
            fu = fdx(xu);
            iu = 0;
            il++;
            if (il >= 2) {
                fl /= 2; 
            }
        } else if (test > 0) {
            xl = xr;
            fl = fdx(xl);
            il = 0;
            iu++;
            if (iu >= 2) {
                fu /= 2;
            }
        }

        cout << "Iteration " << iter << ": xr = " << xr << ", Ea = " << Ea << "%" << endl;

        if (Ea <= Es || iter >= imax) {
            break;
        }

    } while (true);

    return xr;  
}

int main() {
    double xl = 0, xu = 1.3;  
    double Es = 0.0001;       
    int imax = 10;            

    double root = FPM(xl, xu, Es, imax);
    cout << "Approximate root: " << root << endl;

    return 0;
}
