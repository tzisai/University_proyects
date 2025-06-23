#include <iostream>
#include <string.h>

class figura {
	
protected:
	int altura,base;
public:
	~figura();
	virtual void setBnA(int,int);
	virtual void getN(int);
};

class cuadrado :public figura{
	private:
		int lado;
	public:
		void setBnA(int);
		void perimetroC(int);
		void areaC(int);
};

class rectangulo :public figura{
	private:
		int baseR,alturaR;
	public:
	void perimetroR(int,int);
	void areaR(int,int);	
	void setBnA(int);
};
class triangulo :public figura{
	private:
		int baseT,altT;
	public:
	void perimetroT(int,int,int);
	void areaT(int,int);	
	void setBnA(int);
};

class circulo:public figura{
	private:
		int radio;
		public:
			circulo(int);
			~circulo();
		void areaC(int,int);
		void PerimetroC(int,int);
		void getN(int);
};

void figura::setBnA(int bas, int alt){
	altura=alt;
	base=bas;
}

figura::~figura(){
	std::cout<<"figura borrada"<<std::endl;
}

void triangulo::perimetroT(base,altura){
	int Perimetro=0;
	Perimetro=
	std::cout<<"El perimetro es de "<<Perimetro<<std::endl;
}
void triangulo::areaT(base,altura){
	int area=0;
	
	area=(base*altura)/2);
	
}






using namespace std;
int main(){
	
	int chosse =0;
	
	do{
		cout<<"Calculo de area y perietros"<<endl;
		cout<<"\tCuadrado(1)"<<endl;
		cout<<"\tTriangulo(2)"<<endl;
		cout<<"\tRectangulo(3)"<<endl;
		cout<<"\tCirculo(3)"<<endl;
		cout<<"\tSalir(4)"<<endl;
		cout<<"Seleccione Oportunamente"<<endl;
		cin>>chosse;
			switch(chosse){
			case 1:{
				break;
			}	
			case 2:{
				int elec;
				system("CLS");
				cout<<"Tu triangulo es equilatero?"<<endl;
				cout<<"Escriba el numero segun sea el caso (1) si | (0)no"<<endl;
				cin>>elec;
				if(elec==1){
					
				}
				else if(elec==0){
					
				}
				else{
					cout<<"ingrese un numero valido"<<endl;
				}
				break;
			}
			case 3:{
				break;
			}	
			case 4:{
				break;
			}	
			}
	}while(chosse!=4);
 
	
	return 0;
}