#include <iostream>
#include <string>
using namespace std;

string transformar(int base,float input){
    string res="";
    int entero=0;
    float decimal=0;
    entero=input;
    decimal=input-entero;
    while(entero>0){
        res=to_string(entero%base)+res;
        entero=entero/base;
    }
    res+=".";
    for(int i=0;i<10;i++){
        decimal*=base;
        res+=to_string(int(decimal));
        decimal-=int(decimal);
    }
    return res;
}


int main(){

int base=0;
float input=0;
bool key=1;

while(key==1){
cout<<"ingresa el numero a transformar"<<endl;
cin>>input;
cout<<"ingresa la base del numero a transformar"<<endl;
cin>>base;
cout<<transformar(base,input)<<endl;



}










    return 0;
}