#include "Particion.h"
#include <iostream>

struct UDBParticion::NodoRegistro {
	Registro* item;
	NodoRegistro* siguiente;
};

struct UDBParticion::ListaRegistros {
	NodoRegistro* primero;
};

struct UDBParticion::Particion {
	int inicioRango;
	int finRango;
	int registrosDisponibles;
	ListaRegistros* registros;
};

/// Si el rango no es valido devuelve NULL.
/// Si el rango es valido crea una instancia valida de Particion que utilizara los identificadores
///  de @inicioRango a @finRango para sus registros
UDBParticion::Particion* UDBParticion::Crear(int inicioRango, int finRango) 
{
	if (inicioRango < 0 or finRango < inicioRango)
		return NULL;

	Particion* nuevaParticion = new Particion;
	nuevaParticion->inicioRango = inicioRango;
	nuevaParticion->finRango = finRango;
	nuevaParticion->registrosDisponibles = finRango - inicioRango + 1;
	nuevaParticion->registros = CrearListaRegistros();
	nuevaParticion->registros->primero = CrearNodoRegistro();
	NodoRegistro* nodo = nuevaParticion->registros->primero;

	for (int i = inicioRango; i < finRango; i++)
	{
		nodo->siguiente = CrearNodoRegistro();
		nodo = nodo->siguiente;
	}
	return nuevaParticion;
}

/// <summary>
/// Crea una nueva ListaRegistros vacia
/// </summary>
/// <returns></returns>
UDBParticion::ListaRegistros* UDBParticion::CrearListaRegistros() 
{
	ListaRegistros* lista = new ListaRegistros;
	lista->primero = NULL;
	return lista;
}

/// <summary>
/// Crea un nuevo NodoRegistro vacio
/// </summary>
/// <returns></returns>
UDBParticion::NodoRegistro* UDBParticion::CrearNodoRegistro() 
{
	NodoRegistro* nodo = new NodoRegistro;
	nodo->item = NULL;
	nodo->siguiente = NULL;
	return nodo;
}

/// <summary>
/// Valida que @particion sea una instancia valida
/// </summary>
/// <param name="particion"></param>
/// <returns></returns>
bool UDBParticion::EsParticionValida(Particion* particion) 
{
	return (particion != NULL
		and particion->registros != NULL
		and particion->registros->primero != NULL
		and particion->inicioRango > 0
		and particion->finRango >= 0
		and particion->finRango > particion->inicioRango
		);
}

/// <summary>
/// Obtiene el rango inicial de @particion
/// </summary>
/// <param name="particion"></param>
/// <returns></returns>
int UDBParticion::ObtenerInicioRango(Particion* particion)
{
	return particion->inicioRango;
}

/// <summary>
/// Obtiene el rango final de @particion
/// </summary>
/// <param name="particion"></param>
/// <returns></returns>
int UDBParticion::ObtenerFinRango(Particion* particion)
{
	return particion->finRango;
}

/// <summary>
/// Obtiene la cantidad de registros disponibles de @particion
/// </summary>
/// <param name="particion"></param>
/// <returns></returns>
int UDBParticion::ObtenerRegistrosDisponibles(Particion* particion)
{
	return particion->registrosDisponibles;
}

/// <summary>
/// Si tiene el registro con identificador igual a @identificador lo devuelve, caso contrario devuelve NULL
/// </summary>
/// <param name="particion"></param>
/// <param name="identificador"></param>
/// <returns></returns>
Registro* UDBParticion::ObtenerRegistro(Particion* particion, int identificador)
{
	if (EsParticionValida(particion))
	{
		int indice = particion->inicioRango;
		NodoRegistro* nodo = particion->registros->primero;

		while (indice <= particion->finRango)
		{
			if (nodo->item != NULL and ObtenerIdentificador(nodo->item) == identificador)
				return nodo->item;

			indice++;
			if (nodo->siguiente != NULL)
				nodo = nodo->siguiente;
		}
	}
	return NULL;
}

/// <summary>
/// Agrega un nuevo registro de valor igual a @valor y con id dentro del rango. Si no es posible no realiza ninguna accion
/// </summary>
/// <param name="particion"></param>
/// <param name="valor"></param>
void UDBParticion::AgregarRegistro(Particion* particion, string valor)
{
	if (particion) // if(particion)
	{
		int indice = particion->inicioRango;
		NodoRegistro* nodo = particion->registros->primero;

		while (indice <= particion->finRango)
		{
			if (nodo->item == NULL)
			{
				nodo->item = UDBRegistro::CrearRegistro(indice, valor);
				particion->registrosDisponibles--;
				return;
			}
			indice++;
			if (nodo->siguiente != NULL)
				nodo = nodo->siguiente;
		}
	}
}
/// <summary>
/// Modifica el registro con identificador igual a @identificador asignandole @valor.
/// Si no existe el registro en la particion no realiza ninguna accion
/// </summary>
/// <param name="particion"></param>
/// <param name="identificador"></param>
/// <param name="valor"></param>
void UDBParticion::ActualizarRegistro(Particion* particion, int identificador, string valor) 
{
	if (particion)
	{
		int indice = particion->inicioRango;
		NodoRegistro* nodo = particion->registros->primero;

		while (indice <= particion->finRango)
		{
			if (nodo->item != NULL and ObtenerIdentificador(nodo->item) == identificador)
			{
				UDBRegistro::CambiarValor(nodo->item, valor);
				return;
			}
			indice++;
			if (nodo->siguiente != NULL)
				nodo = nodo->siguiente;
		}
	}
}

/// <summary>
/// Quita el registro con identificador @identificador de la @particion. 
/// Si no existe el registro no realiza ningua accion
/// </summary>
/// <param name="particion"></param>
/// <param name="identificador"></param>
void UDBParticion::EliminarRegistro(Particion* particion, int identificador) 
{
	if (particion)
	{		
		int indice = particion->inicioRango;
		NodoRegistro* nodo = particion->registros->primero;

		while (indice <= particion->finRango)
		{
			if (nodo->item != NULL and ObtenerIdentificador(nodo->item) == identificador)
			{
				Destruir(nodo->item);
				nodo->item = NULL; 
				particion->registrosDisponibles++;
				return;
			}	
			indice++;
			if (nodo->siguiente != NULL)
				nodo = nodo->siguiente;
			
		}		
	}
}

/// <summary>
/// Libera todos los recursos asociados de @particion
/// </summary>
/// <param name="particion"></param>
void UDBParticion::Destruir(Particion* particion) 
{	
	if (particion)
	{
		int indice = particion->inicioRango;
		NodoRegistro* nodoAnterior = particion->registros->primero;
		NodoRegistro* nodo = particion->registros->primero->siguiente;

		while (indice <= particion->finRango)
		{
			if(nodoAnterior->item != NULL)
				Destruir(nodoAnterior->item);

			delete nodoAnterior;
			nodoAnterior = nodo;
			indice++;

			if(nodo->siguiente != NULL)
				nodo = nodo->siguiente;	
		}
		delete particion->registros;
		delete particion;
	}
}





