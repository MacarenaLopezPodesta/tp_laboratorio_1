#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menu.h"
/****************************************************
 *
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
    int option=0;
    setbuf(stdout,NULL);
    LinkedList* listaEmpleados = ll_newLinkedList();

    controller_CargaUltimoId("UltimoId.txt");
    char UltimoId[20];
    controller_leerUltimoId("UltimoId.txt",UltimoId);
    printf("%s\n",UltimoId);

    do{
    	option=Menu();
	    while(option<1 && option>10)
	    {
	    	option=Menu();
	    }
        switch(option)
        {
            case 1:
            	controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
            	controller_loadFromBinary("data.bin",listaEmpleados);
				break;
            case 3:
            	controller_addEmployee(listaEmpleados,UltimoId);
            	//printf("%s\n",UltimoId);
            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8:
            	controller_saveAsText("data.csv",listaEmpleados);
            	break;
            case 9:
            	controller_saveAsBinary("data.bin",listaEmpleados);
            	break;
            case 10:
            	printf("ACABA DE SALIR DEL PROGRAMA\n");
        }
    }while(option != 10);
    return 0;
}

