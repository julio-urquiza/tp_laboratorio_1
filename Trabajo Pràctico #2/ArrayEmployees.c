/*******************************************************************
*Programa:Trabajo Practico Nº2
*Division:1F
*Fecha:02/10/2020
*Autor:Julio Cesar Urquiza
*
********************************************************************/
#include "ArrayEmployees.h"

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
    if(list!=NULL && len>0)
    {
        retorno=0;
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==1)
            {
                list[i].id=id;
                strncpy(list[i].name,name,sizeof(list[i].name));
                strncpy(list[i].lastName,lastName,sizeof(list[i].lastName));
                list[i].salary=salary;
                list[i].sector=sector;
                list[i].isEmpty=0;
                break;
            }
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
        if(list[i].id==id)
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
    i=findEmployeeById(list,len,id);
    if(list!=NULL && len>0 && id>0)
    {
        if (list[i].isEmpty==1)
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
    if(list!=NULL && len>0)
    {
        printf("\nOrdenados por Sector");
        ordenarArrayEmpleadosSector(list,len,order);
        printEmployees(list,len);
        printf("\n");
        printf("\nOrdenados por Nombre");
        ordenarArrayEmpleadosNombre(list,len,order);
        printEmployees(list,len);
        retorno=0;
    }
    return retorno;
}

int printEmployees(Employee* list, int length)
{
    int retorno=-1;
    int i;
    if(list!=NULL && length>0)
    {
        retorno=0;
        printf("\n%3s %-11s %-11s %10s %8s \n","ID","Nombre","Apellido","Salario","Sector");
        for (i=0;i<length;i++)
        {
            if(list[i].isEmpty==0)
            {
                printf("%3i %-11s %-11s %10.2f %8i \n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
            }

        }
    }
    return retorno;
}



void hardcodearEmpleados(Employee emp[],int len)
{
    int i;
    int ides[4]={1,2,3,4};
    char nombres[4][15]={"carl","lenny","homero","moe"};
    char apellidos[4][15]={"carlson","leonard","simpson","szyslak"};
    float salarios[4]={100,200,300,400};
    int sectores[4]={10,20,30,40};
    int isEmpty[4]={0,0,0,0};

    for (i=0;i<len;i++)
    {
        emp[i].id=ides[i];
        strcpy(emp[i].name,nombres[i]);
        strcpy(emp[i].lastName,apellidos[i]);
        emp[i].salary=salarios[i];
        emp[i].sector=sectores[i];
        emp[i].isEmpty=isEmpty[i];
    }
}

void ingresarDatos(Employee list[],int len,int* id,char nombre[],char apellido[],float* salario,int* sector)
{
    float salarioLocal;
    int sectorLocal;
    int i;
    pedirTexto(nombre,"Ingrese el nombre: ","ERROR, dato incorrecto.\n");
    pedirTexto(apellido,"Ingrese el apellido: ","ERROR, dato incorrecto.\n");
    pedirNumeroComa(&salarioLocal,"Ingrese salario: ","ERROR, dato incorrecto.\n",500000,0);
    pedirNumero(&sectorLocal,"Ingrese sector: ","ERROR, dato incorrecto.\n",500000,0);
    *sector=sectorLocal;
    *salario=salarioLocal;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            *id=i+1;
            break;
        }
    }
}

void pedirOpcionSiONo(char* pOpcion)
{
    pedirTexto(pOpcion,"\ndesea volver al menu(si o no): ","Error ingrese un dato Valido");
    while(!(strcmp(pOpcion,"si")==0 || strcmp(pOpcion,"no")==0))
    {
        pedirTexto(pOpcion,"\nError ingrese si o no: ","Error ingrese un dato Valido");
    }
}

