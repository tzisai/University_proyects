// _autor_
// link y/o nombre del programa
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


float pos(float t,float gravedad){
	return 0.5*gravedad*pow(t,2);
}


int main(){
float gravedad=9.81;
float t=0;
float pos1=0,pos2=0;
float dif=0;
do
{
pos1=pos(t+1,gravedad);	
pos2=pos(t,gravedad);	

dif=pos1-pos2;

if(dif>10.2&&dif<10.4){
	cout<<endl<<t+1;
	break;
}

else{
	cout<<dif<<"\t";
}

t+=0.0001;
}
while(dif!=10);





return 0;
}
