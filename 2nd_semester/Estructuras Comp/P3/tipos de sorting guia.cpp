#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/* 
Martin isai nuñez VIlleda 9 de julio de 2024
Objetivo: Crear un menu que segun la eleccion ejecute el metodo de ordenamiento o busqueda 
vistos en clase de los cuales se incluyen:

selection sort
merge sort
radix sort
heap  sort
shell sort
insertion sort
quick sort 

busqueda por hashing y binaria

*/
void printArray(int arr[], int size)
{
    
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
        cout << endl;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx,aux;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i){
        	aux= arr[min_idx];
        	arr[min_idx]=arr[i];
        	arr[i]=aux;
		}
           
    }
}

void merge(int array[], int const left, int const mid,int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne&& indexOfSubArrayTwo < subArrayTwo) {
    	
        if (leftArray[indexOfSubArrayOne]<= rightArray[indexOfSubArrayTwo]) {
        	
            array[indexOfMergedArray]= leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            
        }
        else {
            array[indexOfMergedArray]= rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]= leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]= rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// A utility function to get maximum
// value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[]
// according to the digit
// represented by exp.
void countSort(int arr[], int n, int exp)
{

    // Output array
    int output[n];
    int i, count[10] = { 0 };

    // Store count of occurrences
    // in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i]
    // now contains actual position
    // of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[],
    // so that arr[] now contains sorted
    // numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[]
// of size n using Radix Sort
void radixsort(int arr[], int n)
{

    // Find the maximum number to
    // know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit.
    // Note that instead of passing digit
    // number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}


// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

// Function to sort an array using
// insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[],int low,int high)
{
  //choose the pivot
  
  int pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i=(low-1);
  
  for(int j=low;j<=high-1;j++)
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

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

int main(){
	int chosse=0;
	int disorder[10];
	int search=0;
	
	do{
		for (int i=0;i<10;i++){
		disorder[i]=rand()%100000 + 100000;
		}
		system("cls");
	cout<<"		Metodos de Ordenacion"<<endl;
	cout<<"(1)Ordenacion por seleccion"<<endl;
	cout<<"(2)Ordenacion por Mezcla directa"<<endl;
	cout<<"(3)Ordenacion metodo Radix"<<endl;
	cout<<"(4)Ordenacion Heap Sorting"<<endl;
	cout<<"(5)Ordenacion Shell"<<endl;
	cout<<"(6)Ordenacion por insercion"<<endl;
	cout<<"(7)Quicksort"<<endl;
	cout<<"		Metodos de Busqueda"<<endl;
	cout<<"(8)Busqueda Binaria"<<endl;
	cout<<"(9)Busqueda por hashing"<<endl;
	cout<<"(10)Salir "<<endl;
	cin>>chosse;
		
		switch(chosse){
			
			case 1:{
				  int n = sizeof(disorder) / sizeof(disorder[0]);
				cout<<"array desordenado"<<endl;
				printArray(disorder,10);
				selectionSort(disorder,n);
				cout<<"array ordenado"<<endl;
				printArray(disorder,10);
				system("pause");
				break;
			}
			case 2:{
					int n = sizeof(disorder) / sizeof(disorder[0]);
				cout<<"array desordenado"<<endl;
				printArray(disorder,10);
				mergeSort(disorder,0,n-1);
				cout<<"array ordenado"<<endl;
				printArray(disorder,10);
				system("pause");
				break;
			}
			
			case 3:{
				int n = sizeof(disorder) / sizeof(disorder[0]);
				cout<<"array desordenado"<<endl;
				printArray(disorder,10);
				radixsort(disorder,n);
				cout<<"array ordenado"<<endl;
				printArray(disorder,10);
				system("pause");
				
				break;
			}
			
		 	case 4:{
		 		
				int n = sizeof(disorder) / sizeof(disorder[0]);
				cout<<"array desordenado"<<endl;
				printArray(disorder,10);
				heapSort(disorder,n);
				cout<<"array ordenado"<<endl;
				printArray(disorder,10);
				system("pause");
				
				break;
			}
			
			case 5:{
				int n = sizeof(disorder) / sizeof(disorder[0]);
				cout<<"array desordenado"<<endl;
				printArray(disorder,10);
				shellSort(disorder,n);
				cout<<"array ordenado"<<endl;
				printArray(disorder,10);
				system("pause");
				
				break;
			}
			
			case 6:{
				int n = sizeof(disorder) / sizeof(disorder[0]);
				cout<<"array desordenado"<<endl;
				printArray(disorder,10);
				insertionSort(disorder,n);
				cout<<"array ordenado"<<endl;
				printArray(disorder,10);
				system("pause");
				break;
			}
			case 7:{
					int n = sizeof(disorder) / sizeof(disorder[0]);
				cout<<"array desordenado"<<endl;
				printArray(disorder,10);
				quickSort(disorder,0,n-1);
				cout<<"array ordenado"<<endl;
				printArray(disorder,10);
				system("pause");
				break;
			}
			case 8:{
				printArray(disorder,10);
				cout<<"que numero deseas buscar?"<<endl;
				cin>>search;
				int n = sizeof(disorder) / sizeof(disorder[0]);
    		int result = binarySearch(disorder, 0, n-1 , search);
    		(result == -1)
        		? cout << "El elemento no esta en el array"<<endl
        		: cout << "El elemento esta en el array"<<endl;
        		system("pause");
				break;
			}
			case 9:{
				
				break;
			}
			case 10:{
				break;
			}
			default:{
				cout<<"Ingrese una opcion valida"<<endl;
				system("pause");
				break;
			}
		}
		
	}while(chosse!=10);
	
	
	return 0;
	
}








