/*
 * Pedido.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Martin Gonzalez
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_

#define VACIO 0
#define OCUPADO 1
#define PENDIENTE 2
#define COMPLETADO 3
#include "Imput.h"
#include "Menu.h"
#include "TipoBasura.h"
#include "Clientes.h"


typedef struct
{
	int idPedido;
	int idTipoBasura;
	float kilosTotales;
	float KilosPolietilenoAltaDensidad;
	float KilosPolietilenoBajaDensidad;
	float KilosPolipropileno;
	char estadoPedido[15];
	int isEmpty;

}ePedido;

void InicializarPedidos(ePedido[], int);

int BuscarLibrePedido(ePedido[], int);

int SiguienteIdPedido(ePedido [],int );

ePedido PedirPedido(ePedido [], int , float );

void MostrarUnPedido(ePedido , eCliente [], int );

void MostrarListaDePedidos(ePedido [], int , eCliente [], int );

#endif /* PEDIDO_H_ */
