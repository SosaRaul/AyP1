#include "Ordenamiento.h"
#include<iostream>


void Swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
 void OrdenarPorBuburja(int *v,int n){

	 for(int i=0;i<n-1;i++){
		 for(int j=0;j<n-1;j++){
			 if(v[j]>v[j+1]){
				 Swap(&v[j],&v[j+1]);
			 }
		 }
	 }
 }

void OrdenarPorSBurbujaAdaptativo(int *v,int n){

	int i = 0,swaps = 0;

	do{
		for(int j=0;j<n-1;j++){
			if(v[j]>v[j+1]){
				Swap(&v[j],&v[j+1]);
				swaps++;
			}
		}
	}while(swaps != 0 && i<n-1);
}
