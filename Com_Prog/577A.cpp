// Martin Isai Nunez Villeda
// (577A)
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

int main(){
ios::sync_with_stdio(0);cin.tie(0);
//freopen("in.txt", "r", stdin);
    int tc=1;
    //cin>>tc;
    int n;
    int h;
    int a [1000]={};
    int M_H=0;
    
        cin>>n;
        cin>>h;
        for(int i=0;i<n;++i){
            cin>>a[i];
            if(a[i]>h){
                M_H+=2;
            }
            else{
                M_H++;
            }          
    }
    cout<<M_H<<endl;
return 0;
}
