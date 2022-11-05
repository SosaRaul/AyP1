/*
 * Esta es la 1er entrega que se hizo del tp el dia 28-10-22
 */

#include <iostream>
#include "Particion.h"
#include "Registro.h"

using namespace std;
using namespace UDBParticion;
using namespace UDBRegistro;

void Mostrar(Particion* particion, int comienzo, int fin);
Particion* CrearEstudiantesAlgortimos();

int main()
{
    Particion* estudiantesAlgoritmos = CrearEstudiantesAlgortimos();
    ActualizarRegistro(estudiantesAlgoritmos, 1003, "");
    EliminarRegistro(estudiantesAlgoritmos, 1000);
    EliminarRegistro(estudiantesAlgoritmos, 1001);
    EliminarRegistro(estudiantesAlgoritmos, 1002);
    EliminarRegistro(estudiantesAlgoritmos, 1003);
    EliminarRegistro(estudiantesAlgoritmos, 1004);
    EliminarRegistro(estudiantesAlgoritmos, 1005);
    EliminarRegistro(estudiantesAlgoritmos, 1006);
    EliminarRegistro(estudiantesAlgoritmos, 1007);
    EliminarRegistro(estudiantesAlgoritmos, 1008);
    EliminarRegistro(estudiantesAlgoritmos, 1009);
    //EliminarRegistro(estudiantesAlgoritmos, 1010);
    Mostrar(estudiantesAlgoritmos, 1000, 1010);
    Destruir(estudiantesAlgoritmos);
}

void Mostrar(Particion* particion, int comienzo, int fin) {
    for (int identificador = comienzo; identificador <= fin; ++identificador) 
    {
        Registro* registro = ObtenerRegistro(particion, identificador);
        if (registro != NULL)
            cout << "ID:" << ObtenerIdentificador(registro) << " Valor:" + ObtenerValor(registro) << endl;
    }
}

Particion* CrearEstudiantesAlgortimos() {
    Particion* estudiantes = Crear(1000, 1010);
    AgregarRegistro(estudiantes, "Alejandro Colli");
    AgregarRegistro(estudiantes, "Alex Urquiza");
    AgregarRegistro(estudiantes, "Cesar Vacirca");
    AgregarRegistro(estudiantes, "Danilo Medina");
    AgregarRegistro(estudiantes, "Elisa Araya");
    AgregarRegistro(estudiantes, "Ezequiel Britez");
    AgregarRegistro(estudiantes, "Facundo Lombardo");
    AgregarRegistro(estudiantes, "Federico Aquino");
    AgregarRegistro(estudiantes, "Gerardo Marchetti");
    AgregarRegistro(estudiantes, "Ivan Petrone");
    AgregarRegistro(estudiantes, "111111111111111");

    return estudiantes;
}
