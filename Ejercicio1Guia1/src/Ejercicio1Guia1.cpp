
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



// Pre:
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
