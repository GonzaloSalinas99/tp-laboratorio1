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
#include "employee.h"
#include "utn.h"

static int employee_generarIdNuevo(void);
/*
 *brief Menu de inicio del programa
 *param int* pOpcion Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 *return (0) si se ingreso correctamente la opcion (-1) Si la opcion es invalida
 */
int employee_menu(int* pOpcion)
{
	int retorno=-1;
	int buffer;

	printf("\n\n*************BIENVENIDO*************\n\n");
	printf("****************************************\n\n");
	printf("-*INGRESE LA OPCION QUE DESEE\n");
	printf("*>OPCION 1: ALTA A EMPLEADO.\n");
	printf("*>OPCION 2: MODIFICAR DATOS EMPLEADO.\n");
	printf("*>OPCION 3: BAJA A EMPLEADO.\n");
	printf("*>OPCION 4: INFORMAR.\n");
	printf("*>OPCION 5: SALIR.\n");

	if(getInt("\n-*ingrese la opcion: ","Error",&buffer,3,5,1)==0)
	{
		*pOpcion=buffer;
		retorno=0;
	}
	return retorno;
}
/*
 *brief Menu de informes del programa
 *param int* pOpcion Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 *return (0) si se ingreso correctamente la opcion (-1) Si la opcion es invalida
 */
int employee_report(int* pOpcion)
{
	int retorno=-1;
	int buffer;
	printf("\n\n*************INFORMES*************\n\n");
	printf("****************************************\n\n");
	printf("-*INGRESE LA OPCION QUE DESEE\n");
	printf("*>OPCION 1: ORDENAR.\n");
	printf("*>OPCION 2: IMPRIMIR.\n");
	printf("*>OPCION 3: PROMEDIO SALARIO Y CUANTOS EMPLEADOS SUPERAN ESTE PROMEDIO.\n");
	printf("*>OPCION 4: VOLVER AL MENU PRINCIPAL.\n");


	if(getInt("\n-*ingrese la opcion: ","Error",&buffer,3,4,1)==0)
	{
		*pOpcion=buffer;
		retorno=0;
	}
	return retorno;
}
/*
 *brief inicia en TRUE (vacio) en todas las posiciones del array.
 *param Employee* pArray Puntero al array de empleados
 *param int len Cantidad de posiciones del array
 *return (0) si se ingreso correctamente la opcion (-1) Si la opcion es invalida
 */
