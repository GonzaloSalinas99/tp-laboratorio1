#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define TRUE 1
#define FALSE 0
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
void employee_borrar(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_printEmployee(LinkedList* pArrayListEmployee, int index);
int employee_generarId(LinkedList* this);
int employee_buscarIndicePorId(LinkedList* this, int idABuscar,int* index);
int employee_ordenarPorNombre (void* thisA, void* thisB);
int employee_ordenarPorId(void* thisA,void* thisB);
int employee_ordenarPorSueldo(void* thisA,void* thisB);
int employee_ordenarPorHorasTrabajadas(void* thisA,void* thisB);


void employee_menuOrdenado();


#endif // employee_H_INCLUDED
