/*
 ============================================================================
 MACARENA LOPEZ PODESTA
 1�C
 TP2
 (HECHO EN ECLIPSE WINDOWS)
 1 Enunciado
Una empresa requiere un sistema para administrar su n�mina de empleados. Se sabe que
dicha n�mina bajo ninguna circunstancia superara los 1000 empleados.
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

El sistema deber� tener el siguiente men� de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero
de Id. El resto de los campos se le pedir� al usuario.
2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
4. INFORMAR:

1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de alg�n empleado.

Para la realizaci�n de este programa, se utilizar� una biblioteca llamada �ArrayEmployees� que
facilitar� el manejo de la lista de empleados y su modificaci�n. En la secci�n siguiente se
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
