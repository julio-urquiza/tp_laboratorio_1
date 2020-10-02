/*******************************************************************
*Division:1F
*Autor:Julio Cesar Urquiza
********************************************************************/
#include "funciones.h"

///////////////////INGRESO Y VALIDACION DE DATOS///////////////////

static int pedirInt(int* pResultado);
static int pedirFloat(float* pResultado);
static int pedirString(char* pResultado);
static int pedirStringInt(char* pResultado);
static int myGets(char* cadena,int longitud);
static int esNumerica(char* cadena);
static int esAlfavetico(char* cadena);
static int esAlfaNumerico(char* cadena);
static int esNumeroConComa(char* cadena);


static int pedirInt(int* pResultado)
{
   int retorno=-1;
   char buffer[100];
   if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
   {
       retorno=0;
       *pResultado=atoi(buffer);
   }
   return retorno;
}

static int pedirFloat(float* pResultado)
{
   int retorno=-1;
   char buffer[100];
   if(myGets(buffer,sizeof(buffer))==0 && esNumeroConComa(buffer))
   {
       retorno=0;
       *pResultado=atof(buffer);
   }
   return retorno;
}

static int pedirString(char* pResultado)
{
   int retorno=-1;
   char buffer[1000];
   if(myGets(buffer,sizeof(buffer))==0 && esAlfavetico(buffer))
   {
       retorno=0;
       strncpy(pResultado,buffer,1000);
   }
   return retorno;
}

static int pedirStringInt(char* pResultado)
{
   int retorno=-1;
   char buffer[1000];
   if(myGets(buffer,sizeof(buffer))==0 && esAlfaNumerico(buffer))
   {
       retorno=0;
       strncpy(pResultado,buffer,1000);
   }
   return retorno;
}

static int myGets(char* cadena,int longitud)
{
    fflush(stdin);
    fgets(cadena,longitud,stdin);
    cadena[strlen(cadena)-1]='\0';//corrige el ENTER
    return 0;
}

