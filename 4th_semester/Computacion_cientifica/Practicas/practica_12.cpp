#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


void sub_regre(float x[],float y[],float a1,float a0,float Sxy,float r2){
	float sumx=0,sumxy=0,st=0;
	float sumy=0,sumx2=0,sr=0;
	int i=0;
	int n=8;
	do{
		sumx+=x[i];
		sumy+=y[i];
		sumxy+=x[i]*y[i];
		sumx2+=pow(x[i],2);
		i++;
	}while(i<n);
	
	float xm=sumx/n;
	float ym=sumy/n;
	
	a1=(n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
	a0=ym-a1*xm;
	i=0;
	do{
		st+=pow((y[i]-ym),2);
		sr+=pow((y[i]-a1*x[i]-a0),2);
		i++;
	}while(i<n);
	
	Sxy=pow((sr/(n-2)),0.5);
	r2=(st-sr)/st;
	
	cout<<"Regresion lineal"<<endl;
	cout<<"a0"<<setw(10)<<"a1"<<setw(10)<<"sxy"<<setw(10)<<"r2"<<endl;
	cout<<a0<<setw(10)<<a1<<setw(10)<<Sxy<<setw(10)<<r2<<endl;
	
	return;
}



int main(){
int n=8;
float a_1,a_0,r2,Sxy;
float x[8]={1,2,2,3,4,4,5,6};
float y[8]={2,3,4,4,4,6,5,7}; 

sub_regre(x,y,a_1,a_0,Sxy,r2);
	
	return 0;
}