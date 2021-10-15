/*
 * Imput.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Martin Gonzalez
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Imput.h"

/** \brief Solicita un numero entero al usuario.
 *
 * \param pEntero int* Puntero donde se recibe el numero.
 * \param mensaje[] char Es el mensaje mostrado al solicitar el numero.
 * \param mensajeError[] char Es el mensaje mostrado en caso de ingreso invalido o fuera del rango.
 * \param minimo int  El numero minimo aceptado inclusive.
 * \param maximo int El numero maximo aceptado inclusive.
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int PedirEntero(int* pEntero, char mensaje[], char mensajeError[], int minimo, int maximo)
{
    char array[13];
    int numero;
    int error;
    if(pEntero != NULL)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(array, 13, stdin);
            if(array[(strlen(array) - 1)] != '\n')
            {
                error = 1;
            } else
            {
                /**Devuelve 1 si ES NUMERICA y 0 si NO ES */
                if(ComprobarArrayNumericaEntero(array, (strlen(array) - 1)) == 0)
                {
                    error = 1;
                }else
                {
                    array[(strlen(array) - 1)] = '\0';
                    numero = atoi(array);
                    if(numero > maximo || numero < minimo)
                    {
                        error = 1;
                    } else
                    {
                        *pEntero = numero;
                    }
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        } while(error == 1);
        return 0;
    }
    return 1;
}

/** \brief Comprueba si el string recibido forma un numero entero.
 *
 * \param cadenaNumerica[] char Array a evaluar.
 * \param tamanio int Dimesion del array.
 * \return int Retorna 1 si el string es correcto, 0 si no lo es o -1 en caso de puntero NULL.
 *
 */
