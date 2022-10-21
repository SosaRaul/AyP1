#include<iostream>
using namespace std;


int ContarMultiplos(int numeros[],int numero,int indiceComienzo,int indiceFin);

int main(){


	return 0;
}


int ContarMultiplos(int numeros[],int numero,int indiceComienzo,int indiceFin){

	if(indiceComienzo == indiceFin && numeros[indiceComienzo]%numero == 0){
		return 1;
	}else{
		return ContarMultiplos(numeros,numero,indiceComienzo-1,indiceFin);
	}
}

