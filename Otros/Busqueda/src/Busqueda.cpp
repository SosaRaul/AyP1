#include "Busqueda.h"
#include<vector>
#include<iostream>

int Busqueda::LinearSearch(std::vector<int> arr,int value){
    unsigned int i = 0;
    while(i < arr.size() && value != arr[i]){
        i++;
    }
    return i == arr.size() ? -1 : i;
}
// My version
int Busqueda::BinarySearchv2(std::vector <int> arr, int value){
    int firstIndex = 0 , lastIndex = arr.size()-1;
    int  centralIndex = (firstIndex+lastIndex)/2;
    while(firstIndex<=lastIndex && arr[centralIndex] != value){
        // Tengo que buscar a la derecha.
        if(value > arr[centralIndex]){
            // inicio = central+1, final no cambia.
            firstIndex = centralIndex+1 ;
        // Tengo que buscar a la izquierda.
        }else{
            // final = central-1
            lastIndex = centralIndex-1;
        }
        centralIndex = (firstIndex+lastIndex)/2;
    }
    return firstIndex > lastIndex ? -1 : centralIndex;
}
// Version Sedgewick
int Busqueda::BinarySearch(std::vector<int> arr,int key){
	int lo = 0, hi = arr.size()-1;
	while(lo <= hi){
		int mid = lo+(hi-lo)/2;
		if(key < arr[mid]){
			hi = mid-1;
		}else if(key > arr[mid]){
			lo = mid+1;
		}else{
			return mid;
		}
	}
	return -1;
}
