#include<iostream>
#include "Lista.h"
using namespace std;

int main(){

	Lista miLista = Lista();
	miLista.AgregarElemento(10);
	miLista.AgregarElemento(23);
	miLista.AgregarElemento(18);
	miLista.RecorrerLista();
	cout << endl;
	//miLista.~Lista();
	miLista.BorrarCoincidencias(10);
	miLista.RecorrerLista();
	//cout << miLista.EsListaVacia();
	//cout << miLista.BuscarElemento(110);

	return 0;
}
