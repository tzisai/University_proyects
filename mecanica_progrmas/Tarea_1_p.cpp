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


float V_corr1=6.2,V_corr2=5.5;
float pista_t=400;

float dist=400;
float res1=0,res2=0;

int vueltas1=0;
int vueltas2=0;

int time=0;
int main(){
		    
    do{
    	
    res1+=6.2;	
    res2+=5.5;	
    		
    (if res1>=400){
    vueltas1++;
	res1-=400;	
	}
	 		
    (if res2>=400){
    vueltas2++;	
    res-=400;
	}
	
	time++;
		
	if(res1==res2){
		return;
	}	
    		
	}while(res1!=res2)
	
	dist1=(vueltas1*400)+res1;
	dist2=(vueltas2*400)+res2;
    
    cout<<"el tiempo que toma en encontrarse aproximadamente es de "<< time
    cout<<"el corredor uno recorrio "<<dist1<<endl;
    cout<<"el corredor dos recorrio "<<dist2<<endl;
    
    
return 0;
}
