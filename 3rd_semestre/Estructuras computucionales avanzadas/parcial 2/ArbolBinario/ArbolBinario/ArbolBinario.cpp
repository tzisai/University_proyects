/*
	Universidad Autónoma de Aguascalientes
	Ing. en Computación Inteligente
	Estructuras Computacionales Avanzadas (3-E)

	Autores:
		Alan Torres Ruiz
		Martín Isaí Nuñez Villeda
		Alan Fernando Martinez Moreno
	Profesor:
		Luis Fernando Gutiérrez Marfileño
	Descripción:
		El programa realiza operaciones en árboles como la inserción
		y despliege del árbol en postorden, inorden, preorden.
	Fecha:
		11/10/24
	Grupo:
		3°E
*/
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Nodo
{
	int dato;
	Nodo* izq;
	Nodo* der;
	Nodo* padre;
};

void menu();
bool isInteger(string);
Nodo* crearNodo(Nodo*, int);
void insertarNodo(Nodo*&, Nodo*, int);
void mostrarArbol(Nodo*, int);
bool buscarNodo(Nodo*, int);
//* Funciones para recorrer nodos *//
void preOrden(Nodo*);
void inOrden(Nodo*);
void postOrden(Nodo*);

Nodo* arbol = NULL;

int main()
{
	menu();
	return 0;
}

void menu()
{
	char opcion;
	string input;
	int validInput, contador = 0;

	system("cls");
	cout << " == Operaciones en árboles binarios ==			\n\n"
		<< "[1] Mostrar árbol								\n"
		<< "[2] Insertar nodo								\n"
		<< "[3] Recorrido Pre-Orden							\n"
		<< "[4] Recorrido In-Orden							\n"
		<< "[5] Recorrido Post-Orden						\n"
		<< "[6] Salir										\n\n"
		<< "Escribe una opcion: \n";
	cin >> opcion;

	system("cls");
	switch (opcion)
	{
	case '1':
		cout << " == Mostrar árbol ==					\n\n";
		mostrarArbol(arbol, contador);
		break;
	case '2':
		cout << " == Insertar nodo ==					\n\n";
		do
		{
			cout << "Ingresa el número a insertar: \n";
			cin >> input;
		} while (!isInteger(input));

		validInput = atoi(input.c_str());
		insertarNodo(arbol, NULL, validInput);
		break;
	case '3':
		cout << " == Recorrido Pre-Orden ==				\n\n";
		preOrden(arbol);
		break;
	case '4':
		cout << " == Recorrido In-Orden ==				\n\n";
		inOrden(arbol);
		break;
	case '5':
		cout << " == Recorrido Post-Orden ==			\n\n";
		postOrden(arbol);
		break;
	case '6':
		return;
	default:
		cout << "Has ingresado una opción incorrecta, inténtalo de nuevo. \n";
		system("pause");
		break;
	}
	cout << "\n";
	system("pause");
	menu();
}

Nodo* crearNodo(Nodo* padre, int n)
{
	Nodo* nuevoNodo = new Nodo();

	nuevoNodo->dato = n;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	nuevoNodo->padre = padre;

	return nuevoNodo;
}

void insertarNodo(Nodo*& arbol, Nodo* padre, int n)
{
	if (arbol == NULL) // Si el árbol está vacío
	{
		Nodo* nuevoNodo = crearNodo(padre, n);
		arbol = nuevoNodo;
	}
	else // Si el arbol NO está vacío
	{
		int valorRaiz = arbol->dato;
		if (n < valorRaiz)
		{
			insertarNodo(arbol->izq, arbol, n);
		}
		else
		{
			insertarNodo(arbol->der, arbol, n);
		}
	}
}

void mostrarArbol(Nodo* arbol, int cont)
{
	if (arbol == NULL) // Si el árbol está vacío
	{
		return;
	}
	else // Si el arbol NO está vacío
	{
		mostrarArbol(arbol->der, cont + 1);
		for (int i = 0; i < cont; i++)
		{
			cout << "\t";
		}
		cout << arbol->dato << endl;
		mostrarArbol(arbol->izq, cont + 1);
	}

}

bool buscarNodo(Nodo* arbol, int n)
{
	if (arbol == NULL)
	{
		return false;
	}
	else if (arbol->dato == n)
	{
		return true;
	}
	else if (n < arbol->dato)
	{
		return buscarNodo(arbol->izq, n);
	}
	else if (n > arbol->dato)
	{
		return buscarNodo(arbol->der, n);
	}
}

void preOrden(Nodo* arbol)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		cout << arbol->dato << " - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void inOrden(Nodo* arbol)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		inOrden(arbol->izq);
		cout << arbol->dato << " - ";
		inOrden(arbol->der);
	}
}

void postOrden(Nodo* arbol)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout << arbol->dato << " - ";
	}
}

bool isInteger(string input)
{
	int i;
	for (i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			return false;
		}
	}
	return true;
}