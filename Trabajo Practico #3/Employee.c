#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"
#include "LinkedList.h"
/*
 * brief Asigna un lugar en memoria para un empleado
 * return Puntero al empleado
 */
Employee* employee_new(void)
{
	return (Employee*)malloc(sizeof(Employee));
}
/*
 * brief Carga, a travez de variables, los campos de un empleado
 * param char* idStr Id a ser cargado
 * param char* nombreStr Nombre a ser cargado
 * param char* horasTrabajadasStr Horas a ser cargadas
 * param char* sueldo Sueldo a ser cargado
 * return Puntero al nuevo empleado
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
	Employee* this = employee_new();

	if(idStr !=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldo != NULL)
	{
			employee_setNombre(this, nombreStr);
			employee_setId(this, atoi(idStr));
			employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr));
			employee_setSueldo(this, atoi(sueldo));
		}
	return this;
}
/*
 * brief Libera el espacio de memoria de un empleado
 */
void employee_borrar(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}


/*
 * brief Escribe en el campo ID
 * param Employee* this puntero a empleado
 * param int id ID a cargar
 * return (0) si salio todo bien (-1)si hubo un error
 */
int employee_setId(Employee* this,int id)
{
    int retorno = -1;

    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
/*
 * brief Duevuelve el ID
 * param Employee* this puntero a empleado
 * param int* id puntero donde devuelve el valor
 * return (0) si salio todo bien (-1)si hubo un error
 */
int employee_getId(Employee* this,int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

/*
 * brief Escribe en el campo Nombre
 * param Employee* this puntero a empleado
 * param int id Nombre a cargar
 * return (0) si salio todo bien (-1)si hubo un error
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        if(esUnNombreValido(nombre, 128) == 1)
        {
            strncpy(this->nombre, nombre, 128);
            retorno = 0;
        }
    }
    return retorno;
}
/*
 * brief Devuelve nombre
 * param Employee* this puntero a empleado
 * param int* nombre puntero donde devuelve el valor
 * return (0) si salio todo bien (-1)si hubo un error
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    // char aux[18]="GONZALO";
    if(this != NULL && nombre != NULL && esUnNombreValido(this->nombre,128) == 1)
    {
        strncpy(nombre,this->nombre, 128);
        retorno = 0;
    }
    return retorno;
}

/*
 * brief Escribe en el campo HorasTrabajadas
 * param Employee* this puntero a empleado
 * param int horasTrabajadas Horas a cargar
 * return (0) si salio todo bien (-1)si hubo un error
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
/*
 * brief Devuelve las horas trabajadas
 * param Employee* this puntero a empleado
 * param int* horasTrabajadas puntero donde devuelve el valor
 * return (0) si salio todo bien (-1)si hubo un error
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

/*
 * brief Escribe en el campo Sueldo
 * param Employee* this puntero a empleado
 * param int sueldo Sueldo a cargar
 * return (0) si salio todo bien (-1)si hubo un error
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}
/*
 * brief Devuelve el sueldo
 * param Employee* this puntero a empleado
 * param int* sueldo puntero donde devuelve el valor
 * return (0) si salio todo bien (-1)si hubo un error
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}
/*
 * brief Imprime la lista de empleados
 * param LinkedList pArrayListEmployee puntero a la lista enlazada a empleados
 * param int index Indice del empleado a imprimir
 * return (0)si salio todo bien (-1)si hubo un error
 */
int employee_printEmployee(LinkedList* pArrayListEmployee, int index)
{
    int retorno = -1;

    Employee* pAuxEmployee;
    int auxId;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(pArrayListEmployee != NULL && index > 0)
    {
        pAuxEmployee = ll_get(pArrayListEmployee, index);
        if( employee_getId(pAuxEmployee, &auxId) == 0 &&
                employee_getNombre(pAuxEmployee, auxNombre) == 0 &&
                employee_getHorasTrabajadas(pAuxEmployee, &auxHorasTrabajadas) == 0 &&
                employee_getSueldo(pAuxEmployee, &auxSueldo) == 0 )
        {
            printf("  %-5d     %-14s     %-10d       %-10d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
        }
        else
        {
            printf("*>Error\n");
        }
    }
    return retorno;
}
/*
 * brief Genera un ID Maximo
 * param LinkedList pArrayListEmployee puntero a la lista enlazada a empleados
 * return (0)si salio todo bien (-1)si hubo un error
 */
int employee_generarId(LinkedList* this)
{
    Employee* auxiliar;
    int cant;
    int auxId;
    int maxID = -1;
    int i;
    if(this != NULL)
    {
        cant = ll_len(this);
        for(i=0;i<cant;i++)
        {
            auxiliar = ll_get(this, i);
            employee_getId(auxiliar, &auxId);
            if(auxId > maxID)
            {
                maxID = auxId;
            }
        }
    }
    maxID += 1;
    return maxID;
}
/*
 * brief Busca la posicion de un empleado por el ID
 * param LinkedList this puntero a la lista enlazada a empleados
 * param int idABuscas ID a ser buscado
 * param int* index puntero donde devuelve el indice del ID busca
 * return (0)si salio todo bien (-1)si hubo un error
 */
int employee_buscarIndicePorId(LinkedList* this, int idABuscar,int* index)
{
	int retorno = -1;
	int i;
	int len;
	int idAux;
	Employee* bufferEmployee;

	if(this!= NULL && idABuscar>0 && index!=NULL)
	{
		len = ll_len(this);
		if(len>0)
		{
			for(i=0;i<len;i++)
			{
				bufferEmployee = ll_get(this, i);
				employee_getId(bufferEmployee,&idAux);
				if(idAux == idABuscar)
				{
					*index = i;
					retorno=0;
				}
			}
		}
	}
	return retorno;
}
/*
 * brief Ordena por nombre
 * param void* thisA puntero donde se recibira el primer empleado
 * param void* thisA puntero donde se recibira el segundo empleado
 * return (0)si salio todo bien (-1)si hubo un error
 */
int employee_ordenarPorNombre (void* thisA, void* thisB)
{
	int retorno;
	Employee* auxA =(Employee*)thisA;
	Employee* auxB =(Employee*)thisB;
	char nombreA[128];
	char nombreB[128];
	int respuesta;
	employee_getNombre(auxA, nombreA);
	employee_getNombre(auxB, nombreB);
	respuesta=strncmp(nombreA,nombreB,128);
	if(respuesta>0)
	{
		retorno=1;
	}
	else if(respuesta<0)
	{
		retorno=-1;
	}
	else
	{
		retorno = 0;
	}
	return retorno;
}
/*
 * brief Ordena por ID
 * param void* thisA puntero donde se recibira el primer empleado
 * param void* thisA puntero donde se recibira el segundo empleado
 * return (0)si salio todo bien (-1)si hubo un error
 */
int employee_ordenarPorId(void* thisA,void* thisB)
{
	int retorno;
	Employee* auxA = (Employee*)thisA;
	Employee* auxB = (Employee*)thisB;
	int idA;
	int idB;
	employee_getId(auxA,&idA);
	employee_getId(auxB,&idB);

	if(idA>idB)
	{
		retorno=1;
	}
	else if(idA<idB)
	{
		retorno=-1;
	}
	else
	{
		retorno=0;
	}
	return retorno;
}
/*
 * brief Ordena por horas trabajadas
 * param void* thisA puntero donde se recibira el primer empleado
 * param void* thisA puntero donde se recibira el segundo empleado
 * return (0)si salio todo bien (-1)si hubo un error
 */
int employee_ordenarPorHorasTrabajadas(void* thisA,void* thisB)
{
	int retorno;
	Employee* auxA = (Employee*)thisA;
	Employee* auxB = (Employee*)thisB;
	int idA;
	int idB;
	employee_getHorasTrabajadas(auxA,&idA);
	employee_getHorasTrabajadas(auxB,&idB);

	if(idA>idB)
	{
		retorno=1;
	}
	else if(idA<idB)
	{
		retorno=-1;
	}
	else
	{
		retorno=0;
	}
	return retorno;
}
/*
 * brief Ordena por sueldo
 * param void* thisA puntero donde se recibira el primer empleado
 * param void* thisA puntero donde se recibira el segundo empleado
 * return (0)si salio todo bien (-1)si hubo un error
 */
int employee_ordenarPorSueldo(void* thisA,void* thisB)
{
	int retorno;
	Employee* auxA = (Employee*)thisA;
	Employee* auxB = (Employee*)thisB;
	int idA;
	int idB;
	employee_getSueldo(auxA,&idA);
	employee_getSueldo(auxB,&idB);

	if(idA>idB)
	{
		retorno=1;
	}
	else if(idA<idB)
	{
		retorno=-1;
	}
	else
	{
		retorno=0;
	}
	return retorno;
}
/*
 * brief menu de opciones
 */
void employee_menuOrdenado()
{
	printf("\n\n*************ORDENADO*************\n\n");
	printf("****************************************\n\n");
	printf("*INGRESE LA OPCION QUE DESEE\n");
	printf("*>OPCION 1: ORDENAR POR NOMBRE.\n");
	printf("*>OPCION 2: ORDENAR POR ID.\n");
	printf("*>OPCION 3: ORDENAR POR HORAS TRABAJADAS.\n");
	printf("*>OPCION 4: ORDENAR POR SUELDO.\n");
	printf("*>OPCION 5: Salir.\n");
	printf("********************************************");

}
