#include <iostream>
#include <stdlib.h>
#include <windows.h> // Necesario para usar el comando system y Sleep en Windows

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void busquedaLineal(int arr[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == valor) {
            system("color 0A"); // Cambia a color verde sobre negro
            cout << arr[i] << "\t";
             Sleep(3500);
             break;
        } else {
            system("color 07"); // Cambia a color blanco sobre negro
            cout << arr[i] << "\t";
        }
        
        Sleep(1000); // Pausa de 1 segundo
    }
    cout << endl;
    system("color 07"); // Restablecer el color original
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

int main() {
    int vector1[10];
 
    
    // Inicializar los vectores con valores aleatorios
    
    for (int i = 0; i < 10; i++) {
        vector1[i] = i+1;
     
    }
    int n = sizeof(vector1) / sizeof(vector1[0]);
    quickSort(vector1, 0, n - 1);

    
    int valor;
    cout << "Ingresa el numero a buscar: ";
    cin >> valor;
   
    cout << "Busqueda Lineal:\n";
    busquedaLineal(vector1, n, valor);
    
     int result = binarySearch(vector1, 0, n - 1, valor);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    

    return 0;
}
