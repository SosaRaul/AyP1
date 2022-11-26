#include "Particion.h"
#include <iostream>

const int capacidadInicial = 4;

int CompararIdentificadores(int idA, int idB);
bool IdPerteneceARango(UDBParticion::Particion* particion,int id);

struct UDBParticion::Particion {
	int inicioRango;
	int finRango;
    int capacidadRegistros;
    int cantidadDeElementos;
	Registro** registros;
};

UDBParticion::Particion* UDBParticion::Crear(int inicioRango, int finRango) {
	Particion* nuevaParticion = NULL;
	if(inicioRango > 0 &&  inicioRango <= finRango){
		nuevaParticion = new Particion;
		Registro** registros = new Registro*[capacidadInicial];
		nuevaParticion->registros = registros;
		nuevaParticion->inicioRango = inicioRango;
		nuevaParticion->finRango = finRango;
		nuevaParticion->capacidadRegistros = capacidadInicial;
		nuevaParticion->cantidadDeElementos = 0;
	}
	return nuevaParticion;
}

int UDBParticion::ObtenerRanking(Particion* particion, int identificadorBuscado) {
    int indiceComienzo = 0;
    int indiceFin = particion->cantidadDeElementos - 1;
    while (indiceComienzo <= indiceFin) {
        int indiceMitad = indiceComienzo + (indiceFin - indiceComienzo) / 2;
        int identificadorObtenido = UDBRegistro::ObtenerIdentificador(particion->registros[indiceMitad]);
        if (CompararIdentificadores(identificadorObtenido,identificadorBuscado) > 0)
            indiceFin = indiceMitad - 1;
        else if (CompararIdentificadores(identificadorObtenido,identificadorBuscado) < 0)
            indiceComienzo = indiceMitad + 1;
        else
            return indiceMitad;
    }
    return -1;
}
Registro* UDBParticion::ObtenerRegistro(Particion* particion, int identificador) {
	int posicion = ObtenerRanking(particion,identificador);
    return (posicion != -1) ? particion->registros[posicion] : NULL;
}

void UDBParticion::Destruir(Particion* particion) {
	for(int i = 0;i < particion->capacidadRegistros;++i){
		Destruir(particion->registros[i]);
	}
	delete particion;
}

void UDBParticion::ActualizarRegistro(Particion* particion, int identificador, string valor) {
	Registro* registro = ObtenerRegistro(particion,identificador);
	if(registro != NULL){
		CambiarValor(registro,valor);
	}
}
int CompararIdentificadores(int idA, int idB) {
    return idA - idB;
}

void Redimensionar(UDBParticion::Particion* particion,int nuevaCapacidad){
		int capacidadMaxima = ObtenerCapacidadMaxima(particion);
		int nuevaCapacidadRegistros = nuevaCapacidad < capacidadMaxima ? nuevaCapacidad : capacidadMaxima;
		Registro** nuevosRegistros = new Registro*[nuevaCapacidadRegistros];
		for(int i = 0 ; i < particion->cantidadDeElementos ;++i){
			nuevosRegistros[i]	= UDBRegistro::CrearRegistro(ObtenerIdentificador(particion->registros[i]),ObtenerValor(particion->registros[i]));
			UDBRegistro::Destruir(particion->registros[i]);
		}
	//	DestruirRegistros(particion);
		particion->capacidadRegistros = nuevaCapacidadRegistros;
		particion->registros = nuevosRegistros;
}
void UDBParticion::DestruirRegistros(Particion* particion) {
    for (int i = 0; i < particion->cantidadDeElementos; ++i) {
        UDBRegistro::Destruir(particion->registros[i]);
    }
    delete[] particion->registros;
}

int UDBParticion::ObtenerCapacidadMaxima(Particion* particion) {
    return particion->finRango - particion->inicioRango + 1;
}


bool EsParticionVacia(UDBParticion::Particion* particion){
	return particion->cantidadDeElementos == 0;
}

void UDBParticion::AgregarRegistro(Particion* particion, string valor) {

	if(EsParticionVacia(particion)){
		Registro* nuevoRegistro = UDBRegistro::CrearRegistro(particion->inicioRango,valor);
		particion->registros[0] = nuevoRegistro;
		particion->cantidadDeElementos +=1;

	}else{
		int posicionUltimoRegistro = particion->cantidadDeElementos-1;
		if(ObtenerIdentificador(particion->registros[posicionUltimoRegistro]) < particion->finRango){
			if(particion->cantidadDeElementos == particion->capacidadRegistros){
				int nuevaCapacidad = particion->cantidadDeElementos*2;
				Redimensionar(particion,nuevaCapacidad);
			}
			int identificadorNuevo = ObtenerIdentificador(particion->registros[posicionUltimoRegistro]) + 1;
			Registro* nuevoRegistro = UDBRegistro::CrearRegistro(identificadorNuevo,valor);
			particion->cantidadDeElementos +=1;
			particion->registros[particion->cantidadDeElementos-1] = nuevoRegistro;
		}
	}
}


void UDBParticion::EliminarRegistro(Particion* particion, int identificador) {

	Registro* registro = ObtenerRegistro(particion,identificador);
	if(registro != NULL){
		Destruir(registro);
	}


}

bool IdPerteneceARango(UDBParticion::Particion* particion,int id){
	return (id >= particion->inicioRango) && (id <= particion->finRango);
}