int comprobarSiHayEmpleados(Employee emp[],int elementos)
{
    int retorno=-1;
    int i;
    for(i=0;i<elementos;i++)
    {
        if(emp[i].isEmpty==0)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}

int ordenarArrayEmpleadosNombre(Employee pEmpleados[],int elementos,int order)
{
    Employee empleadosAuxiliares;
    int flagSwap;
    int i;
    int contador=0;
    int retorno=-1;
    int nuevoLimite;
    if(pEmpleados!=NULL && elementos>=0)
    {
        nuevoLimite=elementos-1;
        do{
            flagSwap=0;
            for(i=0;i<nuevoLimite;i++)
            {
                contador++;
                if (order==1)//Up mayor a menor
                {
                    if(strcmp(pEmpleados[i].name,pEmpleados[i+1].name)<0 && pEmpleados[i].isEmpty==0 && pEmpleados[i+1].isEmpty==0 )
                    {
                        flagSwap=1;
                        empleadosAuxiliares=pEmpleados[i];
                        pEmpleados[i]=pEmpleados[i+1];
                        pEmpleados[i+1]=empleadosAuxiliares;
                    }
                }
                else //Down menor a mayor
                {
                    if(strcmp(pEmpleados[i].name,pEmpleados[i+1].name)>0 && pEmpleados[i].isEmpty==0 && pEmpleados[i+1].isEmpty==0)
                    {
                        flagSwap=1;
                        empleadosAuxiliares=pEmpleados[i];
                        pEmpleados[i]=pEmpleados[i+1];
                        pEmpleados[i+1]=empleadosAuxiliares;
                    }
                }
            }
            nuevoLimite--;
        }while(flagSwap);
        retorno=contador;
    }
    return retorno;
}

int ordenarArrayEmpleadosSector(Employee pEmpleados[],int elementos,int order)
{
    Employee empleadosAuxiliares;
    int flagSwap;
    int i;
    int contador=0;
    int retorno=-1;
    int nuevoLimite;
    if(pEmpleados!=NULL && elementos>=0)
    {
        nuevoLimite=elementos-1;
        do{
            flagSwap=0;
            for(i=0;i<nuevoLimite;i++)
            {
                contador++;
                 if (order==1)//Up¿? mayor a menor
                {
                    if(pEmpleados[i].sector<pEmpleados[i+1].sector && pEmpleados[i].isEmpty==0 && pEmpleados[i+1].isEmpty==0)
                    {
                        flagSwap=1;
                        empleadosAuxiliares=pEmpleados[i];
                        pEmpleados[i]=pEmpleados[i+1];
                        pEmpleados[i+1]=empleadosAuxiliares;
                    }
                }
                else//Down menor a mayor
                {
                    if(pEmpleados[i].sector>pEmpleados[i+1].sector && pEmpleados[i].isEmpty==0 && pEmpleados[i+1].isEmpty==0)
                    {
                        flagSwap=1;
                        empleadosAuxiliares=pEmpleados[i];
                        pEmpleados[i]=pEmpleados[i+1];
                        pEmpleados[i+1]=empleadosAuxiliares;
                    }
                }
            }
            nuevoLimite--;
        }while(flagSwap);
        retorno=contador;
    }
    return retorno;
}

void informarSobreSalarioEmpleados(Employee pEmpleados[],int elementos)
{

    float acumuladorSueldos=0;
    int contadorEmpleadoSuperanPromedio=0;
    int i;
    int contadorEmpleados=0;
    float promedioSueldos;
    for(i=0;i<elementos;i++)
    {
        if(pEmpleados[i].isEmpty==0)
        {
            acumuladorSueldos+=pEmpleados[i].salary;
            contadorEmpleados++;
        }
    }
    promedioSueldos=acumuladorSueldos/contadorEmpleados;

    for(i=0;i<elementos;i++)
    {
        if(pEmpleados[i].isEmpty==0 && promedioSueldos<pEmpleados[i].salary)
        {
            contadorEmpleadoSuperanPromedio++;
        }
    }
    printf("el promedio es %.2f y hay %i empleados que lo superan",promedioSueldos,contadorEmpleadoSuperanPromedio);
}


