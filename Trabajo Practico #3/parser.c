#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param FILE* pFile puntero a la estructura FILE
 * \param pArrayListEmployee LinkedList* puntero a la lista enlazada
 * \return int (0) si salio todo bien (-1)si hubo un error
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1; //retorno error
	Employee* pEmployee;
	char id[128];
	char nombre[128];
	char horasTrabajadas[128];
	char sueldo[128];
	int r;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
			if(r == 4)
			{
				pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				if(pEmployee != NULL)
				{
					ll_add(pArrayListEmployee, pEmployee);
					retorno = 0;
				}
			}
		}
		while(feof(pFile) == 0);
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param FILE* pFile puntero a la estructura FILE
 * \param pArrayListEmployee LinkedList* puntero a la lista enlazada
 * \return int (0) si salio todo bien (-1)si hubo un error
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	int len=ll_len(pArrayListEmployee);
	Employee* bufferEmployee;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		for(i=0;i<len;i++)
		{
			bufferEmployee=ll_get(pArrayListEmployee, i);
			fwrite(bufferEmployee,sizeof(Employee),1,pFile);
		}
		retorno=0;
	}
    return retorno;
}
