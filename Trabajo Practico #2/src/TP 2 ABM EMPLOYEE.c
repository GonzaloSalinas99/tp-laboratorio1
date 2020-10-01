
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "utn.h"
#include <string.h>
#define QTY_EMPLOYEE 1000


int main(void)
{
	setbuf(stdout,NULL);
	Employee empleado[QTY_EMPLOYEE];
	int opcion=0;
	int order;
	int flagEmployee=0;

	employee_initArray(empleado,QTY_EMPLOYEE);

	do
	{

		switch(employee_menu())
		{
			case 1:

					if(employee_data(empleado, QTY_EMPLOYEE)==0)
					{
						printf("\nEmpleado cargado correctamente\n");
						flagEmployee=1;
					}
				break;
			case 2:
					if(employee_modify(empleado,QTY_EMPLOYEE)==0 && flagEmployee==1)
					{
						printf("\nEmpleado modificado correctamente\n");
					}
					else
					{
						printf("No se pudo realizar la modificacion\n");
					}
				break;
			case 3:
					if(employee_unsubscribe(empleado,QTY_EMPLOYEE)==0 && flagEmployee==1)
					{
						printf("\nEmpleado borrado correctamente\n");
					}
				break;
			case 4:
					if(getInt("\nIngrese <0> si quiere odenar la lista de forma ascendente\n"
							  "Ingrese <1> si quiere ordenar la lista de forma descendente\nOpcion elegida","ERROR",&order,3,1,0)==0)
					{
						employee_sortEmployee(empleado,QTY_EMPLOYEE,order && flagEmployee==1);
					}
				break;
			case 5:
				 employee_promedioTotal(empleado, QTY_EMPLOYEE && flagEmployee==1);
				break;
			case 6:
					employee_imprimir(empleado,QTY_EMPLOYEE && flagEmployee==1);
				break;
		}
	}while(opcion!=7);



	return EXIT_SUCCESS;
}
