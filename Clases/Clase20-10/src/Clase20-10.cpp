#include <iostream>
using namespace std;

struct Nodo {
    int item;
    Nodo *siguiente;
};

struct Lista {
    Nodo *primero;
};

Nodo* CrearNodo(int item);
Lista* CrearListaVacia();
void DestruirNodo(Nodo* nodo);
void DestruirLista(Lista* lista);

void AgregarNodoAlComienzo(Lista* lista, Nodo* nodo);
void AgregarNodoAlFinal(Lista* lista, Nodo* nodo);
void QuitarPrimerNodo(Lista* lista);
void QuitarUltimoNodo(Lista* lista);
int ObtenerTamanio(Lista* lista);
void MostrarLista(Lista* lista);
int ObtenerTamanio(Lista* lista);

int main() {
    Lista* lista = CrearListaVacia();

    AgregarNodoAlFinal(lista, CrearNodo(10));
    AgregarNodoAlFinal(lista, CrearNodo(15));
    AgregarNodoAlFinal(lista, CrearNodo(20));
    AgregarNodoAlFinal(lista, CrearNodo(30));

    MostrarLista(lista); // 10 -> 15 -> 20 -> 30

    AgregarNodoAlComienzo(lista, CrearNodo(40));
    AgregarNodoAlComienzo(lista, CrearNodo(50));

    MostrarLista(lista); // 50 -> 40 -> 10 -> 15 -> 20 -> 30
    cout << "\nTamanio: " << ObtenerTamanio(lista);
    /*
    QuitarPrimerNodo(lista);
    QuitarUltimoNodo(lista);

    cout << "El tamaño de la lista es " << ObtenerTamanio(lista) << endl;
    MostrarLista(lista); // 40 -> 10 -> 15 -> 20

    DestruirLista(lista);
    */
    cout << endl << endl;
    return 0;
}

Nodo* CrearNodo(int item) {
    Nodo *nodo = new Nodo;
    nodo->item = item;
    nodo->siguiente = NULL;
    return nodo;
}

Lista* CrearListaVacia() {
    Lista *lista = new Lista;
    lista->primero = NULL;
    return lista;
}


void AgregarNodoAlFinal(Lista* lista, Nodo* nuevoNodo) {
    if (lista->primero == NULL) {
        lista->primero = nuevoNodo;
    } else {
        Nodo *nodo = lista->primero;
        while(nodo->siguiente != NULL) {
            nodo = nodo->siguiente;
        }
        nodo->siguiente = nuevoNodo;
    }
}

void MostrarLista(Lista* lista) {
    if (lista->primero == NULL) {
        cout << "la lista está vacía" << endl;
    } else {
        Nodo *nodo = lista->primero;
        while(nodo->siguiente != NULL) {
            cout << nodo->item << " -> ";
            nodo = nodo->siguiente;
        }
        cout << nodo->item << endl;
    }
}
// OBS: (Anda) pero fijarse que se puede hacer sin tener que usar ese puntero paux.(Mirar codigo de la clase)
void AgregarNodoAlComienzo(Lista* lista,Nodo* nodo){
	if(!lista){
		AgregarNodoAlFinal(lista,nodo);
	}
	else{
		Nodo *paux = lista->primero;
		lista->primero = nodo;
		lista->primero->siguiente = paux;
	}
}

int ObtenerTamanio(Lista* lista){
	int cont = 0;
	Nodo* p;

	if(lista){
		p = lista->primero;
		while(p){
			cont++;
			p = p->siguiente;
		}
	}
	return cont;
}
