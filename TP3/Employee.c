#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"

/**
 * @fn Employee* employee_new()
 * @brief Crea el espacio para un empleado
 *
 * @return Employee
 */
Employee* employee_new()
{
	Employee* empleado=(Employee*)malloc(sizeof(Employee));
	return empleado;
}
/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief Guarda los parametros dentro del empleado
 *
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @param sueldoStr
 * @return empleado
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* empleado = employee_new();
	if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		employee_setId(empleado,atoi(idStr));
		employee_setHorasTrabajadas(empleado,atoi(horasTrabajadasStr));
		employee_setNombre(empleado,nombreStr);
		employee_setSueldo(empleado,atoi(sueldoStr));
	}
	return empleado;
}
/**
 * @fn int employee_setId(Employee*, int)
 * @brief Establece el id
 *
 * @param this
 * @param id
 * @return int
 */
int employee_setId(Employee* this,int id)
{
	int error=0;
	if(this!=NULL)
	{
		this->id = id;
		error=1;
	}
	return error;
}
/**
 * @fn int employee_getId(Employee*, int*)
 * @brief Obtiene el id
 *
 * @param this
 * @param id
 * @return int
 */
int employee_getId(Employee* this,int* id)
{
	int error=0;
	if(this!=NULL)
	  {
		*id = this->id;
		 error=1;
	  }
	return error;
}
/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief Obtiene el nombre
 *
 * @param this
 * @param nombre
 * @return int
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int error = 0;
	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		error = 1;
	}
	return error;
}
/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief  Obtiene las horas trabajadas
 *
 * @param this
 * @param horasTrabajadas
 * @return int
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int error = 0;
	if (this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		error = 1;
	}
	return error;
}
/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief Obtiene el sueldo
 *
 * @param this
 * @param sueldo
 * @return int
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int error = 0;
	if (this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		error = 1;
	}
	return error;
}
/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief  Establece las horas trabajadas
 *
 * @param this
 * @param horasTrabajadas
 * @return int
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int error=0;
	if(this!=NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		error=1;
	}
	return error;
}
/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief Establece las horas trabajadas
 *
 * @param this
 * @param nombre
 * @return int
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int error=0;
	if(this!=NULL)
	{
		strcpy(this->nombre,nombre);
		error=1;
	}
	return error;
}
/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief Establece el sueldo
 *
 * @param this
 * @param sueldo
 * @return int
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int error=0;
	if(this!=NULL)
	{
		this->sueldo = sueldo;
		error=1;
	}
	return error;
}
