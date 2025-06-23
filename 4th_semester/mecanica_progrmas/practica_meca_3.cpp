#include <iostream>
using namespace std;

int main(){
    float trabajo=147.15;
    float T_f=1.56;
    float d=0;
do {
    trabajo-=T_f;
    cout<<trabajo<<endl;
    if (trabajo<T_f){
        d=trabajo/1.56;
        break;
    }

}while(true);
cout<<"la distanca recorrida es: "<<d*2<<endl;

    return 0;
}