static int esNumerica(char* cadena)
{
    int retorno=1;
    int i=0;

    if(cadena[0]=='-')
    {
        i=1;
    }
    for(;cadena[i]!='\0';i++)
    {

        if(cadena[i]>'9'|| cadena[i]<'0')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

static int esAlfavetico(char* cadena)
{
    int retorno=1;
    int i=0;

    for(;cadena[i]!='\0';i++)
    {

        if(cadena[i]!=' '&& (cadena[i]<'a' || cadena[i]<'z') &&(cadena[i]<'A' || cadena[i]<'Z') )
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

static int esAlfaNumerico(char* cadena)
{
    int retorno=1;
    int i=0;

    for(;cadena[i]!='\0';i++)
    {

        if(cadena[i]!=' '&& (cadena[i]<'a' || cadena[i]<'z') &&(cadena[i]<'A' || cadena[i]<'Z') && (cadena[i]>'9'|| cadena[i]<'0'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

static int esNumeroConComa(char* cadena)
{
    int retorno=1;
    int i=0;
    int contadorPuntos=0;

    if(cadena[0]=='-')
    {
        i=1;
    }
    for(;cadena[i]!='\0';i++)
    {
        if(i==0 && (cadena[i]=='-'||cadena[i]=='+'))
        {
            continue;
        }
        if((cadena[i]>'9'|| cadena[i]<'0') && cadena[i]!='.')
        {
            if (cadena[i]=='.' && contadorPuntos==0)
            {
                contadorPuntos++;
            }
            else
            {
                retorno=0;
                break;
            }
        }

    }
    return retorno;
}

int pedirNumero(int* pResultado,char* mensaje,char* mensajeError,int maximo,int minimo)
{
    int retorno=-1;
    int buffer;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo)
    {
        do{
            printf("%s",mensaje);
            if(pedirInt(&buffer)==0 && buffer >=minimo && buffer <=maximo)
            {
                *pResultado=buffer;
                retorno=0;
                break;
            }
            printf("%s",mensajeError);
        }while(1);
    }
    return retorno;
}

int pedirNumeroSinLimite(int* pResultado,char* mensaje,char* mensajeError)
{
    int retorno=-1;
    int buffer;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
        do{
            printf("%s",mensaje);
            if(pedirInt(&buffer)==0)
            {
                *pResultado=buffer;
                retorno=0;
                break;
            }
            printf("%s",mensajeError);
        }while(1);
    }
    return retorno;
}

int pedirNumeroComa(float* pResultado,char* mensaje,char* mensajeError,int maximo,int minimo)
{
    int retorno=-1;
    float buffer;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo)
    {
        do{
            printf("%s",mensaje);
            if(pedirFloat(&buffer)==0 && buffer >=minimo && buffer <=maximo)
            {
                *pResultado=buffer;
                retorno=0;
                break;
            }
            printf("%s",mensajeError);
        }while(1);
    }
    return retorno;
}

int pedirTexto(char* pTexto,char* mensaje,char* mensajeError)
{
    int retorno=-1;
    int espacio=sizeof(pTexto);
    char buffer[1000];
    if(pTexto!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
        do{
            printf("%s",mensaje);
            if(pedirString(buffer)==0)
            {
                strcpy(pTexto,buffer);
                retorno=0;
                break;
            }
            printf("%s",mensajeError);
        }while(1);
    }
    return retorno;
}

int pedirTextoConNumeros(char* pTexto,char* mensaje,char* mensajeError)
{
    int retorno=-1;
    int espacio=sizeof(pTexto);
    char buffer[1000];
    if(pTexto!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
        do{
            printf("%s",mensaje);
            if(pedirStringInt(buffer)==0)
            {
                strcpy(pTexto,buffer);
                retorno=0;
                break;
            }
            printf("%s",mensajeError);
        }while(1);
    }
    return retorno;
}


///////////////////OPERACIONES MATEMATICAS///////////////////


int mSumar(int* pResultado, int numero1,int numero2)
{
    int retorno=-1;
    if(pResultado!=NULL)
    {
        *pResultado=numero1+numero2;

        retorno=0;
    }
    return retorno;
}

int mRestar(int* pResultado, int numero1,int numero2)
{
    int retorno=-1;
    if(pResultado!=NULL)
    {
        *pResultado=numero1-numero2;
        retorno=0;
    }
    return retorno;
}

int mMultiplicar(int* pResultado, int numero1,int numero2)
{
    int retorno=-1;
    if(pResultado!=NULL)
    {
        *pResultado=numero1*numero2;
        retorno=0;
    }
    return retorno;
}

int mDividir(int* pResultado, int numero1,int numero2)
{
    int retorno=-1;
    if(pResultado!=NULL && numero2!=0)
    {
        *pResultado=numero1/numero2;
        retorno=0;
    }
    return retorno;
}

int mCalcularFactorial(int* pResultado, int numero)
{
    int retorno=-1;
    int resultadoAux;
    if(pResultado!=NULL)
    {
        if (numero == 0)
        {
            *pResultado=1;
        }
        else
        {
            mCalcularFactorial(&resultadoAux,numero-1);
            *pResultado = numero * resultadoAux;
        }
            retorno=0;
    }
    return retorno;
}

int calcularNumeroAleatorio(int desde, int hasta)
{
    srand(time(NULL));
    return desde + (rand() % (hasta + 1 - desde));
}


///////////////////ARRAYS///////////////////


void inicializarArrayInt(int* arrays, int elementos, int valor)
{
    int i;
    for(i=0; i < elementos; i++)
    {
        arrays[i] = valor;
    }
}

int mostrarArrayInt(int* pArray,int limite)
{
    int retorno=-1;
    int i;
    if(pArray!=NULL && limite>=0)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            printf("indice %i - valor %i\n",i,pArray[i]);
        }
    }
    return retorno;
}

void inicializarArrayString(char arrays[][100],int elementos,char Texto[])
{
    int i;
    for(i=0;i<elementos;i++)
    {
        strncpy(arrays[i],Texto,sizeof(arrays[i]));
    }
}

int mostrarArrayString(char arrays[][100],int elementos)
{
    int i;
    for(i=0;i<elementos;i++)
    {
        printf("%s\n",arrays[i]);
    }
    return 0;
}

void inicializarArrayFloat(float* arrays, int elementos, float valor)
{
    int i;
    for(i=0; i < elementos; i++)
    {
        arrays[i] = valor;
    }
}

int mostrarArrayFloat(float* pArray,int limite)
{
    int retorno=-1;
    int i;
    if(pArray!=NULL && limite>=0)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            printf("indice %i - valor %f",i,pArray[i]);
        }
    }
    return retorno;
}

int buscarPrimeraOcurrencia(int array[], int elementos, int valor)
{
    int i;
    for(i=0; i < elementos; i++)
    {
        if(array[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

int BuscarPares(int numeros[], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(numeros[i] % 2 == 0)
        {
            return numeros[i];
        }
    }
    return 0;
}

int BuscarMaximos(int numeros[], int cantidad)
{
    int i;
    int maximo;
    for(i=0; i<cantidad; i++)
    {
        if(i == 0 || numeros[i] > maximo)
        {
            maximo = numeros[i];
        }
    }
    return maximo;
}

int ContadorMaximos (int numeros[], int cantidad)
{
    int i;
    int maximo[cantidad];
    int contadorMaximos = 0;

    for(i=0; i<cantidad; i++)
    {
        maximo[i] = BuscarMaximos(numeros, cantidad);
        if(numeros[i] == maximo[cantidad])
        {
            contadorMaximos++;
        }
    }
    return contadorMaximos;
}

int BuscarMinimos(int numeros[], int cantidad)
{
    int i;
    int minimo;
    for(i=0; i<cantidad; i++)
    {
        if(i == 0 || numeros[i] < minimo)
        {
            minimo = numeros[i];
        }
    }
    return minimo;
}

int ContadorMinimos(int numeros[], int cantidad)
{
    int i;
    int minimo;
    int contadorMinimos;
    minimo = BuscarMinimos(numeros, cantidad);
    contadorMinimos = 0;
    for(i=0; i<cantidad; i++)
    {
        if(numeros[i] == minimo)
        {
            contadorMinimos++;
        }
    }
    return contadorMinimos;
}


///////////////////BURBUJEO///////////////////


int ordenarArrayIntMaxMin(int* pArray,int limite)//bubujeo
{
    int flagSwap;
    int i;
    int contador=0;
    int retorno=-1;
    int buffer;
    int nuevoLimite;
    if(pArray!=NULL && limite>=0)
    {
        nuevoLimite=limite-1;
        do{
            flagSwap=0;
            for(i=0;i<nuevoLimite;i++)
            {
                contador++;
                if(pArray[i]<pArray[i+1])
                {
                    flagSwap=1;
                    buffer=pArray[i];
                    pArray[i]=pArray[i+1];
                    pArray[i+1]=buffer;
                }
            }
            nuevoLimite--;
        }while(flagSwap);
        retorno=contador;
    }
    return retorno;
}

int ordenarArrayIntMinMax(int* pArray,int limite)//bubujeo
{
    int flagSwap;
    int i;
    int contador=0;
    int retorno=-1;
    int buffer;
    int nuevoLimite;
    if(pArray!=NULL && limite>=0)
    {
        nuevoLimite=limite-1;
        do{
            flagSwap=0;
            for(i=0;i<nuevoLimite;i++)
            {
                contador++;
                if(pArray[i]>pArray[i+1])
                {
                    flagSwap=1;
                    buffer=pArray[i];
                    pArray[i]=pArray[i+1];
                    pArray[i+1]=buffer;
                }
            }
            nuevoLimite--;
        }while(flagSwap);
        retorno=contador;
    }
    return retorno;
}

int ordenarArrayString(char pArray[][100],int limite)
{
    int flagSwap;
    int i;
    int contador=0;
    int retorno=-1;
    char buffer[100];
    int nuevoLimite;
    if(pArray!=NULL && limite>=0)
    {
        nuevoLimite=limite-1;
        do{
            flagSwap=0;
            for(i=0;i<nuevoLimite;i++)
            {
                contador++;
                if(strcmp(pArray[i],pArray[i+1])>0)
                {
                    flagSwap=1;
                    strcpy(buffer,pArray[i]);
                    strcpy(pArray[i],pArray[i+1]);
                    strcpy(pArray[i+1],buffer);
                }
            }
            nuevoLimite--;
        }while(flagSwap);
        retorno=contador;
    }
    return retorno;
}


//////////////////////////////////////////////


char QuitarSaltoLinea(char cadena[])
{
    int i;
    for(i=0;cadena[i] != '\0';i++)
    {
        if(cadena[i] == '\n')
        {
            cadena[i] = '\0';
        }
    }
    return cadena[i];
}

void InicialesEnMayus(char cadena[])
{
    int i;
    strlwr(cadena);
    for(i = 0; i < strlen(cadena); i++)
    {
        if(i == 0 || (cadena[i-1] == ' ' && cadena[i] >= 'a' && cadena[i] <= 'z'))
        {
            cadena[i] = toupper(cadena[i]);
        }
    }
}


