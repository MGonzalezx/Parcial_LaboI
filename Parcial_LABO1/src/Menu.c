/*
 * Menu.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Martin Gonzalez
 */


#include <stdio.h>
#include <stdlib.h>
#include "Imput.h"
#include "Menu.h"

/** \brief Imprime el menu principal en pantalla.
 *
 * \param void
 * \return void
 *
 */
void menuPrincipal_print(void)
{
    printf("1) Alta de cliente\n");
    printf("2) Modificar datos de cliente\n");
    printf("3) Baja de cliente\n");
    printf("4) Crear pedido de recolección\n");
    printf("5) Procesar residuos\n");
    printf("6) Imprimir Clientes\n");
    printf("7) Imprimir Pedidos pendientes\n");
    printf("8) Imprimir Pedidos procesados\n");
    printf("9) Cantidad de pedidos pendientes X localidad\n");
    printf("10) Cantidad de kilos de polipropileno reciclado promedio por cliente\n");
    printf("11) Cliente con más pedidos pendientes\n");
    printf("12) Cliente con más pedidos completados\n");
    printf("13) Salir\n");

}



/** \brief Pregunta al usuario por una opcion del menu principal y la devuelve.
 *
 * \param void
 * \return int Retorna la opcion del menu que selecciona el usuario
 *
 */
int menuPrincipal(void)
{
    int opcion;
    printf("\n");
    menuPrincipal_print();
    PedirEntero(&opcion, "\nIntroduzca una opcion: ", "\nError, opcion invalida. Introduzca una opcion valida: ", 1, 13);
    fflush(stdin);
    return opcion;
}

/** \brief Imprime el menu de edicion de un cliente en pantalla.
 *
 * \param void
 * \return void
 *
 */

void menuEditarCliente_print(void)
{

	printf("1. Direccion\n");
	printf("2. Localidad\n");
	printf("3. Volver Atras\n");
	printf("Elija una opcion: ");
}

/** \brief Pregunta al usuario por una opcion del menu de edicion de un cliente y la devuelve.
 *
 * \param void
 * \return int
 *
 */

int menuEditarCliente(void)
{
    int opcion;
    printf("\n");
    menuEditarCliente_print();
    PedirEntero(&opcion, "\n¿Que desea modificar? ", "\nError, opcion invalida. Introduzca una opcion valida: ", 1, 3);
    return opcion;
}
