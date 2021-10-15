/*
 * Pedido.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Martin Gonzalez
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Pedido.h"



/// Inicializa una lista de Pedidos
///
/// @param listadoPedidos la lista con la que vamos a trabajar
/// @param tamListadoPedidos tamaño de la lista
void InicializarPedidos(ePedido listadoPedidos[], int tamListadoPedidos)
{
    int i;
    for(i=0; i<tamListadoPedidos; i++)
    {
    	listadoPedidos[i].isEmpty = VACIO;
    }
}

/// Busca un lugar libre en una lista dada
///
/// @param listadoPedidos la lista con la que vamos a trabajar
/// @param tamListadoPedidos tamaño de la lista
/// @return int retorna el indice libre
int BuscarLibrePedido(ePedido listadoPedidos[], int tamListadoPedidos)
{
    int i;
    int index;
    index = -1; //Si no encuentra espacio disponible

    for(i=0; i<tamListadoPedidos; i++)
    {
        if(listadoPedidos[i].isEmpty == VACIO)//Criterio de busqueda
        {
            index = i;
            break;
        }
    }

    return index;
}


/// Busca un ID y devuelve el siguiente de este.
///
/// @param listadoPedidos la lista con la que vamos a trabajar
/// @param tamListadoPedidos tamaño de la lista
/// @return retorno retorna el ID siguiente
int SiguienteIdPedido(ePedido listadoPedidos[], int tamListadoPedidos)
{
    int retorno = 0;
    int i;
    if(tamListadoPedidos > 0 && listadoPedidos != NULL)
    {
        for(i=0; i<tamListadoPedidos; i++)
        {
            if(listadoPedidos[i].isEmpty == OCUPADO)
            {
                    if(listadoPedidos[i].idPedido>retorno)
                    {
                         retorno=listadoPedidos[i].idPedido;
                    }

            }
        }
    }

    return retorno+1;
}

/// Completa los datos necesarios al momento de dar el Alta de un pedido
///
/// @param listadoClientes la lista con la que vamos a trabajar
/// @param tamListadoClientes tamaño de la lista
/// @return retorna el cliente con sus datos cargados
ePedido PedirPedido(ePedido listadoPedidos[], int tamListadoPedidos, float kilogramosTotates)
{
	ePedido miPedido;


	int id;

	id = SiguienteIdPedido(listadoPedidos,tamListadoPedidos);

	miPedido.kilosTotales = kilogramosTotates;
	strcpy(miPedido.estadoPedido, "Pendiente");
	miPedido.idPedido = id;
	miPedido.isEmpty = OCUPADO;
	return miPedido;

}


/// Muestra un solo pedido por pantalla
/// @param pedidoParametro el pedido que vamos a mostrar
/// @param tipoBasuraParametro la lista con la que vamos a trabajar
/// @param tamTipoBasura tamaño de la lista
void MostrarUnPedido(ePedido pedidoParametro, eCliente clienteParametro[], int tamCliente)
{

	int i;
		for (i = 0; i<tamCliente; i++)
		{
			if(clienteParametro[i].idPedido == pedidoParametro.idPedido)
			{
				printf("\n%d \t %s \t %.2f \t %s\n", pedidoParametro.idPedido,
													pedidoParametro.estadoPedido,
													pedidoParametro.kilosTotales,
													clienteParametro[i].nombre);
				break;
			}

		}


}

/// Muestra una lista de clientes por pantalla
///
/// @param listadoClientes lista con la que vamos a trabajar
/// @param tamListadoClientes tamaño de la lista
void MostrarListaDePedidos(ePedido listadoPedidos[], int tamListadoPedidos, eCliente listadoClientes[], int tamCliente)
{
    int i;

    printf("ID \t ESTADO \t KILOS \t NOMBRE DE LA EMPRESA");
    for(i=0; i<tamListadoPedidos; i++)
    {
        if(listadoPedidos[i].isEmpty != VACIO) // Solo vamos a mostrar los lugares ocupados
        {
        	MostrarUnPedido(listadoPedidos[i],listadoClientes,tamCliente);
        }
    }

}
