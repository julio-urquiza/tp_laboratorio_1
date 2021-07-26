#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "options.h"


#define TAM 1000

int menu(void);

int main()
{
    int seguir=1;
    Employee empleados[TAM];
    /*
    Employee empleados[TAM]=
    {
        {200,"julio","urquiza",15000,23,0},
        {201,"coco","ramirez",12000,56,0},
        {202,"milo","perez",13000,23,0},
        {203,"matias","tomson",17000,56,0},
        {204,"ernesto","simpsons",20000,23,0},
        {205,"juan","davila",16000,56,0},
        {206,"ivan","estevez",11000,23,0},
        {207,"lola","messi",12000,56,0}
    };
    */

    initEmployees(empleados,TAM);

    do{
        switch(menu())
        {
        case 1:
            //altas
            system("cls");
            darDeAltaEmpleado(empleados,TAM);
            break;
        case 2:
            //modificaciones
            system("cls");
            modificarEmpleado(empleados,TAM);
            break;
        case 3:
            //bajas
            system("cls");
            darDeBajaEmpleado(empleados,TAM);
            break;
        case 4:
            //informar
            system("cls");
            informar(empleados,TAM);
            break;
        case 5:
            //salir
            system("cls");
            printf("Esta saliendo del programa\n");
            seguir=0;
            break;

        }

    }while(seguir);
    return 0;
}

