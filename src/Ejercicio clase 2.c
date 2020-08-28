/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	setbuf(stdout, NULL);
	int numeroIngresado;
	int promedio;
	int maximo;
	int minimo;
	int i;
	int acumulador=0;
	int respuestaScanF;


	for(i=0;i<5;i++)
	{
		printf("ingrese un numero");
		fflush(stdin);
		respuestaScanF = scanf("%d" , &numeroIngresado);
		while(respuestaScanF==0)
		{
			printf("Eror reingrese un numero");

			respuestaScanF = scanf("%d" , &numeroIngresado);
		}
		maximo = numeroIngresado;
		minimo = numeroIngresado;

		if(numeroIngresado>maximo)
		{
			maximo = numeroIngresado;
		}
		if(numeroIngresado<minimo)
		{
			minimo=numeroIngresado;
		}
		acumulador+=numeroIngresado;
	}
	promedio= (float) acumulador / i; //usamos el casteo para que, cuando saque el promedio, si da decimal, me lo pueda mostrar
									//si no lo castearia, solamente me mostraria el numero entero y no su decimal.
	printf("el promedio de los numeros ingresados es  %f" , promedio);
	printf("el maximo numero ingresado es  %d" , maximo);
	printf("el minimo numero ingresado es  %d" , minimo);
}
