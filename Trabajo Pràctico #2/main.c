/*******************************************************************
*Programa:Trabajo Practico Nº2
*
*Objetivo:

1. Enunciado
Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
Datos:
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

*Division:1F
*Fecha:02/10/2020
*Autor:Julio Cesar Urquiza
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define T 4


int main()
{
    Employee empleados[T];
    Employee empAux;
    int id;
    int orden;
    int posicion;
    int selector;
    int opcionSwich;
    char opcion[51];

    initEmployees(empleados,T);
    /*hardcodearEmpleados(empleados,T);
    posicion=comprobarSiHayEmpleados(empleados,T);
    printf("%i",posicion);*/


    printf("Bienvenido");
    do{
        printf("\nQue desea hacer: ");
        printf("\n1.Para ingresar empleados");
        printf("\n2.Para modificar empleados");
        printf("\n3.Para eliminar empleados");
        printf("\n4.Para imprimir la lista de empleados ordenados");
        printf("\n5.Para Salir\n");
        pedirNumero(&opcionSwich,"\nIngrese un numero: ","ERROR,ingrese un entre 1 y 5: ",5,1);
        switch(opcionSwich)
        {
            case 1:
                do{
                    //hardcodearEmpleados(empleados,T);
                    ingresarDatos(empleados,T,&empAux.id,empAux.name,empAux.lastName,&empAux.salary,&empAux.sector);
                    addEmployee(empleados,T,empAux.id,empAux.name,empAux.lastName,empAux.salary,empAux.sector);
                    printEmployees(empleados,T);
                    pedirOpcionSiONo(opcion);
                }while(strcmp(opcion,"no")==0);
                break;
            case 2:
                do{
                    if(comprobarSiHayEmpleados(empleados,T)==1)
                    {
                        pedirNumero(&id,"Indique el id del empleado que deasea modificicar: ","ERROR, ID invalida.\n",1000,0);
                        posicion=findEmployeeById(empleados,T,id);
                        if(empleados[posicion].isEmpty==0)
                        {
                            printf("1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n");
                            pedirNumero(&selector,"Ingrese una opcion(1 a 4): ","ERROR, opcion incorrecta.\n",4,1);
                            switch(selector)
                            {
                                case 1:
                                    pedirTexto(empleados[posicion].name,"Ingrese el nuevo nombre: ","ERROR, dato incorrecto.\n");
                                    break;
                                case 2:
                                    pedirTexto(empleados[posicion].lastName,"Ingrese el nuevo apellido: ","ERROR, dato incorrecto.\n");
                                    break;
                                case 3:
                                    pedirNumeroComa(&empleados[posicion].salary,"Ingrese el nuevo salario: ","ERROR, dato incorrecto.\n",500000,0);
                                    break;
                                case 4:
                                    pedirNumero(&empleados[posicion].sector,"Ingrese el nuevo sector: ","ERROR, dato incorrecto.\n",500000,0);
                                    break;
                            }
                        }
                        else
                        {
                            printf("\nEste empleado no fue cargado aun\n");
                        }
                        pedirOpcionSiONo(opcion);
                    }
                    else
                    {
                        printf("\nLo sentimos,no hay empleados que modificar\n");
                        break;
                    }
                }while(strcmp(opcion,"no")==0);
                break;
            case 3:
                do{
                    if(comprobarSiHayEmpleados(empleados,T)==1)
                    {
                        pedirNumero(&id,"Indique el id del empleado que desea eliminar: ","ERROR, ID invalida.\n",1000,0);
                        posicion=findEmployeeById(empleados,T,id);
                        if(empleados[posicion].isEmpty==0)
                        {
                            removeEmployee(empleados,T,id);
                            printf("\nEmpleado elimanado con exito.\n");
                            printEmployees(empleados,T);
                        }
                        else
                        {
                            printf("\nEste empleado no fue cargado aun\n");
                        }
                        pedirOpcionSiONo(opcion);
                    }
                    else
                    {
                        printf("\nLo sentimos,no hay empleados que eliminar\n");
                        break;
                    }
                }while(strcmp(opcion,"no")==0);
                break;
            case 4:
                do{
                    if(comprobarSiHayEmpleados(empleados,T)==1)
                    {
                        printf("\n1.Para orden descendente de mayor a menor.");
                        printf("\n0.Para orden descendente de menor a mayor.");
                        pedirNumero(&orden,"\nIngrese una opcion(1 o 0): ","ERROR\n",1,0);
                        sortEmployees(empleados,T,orden);
                        printf("\n");
                        informarSobreSalarioEmpleados(empleados,T);

                        pedirOpcionSiONo(opcion);
                    }
                    else
                    {
                        printf("\nLo sentimos,no hay empleados que mostrar\n");
                        break;
                    }
                }while(strcmp(opcion,"no")==0);
                break;
            case 5:
                printf("\nUsted esta saliendo.Gracias por su tiempo\n");
                break;
        }
    }while(opcionSwich!=5);
    return 0;
}
