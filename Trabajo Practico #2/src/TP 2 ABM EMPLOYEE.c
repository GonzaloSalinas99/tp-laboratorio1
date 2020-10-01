
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "utn.h"
#include <string.h>
#define QTY_EMPLOYEE 1000


int main(void)
{
	setbuf(stdout,NULL);
	Employee list[QTY_EMPLOYEE];
	int opcionInicio;
	int opcionInforme;
	int order;
	int flagEmployee=0;

	employee_initArray(list,QTY_EMPLOYEE);

	do
	{
		switch(employee_menu(&opcionInicio))
		{
			case 1:

					if(employee_data(list, QTY_EMPLOYEE)==0)
					{
						printf("\nEmpleado cargado correctamente\n");
						flagEmployee=1;
					}
				break;
			case 2:
					if(employee_modify(list,QTY_EMPLOYEE)==0 && flagEmployee==1)
					{
						printf("\nEmpleado modificado correctamente\n");
					}
					else
					{
						printf("No se pudo realizar la modificacion\n");
					}
				break;
			case 3:
					if(employee_unsubscribe(list,QTY_EMPLOYEE)==0 && flagEmployee==1)
					{
						printf("\nEmpleado borrado correctamente\n");
					}
				break;
			case 4:

				do
				{
					switch(employee_report(&opcionInforme))
						{
						case 1:
								if(getInt("\n\n<OPCION 1: IMPRIMIR.\n"
										"OPCION 2 : ORDENAR DE FORMA ASCENDENTE.\n"
										"OPCION 3 : ORDENAR DE FORMA DESCENDENTE.\n"
										"OPCION 4 : VOLVER AL MENU DE INFORMES.\n\n"
										"Ingrese opcion elegida: ","\nError,Opcion incorrecta.\n",&order,3,4,1)==0)
								{
									employee_sortEmployee(list, QTY_EMPLOYEE, order);
								}
							break;

						case 2:
								employee_promedioTotal(list, QTY_EMPLOYEE && flagEmployee==1);
							break;
						}
				}while(opcionInforme!=3);


					break;

		}
	}while(opcionInicio!=5);



	return EXIT_SUCCESS;
}
