// _Martin Nuñez Villeda_
// presicion y serie de mclaurin
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

double fact(int n){
	double factorial=1;
 	for(int i=1;i<=n;i++){
 		factorial*=i;
	 }
	 return factorial;
}

double E_rr(double x, double sum) {	
    return abs(exp(x) - sum) / exp(x) * 100;
}

/*float mcl_ex(){	
	float aprox=1+x;
	for(int i=2;i<nveces;i++){
		aprox+=pow(x,i)/(fact(i));
	}	
	return aprox;
}*/
/*Aqui queria hacerlo como funcion pero dados lo requerimietos del programa era mejor tener una 
version modificada en el main*/


int main(){
int i=0, x=0;
double aprox=1;
double ant=aprox;
double sum=aprox;
cout<<"ingrese el valor de x para la serie de mclourin \n";
cin>>x;

cout<<endl;

cout<<"iteracion"<<" "<< "termino"<<" "<<"sumatoria "<<"error relativo"<<endl;

cout<<i<<"\t"<< aprox<<setw(8)<<"\t"<<setw(8)<<sum<<"\t 100%"<<endl;
i++;
aprox+=x;
sum+=aprox;
cout<<i<<"\t"<< aprox<<setw(8)<<"\t"<<setw(8)<<sum<<"\t 99%"<<endl;

while(ant!=sum){
	ant=sum;
	aprox=pow(x,i)/(fact(i));
	sum+=aprox;
	cout<<i<<"\t"<<setw(8)<<aprox<<setw(8)<<"\t"<<sum<<"\t"<<E_rr(x,sum)<<"%"<<endl;
	i++;
};
		


cout<<"\n valor exacto:  "<<exp(x)<<endl;


return 0;
}
