/*******************************************************************
*Programa:Trabajo Practico Nº1
*Division:1F
*Fecha:12/09/2020
*Autor:Julio Cesar Urquiza
*
********************************************************************/

#include "Aritmèticas.h"
int sumar(int numero1,int numero2)
{
    int resultado;
    resultado=numero1+numero2;
    return resultado;
}

int restar(int numero1,int numero2)
{
    int resultado;
    resultado=numero1-numero2;
    return resultado;
}

int multiplicar(int numero1,int numero2)
{
    int resultado;
    resultado=numero1*numero2;
    return resultado;
}

float dividir(float* variable,float numero1,float numero2)
{
    int retono;
    float resultado;
    retono=0;
    if (numero2!=0)
    {
    resultado=(float)numero1/numero2;
    retono=1;
    }
    *variable=resultado;
    return retono;
}

int calcularFactorial(int numero)
{
    int resultado;

    if (numero == 0)
    {
        resultado=1;
    }
    else
    {
        resultado = numero * calcularFactorial(numero-1);
    }
    return resultado;
}

int pedirNumero(int* variable,char* mensaje)
{
    int retorno;
    retorno=0;
    if(variable!=NULL && mensaje!=NULL)
    {
        int bufferInt;
        printf("%s",mensaje);
        scanf("%i",&bufferInt);
        *variable=bufferInt;
        retorno=1;
    }
    return retorno;
}

