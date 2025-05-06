#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string decimalToBaseIntegerPart(int integerPart, int base) {
    string digits = "0123456789ABCDEF";
    string result = "";
    while (integerPart > 0) {
        result = digits[integerPart % base] + result;
        integerPart /= base;
    }
    return result;
}

string decimalToBaseFractionalPart(double fractionalPart, int base, int precision) {
    string digits = "0123456789ABCDEF";
    string result = "";
    for (int i = 0; i < precision; ++i) {
        fractionalPart *= base;
        int fractionalDigit = static_cast<int>(fractionalPart);
        result += digits[fractionalDigit];
        fractionalPart -= fractionalDigit;
    }
    return result;
}

string decimalToBase(double decimal, int base, int precision) {
    if (base < 2 || base > 16) {
        return "Base no soportada. Solo bases entre 2 y 16 son aceptadas.";
    }
    int integerPart = static_cast<int>(decimal);
    double fractionalPart = decimal - integerPart;

    string result = decimalToBaseIntegerPart(integerPart, base);
    if (!result.empty()) {
        result += ".";
    }
    result += decimalToBaseFractionalPart(fractionalPart, base, precision);

    return result;
}

int main() {
    double decimal;
    int base, precision;
    cout << "Introduce el numero decimal: ";
    cin >> decimal;
    cout << "Introduce la base (entre 2 y 16): ";
    cin >> base;
    cout << "Introduce la precision (numero de digitos decimales): ";
    cin >> precision;
    
    string convertedNumber = decimalToBase(decimal, base, precision);
    cout << "Numero en base " << base << ": " << convertedNumber << endl;
    return 0;
}
