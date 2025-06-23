#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>

using namespace std;

//punteros i
int main(){
    setlocale( LC_ALL, "" );

    string proposicion, prop;
    int len, columnas=0, count;
    char negacion = '~';

    getline(cin, proposicion);
    prop = proposicion;
    
    proposicion.erase(remove_if(proposicion.begin(), proposicion.end(), ::isspace), proposicion.end());

    len = proposicion.length();
    cout<<len<<endl;

    for(int i = 0; i < len; i++){
        if(isalpha(proposicion[i])){
            columnas++;
        }
    }
    for(int i = 0; i < len; i++){
        count=1;
        for(int j = i+1; j < len; j++){
            if(isalpha(proposicion[i]) == proposicion[j]){
                count++;
                proposicion[j] = '0';
            }
        }
        if(count > 1 && proposicion[i] != '0'){
            columnas--;
        }
    }

    for (int row = 0; row < (1 << columnas); ++row) {
        cout << "|";
        for (int i = 0; i < columnas; ++i) {
            bitset<1> bit(i & (1 << (columnas - 1 - i)));
            cout << "   " << ((row & (1 << (columnas - 1 - i))) ? 1 : 0) << "        |";
        }
        if(proposicion.find(negacion) != string::npos){
            for (int i = 0; i < columnas; ++i) {
                bitset<1> bit(i & (1 << (columnas - 1 - i)));
                cout << "   " << (!(row & (1 << (columnas - 1 - i))) ? 1 : 0) << "        |";
            }
        }
        
        /*
        And &
        OR ^
        Implicación $
        Doble Implicación 
        */

        cout<<endl;
    }

    return 0;
}