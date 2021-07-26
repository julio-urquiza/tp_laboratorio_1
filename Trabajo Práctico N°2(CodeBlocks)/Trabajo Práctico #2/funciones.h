/*******************************************************************
*Division:1g
*Autor:Julio Cesar Urquiza
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>




/** \brief pide un int al usuario y comprueba que sea un numero entero que este entre los datos ingresados
 *
 * \param pResultado int* variable por referencia donde se almacenarà el numero
 * \param mensaje char* mensaje que verà el usuario, que le indicarà que hacer
 * \param mensajeError char* mensaje que verà el usuario en caso de equivocarse
 * \param maximo int valor màximo que puede ingresar el usuario
 * \param minimo int valor mìnimo que puede ingresar el usuario
 * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int pedirNumero(int* pResultado,char* mensaje,char* mensajeError,int maximo,int minimo);

/** \brief pide un int al usuario y comprueba que sea un numero entero
 *
 * \param pResultado int* variable por referencia donde se almacenarà el numero
 * \param mensaje char* mensaje que verà el usuario, que le indicarà que hacer
 * \param mensajeError char* mensaje que verà el usuario en caso de equivocarse
 * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int pedirNumeroSinLimite(int* pResultado,char* mensaje,char* mensajeError);

/** \brief pide un float al usuario y comprueba que sea un numero flotante que este entre los datos ingresados
 *
 * \param pResultado float* variable por referencia donde se almacenarà el numero
 * \param mensaje char* mensaje que verà el usuario, que le indicarà que hacer
 * \param mensajeError char* mensaje que verà el usuario en caso de equivocarse
 * \param maximo int valor màximo que puede ingresar el usuario
 * \param minimo int valor mìnimo que puede ingresar el usuario
 * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int pedirNumeroComa(float* pResultado,char* mensaje,char* mensajeError,int maximo,int minimo);

/** \brief pide un string al usuario y comprueba que sea una cadena de caracteres
 *
 * \param pResultado int* variable por referencia donde se almacenarà la cadena
 * \param mensaje char* mensaje que verà el usuario, que le indicarà que hacer
 * \param mensajeError char* mensaje que verà el usuario en caso de equivocarse
 * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int pedirTexto(char* pTexto,char* mensaje,char* mensajeError);

/** \brief pide un string al usuario y comprueba que sea una cadena ya sea de caracteres con numeros o solo una con letras
 *
 * \param pResultado int* variable por referencia donde se almacenarà la cadena
 * \param mensaje char* mensaje que verà el usuario, que le indicarà que hacer
 * \param mensajeError char* mensaje que verà el usuario en caso de equivocarse
 * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int pedirTextoConNumeros(char* pTexto,char* mensaje,char* mensajeError);



/** \brief realiza la suma de dos variables int
 *
 * \param pResultado int* variable por referencia donde se almacenarà el resultado de la operaciòn
 * \param numero1 int variable a operar
 * \param numero2 int variable a operar
 * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int mSumar(int* pResultado, int numero1,int numero2);

/** \brief realiza la resta de dos variables int
 *
 * \param pResultado int* variable por referencia donde se almacenarà el resultado de la operaciòn
 * \param numero1 int variable a operar
 * \param numero2 int variable a operar
 * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int mRestar(int* pResultado, int numero1,int numero2);

/** \brief realiza la multiplicaciòn de dos variables int
 *
 * \param pResultado int* variable por referencia donde se almacenarà el resultado de la operaciòn
 * \param numero1 int variable a operar
 * \param numero2 int variable a operar
 * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int mMultiplicar(int* pResultado, int numero1,int numero2);

/** \brief realiza la division de dos variables int
 *
 * \param pResultado int* variable por referencia donde se almacenarà el resultado de la operaciòn
 * \param numero1 int variable a operar
 * \param numero2 int variable a operar
 * \return int retorna -1 si no pudo completar la tarea(division por 0), en caso de que la complete regresa 1
 */
int mDividir(int* pResultado, int numero1,int numero2);

/** \brief realiza el factorial de una variable
 *
 * \param pResultado int* variable por referencia donde se almacenarà el resultado de la operaciòn
 * \param numero int variable a operar
 * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int mCalcularFactorial(int* pResultado, int numero);

/** \brief Calcula un numero aleatorio
 *
 * \param desde int mìnimo numero para el valor aleatorio
 * \param hasta int màximo numero para el valor aleatorio
 * \return int retorna el numero generado aleatoriamente
 */
int calcularNumeroAleatorio(int desde, int hasta);



/** \brief inicializa un array con una variable int
 *
 * \param arrays int* array que queramos inicializar
 * \param elementos int cantidad de elementos del array
 * \param valor int variable con la que queramos inicializar le array
 * \return void
 */
void inicializarArrayInt(int* arrays, int elementos, int valor);

