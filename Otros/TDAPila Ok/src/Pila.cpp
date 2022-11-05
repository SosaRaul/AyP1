// Status : Funcionan OK las primitivas
#include "Pila.h"
#include <iostream>
using namespace std;


struct Nodo{
	int valor;
	Nodo *sig;
};
struct TDAPila::Pila{
	Nodo *cima;
};

Nodo* ObtenerNodo(int valor){
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->valor = valor;
	nuevoNodo->sig = nullptr;
	return nuevoNodo;
}
void TDAPila::Apilar(Pila *pila,int valor){
	Nodo *nuevoNodo = ObtenerNodo(valor);
	// Si la pila esta vacia.
	if(PilaVacia(pila)){
		// Directamente lo agrego.
		pila->cima = ObtenerNodo(valor);
	}else{
		nuevoNodo->sig = pila->cima;
		pila->cima = nuevoNodo;
	}
}

void TDAPila::MostrarPila(const Pila *pila){
	Nodo *nodoActual = pila->cima;
	// Si la pila esta vacia.
	if(!pila->cima){
		cout << "Pila vacia " << endl;
	}else{
		while(nodoActual){
			cout << nodoActual->valor << endl;
			nodoActual = nodoActual->sig;
		}
	}
}
void TDAPila::Desapilar(Pila *pila){
	// Solo desapilo si hay algo en la pila.
	if(pila->cima){
		Nodo *aux = pila->cima;
		pila->cima = pila->cima->sig;
		delete(aux);
	}
}
TDAPila::Pila* TDAPila::CrearPila(){
	Pila *pila = new Pila;
	pila->cima = nullptr;
	return pila;
}

bool TDAPila::PilaVacia(const Pila *pila){
	return pila->cima == nullptr;
}

