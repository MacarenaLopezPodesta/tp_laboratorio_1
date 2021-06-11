#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	  FILE* pUltimoId;
	  int error = 0;
	  char id[20];
	  char nombre[20];
	  char horasTrabajadas[20];
	  char sueldo[20];
	  Employee* pEmpleado;

	  fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
	  if(pFile!=NULL && pArrayListEmployee!=NULL)
	  {
		  ll_clear(pArrayListEmployee);
		  while(!feof(pFile))
		  {
			   fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
			   pEmpleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
		       if(pEmpleado!=NULL)
		       {
				 ll_add(pArrayListEmployee,pEmpleado);
				 error=1;
		       }
		  }
	  }
	  pUltimoId=fopen("UltimoId.txt","w");
	  fprintf(pUltimoId,"%s",id);
	  fclose(pUltimoId);
	  return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int error= 0;
	FILE* pUltimoId;
	int id;
	int horasTrabajadas;
	int sueldo;
	Employee* empleado;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		ll_clear(pArrayListEmployee);
		while (!feof(pFile))
		{
			empleado = employee_new();
			fread(empleado, sizeof(Employee), 1, pFile);

			employee_getId(empleado, &id);
			employee_getHorasTrabajadas(empleado, &horasTrabajadas);
			employee_getSueldo(empleado, &sueldo);

			if (id != 0 && horasTrabajadas != 0 && sueldo != 0)
			{
				if ((pUltimoId = fopen("UltimoId.txt", "w")) != NULL)
				{
					fprintf(pUltimoId, "%d", id);
					fclose(pUltimoId);
				}
				ll_add(pArrayListEmployee, empleado);
			}
		}
		error = 1;
	}
	else printf("Error...\n");
	return error;
}
