
// Ejemplo:
// Si invoco Encriptar con texto = "AON" y clave = 1 entonces
// texto quedaria transformado a "OPB" ya que
// - La primer transformacion de AON seria invertirlo -> NOA
// - Como el parametro @clave es uno le suma uno a cada caracter -> "OPB"
#include<iostream>
using namespace std;

void Encriptar(char texto[],int clave);
void InvertirCadena(char cadena[]);
int LargoCadena(char cadena[]);
void MostrarCadena(char cadena[]);

int main(){

	char cadena[] = "AON";
	unsigned int clave = 1;
	Encriptar(cadena,clave);
	cout << cadena;

	return 0;
}
void Encriptar(char texto[],int clave){
	InvertirCadena(texto);
	for(int i = 0;i<LargoCadena(texto);i++){
		texto[i] = texto[i] + clave;
	}
}

int LargoCadena(char cadena[]){

	int i = 0;

	while(cadena[i] != '\0'){
		i++;
	}
	return i;
}
void InvertirCadena(char cadena[]){

	int movimientos = LargoCadena(cadena)%2 ? (LargoCadena(cadena)-1)/2 : (LargoCadena(cadena))/2;

	for(int i=0;i<movimientos;i++){
		int temp = cadena[i];
		cadena[i] = cadena[LargoCadena(cadena)-1-i];
		cadena[LargoCadena(cadena)-1-i] = temp;
	}
}
void MostrarCadena(char cadena[]){

	for(int i = 0;i<LargoCadena(cadena);i++){
		cout << cadena[i] << " ";
	}
}
