/*
 * CALCULADORA.h
 *
 *  Created on: 7 sept. 2020
 *      Author: Gonzalo
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

int getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int minimo,int maximo);
int obtenerNumeroEntero(char* mensaje, char* mensajeError, int* pResultado,int reintentos);
int factoreo(int numeroIngresado, int* resultado);
int suma(int primerOperando, int segundoOperando, int* resultado);
int resta(int primerOperando, int segundoOperando, int* resultado);
int multiplicacion(int primerOperando, int segundoOperando, int* resultado);
int division(int primerOperando, int segundoOperando, float* resultado);



#endif /* CALCULADORA_H_ */
