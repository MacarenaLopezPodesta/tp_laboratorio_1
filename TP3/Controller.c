#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "Validaciones.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int error = 0;
	FILE* pArchivo;
	pArchivo=fopen(path,"r");
	if(path!=NULL && pArrayListEmployee!=NULL && pArchivo!=NULL)
	{
		  if(parser_EmployeeFromText(pArchivo,pArrayListEmployee)==1)
		  {
			  printf("\nSe cargo correctamente\n");
			  error = 1;
		  }else
		  {
			  printf("\nArchivo vacio\n");
		  }
	}
	fclose(pArchivo);
    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int error=0;
	FILE* pArchivo;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		if((pArchivo = fopen(path,"rb")) != NULL)
		{
			parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
			error = 1;
			fclose(pArchivo);
			printf("\nSe cargo correctamente\n");
		}else
		{
			printf("\nArchivo vacio\n");
		}
	}
	return error;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	FILE* pUltimoId;
	Employee* empleado = employee_new();

	char id[50];
	char nombre[50];
	char horasTrabajadas[50];
	char salario[50];

	pUltimoId=fopen("UltimoId.txt","r");
	if(pUltimoId!=NULL)
	{
		fscanf(pUltimoId,"%s",id);
		fclose(pUltimoId);
	}

	printf("Ingrese nombre:\n");
	scanf("%s",nombre);
	printf("Ingrese las horas trabajadas:\n");
	scanf("%s",horasTrabajadas);
	printf("Ingrese salario:\n");
	scanf("%s",salario);

	sprintf(id, "%d",atoi(id)+1);
	empleado=employee_newParametros(id,nombre,horasTrabajadas,salario);
    ll_add(pArrayListEmployee, empleado);

    pUltimoId=fopen("UltimoId.txt","w");
	if(pUltimoId!=NULL)
	{
		fscanf(pUltimoId,"%s",id);
		fclose(pUltimoId);
	}

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int error = 1;
	Employee* EmpleadoAModificar;

	char nuevoNombre[20];
	int idParaModificar;
	int i;
	int nuevoSueldo;
	int nuevasHsTrabajadas;
	int opcion;
	int idEncontrado;
    int len=ll_len(pArrayListEmployee);

    idParaModificar=getIntNew("\nIngrese el id a modificar:\n","\nERROR.Ingrese el id a modificar:\n");
	if(pArrayListEmployee!=NULL)
	{
		for(i=0;i<len;i++)
		  {
			EmpleadoAModificar = (Employee*)ll_get(pArrayListEmployee,i);
		    employee_getId(EmpleadoAModificar,&idEncontrado);

			  if(idParaModificar == idEncontrado)
			  {
				  printf("Ingrese para modificar:\n1.Nombre\n2.Horas Trabajadas\n3.Salario");
				  opcion= getIntNew(" ","Error, ingrese un numero:\n");
				  switch(opcion)
				  {
					case 1:
					printf("Ingrese el nuevo nombre:\n");
					scanf("%s",nuevoNombre);
					employee_setNombre(EmpleadoAModificar,nuevoNombre);
					  break;
					case 2:
					printf("Ingrese nuevas horas trabajadas:\n");
					scanf("%d", &nuevasHsTrabajadas);
					employee_setHorasTrabajadas(EmpleadoAModificar,nuevasHsTrabajadas);
					  break;
					case 3:
					printf("Ingrese nuevo sueldo:\n");
					scanf("%d",&nuevoSueldo);
					employee_setSueldo(EmpleadoAModificar,nuevoSueldo);
					  break;
				  }
				  break;
				}
	   }

	}
	return error;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* EmpleadoAEliminar;
	int len=ll_len(pArrayListEmployee);
	int idEliminar;
	int idEncontrado;
	int eliminar;
	int error=1;
	idEliminar=getIntNew("\nIngrese el id a dar de baja:\n","\nERROR.Ingrese el id a dar de baja:\n");
	if(pArrayListEmployee!=NULL)
	{
		for(int i=0;i<len;i++)
		  {
			EmpleadoAEliminar = (Employee*)ll_get(pArrayListEmployee,i);
			employee_getId(EmpleadoAEliminar,&idEncontrado);
			if(idEliminar==idEncontrado)
			{
				eliminar=getIntNew("Ingrese 1 si quiere eliminar el empleado:\n","ERROR.Ingrese 1 si quiere eliminar el empleado:\n");
				if(eliminar==1)
				{
					ll_remove(pArrayListEmployee,i);
					printf("Se elimino el empleado\n");
					error=0;
				}
				break;
			}
		  }
	}
    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int error=1;
	int i;
	Employee* empleado;
	int len=ll_len(pArrayListEmployee);;
	if(pArrayListEmployee!=NULL)
	 {
		printf("\n%15s %20s %20s %15s\n","ID","NOMBRE","HORAS TRABAJADAS","SUELDO");
		for(i=0;i<len;i++)
	    {
			empleado = (Employee*)ll_get(pArrayListEmployee,i);
			printf("%15d %20s %20d %15d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
		    error=0;
	    }
	  }
	return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int error=1;
	int opcion;
	int len=ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && len>0)
	{
		opcion=getIntNew("Ingresa para ordenar por: \n 1.Nombre\n 2.Horas Trabajadas\n 3.Sueldo\n 4.Id\n","ERROR.Ingresa para ordenar por: \n 1.Nombre\n 2.Horas Trabajadas\n 3.Sueldo\n 4.Id\n");
		switch(opcion)
		{
		    case 1:
		    	ll_sort(pArrayListEmployee,OrdenamientoPorNombre,1);
			break;
		    case 2:
		    	ll_sort(pArrayListEmployee,OrdenamientoPorHsTrabajadas,1);
		    break;
		    case 3:
		    	ll_sort(pArrayListEmployee,OrdenamientoPorSueldo,1);
		    break;
		    case 4:
		    	ll_sort(pArrayListEmployee,OrdenamientoPorId,1);
		    break;
		}
	}
    return error;
}
/**
 * @fn int OrdenamientoPorNombre(void*, void*)
 * @brief
 *
 * @param empleadoI
 * @param empleadoJ
 * @return int
 */
