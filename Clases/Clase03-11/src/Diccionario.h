#include "TanqueAgua.h"

using UndavTanqueAgua::TanqueAgua;
#define SonIguales(a,b) a==b
#define Clave int // Es muy deseable que sea inmutable!
#define Valor TanqueAgua*

namespace UndavDiccionario {
	struct Diccionario;
	Diccionario* Crear();

	// Postcondicion: Agrega el par de elemento @clave-@valor en diccionario. Si la @clave ya existe, reemplaza
	// el valor por @valor
	void Agregar(Diccionario* diccionario, Clave clave, Valor valor);

	// Postcondicion: Si existe en @diccionario la @clave obtiene el valor asociado a la misma
	// Si no existe devuelve NULL/Se lanza una exception
	Valor Obtener(const Diccionario* diccionario, Clave clave);


	bool Existe(const Diccionario* diccionario, Clave clave);
	void Quitar(Diccionario* diccionario, Clave clave);
	bool EstaVacio(const Diccionario* diccionario);
	int ObtenerTamanio(const Diccionario* diccionario);

	void Destruir(Diccionario* diccionario);
}
