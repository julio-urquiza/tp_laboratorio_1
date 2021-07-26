#include "ArrayEmployees.h"
#include "funciones.h"
#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

#endif // OPTIONS_H_INCLUDED

int darDeAltaEmpleado(Employee list[],int len);
int modificarEmpleado(Employee list[],int len);
int darDeBajaEmpleado(Employee list[],int len);
int informar(Employee list[],int len);

int menu(void);
int opcion(void);
void ingresarDatos(Employee list[],int len,int* id,char nombre[],char apellido[],float* salario,int* sector);
void informarSobreSalarioEmpleados(Employee list[],int len);
int comprobarSiHayEmpleados(Employee list[],int len);