int ComprobarArrayNumericaEntero(char cadenaNumerica[], int tamanio)
{
    int retorno = -1;
    int indice = 0;
    if(cadenaNumerica != NULL && tamanio > 0)
    {
        retorno = 1;
        if(cadenaNumerica[0] == '-')
        {
            indice = 1;
        }
        for( ; indice < tamanio; indice++)
        {
            if(isdigit(cadenaNumerica[indice]) == 0)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Solicita un numero decimal al usuario.
 *
 * \param pNumero float* Puntero donde se recibe el numero.
 * \param mensaje[] char Es el mensaje mostrado al solicitar el numero.
 * \param mensajeError[] char Es el mensaje mostrado en caso de ingreso invalido o fuera del rango.
 * \param minimo float  El numero minimo aceptado inclusive.
 * \param maximo float El numero maximo aceptado inclusive.
 * \return float Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int PedirFlotante(float* pNumero, char mensaje[], char mensajeError[], float minimo, float maximo)
{
    char array[13];
    float numero;
    int error;
    if(pNumero != NULL)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(array, 13, stdin);
            /**< EVALUA QUE EL LARGO DEL STRING INTRODUCIDO SEA CORRECTO*/
            if(array[(strlen(array) - 1)] != '\n')
            {
                error = 1;
            } else
            {
                array[(strlen(array) - 1)] = '\0';
                /**Devuelve 1 si ES FLOTANTE y 0 si NO ES */
               if(ComprobarStringNumeroFlotante(array, strlen(array)) == 0)
                {
                    error = 1;
                }else
                {
                    numero = atof(array);
                    if(numero > maximo || numero < minimo)
                    {
                        error = 1;
                    } else
                    {
                        *pNumero = numero;
                    }
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        } while(error == 1);
        return 0;
    }
    return 1;
}


int ComprobarStringNumeroFlotante(char cadenaNumerica[], int tamanio)
{
    int retorno = -1;
    int cantidadPuntos = 0;
    int indice = 0;
    if(cadenaNumerica != NULL && tamanio > 0)
    {
        retorno = 1;
        if(cadenaNumerica[0] == '-')
        {
            indice = 1;
        }
        for( ; indice < tamanio; indice++)
        {
            if(cadenaNumerica[indice] == '.')
            {
                cantidadPuntos++;
                if(cantidadPuntos > 1)
                {
                    retorno = 0;
                    break;
                }
            }else
            {
                if(isdigit(cadenaNumerica[indice]) == 0)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

/** \brief Pide al usuario un numero positivo en forma de string.
 *
 * \param arrayLetras[] char Array donde se recibe el string.
 * \param tamanio int Dimension del array.
 * \param mensaje[] char Mensaje a mostrar.
 * \param mensajeError[] char Mensaje a mostrar en caso de que los datos recibidos no sean validos.
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int PedirStringDeNumerosPositivo(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[])
{
    int error;
    char arrayAuxiliar[tamanio + 1];
    if(arrayLetras != NULL && tamanio > 0)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(arrayAuxiliar, (tamanio + 1), stdin);
            if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
            {
                error = 1;
            } else
            {
                arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
                if(ComprobarStringNumericoPositivo(arrayAuxiliar, (strlen(arrayAuxiliar) + 1)) != 1)
                {
                    error = 1;
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        }while(error == 1);
        strncpy(arrayLetras, arrayAuxiliar, strlen(arrayAuxiliar) + 1);
        return 0;
    }
    return 1;
}

int PedirStringCaracteresAlfabeticos(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[])
{
    int error;
    char arrayAuxiliar[tamanio + 1];
    if(arrayLetras != NULL && tamanio > 0)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(arrayAuxiliar, (tamanio + 1), stdin);
            /**< EVALUA QUE EL LARGO DEL STRING INTRODUCIDO SEA CORRECTO*/
            if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
            {
                printf("\nLINEA 1\n");
                error = 1;
            } else
            {
                arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
                /**< COMPRUEBA QUE ESTE FORMADO POR LETRAS*/
                if(ComprobarStringCaracteresAlfabeticos(arrayAuxiliar, strlen(arrayAuxiliar)) != 1)
                {
                    printf("\nLINEA 2\n");
                    error = 1;
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        }while(error == 1);

        strncpy(arrayLetras, arrayAuxiliar, (strlen(arrayAuxiliar)+ 1));
        return 0;
    }
    return 1;
}

int PedirStringCaracteresAlfabeticosEspaciados(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[])
{
    int error;
    char arrayAuxiliar[tamanio + 1];
    if(arrayLetras != NULL && tamanio > 0)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(arrayAuxiliar, (tamanio + 1), stdin);
            /**< EVALUA QUE EL LARGO DEL STRING INTRODUCIDO SEA CORRECTO*/
            if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
            {
                error = 1;
            } else
            {
                arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
                /**< COMPRUEBA QUE ESTE FORMADO POR LETRAS Y ESPACIO*/
                if(ComprobarStringCaracteresAlfabeticosEspaciados(arrayAuxiliar, strlen(arrayAuxiliar)) != 1)
                {
                    error = 1;
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        }while(error == 1);

        strncpy(arrayLetras, arrayAuxiliar, (strlen(arrayAuxiliar)+ 1));
        return 0;
    }
    return 1;
}



int PedirAlfanumericaConEspacio(char arrayAlfanumerica[], int tamanio, char mensaje[], char mensajeError[])
{
    if(arrayAlfanumerica != NULL && tamanio > 0)
    {
        int error;
        int indice;
        char arrayAuxiliar[tamanio + 1];
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(arrayAuxiliar, (tamanio + 1), stdin);
            if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
            {
                error = 1;
            } else
            {
                if(isalnum(arrayAuxiliar[0]) == 0 || isalnum(arrayAuxiliar[strlen(arrayAuxiliar) - 2]) == 0)
                {
                    error = 1;
                } else
                {
                    for(indice = 1; indice < (strlen(arrayAuxiliar) - 2); indice++)
                    {
                        if(isalnum(arrayAuxiliar[indice]) == 0 && arrayAuxiliar[indice] != ' ')
                        {
                            error = 1;
                        }
                    }
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        }while(error == 1);

        arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
        strncpy(arrayAlfanumerica, arrayAuxiliar, (strlen(arrayAuxiliar)+ 1));
        return 0;
    }
    return -1;
}

/** \brief Comprueba si el string recibido tiene solo caracteres numericos positivos.
 *
 * \param cadenaNumerica[] char Array a evaluar.
 * \param tamanio int Dimesion del array.
 * \return int Retorna 1 si el string es correcto, 0 si no lo es o -1 en caso de puntero NULL.
 *
 */
int ComprobarStringNumericoPositivo(char cadenaNumerica[], int tamanio)
{
    int retorno = -1;
    int indice;
    if(cadenaNumerica != NULL && tamanio > 0)
    {
        retorno = 1;
        if(strlen(cadenaNumerica) == 0 || strlen(cadenaNumerica) >= tamanio)
        {
            retorno = 0;
        } else
        {
            for(indice = 0; indice < tamanio; indice++)
            {
                if(cadenaNumerica[indice] == '\0')
                {
                    break;
                }
                if(isdigit(cadenaNumerica[indice]) == 0)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}


int ComprobarStringCaracteresAlfabeticos(char stringLetras[], int tamanio)
{
    int retorno = -1;
    int indice;
    if(stringLetras != NULL && tamanio > 0)
    {
        retorno = 1;
        for(indice = 0; indice < tamanio; indice++)
        {
            if(isalpha(stringLetras[indice]) == 0)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


int ComprobarStringCaracteresAlfabeticosEspaciados(char stringLetras[], int tamanio)
{
    int retorno = -1;
    int indice;
    if(stringLetras != NULL && tamanio > 0)
    {
        retorno = 1;
        for(indice = 0; indice < tamanio; indice++)
        {
            if(isalpha(stringLetras[indice]) == 0 && stringLetras[indice] != ' ')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Solicita al usuario una respuesta SI o NO y la devuelve en un unico caracter.
 *
 * \param mensaje[] char Mensaje a mostrar.
 * \return char Devuelve 'n' para NO y 's' para SI.
 *
 */
char PedirRespuestaSN(char mensaje[])
{
    char respuesta;
    printf("%s", mensaje);
    do
    {
        fflush(stdin);
        respuesta = getchar();
        respuesta = tolower(respuesta);
        if(respuesta != 's' && respuesta != 'n')
        {
            printf("\nRespuesta invalida. Ingrese s(para si) o n (para no): ");
        }
    } while(respuesta != 's' && respuesta != 'n');
    return respuesta;
}


