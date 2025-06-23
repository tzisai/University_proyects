#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// Declaraciones de funciones
void imprimir_tabla_verdad(char *expresion, int n, int **matriz);
int evaluar_expresion(char *expresion, int *valores);

// Función principal
int main() {
  // Declaraciones de variables
  char expresion[100];
  int n;
  int **matriz;

  // Solicita la expresión lógica
  printf("Ingrese una expresión lógica: ");
  fgets(expresion, sizeof(expresion), stdin);

  // Obtiene el número de variables
  n = contar_letras_unicas(expresion);

  // Reserva memoria para la matriz
  matriz = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    matriz[i] = malloc(2 * sizeof(int));
  }

  // Imprime la cabecera de la tabla
  printf("P | Q | %s\n", expresion);

  // Itera sobre todas las combinaciones de valores de las variables
  for (int i = 0; i <= 1; i++) {
    matriz[0][i] = i;
    for (int j = 0; j <= 1; j++) {
      matriz[1][j] = j;

      // Imprime el valor de las variables
      printf("%d | %d | ", matriz[0][i], matriz[1][j]);

      // Evalúa la expresión lógica
      matriz[2][i * 2 + j] = evaluar_expresion(expresion, matriz);
    }
  }

  // Imprime la matriz
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  // Libera la memoria asignada
  for (int i = 0; i < n; i++) {
    free(matriz[i]);
  }
  free(matriz);

  return 0;
}

// Función para imprimir la tabla de verdad
void imprimir_tabla_verdad(char *expresion, int n, int **matriz) {
  // Declaraciones de variables
  int i, j;

  // Imprime la cabecera de la tabla
  printf("P | Q | %s\n", expresion);

  // Itera sobre todas las combinaciones de valores de las variables
  for (i = 0; i <= 1; i++) {
    matriz[0][i] = i;
    for (j = 0; j <= 1; j++) {
      matriz[1][j] = j;

      // Imprime el valor de las variables
      printf("%d | %d | ", matriz[0][i], matriz[1][j]);

      // Evalúa la expresión lógica
      printf("%d\n", matriz[2][i * 2 + j]);
    }
  }
}

// Función para evaluar una expresión lógica
int evaluar_expresion(char *expresion, int *valores) {
  // Declaraciones de variables
  int valor;

  // Itera sobre la expresión lógica
  for (valor = 0; valor < strlen(expresion); valor++) {
    // Obtiene el operador lógico actual
    char operador = expresion[valor];

    // Evalúa el operador lógico
    switch (operador) {
      case '^':
        valor = (valor || evaluar_expresion(expresion + valor + 1, valores));
        break;
      case 'v':
        valor = (valor && evaluar_expresion(expresion + valor + 1, valores));
        break;
      case '~':
        valor = !evaluar_expresion(expresion + valor + 1, valores);
        break;
      default:
        // Si el operador no es válido, devuelve un error
        return -1;
    }
  }

  // Devuelve el valor de la expresión
  return valor;
}
