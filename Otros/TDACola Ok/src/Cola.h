/*
 * Cola.h
 *
 *  Created on: Nov 5, 2022
 *      Author: RaulSosa
 *      Cola implementada con lista enlazada simple.
 *      Status : Funcionan bien las primitivas basicas.
 *
 */

#ifndef SRC_COLA_H_
#define SRC_COLA_H_

namespace TDACola{

	struct Cola;
	Cola* CrearCola();
	void Encolar(Cola *cola,int valor);
	void Desencolar(Cola *cola);
	void MostrarCola(const Cola *cola);
	bool ColaVacia(const Cola *cola);


}



#endif /* SRC_COLA_H_ */
