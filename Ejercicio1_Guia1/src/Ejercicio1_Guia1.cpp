//============================================================================
// Name        : Ejercicio1_Guia1.cpp
// Author      : RaulSosa
// Version     :
// Description : Modelar una tipo de dato para una carta de una baraja.
//============================================================================

#include <string>
#include <iostream>
using namespace std;


struct Carta{
	string palo;
	int valor;
};

struct Baraja{
	int cantidadCartas;
	int tiposDePalos[];

};



// Pre: Ninguna
// Post : Devuelve una instancia válida de Carta

Carta* CrearCarta(string palo,int valor){
	Carta *carta = new Carta;
	carta->palo = palo;
	carta->valor = valor;
	return carta;
}





int main() {







	return 0;
}
