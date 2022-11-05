#include "Cola.h"
#include <iostream>
using namespace std;

struct Nodo{
	int valor;
	Nodo* sig;
};

struct TDACola::Cola{
	Nodo *primero;
	Nodo *ultimo;
};

Nodo* ObtenerNodo(int valor){
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->valor = valor;
	nuevoNodo->sig = nullptr;
	return nuevoNodo;
}

TDACola::Cola* TDACola::CrearCola(){
	Cola *cola = new Cola;
	cola->primero = nullptr;
	cola->ultimo = nullptr;
	return cola;
}

void TDACola::Encolar(Cola *cola,int valor){
	Nodo* nuevoNodo = ObtenerNodo(valor);
	// Si la cola esta vacia.
	if(ColaVacia(cola)){
		cola->primero = ObtenerNodo(valor);
		cola->ultimo = nullptr;

	}else if(cola->primero != nullptr && cola->ultimo == nullptr){ // Si tenia un solo elemento la cola.
		cola->ultimo = nuevoNodo;
		cola->primero->sig = nuevoNodo;
		// Si tiene 2 o más elementos.
	}else if(cola->primero != nullptr && cola->ultimo != nullptr){
		cola->ultimo->sig = nuevoNodo;
		cola->ultimo = nuevoNodo;
	}

}
void TDACola::Desencolar(Cola *cola){
	if(ColaVacia(cola) == false && (cola->primero == cola->ultimo)){ // Si solo hay un elemento.
		delete(cola->primero);
		cola->primero = nullptr;
		cola->ultimo = nullptr;
	}else if(cola->primero != nullptr && cola->ultimo != nullptr){ // Si hay 2 o mas elementos.
		Nodo *aux = cola->primero->sig;
		delete(cola->primero);
		cola->primero = aux;
	}
}
bool TDACola::ColaVacia(const Cola *cola){
	return cola->primero == nullptr && cola->ultimo == nullptr;
}
void TDACola::MostrarCola(const Cola *cola){
	Nodo *aux = cola->primero;
	// Si la Cola esta vacia.
	if(ColaVacia(cola)){
		cout << "Cola vacia! " << endl;
	}else{
		while(aux){
			cout << aux->valor << endl;
			aux = aux->sig;
		}
	}
}
