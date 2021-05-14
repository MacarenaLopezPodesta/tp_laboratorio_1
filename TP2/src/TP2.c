/*
 ============================================================================
 MACARENA LOPEZ PODESTA
 1°C
 TP2
 (HECHO EN ECLIPSE WINDOWS)
 1 Enunciado
Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
DATOS:
struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;

}typedef Employee;

El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:

1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.

Para la realización de este programa, se utilizará una biblioteca llamada “ArrayEmployees” que
facilitará el manejo de la lista de empleados y su modificación. En la sección siguiente se
detallan las funciones que esta biblioteca debe tener.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"

#define TamEmpleado 1000
int main(void)
{
   int opcion;
   int index;
   float salarioTotal;
   eEmployee ListadoEmpleado[TamEmpleado];
   setbuf(stdout, NULL);
   initEmployees(ListadoEmpleado,TamEmpleado);
   printf("BIENVENIDO. INGRESE UN NUMERO DEL MENU PARA CARGAR EMPLEADOS: \n");
   do
   {
	   printf("1. ALTA\n");
	   printf("2. BAJA\n");
	   printf("3. MODIFICAR\n");
	   printf("4. LISTADO\n");
	   printf("5. SALARIOS\n");
	   printf("6. SALIR\n");
	   scanf("%d", &opcion);
	   switch(opcion)
	   {
		   case 1:
		   CargaLibre(ListadoEmpleado,TamEmpleado);
		   addEmployee(ListadoEmpleado,TamEmpleado);
			  break;
	   	   case 2:
	   		index=findEmployeeById(ListadoEmpleado,TamEmpleado);
			if(index==-1)
			{
				printf("NO SE ENCONTRO EL ID INGRESADO\n");
			}
			else
			{
				printf("SE ENCONTRO EL ID INGRESADO\n");
				removeEmployee(ListadoEmpleado,index);
			}
	   		   break;
	   	   case 3:
	   		index=findEmployeeById(ListadoEmpleado,TamEmpleado);
			if(index==-1)
			{
				printf("NO SE ENCONTRO EL ID INGRESADO\n");
			}
			else
			{
				printf("SE ENCONTRO EL ID INGRESADO\n");
				ModificarEmpleado(ListadoEmpleado,index);
			}
	   		   break;
	   	   case 4:
	   		    sortEmployees(ListadoEmpleado,TamEmpleado);
	   		    printEmployees(ListadoEmpleado,TamEmpleado);
	   		   break;
	   	   case 5:
	   		salarioTotal=SalarioTotal(ListadoEmpleado,TamEmpleado);
	   		printf("Salario total: %.2f\n",salarioTotal);
	   		   break;
	   }

   }while(opcion != 6);
}
