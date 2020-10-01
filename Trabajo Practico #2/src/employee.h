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

int employee_menu();
int employee_initArray(Employee* arrayEmployee, int len);
int employee_data(Employee* arrayEmployee,int len);
int employee_alta(Employee* arrayEmployee,int len ,int indice,char* name,char* lastName,int sector,float salary,int id);
int employee_espacioLibre(Employee* arrayEmployee, int len, int* pResultado);
int employee_modify(Employee* arrayEmployee,int limite);
int employee_unsubscribe(Employee* arrayEmployee,int limite);
int employee_sortEmployee(Employee* arrayEmployee, int len,int order);
int employee_imprimir(Employee* arrayEmployee, int len);
int employee_promedioTotal(Employee* arrayEmployee,int len);
int employee_higherSalary(Employee* arrayEmployee,int len,float promedio, int* pResultado);
int employee_promedio(float salario,int cantidadId,float* pResultado);
int employee_contarId(Employee* arrayEmployee,int len,int* cantidadId);
int employee_salary(Employee* arrayEmployee,int len,float* pResultado);




#endif /* EMPLOYEE_H_ */
