#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "options.h"
#include "funciones.h"
#include "ArrayEmployees.h"


//menu Switch

int darDeAltaEmpleado(Employee list[],int len)
{
    int retorno=0;
    if(list!=NULL && len>0)
    {
        Employee empAux;
        do{
            ingresarDatos(list,len,&empAux.id,empAux.name,empAux.lastName,&empAux.salary,&empAux.sector);
            addEmployee(list,len,empAux.id,empAux.name,empAux.lastName,empAux.salary,empAux.sector);
            printEmployees(list,len);
            retorno=1;
        }while(opcion());
    }
    return retorno;
}

int modificarEmpleado(Employee list[],int len)
{
    int id;
    int posicion;
    int selector;
    int retorno=0;
    if(list!=NULL && len>0)
    {
        do{
            system("cls");
            if(comprobarSiHayEmpleados(list,len)==1)
            {
                printEmployees(list,len);
                pedirNumero(&id,"Indique el id del empleado que deasea modificicar: ","ERROR, ID invalida.\n",1000,0);
                posicion=findEmployeeById(list,len,id);
                if(list[posicion].isEmpty==0)
                {
                    printf("1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n");
                    pedirNumero(&selector,"Ingrese una opcion(1 a 4): ","ERROR, opcion incorrecta.\n",4,1);
                    switch(selector)
                    {
                        case 1:
                            pedirTexto(list[posicion].name,"Ingrese el nuevo nombre: ","ERROR, dato incorrecto.\n");
                            break;
                        case 2:
                            pedirTexto(list[posicion].lastName,"Ingrese el nuevo apellido: ","ERROR, dato incorrecto.\n");
                            break;
                        case 3:
                            pedirNumeroComa(&list[posicion].salary,"Ingrese el nuevo salario: ","ERROR, dato incorrecto.\n",500000,0);
                            break;
                        case 4:
                            pedirNumero(&list[posicion].sector,"Ingrese el nuevo sector: ","ERROR, dato incorrecto.\n",500000,0);
                            break;
                    }
                    system("cls");
                    printEmployees(list,len);
                    retorno=1;
                }
                else
                {
                    printf("\nEste empleado no fue cargado aun\n");
                }
            }
            else
            {
                printf("\nLo sentimos,no hay empleados que modificar\n");
                system("pause");
                break;
            }
        }while(opcion());
    }
    return retorno;
}

int darDeBajaEmpleado(Employee list[],int len)
{
    int id;
    int posicion;
    int retorno=0;
    if(list!=NULL && len>0)
    {
        do{
            system("cls");
            if(comprobarSiHayEmpleados(list,len)==1)
            {
                printEmployees(list,len);
                pedirNumero(&id,"Indique el id del empleado que desea eliminar: ","ERROR, ID invalida.\n",1000,0);
                posicion=findEmployeeById(list,len,id);
                if(list[posicion].isEmpty==0)
                {
                    removeEmployee(list,len,id);
                    printf("\nEmpleado elimanado con exito.\n");
                    system("cls");
                    printEmployees(list,len);
                    retorno=1;
                }
                else
                {
                    printf("\nEste empleado no fue cargado aun\n");
                }
            }
            else
            {
                printf("\nLo sentimos,no hay empleados que eliminar\n");
                system("pause");
                break;
            }
        }while(opcion());
    }
    return retorno;
}

int informar(Employee list[],int len)
{
    int retorno=0;
    if(list!=NULL && len>0)
    {
        if(comprobarSiHayEmpleados(list,len)==1)
        {
            sortEmployees(list,len,1);
            printEmployees(list,len);
            printf("\n");
            informarSobreSalarioEmpleados(list,len);
            retorno=1;
        }
        else
        {
            printf("\nLo sentimos,no hay empleados que mostrar\n");
        }
    }
    system("pause");
    return retorno;
}


//funciones auxiliares

int menu(void)
{
    int opcion;
    system("cls");
    printf("1.Dar de alta un empleado\n");
    printf("2.Modificar un empleado\n");
    printf("3.Dar de baja un empleado\n");
    printf("4.Mostrar informes\n");
    printf("5.Salir\n");
    pedirNumero(&opcion,"ingrese un numero: ","ERROR, ingrese un numero valido: ",5,1);
    return opcion;
}

void ingresarDatos(Employee list[],int len,int* id,char nombre[],char apellido[],float* salario,int* sector)
{
    float salarioLocal;
    int sectorLocal;
    pedirTexto(nombre,"Ingrese el nombre: ","ERROR, dato incorrecto.\n");
    pedirTexto(apellido,"Ingrese el apellido: ","ERROR, dato incorrecto.\n");
    pedirNumeroComa(&salarioLocal,"Ingrese salario: ","ERROR, dato incorrecto.\n",500000,0);
    pedirNumero(&sectorLocal,"Ingrese sector: ","ERROR, dato incorrecto.\n",500000,0);
    *sector=sectorLocal;
    *salario=salarioLocal;
    *id=200+findEmployeeFree(list,len);
}

int opcion(void)
{
    int retorno;
    pedirNumero(&retorno,"Desea continuar(1.si 0.no): ","ERROR, dato incorrecto ingrese 1 o 0.\n",1,0);
    return retorno;
}

int comprobarSiHayEmpleados(Employee list[],int len)
{
    int retorno=-1;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}

void informarSobreSalarioEmpleados(Employee list[],int len)
{

    float acumuladorSueldos=0;
    int contadorEmpleadoSuperanPromedio=0;
    int i;
    int contadorEmpleados=0;
    float promedioSueldos;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            acumuladorSueldos+=list[i].salary;
            contadorEmpleados++;
        }
    }
    promedioSueldos=acumuladorSueldos/contadorEmpleados;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0 && promedioSueldos<list[i].salary)
        {
            contadorEmpleadoSuperanPromedio++;
        }
    }
    printf("El promedio es %.2f y hay %i empleados que lo superan\n",promedioSueldos,contadorEmpleadoSuperanPromedio);
}


