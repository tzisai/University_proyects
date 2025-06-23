#include <iostream>
using namespace std;

int main(){
    float trabajo=147.15;
    float T_f=19.62;
    float d=0;
do {
    trabajo-=T_f;
    
    if (trabajo<T_f){
        d=trabajo/19.62;
        break;
    }

}while(trabajo<0);
cout<<"la distanca recorrida es: "<<d<<endl;

    return 0;
}