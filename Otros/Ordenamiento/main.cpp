#include "Ordenamiento.h"
#include<iostream>
void Mostrar(int *v,int n){
	for(int i=0;i<n;i++){
		std::cout << v[i] << " " ;
	}
}
int main(){

	int v[] = {10,11,12,13};
	//std::cout << "Antes: " << "n1= " << n1 << " n2= " << n2 << std::endl;
	//Swap(&n1,&n2);
	//std::cout << "Despues: " << "n1= " << n1 << " n2= " << n2 << std::endl;
	OrdenarPorSeleccionAdaptativo(v,4);
	Mostrar(v,4);
	OrdenarPorSeleccion(v,4);
	Mostrar(v,4);
	return 0;
}