int employee_initArray(Employee* pArray, int len)
{
	int retorno = -1;
	if(pArray != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			pArray[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}
/*
 * brief Genera un ID unico y autoincremetable cada vez que es llamada
 */
static int employee_generarIdNuevo(void)
{
	static int id=0;
	id++;
	return id;
}
/*
 * brief Pide datos al usuario pra luego guardarlas en variables internas
 * param Employee* pArray Puntero al array de empleados
 * param int len Cantidad de posiciones que tiene el array
 * return (0) si se pudo realizar el pedido de datos con exito (-1) si no se pudo realizar correctamente el pedido de datos
 */
int employee_data(Employee* pArray,int len)
{
	int retorno = -1;
	char name[LONG_NOMBRE];
	char lastName[LONG_NOMBRE];
	int sector;
	float salary;
	int indice;
	int id;

	if(pArray!=NULL && len>0)
	{

		if(employee_espacioLibre(pArray,QTY_EMPLOYEE,&indice)==0 &&
			getNombre("\n-*Ingrese el nombre: ","\nError, no es un nombre valido.",name,3,LONG_NOMBRE)==0 &&
			getNombre("-*Ingrese el apellido: ","Error, no es un apellido valido", lastName,3,LONG_NOMBRE)==0 &&
			utn_getNumeroFloat(&salary,"-*ingrese el salario: ","Error no es un salario valido",0.00,9999999.99,3)==0&&
			getInt("-*Ingrese el sector al que pertenece:\nOPCION 1: Caja\nOPCION 2:Produccion\nOPCION 3:Cocina\nOPCION 4:Cafeteria\nNumero a ingresar: ",
					"Error, sector invalido.",&sector,3,4,1)==0)
		{
			id=employee_generarIdNuevo();
			employee_alta(pArray, len, indice, name, lastName, sector, salary,id);
			printf("El ID de este empleado es: %d",pArray[indice].id);
			retorno=0;
		}
	}
	return retorno;
}
/*
 *brief Carga, a travez de las variables, los campos del array ingresado segun su posicion
 * param Employee* pArray Puntero al array de empleados
 * param int len Cantidad de posiciones que tiene el array
 * param int indice posicion del array
 * param char* name Nombre ingresado por el usuario
 * param char* lastName Nombre ingresado por el usuario
 * param int sector Sector ingresado por el usuario
 * param float salary Salario ingresado por el usuario
 * param int id ID generado luego de pedir los datos al usuario
 * return
 * (0)Si se pudo realizar la carga de datos (-1) si no se reazlizo la carga con exito
 */
int employee_alta(Employee* pArray,int len ,int indice,char* name,char* lastName,int sector,float salary,int id)
{
	int retorno = -1;

	if(	pArray != NULL && len > 0 &&	indice >=0 && indice < len
		&& pArray[indice].isEmpty == TRUE &&	name!=NULL &&
		lastName!= NULL && sector>0 && salary <9999999.99 && id>0)
	{
			strncpy(pArray[indice].name,name,LONG_NOMBRE);
			strncpy(pArray[indice].lastName,lastName,LONG_NOMBRE);
			pArray[indice].sector=sector;
			pArray[indice].salary=salary;
			pArray[indice].id=id;
			pArray[indice].isEmpty = FALSE;
			retorno = 0;
	}
	return retorno;
}
/*
 * brief Recorre el array y busca un indice vacio
 * param Employee* pArray Puntero al array de empleados
 * param int len Cantidad de posiciones que tiene el array
 * param int* pResultado Direccion de memoria de la variable donde escribe la posicion encontrada
 * return (0)si se encontro una posicion vacio (-1)si no encontro una posicion vacio
 */
int employee_espacioLibre(Employee* pArray, int len, int* pResultado)
{
	int retorno=-1;
	int i;
	if(pArray!=NULL && len>0 && pResultado!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].isEmpty==TRUE)
			{
				*pResultado=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
/*
 * brief busca una posicion determinada a travez del ID
 * param Employee* pArray puntero al array de empleados
 * param int len Cantidad de posiciones que tiene el array
 * param int idBuscar ID ingresado por el usuario para buscar su indice o posicion
 * param int* pIndice Direccion de memoria de la variable donde escribe el valor encontrado
 *return (0)si pudo encontrar la posicion(-1)si no la encontro
 */
int employee_buscarIndicePorId (Employee* pArray, int len,int idBuscar,int * pIndice)
{
    int retorno = -1;
    int i ;
        if (pArray != NULL && len >0 && pIndice != NULL && idBuscar >= 0)
        {
                for ( i = 0; i<len; i++)
                {
                    if(pArray[i].isEmpty==FALSE &&
                       pArray[i].id == idBuscar)
                    {
                        *pIndice = i;
                        retorno = 0;
                    break;
                    }
                }
            }
            else
            {
                printf("error");
            }
        return retorno;
}
/*
 * brief Modifica los datos ingresados
 * param Employee* pArray puntero al array de empleados
 * param int len Cantidad de posiciones que tiene el array
 * return (0) si la modificacion se realizo con exito (-1)Si no se modificaron los datos correctamente
 */
int employee_modify(Employee* pArray,int limite)
{
	int retorno=-1;
	int buscarId;
	int indiceModificar;
	int opcion;
	int flagId=1;
	Employee bufferEmployee;
	if(employee_imprimir(pArray,limite)==0)
	{
		if(getInt("Ingrese el ID para modificar los datos","Error, no es un numero valido",&buscarId,3,1000,1)==0 &&
			pArray != NULL && limite>0 && buscarId >0)
		{
			if(employee_buscarIndicePorId(pArray,limite,buscarId,&indiceModificar)==0)
			{
				if(pArray[indiceModificar].isEmpty==FALSE)
				{
					flagId=0;
					getInt("-*Opciones a modificar\n-*Opcion 1: Nombre\n-*Opcion 2: Apellido\n"
							"-*Opcion 3: Salario\n-*Opcion 4: Sector\n"
							"-*Ingrese campo a modificar: ","ERORR, No es un campo valido\n",&opcion,3,4,1);

					switch(opcion)
					{
						case 1:
								if(getNombre("-*Ingrese el nuevo nombre: ","\nError, no es un nombre valido.",bufferEmployee.name,3,LONG_NOMBRE)==0)
								{
									strncpy(pArray[indiceModificar].name,bufferEmployee.name,LONG_NOMBRE);
								}
								break;
						case 2:
								if(getNombre("-*Ingrese el nuevo apellido: ","\nError, no es un nombre valido.",bufferEmployee.lastName,3,LONG_NOMBRE)==0)
								{
									strncpy(pArray[indiceModificar].lastName,bufferEmployee.lastName,LONG_NOMBRE);
								}

							break;
						case 3:
								if(utn_getNumeroFloat(&bufferEmployee.salary,"-*ingrese el nuevo salario: ","Error no es un salario valido",0,200000,3)==0)
								{
									pArray[indiceModificar].salary=bufferEmployee.salary;
								}
								break;
						case 4:
								if(getInt("-*Ingrese el nuevo sector al que pertenece:\nOpcion1:Caja\nOpcion2:Produccion\nOpcion3:Cocina\nOpcion4:Cafeteria\nNumero a ingresar: ",
											"Error, sector invalido.",&bufferEmployee.sector,3,4,1)==0)
								{
									pArray[indiceModificar].sector=bufferEmployee.sector;
								}
								break;
					}
					retorno=0;
				}
			}
		}

	}
	if(flagId==1)
	{
		printf("No se encontro el ID que ingreso");
	}
	return retorno;
}
/*
 * brief Elimina los datos ingresados
 * param Employee* pArray puntero al array de empleados
 * param int len Cantidad de posiciones que tiene el array
 * return (0)Si se puedo eliminar los datos (-1)Si no se pudo borrar los datos correctamente
 */
int employee_unsubscribe(Employee* pArray,int limite)
{
	int retorno=-1;
	int i;
	int buscarId;
	int indiceBorrar;
	if(employee_imprimir(pArray,limite)==0)
	{
		if(getInt("-*Ingrese el ID para modificar los datos","Error, no es un numero valido",&buscarId,3,1000,1)==0 &&
					pArray != NULL && limite>0 && buscarId >0)
				{
					if(employee_buscarIndicePorId(pArray,limite,buscarId,&indiceBorrar)==0)
					{
						if(pArray[indiceBorrar].isEmpty==FALSE)
						{
							pArray[i].isEmpty = TRUE;
							retorno=0;
							break;
					}
			}
		}
	}
	return retorno;
}
/*
 * brief Ordena los datos del array de forma ASCENDENTE o DESCENDENTE
 * param Employee* pArray puntero al array de empleados
 * param int len Cantidad de posiciones que tiene el array
 * param int order Numero ingresado por el usuario (1)ASCENDENTE (2)DESCENDENTE
 * return (0)Si se realizo el ordenamiento con exito (-1)Si no se ordeno correctamente el array
*/
int employee_sortEmployee(Employee* pArray, int len, int order)
{
	Employee bufferEmployee;
	int retorno=-1;
	int i;
	int flagOrder=1;

	if(pArray!=NULL && len>0 && (order>0 || order<5))
	{
		while(flagOrder==1)
		{
			flagOrder=0;
			for(i=0;i<len-1;i++)
			{
				if(order==1&& pArray[i].sector<pArray[i+1].sector)
				{
					bufferEmployee=pArray[i];
					pArray[i]=pArray[i+1];
					pArray[i+1]=bufferEmployee;
					flagOrder=1;
				}
				else if(pArray[i].sector==pArray[i+1].sector &&
						strncmp(pArray[i].lastName,pArray[i+1].lastName,LONG_NOMBRE)>0)
				{
					bufferEmployee=pArray[i];
					pArray[i]=pArray[i+1];
					pArray[i+1]=bufferEmployee;
					flagOrder=1;
				}
				if(order==2&& pArray[i].sector>pArray[i+1].sector)
					{
						bufferEmployee=pArray[i];
						pArray[i]=pArray[i+1];
						pArray[i+1]=bufferEmployee;
						flagOrder=1;
					}
					else if(pArray[i].sector==pArray[i+1].sector &&
							strncmp(pArray[i].lastName,pArray[i+1].lastName,LONG_NOMBRE)>0)
					{
						bufferEmployee=pArray[i];
						pArray[i]=pArray[i+1];
						pArray[i+1]=bufferEmployee;
						flagOrder=1;
					}

			}
			if(order==3)
			{
				break;
			}

		}
	}
	return retorno;
}
/*
 *  brief Imprime el array
 * param Employee* pArray puntero al array de empleados
 * param int len Cantidad de posiciones que tiene el array
 * return (0)Si se realiza la impresion con exito (-1)Si no se pudo imprimir correctamente
 */
int employee_imprimir(Employee* pArray, int len)
{
	int retorno = -1;
	if(pArray != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArray[i].isEmpty == FALSE)
			{
				printf("\nSECTOR	-	APELLIDO	-	NOMBRE	-	SALARIO		-	ID	");
				printf("\n%d               %s                 %s         $%.2f              %d",pArray[i].sector,pArray[i].lastName,pArray[i].name,pArray[i].salary,pArray[i].id);

			}
		}
		retorno = 0;
	}
	return retorno;
}
/*
 * brief Acumula salarios ingresados por el usuario
 * param Employee* pArray puntero al array de empleados
 * param int len Cantidad de posiciones que tiene el array
 * param float* pResultado Direccion de memoria de la variable donde escribe el numero acumulado
 * return (0)Si pudo acumular todos los salarios (-1)Si no se realizo con exito la acumulacion de salarios
 */
int employee_salary(Employee* pArray,int len,float* pResultado)
{
	int retorno=-1;
	int i;
	float acumulador=0;

	if(pArray!=NULL && len>0 && pResultado!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].isEmpty==FALSE)
			{
				acumulador = acumulador + pArray[i].salary;
				retorno=0;
			}
		}
	}
	*pResultado=acumulador;
	return retorno;
}
/*
 * brief Cuenta los ID ingresados hay
 * param Employee* pArray puntero al array de empleados
 * param int len Cantidad de posiciones que tiene el array
 * param int`cantidadId Direccion de memoria de la variable donde se escribe el el total de ID encontrados
 * return (0) si encontro 1 o mas ID (-1) si no encontro ningun ID
 */
