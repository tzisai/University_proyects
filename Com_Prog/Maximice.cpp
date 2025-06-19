// Martin Isai Nunez Villeda
// (-------)
//#pragma GCC optimize("Ofast,unroll-loops")//-0.0+0.0=-0  
//#pragma GCC target("avx2") // STL cointaner = std::allocator err
#include <bits/stdc++.h>

using ull = unsigned long long;
using ll = long long;
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end() 
#define yn(x) (cout << ((x) ? "YES" : "NO"))
#define dbg(...) cerr<<"LINE("<<__LINE__<<")->["<<#__VA_ARGS__<<"]: ["<<(__VA_ARGS__)<<"]\n";   
#define pb push_back 
#define F first
#define S second



bool checkPrimeNumber(int n) {
    bool isPrime = true;

    if (n == 0 || n == 1) {
        isPrime = false;
    }
    else {
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
}


/*int GD(int x){
    int gdc=0;
    for(int i=1;i<x;i++){
            if(x%i==0&&i!=x){
                gdc=i;
                cout<<gdc<<"\t";
            }
    }
    return gdc;
    
}*/

int main(){
ios::sync_with_stdio(0);cin.tie(0);

    //cin>>tc;
    int n,gdc =1,aux=0,cont=0,ant=0,y;
    int numbers[1000];
    cin>>n;

    

    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }

    cout<<endl;



    for(int i=0;i<n;i++){
        if(checkPrimeNumber(numbers[i])){
            y=numbers[i]-1;
        }
        else{
                for(int j=1;j<numbers[i];j++){
                    if(numbers[i]%j==0){
                for(int k=1;k<numbers[i];k++){
                        ant=aux;
                        aux=(j*k)+j;
                        if(aux>ant&& j*k<numbers[i]){
                            y=j*k;
                            }
                        }
                    }
                }
        }
       cout<<y<<endl;
        
    }

return 0;
}
