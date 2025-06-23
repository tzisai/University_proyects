#include <iostream>
#include <stdlib.h>
using namespace std;

int partition(int arr[],int low,int high)
{
  //choose the pivot
  
  int pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i=(low-1);
  
  for(int j=low;j<=high;j++)
  {
    //If current element is smaller than the pivot
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}

// The Quicksort function Implement
           
void quickSort(int arr[],int low,int high)
{
  // when low is less than high
  if(low<high)
  {
    // pi is the partition return index of pivot
    
    int pi=partition(arr,low,high);
    
    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}

void busquedal(){
		int n=0;
	cout<<"ingresa el numero a buscar"<<endl;
	cin>>n;
	
	for(int i=0;i<10;i++){
		if(i=1){
			system("color 0A");
			cout<<vector1[1]<<"\t";
			system("color 7A");
		}
		else{
			cout<<vector1[1]<<"\t";
		}
	cout<<vector1[1]<<"\t";	
	cout<<vector1[2]<<"\t";	
	cout<<vector1[3]<<"\t";	
	cout<<vector1[4]<<"\t";	
	cout<<vector1[5]<<"\t";	
	cout<<vector1[6]<<"\t";	
	cout<<vector1[7]<<"\t";	
	cout<<vector1[8]<<"\t";	
	cout<<vector1[9]<<"\t";	
	cout<<vector1[10]<<"\t";	
	
}

void busquedaBin(){

}

int main(){
	
  
int vector1[10];
int vector2[10];	
	
	
	for(int i=0;i<10;i++){
		vector1[i]=rand% 100;
		vector2[i]=rand% 100;
	}
	
int n=sizeof(vector1)/sizeof(vector1[0]);
  quickSort(vector1,0,n-1);
	
	
int n=sizeof(vector2)/sizeof(vector2[0]);
  quickSort(vector2,0,n-1);
  
  	
	return 0;
}