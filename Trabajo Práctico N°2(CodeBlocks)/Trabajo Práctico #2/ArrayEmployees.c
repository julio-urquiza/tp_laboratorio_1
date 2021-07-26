#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int findEmployeeFree(Employee* list,int len)
{
    int retorno=-1;
    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int initEmployees(Employee* list, int len)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0)
    {
        retorno=0;
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=1;
        }
    }
        return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int retorno=-1;
    int i;
    Employee auxEmployee;
    if(list!=NULL && len>0)
    {
        i=findEmployeeFree(list,len);
        if(i!=-1)
        {
            auxEmployee.id=id;
            strncpy(auxEmployee.name,name,sizeof(auxEmployee.name));
            strncpy(auxEmployee.lastName,lastName,sizeof(auxEmployee.lastName));
            auxEmployee.salary=salary;
            auxEmployee.sector=sector;
            auxEmployee.isEmpty=0;
            list[i]=auxEmployee;
            retorno=0;
        }
    }
    return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int posicion=-1;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].id==id && !list[i].isEmpty)
        {
            posicion=i;
            break;
        }
    }
    return posicion;
}

int removeEmployee(Employee* list, int len, int id)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0 && id>0)
    {
        i=findEmployeeById(list,len,id);
        if (list[i].isEmpty)
        {
            printf("no hay ningun empleado ingresado con ese ID\n");
        }
        else
        {
            list[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
    int retorno=-1;
    Employee auxEmployee;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                //alfaveticamente por apellido y por sector
                if (( order && (list[i].sector>list[j].sector ||(list[i].sector==list[j].sector && strcmp(list[i].lastName,list[j].lastName)>0))) ||
                   (!order && (list[i].sector<list[j].sector ||(list[i].sector==list[j].sector && strcmp(list[i].lastName,list[j].lastName)<0))))
                {
                    auxEmployee=list[i];
                    list[i]=list[j];
                    list[j]=auxEmployee;
                }
            }
        }
    }
    return retorno;
}

int printEmployees(Employee* list, int len)
{
    int retorno=-1;
    if(list!=NULL && len>0)
    {
        printf("Lista de empleados\n");
        printf("%3s %-11s %-11s %10s %8s \n","ID","Nombre","Apellido","Salario","Sector");
        for (int i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
                printf("%3d %-11s %-11s %10.2f %8d \n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
                retorno=0;
            }
        }
        printf("\n");
    }
    return retorno;
}

