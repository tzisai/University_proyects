#include <bits/stdc++.h>
using namespace std;

string transformTB(const string& input) {
    string trans = "";
    for (char c : input){
        if (c == 'G' ) trans += '1';
        else if (c == 'g')trans += '0';
        else if (c == '-' || c == '+') trans += '2';
    }
    return trans;
}

bool isequal(const string& a, const string& b){
    for (int i = 0; i < a.length(); i++){
        if (a[i] != b[i]) return false;
    }
    return true;
}

char imposible(const string& aux){
    for (char c : aux){
        if (c == '-' || c == '+') return '*';
    }
    return ' ';
}

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string numbers[10] = {
        "1110111", // 0
        "0000011", // 1
        "0111110", // 2
        "0011111", // 3
        "1001011", // 4
        "1011101", // 5
        "1111101", // 6
        "0010011", // 7
        "1111111", // 8
        "1011111"  // 9
    };

    vector<string> LEDS(n);
    vector<string> aux(n);
    string final = "";

    for (int i = 0; i < n; i++) {
        cin >> LEDS[i];
        cout << imposible(LEDS[i]);
        aux[i] = transformTB(LEDS[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 10; k++) {
            if (isequal(numbers[k], aux[i])) {
                final += to_string(k);
                break; 
            }
        }
    }

    cout << endl << final << endl;

    return 0;
}
