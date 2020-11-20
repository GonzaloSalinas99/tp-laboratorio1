
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
	int banderaNumero1=1;
	int banderaNumero2=1;

	do
	{
		switch(	calculadora_menu(&opciones))
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
			if( banderaNumero1==0 && banderaNumero2==0 && suma(numero1,numero2,&resultadoSuma)==0)
			{
				printf("\nLa suma de %d y %d da como resulado: %d",numero1,numero2,resultadoSuma);
			}
			break;
		case 4:
			if(banderaNumero1==0 && banderaNumero2==0 && resta(numero1,numero2,&resultadoResta)==0)
			{
				printf("\nLa resta de %d y %d da como resulado: %d",numero1,numero2,resultadoResta);
			}
			else
			{
				printf("No se puede realizar una operacion si no se ingresaron dos numeros");
			}
			break;
		case 5:
			if( banderaNumero1==0 && banderaNumero2==0 && multiplicacion(numero1, numero2, &resultadoMultiplicacion)==0)
			{
				printf("\nLa multiplicacion de %d y %d da como resulado: %d",numero1,numero2,resultadoMultiplicacion);
			}
			else
			{
				printf("No se puede realizar una operacion si no se ingresaron dos numeros");
			}
			break;
		case 6:
			if(banderaNumero1==0 && banderaNumero2==0 && division (numero1,numero2,&resultadoDivision)==0)
			{
				printf("\nLa division de %d y %d da como resulado: %.2f",numero1,numero2,resultadoDivision);
			}
			else
			{
				printf("\nNo se pudo realizar la division porque el segundo numero ingresado es 0.");
			}
			break;
		case 7:
			if(banderaNumero1==0 && banderaNumero2==0 && factoreo(numero2,&resultadoFactoreo)==0)
			{
				printf("El %d factorizado es: %d",numero1,resultadoFactoreo);
			}
			else
			{
				printf("No se pudo realizar el factoreo de %d",numero1);
			}

			if(banderaNumero1==0 && banderaNumero2==0 && factoreo(numero2,&resultadoFactoreo)==0 )
			{
				printf("\nEl %d factorizado es: %d",numero2,resultadoFactoreo);
			}
			else
			{
				printf("No se pudo realizar el factoreo de %d",numero2);
			}

			break;
		case 8:
			if(banderaNumero1==0 && banderaNumero2==0 && suma(numero1,numero2,&resultadoSuma)==0)
			{
				printf("\nLa suma de %d y %d da como resulado: %d",numero1,numero2,resultadoSuma);
			}
			if( banderaNumero1==0 && banderaNumero2==0 && resta(numero1,numero2,&resultadoResta)==0)
			{
				printf("\nLa resta de %d y %d da como resulado: %d",numero1,numero2,resultadoResta);
			}
			if(banderaNumero1==0 && banderaNumero2==0 && multiplicacion(numero1, numero2, &resultadoMultiplicacion)==0)
			{
				printf("\nLa multiplicacion de %d y %d da como resulado: %d",numero1,numero2,resultadoMultiplicacion);
			}
			if(banderaNumero1==0 && banderaNumero2==0 && division (numero1,numero2,&resultadoDivision)==0)
			{
				printf("\nLa division de %d y %d da como resulado: %.2f\n",numero1,numero2,resultadoDivision);
			}
			else
			{
				printf("\nNo se pudo realizar la division porque el segundo numero ingresado es 0.\n");
			}
			if(banderaNumero1==0 && banderaNumero2==0 && factoreo(numero2,&resultadoFactoreo)==0)
			{
				printf("El %d factorizado es: %d\n",numero1,resultadoFactoreo);
			}
			else
			{
				printf("No se pudo realizar el factoreo de %d\n",numero1);
			}

			if(banderaNumero1==0 && banderaNumero2==0 && factoreo(numero2,&resultadoFactoreo)==0)
			{
				printf("El %d factorizado es: %d\n",numero2,resultadoFactoreo);
			}
			else
			{
				printf("No se pudo realizar el factoreo de %d\n",numero2);
			}
		}
	}while(opciones!=9);

return EXIT_SUCCESS;
}
