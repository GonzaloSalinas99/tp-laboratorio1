#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#include "controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Ruta del archivo a cargar
 * \param pArrayListEmployee LinkedList* Puntero a la lista enlazada
 * \return int (0)si salio todo bien (-1)si hubo un error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
   int retorno = -1;
	FILE* pFile;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL && parser_EmployeeFromText(pFile, pArrayListEmployee) == 0)
		{

			printf("*>Datos cargados con exito!\n\n");
			retorno = 0;
		}
		else
		{
			printf("*>No ha sido posible cargar los datos\n\n");
		}
	}
	else
	{
		printf("*>Error NULL\n\n");
	}
	fclose(pFile);
	return retorno;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char* Ruta del archivo a cargar
 * \param pArrayListEmployee LinkedList* Puntero a la lista enlazada
 * \return int (0)si salio todo bien (-1)si hubo un error
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pFile;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path,"rb");
		if(pFile!=NULL && parser_EmployeeFromBinary(pFile, pArrayListEmployee)==0)
		{
			printf("*>Formato Binario cargado con exito\n");
			retorno=0;
		}
		else
		{
			printf("*>No ha sido posible cargar los datos\n\n");
		}
	}
	fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList* Puntero a la lista enlazada
 * \return int (0)si salio todo bien (-1)si hubo un error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee* bufferEmployee = employee_new();
	char nombre[128];
	char sueldo[128];
	char horas [128];
	int id;

	if(pArrayListEmployee!=NULL)
	{
		if(getNombre("\n*>Nombre a ingresar: ","\nError",nombre,3,128)==0 &&
		getNumero("\n*>Ingrese las horas trabajadas: ","\nError",horas,3,10)==0 &&
		getNumero("\n*>Ingrese el sueldo: ","\nError",sueldo, 3,10)==0)
		{
			id = employee_generarId(pArrayListEmployee);
			employee_setNombre(bufferEmployee,nombre);
			employee_setSueldo(bufferEmployee,atoi(sueldo));
			employee_setHorasTrabajadas(bufferEmployee,atoi(horas));
			employee_setId(bufferEmployee,id);
			ll_add(pArrayListEmployee, bufferEmployee);
			printf("\n*>Empleado cargado correctamente.\n");
		}
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList* puntero a la lista enlazada
 * \return int (0)si salio todo bien (-1)si hubo un error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* bufferEmployee;
	int len;
	int indiceAModificar;
	int idABuscar;
	int idAux;
	char nombre[128];
	char horas[128];
	char sueldo[128];

	if(pArrayListEmployee!=NULL)
	{
		len=ll_len(pArrayListEmployee);
		controller_ListEmployee(pArrayListEmployee);
		if(len>0 && getInt("\n*>Ingrese el ID del empleado que quiere modificar: ","ERROR. No existe ese ID",&idABuscar, 3,len,0)==0)
		{
			if(employee_buscarIndicePorId(pArrayListEmployee,idABuscar,&indiceAModificar)==0)
			{
				bufferEmployee = ll_get(pArrayListEmployee, indiceAModificar);
				employee_getId(bufferEmployee,&idAux);

				if(getNombre("\n*>Nombre a ingresar: ","\nError",nombre,3,128)==0 &&
				getNumero("\n*>Ingrese las horas trabajadas: ","\nError",horas,3,10)==0 &&
				getNumero("\n*>Ingrese el sueldo: ","\nError",sueldo, 3,10)==0)
				{
					employee_setNombre(bufferEmployee,nombre);
					employee_setSueldo(bufferEmployee,atoi(sueldo));
					employee_setHorasTrabajadas(bufferEmployee,atoi(horas));
					employee_setId(bufferEmployee, idAux);
					retorno=0;
					printf("\n*>Empleado modificado correctamente.\n");
				}
			}
		}
	}
    return retorno;
}

