#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
	setbuf(stdout,NULL);
    int option;
    int flagTxt=0;
    int flagBin=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados!=NULL)
    {
		do
		{
			switch(controller_menu(&option))
			{
				case 1:
						if(controller_loadFromText("data.csv",listaEmpleados)==0)
						{
							flagTxt=1;
							printf("\n Archivo de texto cargado correctamente");
						}
					break;
				case 2:
						if(controller_loadFromBinary("datta.bin", listaEmpleados)==0)// && flagTxt==1)
						{
							flagBin=1;
							printf("\n Archivo binario cargado correctamente");
						}
						else
						{
							printf("\n No se pudo cargar correctamente el archivo");
						}
									break;
				case 3:
						if((flagBin == 1 || flagTxt == 1) && controller_addEmployee(listaEmpleados)==0)
						{
							printf("\n Alta exitosa");
						}
						else
						{
							printf("\nOcurrio un error en la alta de empleado.\n");
						}
									break;
				case 4:
						if((flagBin == 1 || flagTxt == 1) && controller_editEmployee(listaEmpleados)==0)
						{
							printf("\n Modificacion exitosa");
						}
						else
						{
							printf("\nOcurrio un error en la modificacion de un empleado.\n");
						}
									break;
				case 5:
						if((flagBin == 1 || flagTxt == 1) && controller_removeEmployee(listaEmpleados)==0)
						{
							printf("\n Baja exitosa");
						}
						else
						{
							printf("\nOcurrio un error en la baja de un empleado.\n");
						}
									break;
				case 6:
						if((flagBin == 1 || flagTxt == 1) && controller_ListEmployee(listaEmpleados)==0)
						{
							printf("\n Listado exitoso");
						}
						else
						{
							printf("\nOcurrio un error en el listado de los empleados.\n");
						}

									break;
				case 7:
						if((flagBin == 1 || flagTxt == 1) && controller_sortEmployee(listaEmpleados)==0)
						{
							printf("\n Ordenamiento exitoso");
						}
						else
						{
							printf("\nOcurrio un error en el ordenamiento de los empleados.\n");
						}
									break;
				case 8:
						if((flagBin == 1 || flagTxt == 1) && controller_saveAsText("data.csv",listaEmpleados)==0)
						{
							printf("\n Guardado exitoso");
						}
						else
						{
							printf("\nOcurrio un error en el guardado del archivo de texto.\n");
						}
									break;
				case 9:
						if((flagBin == 1 || flagTxt == 1) && controller_saveAsBinary("datta.bin",listaEmpleados)==0)
						{
							printf("\n Guardado exitoso");
						}
						else
						{
							printf("\nOcurrio un error en el guardado del archivo binario.\n");
						}
									break;
			}
		}while(option!=10);
    }
	ll_deleteLinkedList(listaEmpleados);
    return 0;
}