int OrdenamientoPorNombre(void* empleadoI, void* empleadoJ)
{
   int valor=0;
   valor=strcmp(((Employee*)empleadoI)->nombre,((Employee*)empleadoJ)->nombre);
   return valor;
}

/**
 * @fn int OrdenamientoPorHsTrabajadas(void*, void*)
 * @brief
 *
 * @param empleadoI
 * @param empleadoJ
 * @return int
 */
int OrdenamientoPorHsTrabajadas(void* empleadoI, void* empleadoJ)
{
	int valor=0;

   if(((Employee*)empleadoI)->horasTrabajadas > ((Employee*)empleadoJ)->horasTrabajadas)
   {
	   valor=1;
   }else
   {
	  if(((Employee*)empleadoI)->horasTrabajadas < ((Employee*)empleadoJ)->horasTrabajadas)
	  {
		 valor=-1;
	  }else
	  {
		  valor=0;
	  }
   }
   return valor;
}
/**
 * @fn int OrdenamientoPorSueldo(void*, void*)
 * @brief
 *
 * @param empleadoI
 * @param empleadoJ
 * @return int
 */
int OrdenamientoPorSueldo(void* empleadoI, void* empleadoJ)
{
   int valor=0;

   if(((Employee*)empleadoI)->sueldo > ((Employee*)empleadoJ)->sueldo)
   {
   	   valor=1;
   }else
   {
   	  if(((Employee*)empleadoI)->sueldo < ((Employee*)empleadoJ)->sueldo)
   	  {
   	     valor=-1;
   	  }else
   	  {
   		  valor=0;
   	  }
   }
   return valor;
}
/**
 * @fn int OrdenamientoPorId(void*, void*)
 * @brief
 *
 * @param empleadoI
 * @param empleadoJ
 * @return int
 */
int OrdenamientoPorId(void* empleadoI, void* empleadoJ)
{
   int valor;

   if(((Employee*)empleadoI)->id > ((Employee*)empleadoJ)->id)
   {
	   valor=1;
   }else
   {
	  if(((Employee*)empleadoI)->id < ((Employee*)empleadoJ)->id)
	  {
	     valor=-1;
	  }else
	  {
		  valor=0;
	  }
   }
   return valor;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	FILE* pArchivo;
	int len;
	Employee* empleado;
	if (pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		if ((pArchivo = fopen(path, "w")) != NULL)
		{
			fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");
			for (i = 0; i < len; i++)
			{
				empleado = (Employee*)ll_get(pArrayListEmployee, i);
				fprintf(pArchivo, "%d,%s,%d,%d\n", empleado->id,
						                           empleado->nombre,
												   empleado->horasTrabajadas,
												   empleado->sueldo);
			}
			fclose(pArchivo);
		}
	}
	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	FILE* pArchivo;
	Employee* empleado;
	int len;

	if (pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		if ((pArchivo = fopen(path, "wb")) != NULL)
		{
			for (i=0;i<len;i++)
			{
				empleado=(Employee*)ll_get(pArrayListEmployee,i);
				fwrite(empleado, sizeof(Employee), 1, pArchivo);
			}
			fclose(pArchivo);
		}
	}
    return 1;
}

