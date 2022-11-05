// Status : Funcionan OK las primitivas

namespace TDAPila{

	struct Pila;

	Pila* CrearPila();
	// Pre: Debe existir una Pila.
	// Post: Inserta un elemento en la cima de la Pila.
	void Apilar(Pila *pila,int valor);
	// Pre: Debe existar una Pila
	// Post: Extrae un elemento de la cima de la Pila.
	void Desapilar(Pila *pila);
	// Pre : Debe existir la pila.
	// Post: Muestra la pila.
	void MostrarPila(const Pila *pila);
	// Pre: Debe existir una pila.
	// Post:
	bool PilaVacia(const Pila *pila);


}














