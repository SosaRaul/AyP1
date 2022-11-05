#include<iostream>
#include "Pila.h"
using namespace std;
using namespace TDAPila;

int main(){


	Pila *nuevaPila = CrearPila();
	Apilar(nuevaPila,1);
	Apilar(nuevaPila,11);
	Apilar(nuevaPila,120);
	Apilar(nuevaPila,23);
	MostrarPila(nuevaPila);
	Desapilar(nuevaPila);
	Desapilar(nuevaPila);
	Desapilar(nuevaPila);
	Desapilar(nuevaPila);
	Desapilar(nuevaPila);
	cout << "-------------" << endl;
	Apilar(nuevaPila,23);
	Apilar(nuevaPila,23);

	MostrarPila(nuevaPila);
	return 0;
}
