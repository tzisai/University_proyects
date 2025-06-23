
/* 
Alan Fernando Martinez Moreno 
Alan Torres Ruiz
Martin Isai Nuñez Villeda
ICI Ingenieria en computacion Inteligente 3er semestre


*/



#include <iostream>
#include <vector>
#include <cmath>

// Función para generar todas las combinaciones de un conjunto dado
void generarCombinacionesConBits(const std::string& conjunto) {
    int n = conjunto.size(); // Número de elementos en el conjunto
    int numCombinaciones = pow(2, n); // Total de combinaciones (2^n)

    // Iterar sobre todos los subconjuntos posibles
    for (int i = 0; i < numCombinaciones; i++) {
        std::string combinacion = "";
        std::string bits = "";

        // Generar cada subconjunto
        for (int j = 0; j < n; j++) {
            // Verificar si el bit j está activado en i (subconjunto)
            if (i & (1 << j)) {
                combinacion += conjunto[j]; // Añadir el carácter al subconjunto
                bits += '1'; // Bit activo
            } else {
                bits += '0'; // Bit inactivo
            }
        }

        // Mostrar la combinación generada y su representación en bits
        std::cout << bits << " -> " << combinacion << std::endl;
    }
}

int main() {
    std::string conjunto; // Conjunto de caracteres
    std::cout<<"ingrese la cadena de caracteres que corresponda al conjunto inicial"<<std::endl;
    std::cin>>conjunto;
    std::cout << "Las combinaciones posibles del conjunto '" << conjunto << "' son:\n";
    generarCombinacionesConBits(conjunto);
    return 0;
}
