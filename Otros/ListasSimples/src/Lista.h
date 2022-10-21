// Lista.h
// Declaraciones de métodos y atributos.

#ifndef LISTA_H_
#define LISTA_H_


class Lista{
private:
	struct Nodo{
		int valor;
		Nodo *sig;
	};
	Nodo* pLista;
public:
	Lista();
	~Lista();
	bool EsListaVacia();
	void AgregarElemento(int valor);
	void RecorrerLista();
	void BorrarCoincidencias(int valor);
	Nodo* BuscarElemento(int valor);
};







#endif /* LISTA_H_ */
