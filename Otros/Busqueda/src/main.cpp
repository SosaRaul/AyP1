#include<iostream>
#include<vector>
#include "Busqueda.h"
using namespace std;
using Busqueda::BinarySearch;
using Busqueda::BinarySearchv2;
void ShowVector(vector<int> v){
	for(size_t i = 0;i<v.size();i++){
		cout << v[i] << " ";
	}
}


int main(){
	vector<int> v = {12,45,56,77,99};
	cout << BinarySearch(v,45);
	return 0;
}
