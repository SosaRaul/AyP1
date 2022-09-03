//============================================================================
// Name        : Ejercicio1_Guia1.cpp
// Author      : RaulSosa
// Version     :
// Description : Modelar una tipo de dato para una carta de una baraja.
//============================================================================

#include <iostream>
using namespace std;
struct Version {

	int versionNumber = 0;
	int releaseNumber = 0;
	int changeNumber = 0;

};

void ShowVersion(Version *version);
void NewVersion(Version *version);
void Release(Version *version);
void Commit(Version *version);

int main(void) {

	Version *fileVersion;
	fileVersion = new Version;

	Commit(fileVersion);
	Release(fileVersion);
	NewVersion(fileVersion);
	ShowVersion(fileVersion);

	return 0;
}

void ShowVersion(Version *version) {
	cout << version->versionNumber << endl;
	cout << version->releaseNumber << endl;
	cout << version->changeNumber << endl;
}

void NewVersion(Version *version) {
	version->versionNumber++;
}
void Release(Version *version) {
	version->releaseNumber++;
}

void Commit(Version *version) {
	version->changeNumber++;
}
