#include "Diccionario.h"
#include <iostream>

struct Nodo {
	Clave clave;//int
	Valor valor;//TanqueAgua*

	Nodo* siguiente;
};

struct Lista {
	Nodo* primero;
	int cantidadItems;
};

struct UndavDiccionario::Diccionario {
	Lista* parElementos;
};

Nodo* CrearNodo(Clave clave, Valor valor, Nodo* siguiente) {
	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->clave = clave;
	nuevoNodo->valor = valor;
	nuevoNodo->siguiente = siguiente;
	return nuevoNodo;
}

UndavDiccionario::Diccionario* UndavDiccionario::Crear() {

}

// O(N), Este algoritmo es adaptativo?
void UndavDiccionario::Agregar(Diccionario* diccionario, Clave clave, Valor valor) {
	bool encontrado = false;
	Nodo* iterador = diccionario->parElementos->primero;
	while (iterador != NULL && !encontrado) {
		if (SonIguales(iterador->clave, clave))
		{
			iterador->valor = valor;
			encontrado = true;
		}
	}

	if (!encontrado) {
		diccionario->parElementos->primero = CrearNodo(clave, valor, diccionario->parElementos->primero);
	}
}
