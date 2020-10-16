/*
 * utn.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Belu
 *      QTY = CANTIDAD
 */
#define MAX_CARACTERES 51
#define QTY 4


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stddef.h>

//#include "arrayEmployees.h"
//#include "menu.h"
#include "utn.h"

int valNumber(char* string,int cantidad)
{
	int i;
    int retorno = 1;
    if(string != NULL)
    {
        for(i = 0; string[i] != '\0' && i < cantidad; i++)
        {
            if(string[i] < '0' || string[i] > '9')
            {
                printf("entro 1");
                retorno = 1;
                break;
            }
            else
            {
                retorno = 0;

            }
        }
    }

    return retorno;
}

int validarCaracter(char* string,int cantidad)
{
    int retorno=1;//

    if(string != NULL && cantidad > 0 )
    {

        for(int i=0; i<cantidad && string[i]!='\0'; i++)
        {
            if((string[i]<'a' || string[i]>'z') && (string[i]<' '|| string[i]>' ') && (string[i]<'A' || string[i]>'Z') )
            {
                retorno=1;
                break;
            }
            else
            {
                retorno=0;
            }
        }
    }

    return retorno;
}

int getInt(int* input,char message[],char eMessage[],int minimo,int maximo,int reintentos)
{
    int numero;
    int retorno = 0;
    int contReintentos = 0;
    int rValidacion;
    char auxiliarNum[QTY];

    do
    {
        printf("%s",message);
        fflush(stdin);
        gets(auxiliarNum);
        rValidacion = valNumber(auxiliarNum,QTY);

        if(rValidacion==1)
        {
            contReintentos++;
            printf("%s\n",eMessage);
            rValidacion = valNumber(auxiliarNum,QTY);
        }
        else
        {
             numero = atoi(auxiliarNum);
             if(numero < minimo || numero > maximo)
             {
                printf("%s",eMessage);
                contReintentos++;
             }
             else
             {
                 *input = numero;//valor por referencia, modifico el original.
                 retorno = 0;
                 break;

             }


        }
        if(contReintentos == reintentos)
        {
        	printf("****************************************************");
            printf("Alcanzado el maximo de reintentos.\nAdios ! \n");
            system("pause");
            system("cls");
            retorno=1;
        }

    }while(contReintentos != reintentos);

    return retorno;

}

int getFloat(float* input,char message[],char eMessage[],float minimo,float maximo)
{
    float numero;
    int retorno = 0;

    printf("%s",message);
    scanf("%f",&numero);

    if(numero < minimo || numero > maximo)
    {
        printf("%s",eMessage);
        retorno = 1;
    }
    else{
        *input = numero;
    }

    return retorno;

}
int getCaracter(char* input,char message[],char eMessage[],char minimo,char maximo)
{
    char letra;
    int retorno = 0;

    printf("%s",message);
    fflush(stdin);
    scanf("%c",&letra);
    letra = tolower(letra);
    if(letra < minimo || letra > maximo)
    {
        printf("%s",eMessage);
        retorno = 1;
    }
    else{
        *input = letra;
    }
    return retorno;
}

int getString(char* input,char message[],char eMessage[],int minimo,int maximo,int reintentos)
{
    char nombre[MAX_CARACTERES];
    char auxiliar[256];
    int retorno=0;
    int contadorReintentos=0;
    int rValidar;

    do
    {
        printf("%s",message);
        fflush(stdin);
        gets(auxiliar);
        rValidar = validarCaracter(auxiliar,256);
        if(rValidar == 1)
        {
            contadorReintentos++;
            printf("%s",eMessage);

        }
        else
        {
            if(strlen(auxiliar) < minimo || strlen(auxiliar) > maximo)
            {
                printf("%s",eMessage);
                contadorReintentos++;
                //retorno=1;
            }
            else
            {
                strcpy(nombre,auxiliar);
                strcpy(input,nombre);
                retorno=0;
                break;
            }
        }

        if(contadorReintentos==reintentos)
        {
            printf("Alcanzado el maximo de reintentos.\nAdios ! \n");
            system("pause");
            system("cls");
            retorno=1;
        }

    }while(contadorReintentos!=reintentos);




    return retorno;

}


int NumeroSerie(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* input)
{
    maximo = 11;
    minimo = 8;
    int retorno=-1;
    char bufferStr[maximo];

    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos >= 0 && input != NULL)
    {
        do
        {
            if(!getString(bufferStr,msg,msgError,minimo,maximo,reintentos)) //==0 sin errores !0
            {
                if(validarSerie(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maximo);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int validarSerie(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;

    for(i = 0; stringRecibido[i] != '\0' ; i++)
    {
        if((stringRecibido[i] < '0' || stringRecibido[i] > '9'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
