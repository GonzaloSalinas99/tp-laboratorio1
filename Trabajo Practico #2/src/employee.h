/*
 * employee.h
 *
 *  Created on: 25 sept. 2020
 *      Author: Gonzalo
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_EMPLOYEE 1000
#define QTY_SECTOR 4

typedef struct
{
	char name[LONG_NOMBRE];
	char lastName [LONG_NOMBRE];
	float salary;
	int sector;
	int isEmpty;
	int id;
}Employee;

int employee_menu(int* pOpcion);
int employee_report(int* pOpcion);
int employee_initArray(Employee* pArray, int len);
int employee_data(Employee* pArray,int len);
int employee_alta(Employee* pArray,int len ,int indice,char* name,char* lastName,int sector,float salary,int id);
int employee_espacioLibre(Employee* pArray, int len, int* pResultado);
int employee_modify(Employee* pArray,int limite);
int employee_unsubscribe(Employee* pArray,int limite);
int employee_sortEmployee(Employee* pArray, int len,int order);
int employee_imprimir(Employee* pArray, int len);
int employee_promedioTotal(Employee* pArray,int len);
int employee_higherSalary(Employee* pArray,int len,float promedio, int* pResultado);
int employee_promedio(float salario,int cantidadId,float* pResultado);
int employee_contarId(Employee* pArray,int len,int* cantidadId);
int employee_salary(Employee* pArray,int len,float* pResultado);
int employee_buscarIndicePorId (Employee* pArray, int limite,int idBuscar,int * pIndice);




#endif /* EMPLOYEE_H_ */
