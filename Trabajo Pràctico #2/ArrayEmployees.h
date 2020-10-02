/*******************************************************************
*Programa:Trabajo Practico N�2
*Division:1F
*Fecha:02/10/2020
*Autor:Julio Cesar Urquiza
*
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length);


void hardcodearEmpleados(Employee emp[],int len);
void ingresarDatos(Employee list[],int len,int* id,char nombre[],char apellido[],float* salario,int* sector);
void pedirOpcionSiONo(char*);
int comprobarSiHayEmpleados(Employee emp[],int elementos);
int ordenarArrayEmpleadosNombre(Employee pEmpleados[],int elementos,int order);
int ordenarArrayEmpleadosSector(Employee pEmpleados[],int elementos,int order);
void informarSobreSalarioEmpleados(Employee pEmpleados[],int elementos);
