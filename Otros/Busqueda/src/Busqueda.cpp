#include "Busqueda.h"
#include<vector>


int Busqueda::LinearSearch(std::vector<int> arr,int value){
    unsigned int i = 0;
    while(i < arr.size() && value != arr[i]){
        i++;
    }
    return i == arr.size() ? -1 : i;
}
int Busqueda::BinarySearch(std::vector <int> arr, int value){
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
