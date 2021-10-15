/*
 * Localidad.c
 *
 *  Created on: 15 oct. 2021
 *      Author: RocioGonzalez
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Localidad.h"


void MostrarUnaLocalidad(eLocalidad LocalidadParametro)
{

	printf("\n%d \t %s \n", LocalidadParametro.idLocalidad,LocalidadParametro.descripcion);


}


void MostrarListaDeLocalidades( eLocalidad listadoLocalidad[], int tamListadoLocalidad)
{
    int i;

    printf("ID \t DESCRIPCION ");
    for(i=0; i<tamListadoLocalidad; i++)
    {
        if(listadoLocalidad[i].isEmpty != VACIO) // Solo vamos a mostrar los lugares ocupados
        {
        	MostrarUnaLocalidad( listadoLocalidad[i]);
        }
    }

}
