/*
 * employee.c
 *
 *  Created on: 25 sept. 2020
 *      Author: Gonzalo
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"



static int employee_generarIdNuevo(void);
//INICIAR TODOS LOS EMPLEADOS SIN DATOS
int employee_initArray(Employee* arrayEmployee, int len)
{
	int retorno = -1;
	if(arrayEmployee != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			arrayEmployee[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}
//PEDIR DATOS PARA CARGAR EMPLEADO
int employee_data(Employee* arrayEmployee,int len)
{

	int retorno = -1;
	char name[LONG_NOMBRE];
	char lastName[LONG_NOMBRE];
	int sector;
	float salary;
	int indice;
	int id;


	if(arrayEmployee!=NULL && len>0)
	{

		if(employee_espacioLibre(arrayEmployee,QTY_EMPLOYEE,&indice)==0 &&
			getNombre("Ingrese el nombre: ","\nError, no es un nombre valido.",name,3,LONG_NOMBRE)==0 &&
			getNombre("Ingrese el apellido: ","Error, no es un apellido valido", lastName,3,LONG_NOMBRE)==0 &&
			utn_getNumeroFloat(&salary,"ingrese el salario: ","Error no es un salario valido",0,200000,3)==0 &&
			getInt("Ingrese el sector al que pertenece:\nOpcion1:Caja\nOpcion2:Produccion\nOpcion3:Cocina\nOpcion4:Cafeteria\nNumero a ingresar: ",
					"Error, sector invalido.",&sector,3,4,1)==0)
		{
			id=employee_generarIdNuevo();
			employee_alta(arrayEmployee, len, indice, name, lastName, sector, salary,id);
			printf("El ID de este empleado es: %d",arrayEmployee[indice].id);
			retorno=0;
		}
	}
	return retorno;
}
// DAR ALTA AL EMPLEADO
int employee_alta(Employee* arrayEmployee,int len ,int indice,char* name,char* lastName,int sector,float salary,int id)
{
	int retorno = -1;

	if(	arrayEmployee != NULL && len > 0 &&	indice >=0 && indice < len
		&& arrayEmployee[indice].isEmpty == TRUE &&	name!=NULL &&
		lastName!= NULL && sector>0 && salary <20000)
	{
			strncpy(arrayEmployee[indice].name,name,LONG_NOMBRE);
			strncpy(arrayEmployee[indice].lastName,lastName,LONG_NOMBRE);
			arrayEmployee[indice].sector=sector;
			arrayEmployee[indice].salary=salary;
			arrayEmployee[indice].id=id;
			arrayEmployee[indice].isEmpty = FALSE;
			retorno = 0;
	}
	return retorno;
}
//GENERAR ID NUEVO POR CADA CARGA DE DATOS
static int employee_generarIdNuevo(void)
{
	static int id=0;
	id++;
	return id;
}

//BUSCAR INDICE LIBRE
int employee_espacioLibre(Employee* arrayEmployee, int len, int* pResultado)
{
	int retorno=-1;
	int i;
	if(arrayEmployee!=NULL && len>0 && pResultado!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(arrayEmployee[i].isEmpty==TRUE)
			{
				*pResultado=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
// MODIFICAR EMPLEADO
int employee_modify(Employee* arrayEmployee,int limite)
{
	int retorno=-1;
	int i;
	int buscarId;
	int opcion;
	int flagId=1;
	Employee bufferEmployee;

	if(getInt("Ingrese el id para modificar los datos","Error, no es un numero valido",&buscarId,3,1000,1)==0 &&
		arrayEmployee != NULL && limite>0 && buscarId >0
		)
	{

		for(i=0;i<limite;i++)
		{
			if(arrayEmployee[i].isEmpty==FALSE && arrayEmployee[i].id==buscarId)
			{
				flagId=0;
				getInt("Opciones a modificar\nOpcion 1: Nombre\nOpcion 2: Apellido\nOpcion 3: Salario\nOpcion 4: Sector\n"
				"Ingrese campo a modificar: ","ERORR, No es un campo valido\n",&opcion,3,4,1);

				switch(opcion)
				{
					case 1:
							if(getNombre("Ingrese el nuevo nombre: ","\nError, no es un nombre valido.",bufferEmployee.name,3,LONG_NOMBRE)==0)
							{
								strncpy(arrayEmployee[i].name,bufferEmployee.name,LONG_NOMBRE);
							}
							break;
					case 2:
							if(getNombre("Ingrese el nuevo apellido: ","\nError, no es un nombre valido.",bufferEmployee.lastName,3,LONG_NOMBRE)==0)
							{
								strncpy(arrayEmployee[i].lastName,bufferEmployee.lastName,LONG_NOMBRE);
							}

						break;
					case 3:
							if(utn_getNumeroFloat(&bufferEmployee.salary,"ingrese el nuevo salario: ","Error no es un salario valido",0,200000,3)==0)
							{
								arrayEmployee[i].salary=bufferEmployee.salary;
							}
							break;
					case 4:
							if(getInt("Ingrese el nuevo sector al que pertenece:\nOpcion1:Caja\nOpcion2:Produccion\nOpcion3:Cocina\nOpcion4:Cafeteria\nNumero a ingresar: ",
										"Error, sector invalido.",&bufferEmployee.sector,3,4,1)==0)
							{
								arrayEmployee[i].sector=bufferEmployee.sector;
							}
							break;

				}
				retorno=0;
			}

		}

	}
	if(flagId==1)
	{
		printf("No se encontro el ID que ingreso");
	}
	return retorno;
}
// ELIMINAR EMPLEADO
int employee_unsubscribe(Employee* arrayEmployee,int limite)
{
	int retorno=-1;
	int i;
	int buscarId;

	if(getInt("Ingrese el id para borrar  los datos","Error, no es un numero valido",&buscarId,3,1000,1)==0 &&
		arrayEmployee != NULL && limite>0 && buscarId >0)
	{
		for(i=0;i<limite;i++)
		{
			if(arrayEmployee[i].isEmpty==FALSE && arrayEmployee[i].id == buscarId)
				{
					arrayEmployee[i].isEmpty = TRUE;
					retorno=0;
					break;
				}
		}
	}
	return retorno;
}

// ORDENAR
int employee_sortEmployee(Employee* arrayEmployee, int len, int order)
{
	Employee bufferEmployee;
	int retorno=-1;
	int i;
	int flagOrder=1;

	if(arrayEmployee!=NULL && len>0 && order>=0)
	{
		while(flagOrder==1)
		{
			flagOrder=0;
			for(i=0;i<len-1;i++)
			{
				if(order==1 && arrayEmployee[i].sector<arrayEmployee[i+1].sector)
				{
					bufferEmployee=arrayEmployee[i];
					arrayEmployee[i]=arrayEmployee[i+1];
					arrayEmployee[i+1]=bufferEmployee;
					flagOrder=1;
				}
				else if(arrayEmployee[i].sector==arrayEmployee[i+1].sector &&
						strncmp(arrayEmployee[i].lastName,arrayEmployee[i+1].lastName,LONG_NOMBRE)>0)
				{
					bufferEmployee=arrayEmployee[i];
					arrayEmployee[i]=arrayEmployee[i+1];
					arrayEmployee[i+1]=bufferEmployee;
					flagOrder=1;
				}
				if(order==0&& arrayEmployee[i].sector>arrayEmployee[i+1].sector)
					{
						bufferEmployee=arrayEmployee[i];
						arrayEmployee[i]=arrayEmployee[i+1];
						arrayEmployee[i+1]=bufferEmployee;
						flagOrder=1;
					}
					else if(arrayEmployee[i].sector==arrayEmployee[i+1].sector &&
							strncmp(arrayEmployee[i].lastName,arrayEmployee[i+1].lastName,LONG_NOMBRE)>0)
					{
						bufferEmployee=arrayEmployee[i];
						arrayEmployee[i]=arrayEmployee[i+1];
						arrayEmployee[i+1]=bufferEmployee;
						flagOrder=1;
					}
			}
		}
	}
	return retorno;
}

//funcion para recorrer el array y guardar los salarios acumulados
//funcion para recorrer el array y contar cuantos id son
//funcion para sacar el promedio de los salarios divididos cuantos id se contaron
// funcion para ver cuantos empleadon superan el promedio


//SALARIOS ACUMULADOS
int employee_salary(Employee* arrayEmployee,int len,float* pResultado)
{
	int retorno=-1;
	int i;
	float acumulador=0;

	if(arrayEmployee!=NULL && len>0 && pResultado!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(arrayEmployee[i].isEmpty==FALSE)
			{
				acumulador = acumulador + arrayEmployee[i].salary;
				retorno=0;
			}
		}
	}
	*pResultado=acumulador;
	return retorno;
}

// EMPLEADOS CARGADOS
int employee_contarId(Employee* arrayEmployee,int len,int* cantidadId)
{
	int retorno=-1;
	int contadorId=0;
	int i;

	if(arrayEmployee!=NULL && len>0 && cantidadId!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(arrayEmployee[i].isEmpty==FALSE && arrayEmployee[i].id>0)
			{
				contadorId++;
				retorno=0;
			}
		}
	}
	*cantidadId = contadorId;
	return retorno;
}

// PROMEDIO DE SALARIO DIVIDIDO EMPLEADOS
int employee_promedio(float salario,int cantidadId,float* pResultado)
{
	int retorno=-1;

	if(salario>0 && cantidadId>0 && pResultado!=NULL)
	{
		*pResultado=salario/cantidadId;
		retorno=0;
	}
	return retorno;
}

//QUE EMPLEADO SUPERA EL SALARIO MINIMO
int employee_higherSalary(Employee* arrayEmployee,int len,float promedio, int* pResultado)
{
	int retorno=-1;
	int i;
	int contadorSalariosAltos=0;

	if(arrayEmployee!=NULL && len>0 && promedio>0 && pResultado!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(arrayEmployee[i].isEmpty==FALSE && arrayEmployee[i].salary > promedio)
			{
				contadorSalariosAltos++;
				retorno=0;
			}
		}
	}
	*pResultado=contadorSalariosAltos;
	return retorno;
}

int employee_promedioTotal(Employee* arrayEmployee,int len)
{
	int retorno=-1;
	float salarioTotal;
	int empleadosTotal;
	float promedioTotal;
	int salarioMayorPromedio;

	if(employee_salary(arrayEmployee,len,&salarioTotal)==0 &&
		employee_contarId(arrayEmployee,len,&empleadosTotal)==0)
	{
		employee_promedio(salarioTotal,empleadosTotal,&promedioTotal);
	}
	printf("El salario promedio es: %.2f",promedioTotal);
	if(employee_higherSalary(arrayEmployee,len,promedioTotal,&salarioMayorPromedio)==0)
	{
		printf("\nEstos superan el promedio: %d",salarioMayorPromedio);
	}
	else
	{
		printf("\nEl salario de ningun empleado supera al promedio");
	}


	return retorno;
}

//IMPRIMIR

int employee_imprimir(Employee* arrayEmployee, int len)
{
	int retorno = -1;
	if(arrayEmployee != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(arrayEmployee[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - Apellido: %s\nID: %d Sector: %d Salario: %.2f",arrayEmployee[i].name,arrayEmployee[i].lastName,arrayEmployee[i].id,
						arrayEmployee[i].sector,arrayEmployee[i].salary);
			}
		}
		retorno = 0;
	}
	return retorno;
}



int employee_menu()
{
	int retorno;

	printf("********************************************************************\n\n");
	printf("*************BIENVENIDO*********************************************\n\n");
	printf("*INGRESE LA OPCION QUE DESEE\n");
	printf("*>OPCION 1: ALTA A EMPLEADO.\n");
	printf("*>OPCION 2: MODIFICAR DATOS EMPLEADO.\n");
	printf("*>OPCION 3: BAJA A EMPLEADO.\n");

	getInt("\ningresa la opcion: ","Error",&retorno,3,7,1);

	return retorno;
}