int employee_contarId(Employee* pArray,int len,int* cantidadId)
{
	int retorno=-1;
	int contadorId=0;
	int i;

	if(pArray!=NULL && len>0 && cantidadId!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].isEmpty==FALSE && pArray[i].id>0)
			{
				contadorId++;
				retorno=0;
			}
		}
	}
	*cantidadId = contadorId;
	return retorno;
}
/*
 * brief Calcula el promedio del total de salarios divido la cantidad de ID encontrados
 * param float salario Total de salarios acumulados
 * param int cantidadId Total de ID contados
 * float* pResultado Direccion de memoria de la variable donde se escribe el promedio
 * return (0)Si el promedio se pudo realizar (-1) Si no se realizo con exito el
 */
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
/* brief Cuenta los salarios que superan el promedio
 * param Employee* pArray puntero al array de empleados
 * param int len Cantidad de posiciones que tiene el array
 * param float promedio Promedio de salarios
 * param int* pResultado Direccion de memoria de la variable donde se escribe el total de salarios mayores al promedio
 * return (0)Si se pudo realizar el calculo (-1)Si no se realizo con exito
 */
int employee_higherSalary(Employee* pArray,int len,float promedio, int* pResultado)
{
	int retorno=-1;
	int i;
	int contadorSalariosAltos=0;

	if(pArray!=NULL && len>0 && promedio>0 && pResultado!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].isEmpty==FALSE && pArray[i].salary > promedio)
			{
				contadorSalariosAltos++;
				retorno=0;
			}
		}
	}
	*pResultado=contadorSalariosAltos;
	return retorno;
}
/*
 *  * brief Imprime el salario total acumulado,el promedio,y la cantidad de salarios mayores al promedio
 * param Employee* pArray puntero al array de empleados
 * param int len Cantidad de posiciones que tiene el array
 * return(0) si pudo imprimir con extito (-1) si hubo un error con la impresion
 */
int employee_promedioTotal(Employee* pArray,int len)
{
	int retorno=-1;
	float salarioTotal;
	int empleadosTotal;
	float promedioTotal;
	int salarioMayorPromedio;

	if(employee_salary(pArray,len,&salarioTotal)==0 &&
		employee_contarId(pArray,len,&empleadosTotal)==0)
	{
		employee_promedio(salarioTotal,empleadosTotal,&promedioTotal);
		retorno=0;
	}
	printf("\n-*El salario total de los empleados ingresados es: $%.2f\n"
			"-*El salario promedio es: $%.2f",salarioTotal ,promedioTotal);
	if(employee_higherSalary(pArray,len,promedioTotal,&salarioMayorPromedio)==0)
	{
		printf("\n-*La cantidad de empleados que su salario supera el promedio es de: %d",salarioMayorPromedio);
	}
	else
	{
		printf("\nEl salario de ningun empleado supera al promedio");
	}


	return retorno;
}
