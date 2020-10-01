/*
 * utn.h
 *
 *  Created on: 16 sept. 2020
 *      Author: Gonzalo
 */

#ifndef UTN_H_
#define UTN_H_

int getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo);
int esUnNombreValido(char* cadena,int limite);
int getNombre(char* mensaje,char* mensajeError,char* pResultado, int reintentos, int limite);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);



#endif /* UTN_H_ */
