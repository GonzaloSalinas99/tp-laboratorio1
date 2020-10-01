/*
 * Arrays.c
 *
 *  Created on: 18 sept. 2020
 *      Author: Gonzalo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arrays.h"

int imprimirArray (int* pArray,int limite)
{
	int retorno=-1;
	int i;

	if(pArray !=NULL && limite>0)
	{
		for(i=0;i<limite;i++)
		{
			retorno=0;
			printf("%d ",pArray[i]);
		}
	}
	return retorno;
}

int buscarYContarNumero(int* pArray, int limite, int numero,int* vecesEncontrado)
{
	int retorno=-1;
	int i;
	int contadorNumeroEncontrado=0;

		if(pArray !=NULL && vecesEncontrado!=NULL && limite>0)
		{
			for(i=0;i<limite;i++)
			{
				if(pArray[i]==numero)
				{
					contadorNumeroEncontrado++;
					retorno=0;
				}
			}

			*vecesEncontrado=contadorNumeroEncontrado;
		}
return retorno;
}
int buscarYContarCaracter(char* pArray, char caracter,int* vecesEncontrado)
{
	int retorno=-1;
	int i=0;
	int contadorNumeroEncontrado=0;

		if(pArray !=NULL && vecesEncontrado != NULL )
		{
			while(pArray[i] != '\0')
			{
				if(pArray[i]==caracter)
				{
					contadorNumeroEncontrado++;
					retorno=0;
				}
				i++;
			}

			*vecesEncontrado=contadorNumeroEncontrado;
		}
return retorno;
}
int verificarSinSonLetras(char* pArray)
{
	int retorno=0;
	int i=0;

	if(pArray!=NULL)
	{
		for(i=0;pArray[i]!='\0';i++)
		{
			if(	(pArray[i] < 'A' || pArray[i] > 'Z') &&
				(pArray[i] < 'a' || pArray[i] > 'z'))
			{
				retorno=-1;
				break;
			}
		}
	}
return retorno;
}

void ordenarArray(int* pArray, int limite)
{
	int indice;
	int flagEstadoDesordenado = 1;
	int aux;

	while(flagEstadoDesordenado==1)
	{
	flagEstadoDesordenado=0;
		for(indice=0 ; indice<(limite-1)  ; indice++)
		{
			if(pArray[indice] > pArray[indice+1])
			{
				// intercambiar (swap)
				aux = pArray[indice];
				pArray[indice] = pArray[indice+1];
				pArray[indice+1] = aux;
				flagEstadoDesordenado=1;
			}
		}
	}

}
