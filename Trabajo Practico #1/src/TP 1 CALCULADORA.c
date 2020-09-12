
#include <stdlib.h>
#include <stdio.h>
#include "CALCULADORA.h"
int main(void)
{
	setbuf(stdout,NULL);

	int numero1;
	int numero2;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoFactoreo;
	int opciones;
	int resultadoScanF;
	int banderaNumero1=1;
	int banderaNumero2=1;

	do
	{
		resultadoScanF=getInt("\n\nBIENVENIDO\nOpcion1= Ingrese numero1: \nOpcion 2=Ingrese numero2: \nOpcion 3=SUMA\nOpcion 4=RESTA\nOpcion 5=MULTIPLICAS\nOpcion 6=DIVIDIS\nOpcion 7=FACTORIZAR\nOpcion 8=REALIZAR TODOS LOS CALCULOS\nOpcion 9=SALIR\n\n","No es una opcion valida",&opciones,3,1,9);

		if(resultadoScanF==0)
		{
			switch(opciones)
			{
			case 1:
				if(obtenerNumeroEntero("ingrese el primer numero","Error reingrese un numero",&numero1,3)==0)
				{
					banderaNumero1=0;
					printf("\nUsted ingreso: %d",numero1);
				}
				break;
			case 2:
				if(obtenerNumeroEntero("ingrese el segundo numero","Error reingrese un numero",&numero2,3)==0)
				{
					banderaNumero2=0;
					printf("\nUsted ingreso: %d",numero2);
				}
				break;
			case 3:
				if(suma(numero1,numero2,&resultadoSuma)==0&& banderaNumero1==0 && banderaNumero2==0)
				{
					printf("\nLa suma de %d y %d da como resulado: %d",numero1,numero2,resultadoSuma);
				}
				break;
			case 4:
				if(resta(numero1,numero2,&resultadoResta)==0 && banderaNumero1==0 && banderaNumero2==0)
				{
					printf("\nLa resta de %d y %d da como resulado: %d",numero1,numero2,resultadoResta);
				}
				else
				{
					printf("No se puede realizar una operacion si no se ingresaron dos numeros");
				}
				break;
			case 5:
				if(multiplicacion(numero1, numero2, &resultadoMultiplicacion)==0&& banderaNumero1==0 && banderaNumero2==0)
				{
					printf("\nLa multiplicacion de %d y %d da como resulado: %d",numero1,numero2,resultadoMultiplicacion);
				}
				else
				{
					printf("No se puede realizar una operacion si no se ingresaron dos numeros");
				}
				break;
			case 6:
				if(division (numero1,numero2,&resultadoDivision)==0&& banderaNumero1==0 && banderaNumero2==0)
				{
					printf("\nLa division de %d y %d da como resulado: %.2f",numero1,numero2,resultadoDivision);
				}
				else
				{
					printf("\nNo se pudo realizar la division porque el segundo numero ingresado es 0.");
				}
				break;
			case 7:
				if(factoreo(numero1,&resultadoFactoreo)==0 && banderaNumero1==0 && banderaNumero2==0)
				{
					printf("El primer numero factorizado es: %d",resultadoFactoreo);
				}
				else
				{
					printf("No se pudo realizar el factoreo del primer numero");
				}

				if(factoreo(numero2,&resultadoFactoreo)==0 && banderaNumero1==0 && banderaNumero2==0)
				{
					printf("\nEl segundo numero factorizado es: %d",resultadoFactoreo);
				}
				else
				{
					printf("No se pudo realizar el factoreo del segundo numero");
				}

				break;
			case 8:
				if(suma(numero1,numero2,&resultadoSuma)==0&& banderaNumero1==0 && banderaNumero2==0)
				{
					printf("\nLa suma de %d y %d da como resulado: %d",numero1,numero2,resultadoSuma);
				}
				if(resta(numero1,numero2,&resultadoResta)==0&& banderaNumero1==0 && banderaNumero2==0)
				{
					printf("\nLa resta de %d y %d da como resulado: %d",numero1,numero2,resultadoResta);
				}
				if(multiplicacion(numero1, numero2, &resultadoMultiplicacion)==0&& banderaNumero1==0 && banderaNumero2==0)
				{
					printf("\nLa multiplicacion de %d y %d da como resulado: %d",numero1,numero2,resultadoMultiplicacion);
				}
				if(division (numero1,numero2,&resultadoDivision)==0&& banderaNumero1==0 && banderaNumero2==0)
				{
					printf("\nLa division de %d y %d da como resulado: %.2f",numero1,numero2,resultadoDivision);
				}
				else
				{
					printf("\nNo se pudo realizar la division porque el segundo numero ingresado es 0.");
				}
			}
		}
	}while(opciones!=9);
return EXIT_SUCCESS;
}
