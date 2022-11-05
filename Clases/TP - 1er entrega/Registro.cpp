#include "Registro.h"

struct UDBRegistro::Registro {
	string valor;
	int identificador;
};

/// <summary>
/// Crear una instancia valida de Registro con identificador @identificador y con valor @valor
/// </summary>
/// <param name="identificador"></param>
/// <param name="valor"></param>
/// <returns></returns>
UDBRegistro::Registro* UDBRegistro::CrearRegistro(int identificador, string valor) {
	Registro* nuevoRegistro = new Registro;
	nuevoRegistro->valor = valor;
	nuevoRegistro->identificador = identificador;
	return nuevoRegistro;
}

/// <summary>
/// Obtiene el identificador de @registro
/// </summary>
/// <param name="registro"></param>
/// <returns></returns>
int UDBRegistro::ObtenerIdentificador(const Registro* registro) {
	return registro->identificador;
}

/// <summary>
/// Obtiene el valor de @registro
/// </summary>
/// <param name="registro"></param>
/// <returns></returns>
string UDBRegistro::ObtenerValor(const Registro* registro) {
	return registro->valor;
}

/// <summary>
/// Modifica el valor de @registro por @valor
/// </summary>
/// <param name="registro"></param>
/// <param name="valor"></param>
void UDBRegistro::CambiarValor(Registro* registro, string valor) {
	registro->valor = valor;
}

/// <summary>
/// Libera todos los recursos asociados a @registro
/// </summary>
/// <param name="registro"></param>
void UDBRegistro::Destruir(Registro* registro) {
	if (registro != NULL)
		delete registro;
}