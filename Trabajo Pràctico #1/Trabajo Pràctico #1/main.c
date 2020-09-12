/*******************************************************************
*Programa:Trabajo Practico N�1
*
*Objetivo:
Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) �El resultado de A+B es: r�
b) �El resultado de A-B es: r�
c) �El resultado de A/B es: r� o �No es posible dividir por cero�
d) �El resultado de A*B es: r�
e) �El factorial de A es: r1 y El factorial de B es: r2�
5. Salir
� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
(donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)
� Deber�n contemplarse los casos de error (divisi�n por cero, etc)
� Documentar todas las funciones

*Division:1F
*Fecha:12/09/2020
*Autor:Julio Cesar Urquiza
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Aritm�ticas.h"

int main()

{
    int primerNumero;
    int retornoPriNumero;
    int segundoNumero;
    int retornoSegNumero;
    int opcion;
    int suma;
    int resta;
    int retornoDivision;
    float division;
    int multiplicaion;
    int factorialR1;
    int factorialR2;
    int i;

    i=0;

    do
    {
        printf("\n1.Ingresar 1er operando ");
        if (retornoPriNumero==1)
        {
            printf("(A=%i)\n",primerNumero);
        }
        else
        {
            printf("(A=x)\n");
        }
        printf("2.Ingresar 2do operando ");
        if (retornoSegNumero==1)
        {
            printf("(b=%i)\n",segundoNumero);
        }
        else
        {
            printf("(B=y)\n");
        }
        printf("3.Calcular todas las operaciones\n");
        printf("4.Informar resultados\n");
        printf("5.Salir\n");
        pedirNumero(&opcion,"Elija una opcion: ");



        switch(opcion)
        {
            case 1:
                retornoPriNumero=pedirNumero(&primerNumero,"Ingrese el primer numero:");
                break;


            case 2:
                retornoSegNumero=pedirNumero(&segundoNumero,"Ingrese el segundo numero:");
                break;


            case 3:
                if(retornoPriNumero==1 && retornoSegNumero==1)
                {
                    printf("\nOperaciones calculadas\n");
                    suma=sumar(primerNumero,segundoNumero);
                    resta=restar(primerNumero,segundoNumero);
                    retornoDivision=dividir(&division,primerNumero,segundoNumero);
                    multiplicaion=multiplicar(primerNumero,segundoNumero);
                    factorialR1=calcularFactorial(primerNumero);
                    factorialR2=calcularFactorial(segundoNumero);
                    i=1;
                    break;
                }
                else
                {
                    printf("Primero deves ingresar ambos valores\n");
                    break;
                }

            case 4:
                if(i==1)
                {
                    printf("\nMostrando resultados");
                    printf("\na.El resultado de A + B es :%i",suma);
                    printf("\nb.El resultado de A - B es :%i",resta);
                    if(retornoDivision==1)
                    {
                        printf("\nc.El resultado de A / B es :%.2f",division);
                    }
                    else
                    {
                        printf("\nc.No es posible dividir por cero");
                    }
                    printf("\nd.El resultado de A * B es: %i",multiplicaion);
                    printf("\ne.el factorial de A es %i y el de B es %i\n",factorialR1,factorialR2);
                    break;
                }
                else
                {
                    printf("Deves haber calculado los resultados para mostrarlos\n");
                    break;
                }


            case 5:
                printf("\nEsta saliendo.");
                break;


            default:
                printf("\nEsta no es una opcion valida\n");
                break;

        }
    }while(opcion!=5);

    return 0;
}