/** \brief Baja de empleado
 * \param pArrayListEmployee LinkedList* puntero a la lista enlazada
 * \return int (0)si salio todo bien (-1)si hubo un error
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int idABuscar;
	int indiceABorrar;
	Employee* bufferEmployee;
	int len;

	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		len=ll_len(pArrayListEmployee);
		if(len>0 && getInt("\n*>Ingrese el ID del empleado a borrar: ", "ERROR. No se encontro ese ID", &idABuscar,3, len, 0)==0)
		{
			if(employee_buscarIndicePorId(pArrayListEmployee,idABuscar,&indiceABorrar)==0)
			{
				bufferEmployee = ll_get(pArrayListEmployee, indiceABorrar);
				ll_remove(pArrayListEmployee, indiceABorrar);
				employee_borrar(bufferEmployee);
					printf("\n*>Empleado borrado con exito\n");
					retorno = 0;

			}
		}
	}

    return retorno;
}

/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList* puntero a la lista enlazada
 * \return int (0)si salio todo bien (-1)si hubo un error
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
    Employee* auxEmp;
    int auxID;
    int auxSueldo;
    int auxHoras;
    char bufferName[4096];
    int i;
    if(pArrayListEmployee != NULL)
    {
        for(i=1; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmp = ll_get(pArrayListEmployee, i);
            employee_getId(auxEmp, &auxID);
            employee_getSueldo(auxEmp, &auxSueldo);
            employee_getHorasTrabajadas(auxEmp, &auxHoras);
            employee_getNombre(auxEmp, bufferName);
            printf("ID: %-5d | Nombre: %-15s | Horas Trabajadas: %-10d | Sueldo: $%-12d\n",
            auxID, bufferName, auxHoras, auxSueldo);
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 * \param pArrayListEmployee LinkedList* puntero a la lista enlazada
 * \return int (0)si salio todo bien (-1)si hubo un error
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int orden;

	if(pArrayListEmployee!=NULL)
	{
		if(getInt("\n*>Ingrese (1) Ascendente o (0) Descendente\n","Error",&orden,3,1,0)==0)
		{
			ll_sort(pArrayListEmployee, employee_ordenarPorNombre,orden);
		}
		retorno=0;
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* Ruta del archivo en donde guardar los datos
 * \param pArrayListEmployee LinkedList* puntero a la lista enlazada
 * \return int (0) si salio todo bien (-1)si hubo un error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	Employee* bufferEmployee;
	char nombre[128];
	int id;
	int horas;
	int sueldo;
	int len = ll_len(pArrayListEmployee);
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile = fopen(path,"w");
		if(pFile!=NULL)
		{
			for(int i=0;i<len;i++)
			{
				bufferEmployee=(Employee*)ll_get(pArrayListEmployee, i);
				employee_getNombre(bufferEmployee, nombre);
				employee_getId(bufferEmployee, &id);
				employee_getHorasTrabajadas(bufferEmployee, &horas);
				employee_getSueldo(bufferEmployee, &sueldo);
				fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horas,sueldo);
			}
		}
			retorno=0;
	}

	fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* Ruta del archivo en donde guardar los datos
 * \param pArrayListEmployee LinkedList* puntero a la lista enlazada
 * \return int (0) si salio todo bien (-1)si hubo un error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pFile;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path,"wb");
		if(pFile!=NULL)
		{
			retorno=parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		}
		else
		{
			printf("*>NO SE PUDO CARGAR\n");
		}
	}
	fclose(pFile);
    return retorno;
}
/*
 * brief Menu de opciones
 * param int* puntero donde guardar el resultado obtenido
 * return int (0) si salio todo bien (-1)si hubo un error
 */
int controller_menu(int* pOpcion)
{
	int retorno=-1;

	printf("\n\n*************BIENVENIDO*************\n\n");
	printf("****************************************\n\n");
	printf("*INGRESE LA OPCION QUE DESEE\n");
	printf("*>OPCION 1: Carga de datos desde el archivo de texto.\n");
	printf("*>OPCION 2: Carga de datos desde el archivo de binario.\n");
	printf("*>OPCION 3: Alta empleado.\n");
	printf("*>OPCION 4: Modificar empleado.\n");
	printf("*>OPCION 5: Baja empleado.\n");
	printf("*>OPCION 6: Listar empleado.\n");
	printf("*>OPCION 7: Ordenar empleado.\n");
	printf("*>OPCION 8: Guardar los datos en el archivo de texto.\n");
	printf("*>OPCION 9: Guardar los datos en el archivo binario.\n");
	printf("*>OPCION 10: Salir.\n");
	printf("********************************************");

	getInt("\ningresa la opcion: ","Error",&retorno,3,5,1);
	*pOpcion=retorno;
	return retorno;
}
