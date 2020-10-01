/*
 * utn.c
 *
 *  Created on: 16 sept. 2020
 *      Author: Gonzalo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define LIMITE_NOMBRE 50

static int myGets(char *cadena, int longitud);
static int getFloat(float* pFloat);
static int esFlotante(char* array,int limite);




int getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			maximo >= minimo)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%d" , &bufferInt);
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/*
 * utn_getNumeroFloat : Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * pResultado : Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: El mensaje que imprime si el rango no es valido.
 * minimo : valor minimo valido (inclusive)
 * maximo : valor maximo valido (inclusive)
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Retorno: devuelve un 0 si esta todoOK. Devuelve -1 si hubo un error.
 *
 */
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos){
	int retorno = -1;
	float bufferFloat;
	int resultadoScan;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			resultadoScan = getFloat(&bufferFloat);
			if(resultadoScan && minimo <= bufferFloat && maximo >= bufferFloat){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}else{
				printf("%s", mensajeError);
				printf("\n-REINTENTOS: %d \n",reintentos);
				reintentos--;
			}

		}while(reintentos >= 0);
	}
	return retorno;
}

/*
 * getFloat: verifica si la cadena ingresada es flotante
 * pFloat: puntero numero float
 * Retorno: devuelve un 1 si esta todoOK. Devuelve 0 si hubo un error.
 *
 */
static int getFloat(float* pFloat)
{
	int retorno = 0;
	char bufferFloat[64];
	if(pFloat != NULL){
		fflush(stdin);

		if(!myGets(bufferFloat,sizeof(bufferFloat)) && esFlotante(bufferFloat,sizeof(bufferFloat))){
			*pFloat = atof(bufferFloat);
			retorno = 1;
		}
	}
	return retorno;
}

/*
 * esFlotante: Verifica si la cadena ingresada es flotante
 * cadena: cadena de caracteres a ser analizada
 * limite: limite de la cadena
 * Retorno: 1 (verdadero) si la cadena es flotante , 0 (falso) si no y -1 en caso de ERROR de parametro
 *
 */
static int esFlotante(char* array,int limite){
	int retorno = -1;
	int i = 0;
	int contadorDePuntos = 0;

	if(array != NULL && limite > 0){
		retorno = 1;
		if(array[0] != '+' || array[0] != '-'){
			i = 1;
		}
		while(array[i] != '\0'){
			if((array[i] < '0' || array[i] > '9') && array[i] != '.'){
				retorno = 0;
				break;
			}
			if(array[i] == '.'){
				contadorDePuntos++;
				if(contadorDePuntos > 1){
					retorno = 0;
					break;
				}
			}
			i++;
		}
	}
	return retorno;
}


int getNombre(char* mensaje,char* mensajeError,char* pResultado, int reintentos, int limite)
{
	int retorno = -1;
	char bufferChar[LIMITE_NOMBRE];

	if(mensaje!=NULL && mensajeError!=NULL && pResultado!=NULL && reintentos>0 && limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if(myGets(bufferChar,LIMITE_NOMBRE) == 0 && strnlen(bufferChar,sizeof(bufferChar)-1)<= limite &&
					esUnNombreValido(bufferChar,limite) != 0 )
			{
				retorno=0;
				strncpy(pResultado,bufferChar,limite);
				break;
			}
			else
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);

	}
return retorno;
}

/*
 *brief verifica una cadena recibidar para determinar si es un nombre valido
 *param char* cadena Cadena a ser analizada
 *param int limite Indica la cantidad maxima de caracteres
 *return (0) si no pude ser validado el nombre (1) Si el nombre es valido
 */

int esUnNombreValido(char* cadena,int limite)
{
	int respuesta = 1;
	for(int i=0; i<=limite && cadena[i] != '\0';i++)
	{

		if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
			(cadena[i] < 'a' || cadena[i] > 'z') &&
			cadena[i] != '.')
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}
static int myGets(char *cadena, int longitud)
{
	fflush(stdin);
	fgets (cadena, longitud, stdin);
	cadena[strlen (cadena) - 1] = '\0';
	return 0;
}
