/*
 * CALCULADORA.c
 *
 *  Created on: 7 sept. 2020
 *      Author: Gonzalo
 */
#include <stdlib.h>
#include <stdio.h>
/*brief Solicita un numero entero al usuario.
 *param char* mensaje, Mensaje a ser mostrado al usuario.
 *param char* mensajeError, Mensaje de error a ser mostrado al usuario.
 *param int* resultado, Puntero a la direccion de memoria donde se dejara el valor obtenido.
 *param int reintentos, Cantidad de reintentos que tiene el usuario para ingresar el dato.
 *param int minimo, Valor minimo admitido.
 *param int maximo, Valor maximo admitido.
 *return (-1) En caso que no se haya podido realizar la verificacion (0) En caso de que se haya podido realizar la verificacion
 */
int getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int minimo,int maximo)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			minimo <= maximo)
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
 *brief Realizar el factoreo de un numero
 *param int numeroIngresado, Numero que haya ingresado el usuario.
 *param int* resultado, Puntero a la direccion de memoria donde se dejara el valor obtenido.
 *return (-1) Si hubo un error (0) Si salio todo bien.
 */
int factoreo(int numeroIngresado, int* resultado)
{
	int retorno = -1;
	int bufferInt = 1;
	if(numeroIngresado==0)
	{
		*resultado=1;
	}
	else if((numeroIngresado>0 && numeroIngresado <13) && resultado != NULL)
	{
		for(int i=1; i<=numeroIngresado; i++)
		{
			bufferInt *= i;
		}
		*resultado=bufferInt;
		retorno = 0;
	}
	else
	{
		if(numeroIngresado>12)
		{
			printf("\n No se puede realizar el factoreo\n");
		}
	}
	return retorno;
}
/*
*brief Realizar la suma de dos numeros
*param int primerOperando, Primer numero que haya ingresado el usuario.
*param int segundoOperando, Segundo numero que haya ingresado el usuario.
*param int* resultado, Puntero a la direccion de memoria donde se dejara el valor obtenido.
*return (-1) Si hubo un error (0) Si salio todo bien.
*/
int suma(int primerOperando, int segundoOperando, int* resultado)
{
	int retorno = -1;
	*resultado = primerOperando + segundoOperando;
	retorno=0;
	return retorno;
}
/*
*brief Realizar la resta de dos numeros
*param int primerOperando, Primer numero que haya ingresado el usuario.
*param int segundoOperando, Segundo numero que haya ingresado el usuario.
*param int* resultado, Puntero a la direccion de memoria donde se dejara el valor obtenido.
*return (-1) Si hubo un error (0) Si salio todo bien.
*/
int resta(int primerOperando, int segundoOperando, int* resultado)
{
	int retorno = -1;
	*resultado = primerOperando-segundoOperando;
	retorno=0;
	return retorno;
}
/*
*brief Realizar la multiplicacion de dos numeros
*param int primerOperando, Primer numero que haya ingresado el usuario.
*param int segundoOperando, Segundo numero que haya ingresado el usuario.
*param int* resultado, Puntero a la direccion de memoria donde se dejara el valor obtenido.
*return (-1) Si hubo un error (0) Si salio todo bien.
*/
int multiplicacion(int primerOperando, int segundoOperando, int* resultado)
{
	int retorno = -1;
	*resultado = primerOperando*segundoOperando;
	retorno=0;
	return retorno;
}
/*
*brief Realizar la division de dos numeros
*param int primerOperando, Primer numero que haya ingresado el usuario.
*param int segundoOperando, Segundo numero que haya ingresado el usuario.
*param int* resultado, Puntero a la direccion de memoria donde se dejara el valor obtenido.
*return (-1) Si hubo un error (0) Si salio todo bien.
*/
int division(int primerOperando, int segundoOperando, float* resultado)
{
	int retorno = -1;
	if(segundoOperando != 0)
	{
		*resultado = (float)primerOperando/segundoOperando;
		retorno=0;
	}
	return retorno;
}

/*brief Solicita un numero entero al usuario.
 *param char* mensaje, Mensaje a ser mostrado al usuario.
 *param char* mensajeError, Mensaje de error a ser mostrado al usuario.
 *param int* resultado, Puntero a la direccion de memoria donde se dejara el valor obtenido.
 *param int reintentos, Cantidad de reintentos que tiene el usuario para ingresar el dato.
 *return (-1) En caso que no se haya podido realizar la verificacion (0) En caso de que se haya podido realizar la verificacion
 */

int obtenerNumeroEntero(char* mensaje, char* mensajeError, int* pResultado,int reintentos)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%d" , &bufferInt);
			if(resultadoScanf == 1)
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
 * brief menu de opciones
 * return 0 si salio todo bien -1 si hubo un error
 */
int calculadora_menu(int *pOpcion)
{
	int retorno=-1;
	printf("\n\n*************BIENVENIDO*************\n\n");
	printf("****************************************\n\n");
	printf("*INGRESE LA OPCION QUE DESEE\n");
	printf("*>OPCION 1: Ingresar primer numero.\n");
	printf("*>OPCION 2: Ingresar segundo numero.\n");
	printf("*>OPCION 3: Sumar.\n");
	printf("*>OPCION 4: Restar.\n");
	printf("*>OPCION 5: Multiplicar.\n");
	printf("*>OPCION 6: Dividir.\n");
	printf("*>OPCION 7: Factorizar.\n");
	printf("*>OPCION 8: Realizar todos los calculos.\n");
	printf("*>OPCION 9: Salir.\n");
	printf("********************************************");


	getInt("\ningresa la opcion: ","Error Numero incorrecto",&retorno,3,1,9);

	*pOpcion=retorno;
	return retorno;
}
