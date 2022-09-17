#include<iostream>
using namespace std;

void MostrarReversa(char *);
void EsFinCadenaTexto(char *);
int ObtenerFibonacci(int);
int ObtenerFactorial(int);
int ObtenerFibonacciDynamic(int);
void InicializarMemorizador(int *);

//int memorizador[42];


int main(void){
	int n = 3;

	cout << "Fibonacci " << n << ": " << ObtenerFibonacci(n);

	return 0;

}

// Mostrar reversa de maner recursiva
/*void MostrarReversa(char *texto){
	if(!EsFinCadenaTexo(texto)){
		MostrarReversa(*texto+1);
	}
}*/

bool EsFinCadena(char *texto){

}

int ObtenerFibonacci(int n){
	return n <= 1 ? n : ObtenerFibonacci(n-2) + ObtenerFibonacci(n-1);
}
int ObtenerFactorial(int n){
	return n == 1 ? 0 : n*ObtenerFactorial(n-1);
}
int ObtenerFibonacciDynamic(int n){
	if(n<=1){
		return n;
	}
	else{
		return ObtenerFibonacci(n-2) + ObtenerFibonacci(n-1);
	}
}
void InicializarMemorizador(int *memorizador){

}