/** \brief muestra una array de numeros enteros
 *
 * \param pArray int* array a ser mostrado
 * \param limite int cantidad de elementos del array
  * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int mostrarArrayInt(int* pArray,int limite);

/** \brief inicializa un array con una variable con una cadena de caracteres
 *
 * \param arrays int* array que queramos inicializar
 * \param elementos int cantidad de elementos del array
 * \param valor char[] variable con la que queramos inicializar le array
 * \return void
 */
void inicializarArrayString(char[][100],int,char[]);

/** \brief muestra una array de cadena de caracteres
 *
 * \param pArray char* array a ser mostrado
 * \param limite int cantidad de elementos del array
  * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int mostrarArrayString(char[][100],int);

/** \brief inicializa un array del tipo float con una variable float
 *
 * \param arrays float* array que queramos inicializar
 * \param elementos int cantidad de elementos del array
 * \param valor float variable con la que queramos inicializar le array
 * \return void
 */
void inicializarArrayFloat(float* arrays, int elementos, float valor);

/** \brief muestra una array del tipo float
 *
 * \param pArray float* array a ser mostrado
 * \param limite int cantidad de elementos del array
  * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int mostrarArrayFloat(float* pArray,int limite);


/** \brief busca la primera ocurrencia de cualquier valor en un array de enteros
 *
 * \param array[] int cadena de enteros a ser modificada
 * \param elementos int cantidad de elementos del vector
 * \param valor int variable a ser buscada
 * \return int retona -1
 */
int buscarPrimeraOcurrencia(int array[], int elementos, int valor);

/** \brief busca los nùmeros pares en una array de enteros
 *
 * \param int[] el vector a ser manipulado
 * \param int cantidad de elementos del array
 * \return retona 0
 */
int BuscarPares(int numeros[], int cantidad);


/** \brief busca el màximo en una array en enteros
 *
 * \param numeros[] int array a ser manipulado
 * \param cantidad int cantidad de elementos del array
 * \return int retorna el valor maximo
 */
int BuscarMaximos(int numeros[], int cantidad);

/** \brief cuenta la cantidad de apariciones del Màximo en el array
 *
 * \param int [] array de enteros a ser manipulado
 * \param int cantidad de elmentos del array
 * \return retorna la cantidad de apariciones
 *
 */
int ContadorMaximos (int numeros[], int cantidad);

/** \brief busca el mìnimo en una array en enteros
 *
 * \param numeros[] int array a ser manipulado
 * \param cantidad int cantidad de elementos del array
 * \return int retorna el valor mìnimo
 */
int BuscarMinimos(int numeros[], int cantidad);

/** \brief cuenta la cantidad de apariciones del mìnimo en el array
 *
 * \param int [] array de enteros a ser manipulado
 * \param int cantidad de elmentos del array
 * \return retorna la cantidad de apariciones
 *
 */
int ContadorMinimos(int numeros[], int cantidad);


/** \brief metodo de burbujeo, ordena una array de enteros del Màximo al mìnimo
 *
 * \param int [] array de enteros a ser manipulado
 * \param int cantidad de elmentos del array
 * \return int retorna la cantidad de veces que se ejecuto para ver su rendimiento
 *
 */
int ordenarArrayIntMaxMin(int* pArray,int limite);

/** \brief metodo de burbujeo, ordena una array de enteros del mìnimo al Màximo
 *
 * \param int [] array de enteros a ser manipulado
 * \param int cantidad de elmentos del array
 * \return int retorna la cantidad de veces que se ejecuto para ver su rendimiento
 *
 */
int ordenarArrayIntMinMax(int* pArray,int limite);

/** \brief metodo de burbujeo, ordena una array de cadena de caracters del Màximo al mìnimo
 *
 * \param char[][100] array de dos dimensiones, array de caracteres a ser manipulado
 * \param int cantidad de elmentos del array
 * \return int retorna la cantidad de veces que se ejecuto para ver su rendimiento

 */
int ordenarArrayString(char[][100],int );



/** \brief quita el salto de linea a una cadena de caracteres
 *
 * \param cadena[] la cadena de caracteres a ser manipulada
 * \return char retorna la cadena ya modificada
 */
char QuitarSaltoLinea(char cadena[]);

/** \brief asigna una mayuscula al primer caracter de una cadena
 *
* \param cadena[] la cadena de caracteres a ser manipulada
 * \return void
 */
void InicialesEnMayus(char cadena[]);





//#include <string.h>
//Algunas de las funciones más importantes son:
//strlen(<cadena>): Devuelve la longitud de la cadena sin tomar en cuenta el caracter de final de cadena.
//strcpy(<cadena_destino>, <cadena_origen>) : Copia el contenido de <cadena_origen> en <cadena_destino>.
//strcat(<cadena_destino>, <cadena_origen>) : Concatena el contenido de <cadena_origen> al final de <cadena_destino>.
//strcmp(<cadena1>, <cadena2>) :Compara las dos cadenas y devuelve un 0 si las dos cadenas son iguales,
//un número negativo si <cadena1> es menor que (precede alfabéticamente a) <cadena2> y un número positivo (mayor que cero) si <cadena1> es mayor que <cadena2>.

