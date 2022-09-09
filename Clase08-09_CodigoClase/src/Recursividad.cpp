#include <iostream>
using namespace std;

int Factorial(int n);
bool PuedoLlegarAPlantaBaja(int boton1, int boton2, int piso);
int main(void){
	int n1 = 3 , n2 = 4 , n3 = 5;
	cout << Factorial(n1) << endl;
	cout << Factorial(n2) << endl;
	cout << Factorial(n3) << endl;
	return 0;
}

int Factorial(int n){
	// Caso base: Factorial(0) = 1 y Factorial(1) = 1
	if(n == 0 || n == 1){
		return 1;
	}
	// Caso recursivo : Factorial(n) = n * Factorial(n-1)
	else{
		return n*Factorial(n-1);
	}
}

bool PuedoLlegarAPlantaBaja(int boton1, int boton2, int piso) {
    if (piso == 0) {
        return true;
    }

    bool opcion1;
    bool opcion2;


}
