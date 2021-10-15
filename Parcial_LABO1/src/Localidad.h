/*
 * Localidad.h
 *
 *  Created on: 15 oct. 2021
 *      Author: RocioGonzalez
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#define VACIO 0
#define OCUPADO 1

typedef struct
{
	int idLocalidad;
	char descripcion[25];
	int isEmpty;

}eLocalidad;

void MostrarUnaLocalidad(eLocalidad LocalidadParametro);

void MostrarListaDeLocalidades( eLocalidad listadoLocalidad[], int tamListadoLocalidad);

#endif /* LOCALIDAD_H_ */
