/*
 * Arrays.h
 *
 *  Created on: 18 sept. 2020
 *      Author: Gonzalo
 */

#ifndef ARRAYS_H_
#define ARRAYS_H_

int imprimirArray (int* pArray,int limite);
int buscarYContarNumero(int* pArray, int limite, int numero,int* vecesEncontrado);
int buscarYContarCaracter(char* pArray, char letra, int* vecesEcontrado);
int verificarSinSonLetras(char* pArray);
void ordenarArray(int* pArray, int limite);

#endif /* ARRAYS_H_ */
