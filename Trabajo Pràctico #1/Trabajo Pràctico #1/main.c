#include <stdio.h>
#include <stdlib.h>
#include "Aritmèticas.h"

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
