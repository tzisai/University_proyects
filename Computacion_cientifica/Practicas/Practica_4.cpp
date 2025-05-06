// _autor_
// link y/o nombre del programa
//#pragma GCC optimize("Ofast,unroll-loops")//-0.0+0.0=-0  
//#pragma GCC target("avx2") // STL cointaner = std::allocator err
#include <bits/stdc++.h>
#include <iomanip>
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


void Hexx(float num){
	unsigned int Hex;

    cout<<"ingresa un numero a transformar :"<<endl;
    cin>>num;
    
    memcpy(&Hex,&num,sizeof(num));
    
    cout<<num<<" es:"<<hex<<uppercase<<setw(8)<<setfill('0')<<Hex<<dec<<endl;
}

void comp(){
	
	floatz comp=20.08+2.01;
	
	if(comp==22.09){
	cout<<"20.08+2.01 es igual a  22.09"<<endl;
		cout<<comp<<endl;
	}
	else{
	cout<<"20.08+2.01 no es igual a  22.09"<<endl;
	cout<<comp<<endl;
	}
}

void suma(){
	float chiquito=0;
	
	
	for(int i=0;i<100000000;i++){
		chiquito+=0.00001;
			
	}
	cout<<chiquito;
	
}


int main(){
//ios::sync_with_stdio(0);cin.tie(0);
//freopen("in.txt", "r", stdin);

float num;
Hexx(num);
comp();
suma();
    
    
    
return 0;
}
