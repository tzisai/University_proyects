#include <iostream>
#include <vector>//use vector para que sea como las listsas de python.
#include <cmath>//para las potencias
#include <numeric>//Acummulate es como sum en python

using namespace std;

int main() {
    int degree = 5;
    vector<double> x = {0, 5, 10, 15, 20, 25, 30};
    vector<double> y = {0.0000, 1.5297, 9.5120, 8.7025, 2.8087, 1.0881, 0.3537};

    vector<double> sums;
    sums.push_back(x.size());

    vector<double> temp = x;

    for (int i = 1; i <= degree * 2; ++i) {
        vector<double> temp(x.size());
        for (size_t j = 0; j < x.size(); ++j) {
            temp[j] = pow(x[j], i);
        }
        sums.push_back(accumulate(temp.begin(), temp.end(), 0.0));
    }

    cout << "sums: ";
    for (double s : sums) {
        cout << s << " ";
    }
    cout<<endl;

    vector<double> b;

    temp.resize(x.size());
    for (size_t i = 0; i < x.size(); ++i) {
        temp[i] = pow(x[i], 0) * y[i];
    }
    b.push_back(accumulate(temp.begin(), temp.end(), 0.0));

    for (int i = 1; i <= degree; ++i) {
        for (size_t j = 0; j < x.size(); ++j) {
            temp[j] = pow(x[j], i) * y[j];
        }
        b.push_back(accumulate(temp.begin(),temp.end(), 0.0));
    }

    cout << "b: ";
    for (double value : b) {
        cout << value << " ";
    }
    cout << endl;

    vector<vector<double>> a(degree + 1, vector<double>(degree + 1));

    for (int i = 0; i <= degree; ++i) {
        for (int j = 0; j <= degree; ++j) {
            a[i][j] = sums[i + j];
        }
    }

    cout <<"a:"<<endl;
    for (const auto& row : a) {
        for (double val : row) {
            cout<<val<< " "<<endl;
        }
        cout << endl;
    }

    return 0;
}