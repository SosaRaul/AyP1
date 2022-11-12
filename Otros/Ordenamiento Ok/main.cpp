#include "Ordenamiento.h"
#include<iostream>
using namespace Ordenamiento;
using namespace std;

void Mostrar(int *v,int n){
	for(int i=0;i<n;i++){
		cout << v[i] << " " ;
	}
}
int main(){

	int v[] = {15,1,12,13};
	//std::cout << "Antes: " << "n1= " << n1 << " n2= " << n2 << std::endl;
	//Swap(&n1,&n2);
	//std::cout << "Despues: " << "n1= " << n1 << " n2= " << n2 << std::endl;
	BubbleSortAdaptative(v,4);
	Mostrar(v,4);

	return 0;
}
