/*
 * Clientes.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Martin Gonzalez
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

#define VACIO 0
#define OCUPADO 1
#include "Imput.h"
#include "Menu.h"
#include "Localidad.h"
typedef struct
{
	int idCliente;
	char nombre[25];
	char cuit[14];
	char direccion[25];
	//char localidad[25];
	int idLocalidad;
	int idPedido;
	int isEmpty;

}eCliente;

void InicializarClientes(eCliente[], int);

int BuscarLibre(eCliente[], int);

int SiguienteId(eCliente [],int );

eCliente PedirCliente(eCliente [], int, eLocalidad [], int  );

int VerificarLocalidadID(eLocalidad [], int , int );

int VerificarCuit(char [14]);

int CargarClienteALaLista(eCliente [], int ,eLocalidad [], int  );

void MostrarUnCliente(eCliente , eLocalidad [], int );

void MostrarListaDeClientes(eCliente [], int, eLocalidad [], int  );

int ModificarCliente(eCliente [], int ,eLocalidad [], int );

int EliminarCliente(eCliente [], int , eLocalidad [], int );

#endif /* CLIENTES_H_ */
