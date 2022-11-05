#include "Cola.h"
#include <iostream>
using namespace std;
using namespace TDACola;
int main(){

	Cola *nuevaCola = CrearCola();
	Encolar(nuevaCola,10);
	Encolar(nuevaCola,50);
	Encolar(nuevaCola,9);
	Encolar(nuevaCola,22);

	MostrarCola(nuevaCola);
	Desencolar(nuevaCola);
	cout << "------" << endl;
	MostrarCola(nuevaCola);
	Desencolar(nuevaCola);
	cout << "------" << endl;
	MostrarCola(nuevaCola);
	Desencolar(nuevaCola);
	cout << "------" << endl;
	MostrarCola(nuevaCola);
	Desencolar(nuevaCola);
	cout << "------" << endl;
	MostrarCola(nuevaCola);

	return 0;
}
