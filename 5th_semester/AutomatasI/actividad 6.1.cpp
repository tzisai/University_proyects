#include <iostream>
#include <string>
using namespace std;

enum State1 { Q0=0, Q1=1, Q2=2, Q3=3 };      
enum State2 { P0=0, P1=1, P2=2, P3=3, P4=4, Dead=5 }; 


const char* name1(State1 s) {
    switch(s){ case Q0:return"q0";case Q1:return"q1";case Q2:return"q2";case Q3:return"q3";}
    return"?";
}
const char* name2(State2 s) {
    switch(s){ case P0:return"q0";case P1:return"q1";case P2:return"q2";case P3:return"q3";case P4:return"q4";case Dead:return"∅";}
    return"?";
}


State1 transicion1(State1 s,char e){
    switch(s){
        case Q0: return (e=='0')?Q2:(e=='1')?Q1: s;
        case Q1: return (e=='0')?Q3:(e=='1')?Q0: s;
        case Q2: return (e=='0')?Q0:(e=='1')?Q3: s;
        case Q3: return (e=='0')?Q1:(e=='1')?Q2: s;
    }
    return s;
}


State2 transicion2(State2 s,char e){
    switch(s){
        case P0: if(e=='0') return P1; if(e=='1') return Dead; break;
        case P1: if(e=='1') return P2; if(e=='0') return Dead; break;
        case P2: if(e=='0') return P3; if(e=='1') return P2; break;
        case P3: if(e=='0') return P3; if(e=='1') return P4; break;
        case P4: if(e=='0') return P3; if(e=='1') return P2; break;
        case Dead: return Dead;
    }
    return s;
}

int main(){
    bool seguir=true;
    while(seguir){
        cout<<"Seleccione el Automata a probar\n";
        cout<<"1) Automata ejercicio 1 (final: q0)\n";
        cout<<"2) Automata ejercicio 3 (final: q1)\n";
        cout<<"X) Salir\n> ";
        char elect; cin>>elect;
        switch(elect){
            case '1':{
                cout<<"\n--- Automata ejercicio 1 ---\n";
                State1 estado=Q0;
                while(true){
                    cout<<"Estado actual: "<<name1(estado)<<" | entrada = ";
                    char in;cin>>in;
                    if(in=='x'||in=='X'){
                        bool acept=(estado==Q0);
                        cout<<"\nCadena "<<(acept?"ACEPTADA":"RECHAZADA")<<" (estado final "<<name1(estado)<<")\n\n";
                        break;
                    }
                    if(in!='0'&&in!='1'){ cout<<"Entrada invalida\n"; continue;}
                    estado=transicion1(estado,in);
                }
                break;
            }
            case '2':{
                cout<<"\n--- Automata ejercicio 3 ---\n";
                State2 estado=P0;
                while(true){
                    cout<<"Estado actual: "<<name2(estado)<<" | entrada = ";
                    char in;cin>>in;
                    if(in=='x'||in=='X'){
                        bool acept=(estado==P1);
                        cout<<"\nCadena "<<(acept?"ACEPTADA":"RECHAZADA")<<" (estado final "<<name2(estado)<<")\n\n";
                        break;
                    }
                    if(in!='0'&&in!='1'){ cout<<"Entrada invalida\n"; continue;}
                    estado=transicion2(estado,in);
                }
                break;
            }
            case 'X':case 'x': seguir=false; break;
            default: cout<<"Opcion invalida\n";
        }
    }
    cout<<"Adios!\n";
}
