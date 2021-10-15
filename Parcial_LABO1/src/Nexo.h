/*
 * Nexo.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Martin Gonzalez
 */


#include "Imput.h"
#include "Menu.h"
#include "Pedido.h"
#include "Clientes.h"
#include "TipoBasura.h"

int CrearPedidoDeRecoleccion(eCliente [], int, ePedido[], int, eLocalidad [], int );


int ProcesarResiduos(ePedido [], int , eCliente [], int );

int VerificarKilos(ePedido [], int , int );

int CantidadPendientes(ePedido [], int );

void MonstrarUnClienteConCantidadDePedidosPendientes(eCliente , ePedido [], int, eLocalidad [], int );

void MostrarListaDeClientesConCantidadDePedidosPendientes(eCliente [], int ,ePedido [], int , eLocalidad [], int  );

void ImprimirPedidosPendientes(ePedido [], int  ,eCliente [], int );

void MonstrarUnPedidoConDatosDeClientes(eCliente , ePedido [], int );

void MonstrarUnaListaDePedidosConDatosDeClientes(eCliente [], int ,ePedido [], int  );

void ImprimirPedidosCompletados(ePedido [], int  ,eCliente [], int );

void MonstrarUnPedidoConDatosDeClientesYKilosReciclados(eCliente , ePedido [], int );

void MonstrarUnaListaDePedidosConDatosDeClientesYKilosReciclados(eCliente [], int ,ePedido [], int );

int PedidosPendientesParaDichaLocalidad(eCliente [], int , ePedido [], int , eLocalidad [], int  );

void CantidadDeKilosDePolipropilenoRecicladoPromedioPorCliente();

float PromedioPolipropileno(eCliente listadoClientes[], int tamListadoClientes, ePedido listadoPedidos[], int tamListadoPedidos);

int CantidadClientesconPolipropileno(ePedido [], int );

void ClienteConMasPedidosPendientesOCompletos(ePedido listadoPedidos[], int tamListadoPedidos, eCliente listadoClientes[], int tamListadoClientes, eLocalidad listadoLocalidades[], int tamListadoLocalidades, char estado[15]);
