
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

	if(employee_initArray(list,QTY_EMPLOYEE)==0)
	{
		do
		{
			switch(employee_menu(&opcionInicio))
			{
			printf("%d opcion",opcionInicio);
				case 1:
						if(employee_data(list, QTY_EMPLOYEE)==0)
						{
							printf("\n-*Empleado cargado correctamente\n");
							flagEmployee=1;
						}
					break;
				case 2:
						if(flagEmployee==1 && employee_modify(list,QTY_EMPLOYEE)==0)
						{
							printf("\n-*Empleado modificado correctamente\n");
						}
						else
						{
							printf("-*No se pudo realizar la modificacion\n");
						}
					break;
				case 3:
						if(flagEmployee==1 && employee_unsubscribe(list,QTY_EMPLOYEE)==0)
						{
							printf("\n-*Empleado borrado correctamente\n");
						}
						else
						{
							printf("No se pudo borrar correctamente\n");
						}
					break;
				case 4:
						if(flagEmployee==1)
						{	do
							{
								switch(employee_report(&opcionInforme))
									{
									case 1:
											if(getInt("\n\n-*OPCION 1 :ORDENAR DE FORMA ASCENDENTE.\n"
													"-*OPCION 2 : ORDENAR DE FORMA DESCENTE.\n"
													"-*OPCION 3 : VOLVER AL MENU DE INFORMES.\n\n"
													"-*Ingrese opcion elegida: ","\nError,Opcion incorrecta.\n",&order,3,3,1)==0)
											{
												employee_sortEmployee(list, QTY_EMPLOYEE, order);
											}
										break;

									case 2:
											employee_imprimir(list, QTY_EMPLOYEE);
										break;
									case 3:
											employee_promedioTotal(list,QTY_EMPLOYEE);
										break;
									}
							}while(opcionInforme!=4);
								break;
						}
			}
		}while(opcionInicio!=5);
	}
	return EXIT_SUCCESS;
}
