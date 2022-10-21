#include "Lista.h"
#include<iostream>
using namespace std;
// Implementación del tipo Nodo , que es cada elemento de la lista.


// Constructor
Lista::Lista(): pLista(nullptr) {}

// Destructor
Lista::~Lista(){
	while(pLista != nullptr){
		Nodo *temp = pLista;
		pLista = pLista->sig;
		delete(temp);
	}
}

bool Lista::EsListaVacia(){
	return pLista == nullptr ? true : false;
}

// Borrar todas los elementos que tengan el valor provisto.
void Lista::BorrarCoincidencias(int valor){

	Nodo* actual = pLista;
	Nodo* anterior = actual;
	Nodo* buscado = BuscarElemento(valor);

	while(actual!= nullptr && actual->valor != buscado->valor){
		anterior = actual;
		actual = actual->sig;
	}
	// Si está en el primer lugar.
	if(anterior == actual){
		anterior = actual->sig;
		cout << "Hola";
		delete(actual);
	}
	// Si está en el medio.
	if(anterior->sig == actual){
		anterior->sig = actual->sig;
		delete(actual);
	}
	// Si está al final.
//	if(!actual->sig && ){
		//anterior = actual->sig;

		//delete()
	//}

}

// Encuentra el elemento que tiene el valor provisto.
// Devuelve un puntero a la ubicación del elemento que tiene el valor pedido.
Lista::Nodo* Lista::BuscarElemento(int n){

	Nodo* temp = pLista;
	while(temp != nullptr && (n != temp->valor)){
		temp = temp->sig;
	}
	if(temp){
		return temp;
	}else{
		return nullptr;
	}
}
void Lista::RecorrerLista(){

	Nodo* temp = pLista;
	if(pLista){
		while(temp){
			cout << temp->valor << " ";
			temp = temp->sig;
		}
	}
	else{
		cout << "LISTA VACIA! ";
	}
}
void Lista::AgregarElemento(int n){

	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->sig = nullptr;
	nuevoNodo->valor = n;
	Nodo * temp = pLista;

	// Lista vacia
	if(!pLista){
		pLista = nuevoNodo;
	}
	// Lista con solo elemento
	else if(!pLista->sig){
		pLista->sig = nuevoNodo;
	}
	// Tengo que llegar al final  e insertarlo ahí.
	else{
		while(temp->sig){
			temp = temp->sig;
		}
		temp->sig = nuevoNodo;
	}
}
