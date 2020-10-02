#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void hardcodearEmpleados(Employee emp[],int len);
void ingresarDatos(Employee list[],int len,int* id,char nombre[],char apellido[],float* salario,int* sector);
void pedirOpcionSiONo(char*);
int comprobarSiHayEmpleados(Employee emp[],int elementos);
int ordenarArrayEmpleadosNombre(Employee pEmpleados[],int elementos,int order);
int ordenarArrayEmpleadosSector(Employee pEmpleados[],int elementos,int order);
void informarSobreSalarioEmpleados(Employee pEmpleados[],int elementos);
