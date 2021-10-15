/*
 * Nexo.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Martin Gonzalez
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Nexo.h"

/// Se imprimirán los clientes por pantalla y se pedirá que se ingrese el ID de un
///cliente existente y la cantidad de kilos totales que se recolectarán del cliente. Se generará un ID para el pedido y
///el mismo quedará en estado “Pendiente” hasta que se obtengan los residuos del cliente y se trasladen a la
///empresa.
///
/// @param listadoClientes listado de clientes del cual se eligira el ID
/// @param tamListadoClientes el tamaño del listado de clientes
/// @param listadoPedidos listado de clientes con el que vamos a trabajar
/// @param tamListadoPedidos el tamaño del listado de pedidos
/// @return auxiliar retorna 1 si se pudo crear el pedido, 0 si hubo un error
int CrearPedidoDeRecoleccion(eCliente listadoClientes[], int tamListadoClientes, ePedido listadoPedidos[], int tamListadoPedidos, eLocalidad listadoLocalidades[], int tamListadoLocalidades)
{
	int i;
	int j;
	int idIngresado;
	int auxiliar=0;
	float auxKilosTotales;
	char confirmar;

	MostrarListaDeClientes(listadoClientes, tamListadoClientes, listadoLocalidades,  tamListadoLocalidades);
	PedirEntero(&idIngresado, "Ingrese el ID del cliente a buscar: ", "Error, ingrese un numero entre 1 y 100: ", 1, 100);
	for(i=0; i<tamListadoClientes; i++)
	    {
	        if(idIngresado == listadoClientes[i].idCliente)//Lo encontre
	        {
	        	MostrarUnCliente(listadoClientes[i],listadoLocalidades, tamListadoLocalidades);
	        	PedirFlotante(&auxKilosTotales, "\nIngrese la cantidad de kilos a recolectar: ", "Error,ingrese un numero entre 1 y 1100: ", 1, 1100);
	            confirmar = PedirRespuestaSN("¿Esta seguro que desea crear este pedido? s=si n=no\n ");

	            if(confirmar=='s')
	            {


					j = BuscarLibrePedido(listadoPedidos, tamListadoPedidos);
					if(j!=-1)
					{


						listadoPedidos[j] = PedirPedido(listadoPedidos, tamListadoPedidos, auxKilosTotales);
						listadoClientes[i].idPedido = listadoPedidos[j].idPedido;


					}

	                auxiliar = 1;
	                break;

	            }

	        }
	    }
	return auxiliar;
}


/// Se imprimirán los pedidos por pantalla y se pedirá seleccionar el ID de uno de ellos.
/// Luego deberán ingresarse la cantidad de kilos de plástico de cada uno de los 3 tipos que la empresa puede
/// procesar que se obtuvieron de los kilos totales que se recolectaron. Por último, se marcará al pedido como “Completado”.
///
/// @param listadoPedidos
/// @param tamListadoPedidos
/// @param listadoClientes
/// @param tamListadoClientes
/// @return auxiliar retorna 1 si se pudo procesar el residuo, retorna 0 si hubo un error
int ProcesarResiduos(ePedido listadoPedidos[], int tamListadoPedidos, eCliente listadoClientes[], int tamListadoClientes)
{

	int i;
	int estado;
	int idIngresado;
	int auxiliar=0;
	float auxKilosPolietilenoAltaDensidad;
	float auxKilosPolietilenoBajaDensidad;
	float auxKilosPolipropileno;
	char confirmar;

	MostrarListaDePedidos(listadoPedidos, tamListadoPedidos, listadoClientes,tamListadoClientes);
	PedirEntero(&idIngresado, "\nIngrese el ID del pedido: ", "Error, ingrese un numero entre 1 y 1000: ", 1, 1000);
	for(i=0; i<tamListadoPedidos; i++)
	{
		if(idIngresado == listadoPedidos[i].idPedido)//Lo encontre
		{
			MostrarUnPedido(listadoPedidos[i],listadoClientes, tamListadoClientes);

			printf("\nA continuacion se le pedira la cantidad en kilos "
				"de cada tipo de basura, si se pasa de los kilos totales, debera reingresar los kilos.");

			printf("\nPresione Enter para continuar\n");
			getchar();

			do
			{
				PedirFlotante(&auxKilosPolietilenoAltaDensidad, "\nIngrese la cantidad de kilos de Polietileno de Alta Densidad : ", "Error,ingrese un numero entre 1 y 1100: ", 1, 1100);
				PedirFlotante(&auxKilosPolietilenoBajaDensidad, "\nIngrese la cantidad de kilos de Polietileno de Baja Densidad: ", "Error,ingrese un numero entre 1 y 1100: ", 1, 1100);
				PedirFlotante(&auxKilosPolipropileno, "\nIngrese la cantidad de Polipropileno: ", "Error,ingrese un numero entre 1 y 1100: ", 1, 1100);
				estado = VerificarKilos(listadoPedidos,tamListadoPedidos,auxKilosPolietilenoAltaDensidad+auxKilosPolietilenoBajaDensidad+auxKilosPolipropileno);


			}while(estado == 0);

			confirmar = PedirRespuestaSN("¿Esta seguro que desea afirmar las cantidades de kilos ingresadas? s=si n=no\n ");

			if(confirmar=='s')
			{

				listadoPedidos[i].KilosPolietilenoAltaDensidad = auxKilosPolietilenoAltaDensidad;
				listadoPedidos[i].KilosPolietilenoBajaDensidad = auxKilosPolietilenoBajaDensidad;
				listadoPedidos[i].KilosPolipropileno = auxKilosPolipropileno;
				strcpy(listadoPedidos[i].estadoPedido, "Completado");
				auxiliar = 1;
				break;

			}

		}
	}

	return auxiliar;
}


/// Verifica que la suma de los kilos procesados no superen los kilos originales
///
/// @param listadoPedidos listado de pedidos con el que vamos a trabajar
/// @param tamListadoPedidos el tamaño de la lista
/// @param sumaKilos la suma de los kilos procesados
/// @return estado, retorna 0 si la suma es mayor a los kilos originales, retorna 1 si la suma es menor o igual a los kilos originales
int VerificarKilos(ePedido listadoPedidos[], int tamListadoPedidos, int sumaKilos)
{
	int i;
	int estado = 0;
	for(i = 0; i < tamListadoPedidos; i++)
	{
		if(sumaKilos <= listadoPedidos[i].kilosTotales)
		{
			 estado = 1;
			 break;
		}
	}


	return estado;
}


/// Muestra un cliente con sus datos completos más su cantidad de pedidos pendientes
///
/// @param clienteParametro el cliente que vamos a mostrar
/// @param listadoPedidos la lista de pedidos con la que vamos a trabajar
/// @param tamListadoPedidos el tamaño de la lista de pedidos
void MonstrarUnClienteConCantidadDePedidosPendientes(eCliente clienteParametro, ePedido listadoPedidos[], int tamListadoPedidos,eLocalidad listadoLocalidades[], int tamListadoLocalidades)
{

	int contador;
	int i;

	contador = CantidadPendientes( listadoPedidos,  tamListadoPedidos);


	for (i = 0; i<tamListadoLocalidades; i++)
	{
		if(listadoLocalidades[i].idLocalidad == clienteParametro.idLocalidad)
		{

			printf("\n%d \t %s \t\t %s \t %s \t %s \t\t\t %d \n", clienteParametro.idCliente,
																	clienteParametro.nombre,
																	clienteParametro.cuit,
																	clienteParametro.direccion,
																	listadoLocalidades[i].descripcion,
																	contador);
			break;
		}
	}



}

/// Muestra una lista de clientes con su cantidad de pedidos pendientes por pantalla
///
/// @param listadoClientes la lista clientes con la que vamos a trabajar
/// @param tamListadoClientes el tamaño de la lista clientes
/// @param listadoPedidos la lista de pedidos con la que vamos a trabajar
/// @param tamListadoPedidos el tamaño de la lista pedidos
void MostrarListaDeClientesConCantidadDePedidosPendientes(eCliente listadoClientes[], int tamListadoClientes,ePedido listadoPedidos[], int tamListadoPedidos, eLocalidad listadoLocalidades[], int tamListadoLocalidades )
{
    int i;

    printf("ID \t NOMBRE \t CUIT \t\t DIRECCION \t LOCALIDAD \t CANTIDAD PENDIENTE");
    for(i=0; i<tamListadoClientes; i++)
    {
        if(listadoClientes[i].isEmpty != VACIO) // Solo vamos a mostrar los lugares ocupados
        {
        	MonstrarUnClienteConCantidadDePedidosPendientes(listadoClientes[i], listadoPedidos, tamListadoPedidos, listadoLocalidades, tamListadoLocalidades);
        }
    }

}

/// Cuenta la cantidad de pedidos que tienen un estado "Pendiente" o "Completado"
///
/// @param listadoPedidos la lista de pedidos con la que vamos a trabajar
/// @param tamListadoPedidos tamaño de la lista de pedidos
/// @return contador retorna la cantidad total de pedidos pendientes
int CantidadPendientes(ePedido listadoPedidos[], int tamListadoPedidos)
{
	int i;
	int contador = 0;
	for(i = 0; i < tamListadoPedidos; i++)
	{
		if(strcmp(listadoPedidos[i].estadoPedido, "Pendiente") == 0)
		{
			 contador++;

		}
	}


	return contador;
}



/// Se imprimirá una lista de los pedidos que se encuentren en estado
///“Pendiente” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
///
/// @param listadoPedidos listado de pedidos con la que vamos a trabajar
/// @param tamListadoPedidos tamaño de la lista de pedidos
/// @param listadoClientes listado de clientes con la que vamos a trabajar
/// @param tamListadoClientes tamaño de la lista de clientes
void ImprimirPedidosPendientes(ePedido listadoPedidos[], int tamListadoPedidos ,eCliente listadoClientes[], int tamListadoClientes)
{

	MonstrarUnaListaDePedidosConDatosDeClientes(listadoClientes, tamListadoClientes, listadoPedidos, tamListadoPedidos);

}

/// Muestra por pantalla un pedido "Pendiente"
///  con la información: Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
///
/// @param clienteParametro el cliente que vamos a trabajar
/// @param listadoPedidos el listado de pedidos con el que vamos a trabajar
/// @param tamListadoPedidos el tamaño del listado de pedidos
void MonstrarUnPedidoConDatosDeClientes(eCliente clienteParametro, ePedido listadoPedidos[], int tamListadoPedidos)
{
	int i;
		for (i = 0; i<tamListadoPedidos; i++)
		{
			if(listadoPedidos[i].idPedido == clienteParametro.idPedido)
			{
				if(strcmp(listadoPedidos[i].estadoPedido, "Pendiente") == 0)
				{
					printf("\n%s \t %s \t %.2f\n", clienteParametro.cuit,
													clienteParametro.direccion,
													listadoPedidos[i].kilosTotales);
					break;
				}


			}
		}



}



void MonstrarUnaListaDePedidosConDatosDeClientes(eCliente listadoClientes[], int tamListadoClientes,ePedido listadoPedidos[], int tamListadoPedidos)
{
    int i;

    printf("CUIT \t\t DIRECCION \t KILOS TOTALES");
    for(i=0; i<tamListadoClientes; i++)
    {
        if(listadoClientes[i].isEmpty != VACIO) // Solo vamos a mostrar los lugares ocupados
        {
        	MonstrarUnPedidoConDatosDeClientes(listadoClientes[i], listadoPedidos, tamListadoPedidos);
        }
    }

}

/// procesados: Se imprimirá una lista de los pedidos que se encuentren en estado
///“Completado” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo
///de plástico.
///
/// @param listadoPedidos
/// @param tamListadoPedidos
/// @param listadoClientes
/// @param tamListadoClientes
void ImprimirPedidosCompletados(ePedido listadoPedidos[], int tamListadoPedidos ,eCliente listadoClientes[], int tamListadoClientes)
{


MonstrarUnaListaDePedidosConDatosDeClientesYKilosReciclados(listadoClientes, tamListadoClientes, listadoPedidos, tamListadoPedidos);



}


void MonstrarUnPedidoConDatosDeClientesYKilosReciclados(eCliente clienteParametro, ePedido listadoPedidos[], int tamListadoPedidos)
{
	int i;
		for (i = 0; i<tamListadoPedidos; i++)
		{
			if(listadoPedidos[i].idPedido == clienteParametro.idPedido)
			{

				if(strcmp(listadoPedidos[i].estadoPedido, "Completado") == 0)
				{
					printf("\n%s \t %s \t %.2f \t %.2f \t %.2f\n", clienteParametro.cuit,
														clienteParametro.direccion,
														listadoPedidos[i].KilosPolietilenoAltaDensidad,
														listadoPedidos[i].KilosPolietilenoBajaDensidad,
														listadoPedidos[i].KilosPolipropileno);

					break;
				}

			}
		}



}

void MonstrarUnaListaDePedidosConDatosDeClientesYKilosReciclados(eCliente listadoClientes[], int tamListadoClientes,ePedido listadoPedidos[], int tamListadoPedidos)
{
    int i;

    printf("CUIT \t\t DIRECCION \t PolietilenoAD \t PolietilenoBD \t Polipropileno");
    for(i=0; i<tamListadoClientes; i++)
    {
        if(listadoClientes[i].isEmpty != VACIO ) // Solo vamos a mostrar los lugares ocupados
        {
        	MonstrarUnPedidoConDatosDeClientesYKilosReciclados(listadoClientes[i], listadoPedidos, tamListadoPedidos);
        }
    }

}


/// Pregunta por una localidad e indica la cantidad de pedidos pendientes para dicha localidad.
///
///
/// @param listadoClientes
/// @param tamListadoClientes
/// @param listadoPedidos
/// @param tamListadoPedidos
/// @return contador retorna la cantidad de pedidos pendientes de la localidad dada
int PedidosPendientesParaDichaLocalidad(eCliente listadoClientes[], int tamListadoClientes, ePedido listadoPedidos[], int tamListadoPedidos, eLocalidad listadoLocalidades[], int tamListadoLocalidades)
{

	int i;
	int contador = 0;
	int estado = 0;
	int auxIdLocalidad;

	//PedirStringCaracteresAlfabeticosEspaciados(auxLocalidad, 25, "Ingrese la localidad a buscar: ", "Ah ocurrido un error, reingrese: ");
	printf("\n-------------------------------------------------------------------\n");
	 MostrarListaDeLocalidades(listadoLocalidades, tamListadoLocalidades);
	 printf("\n-------------------------------------------------------------------\n");


		do
		{
			printf("Ingrese el ID de la localidad de la lista de arriba: ");
			scanf("%d", &auxIdLocalidad);
			estado = VerificarLocalidadID(listadoLocalidades,tamListadoLocalidades,auxIdLocalidad);


		}while(estado == 0);

	for(i=0; i<tamListadoClientes; i++)
	{

		if(listadoClientes[i].isEmpty==OCUPADO && listadoClientes[i].idLocalidad == auxIdLocalidad) //strcmp(listadoClientes[i].localidad, auxLocalidad) == 0
		{
			contador = CantidadPendientes( listadoPedidos,  tamListadoPedidos);

		}
	}

	return contador;
}


/// Muestra por pantalla la cantidad de kilos de polipropileno reciclado promedio por cliente.
/// @param listadoClientes
/// @param tamListadoClientes
/// @param listadoPedidos
/// @param tamListadoPedidos
void CantidadDeKilosDePolipropilenoRecicladoPromedioPorCliente(eCliente listadoClientes[], int tamListadoClientes, ePedido listadoPedidos[], int tamListadoPedidos)
{
	float kiloPromedio;

	kiloPromedio = PromedioPolipropileno(listadoClientes,  tamListadoClientes, listadoPedidos, tamListadoPedidos);


	printf("El promedio es: %.2f\n",kiloPromedio);

}

/// Calcula la cantidad de kilos de polipropileno reciclado promedio por cliente.
///
/// @param listadoClientes
/// @param tamListadoClientes
/// @param listadoPedidos
/// @param tamListadoPedidos
/// @return promedio retorna la cantidad de kilos de polipropileno reciclado promedio por cliente.
float PromedioPolipropileno(eCliente listadoClientes[], int tamListadoClientes, ePedido listadoPedidos[], int tamListadoPedidos)
{

	int i;
    float suma=0;
    float promedio =0;
    int contador = 0;
    for(i=0; i < tamListadoPedidos; i++)
    {
        if(listadoPedidos[i].isEmpty==OCUPADO )
        {

            suma = suma + listadoPedidos[i].KilosPolipropileno;

        }

    }

    contador = CantidadClientesconPolipropileno(listadoPedidos, tamListadoPedidos);

    if(suma != 0 || contador != 0)
    {
        promedio = suma / contador;
    }

    return promedio;
}


/// Calcula la cantidad de clientes que tienen reciclados almenos 1 kilo de Polipropileno
///
/// @param listadoPedidos
/// @param tamListadoPedidos
/// @return contador retorna la cantidad de clientes que tienen reciclados almenos 1 kilo de Polipropileno
int CantidadClientesconPolipropileno(ePedido listadoPedidos[], int tamListadoPedidos)
{
	int i;
	int contador = 0;
	for(i=0; i < tamListadoPedidos; i++)
	{
		if(listadoPedidos[i].isEmpty==OCUPADO && listadoPedidos[i].KilosPolipropileno > 0)
		{

			contador++;

		}

	}
	return contador;
}

void ClienteConMasPedidosPendientesOCompletos(ePedido listadoPedidos[], int tamListadoPedidos, eCliente listadoClientes[], int tamListadoClientes, eLocalidad listadoLocalidades[], int tamListadoLocalidades, char estado[15])
{

	int mayorPendientes = 0;
	int mayorCompletados = 0;
	int i;

	// mayorPendientes = CantidadPendientesOCompletados( listadoPedidos,  tamListadoPedidos, "Pendiente");

	 //mayorCompletados = CantidadPendientesOCompletados( listadoPedidos,  tamListadoPedidos, "Completado");



	/*for(i=0;i<tamListadoClientes; i++)
	{
		if(listadoClientes[i].isEmpty==OCUPADO && strcmp(estado, "Pendiente"))
		{
			if(mayorPendientes < listadoClientes[i].cantidadPedidosPendientes)
			{
				mayorPendientes = listadoClientes[i].cantidadPedidosPendientes;

				MostrarUnCliente(listadoClientes[i], listadoLocalidades, tamListadoLocalidades);
			}
		}else if(listadoClientes[i].isEmpty==OCUPADO && strcmp(estado, "Completado"))
			{
				if(mayorCompletados < listadoClientes[i].cantidadPedidosPendientes)
				{
					mayorCompletados = listadoClientes[i].cantidadPedidosPendientes;

					MostrarUnCliente(listadoClientes[i], listadoLocalidades, tamListadoLocalidades);
				}
			}

	}*/

}
