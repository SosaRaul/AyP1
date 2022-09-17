#include <iostream>

using namespace std;

// Precondicion: @origen es una cadena de caracteres, @destino tiene el tamanio suficiente para copiar
// Postcondicion: Copia cada caracter de @origen en @destino, incluso el \0
// - Copia la cadena de caracteres @origen en @destino
void Copiar(char*,char*);

//Precondicion: @cadena es una cadena de caracteres
//Postcondicion: Devuelve la cantidad de caracteres de @cadena
int ContarCaracteres(char *);


// Precondicion: @origen es una cadena de caracteres, @destino tiene el tamanio suficiente para copiar
// Postcondicion: Copia cada caracter de @origen en @destino, incluso el \0
// - Copia la cadena de caracteres @origen en @destino
int Concatenar(char*,char*);


int main()
{
    char texto[] = "Hola que tal";
    char vector[100];
    Copiar(texto, vector);
    cout << vector<<endl;//Hola que tal
    cout << ContarCaracteres(texto);
    return 0;
}




void Copiar(char* origen, char* destino) {

	int i = 0;

	while(*(origen+i) != '\0'){
		*(destino+i) = *(origen+i);
		i++;
	}
	*(destino +i) = '\0';
}

void CopiarEnUnaLinea(char* origen,char* destino){

}

int ContarCaracteres(char *cadena){

	int i = 0;

	while(*(cadena+i) != '\0'){
		i++;
	}
	return i;
}

// Versión mejorada de ContarCaracteres
int ContarCaracteresMejorada(char *cadena){

}

int Concatenar(char* cadena,char* subCadena){
	int i = 0;
	while(*(cadena+i) != '0'){
		i++;
	}
	si
}
