/*
 ============================================================================
 Name        : Parcial_LABO1.c
 Author      : Martin Gonzalez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Imput.h"
#include "Clientes.h"
#include "Pedido.h"
#include "Nexo.h"
#include "Menu.h"
#include "TipoBasura.h"
#include "Localidad.h"
#define CLIENTES 100
#define PEDIDOS 1000


int main(void) {
	setbuf(stdout, NULL);//disable buffer
	int opcion;
	int i;
	int inicializado = 0;
	int pedidoInicado = 0;
	int pedidoCompletado = 0;
	int cantidadPedidosPendientes = 0;

	//eTipoBasura listaTipoBasura[3] = {{1,"Polietileno de alta densidad", OCUPADO},{2,"Polietileno de baja densidad",OCUPADO},{3,"Polipropileno",OCUPADO}};
	eLocalidad listaLocalidad[4] = {{1,"CABA",OCUPADO},{2,"CAÑUELAS",OCUPADO},{3,"Moron",OCUPADO},{4,"LANUS",OCUPADO}};
	eCliente listaDeClientes[CLIENTES];
	ePedido listaDePedidos[PEDIDOS];
	InicializarClientes(listaDeClientes, CLIENTES);
	InicializarPedidos(listaDePedidos, PEDIDOS);


	do
	{
		printf("\nBIENVENIDO\n");
		opcion = menuPrincipal();

		switch(opcion)
		{
			case 1:

				i = CargarClienteALaLista(listaDeClientes, CLIENTES,listaLocalidad,4);
				inicializado = 1;
				   switch(i)
				   {
					   case -1:
						printf("No hay espacio disponible!!!\n");
						printf("\n-------------------------------\n");
					   break;
					   default:
						printf("\n-------------------------------\n");
						printf("Cliente registrado con exito!!!\n");
						printf("\n-------------------------------\n");
					   break;
				   }

				   printf("\nPresione Enter para continuar\n");
					getchar();
				break;
			case 2:
				if(inicializado == 1)//original == 1 para hardcodeo == 0
				{
					 i =ModificarCliente(listaDeClientes, CLIENTES,listaLocalidad, 4);
					   switch(i)
					   {
						   case 0:
							printf("¡¡¡No se modifico nada ya que ah cancelado la modificacion o el ID ingresado no existe!!!\n");
						   break;
						   default:
							printf("¡¡¡Producto Modificado con exito!!!\n");
						   break;
					   }
				}else{
					printf("Debe ingresar un cliente primero");
				}

				printf("\nPresione Enter para continuar\n");
				getchar();


				break;
			case 3:

				if(inicializado == 1)//original == 1 para hardcodeo == 0
				{
					i = EliminarCliente(listaDeClientes, CLIENTES,listaLocalidad,4);
				   switch(i)
				   {
					   case 0:
						printf("\n¡¡¡NO EXISTE ESE ID!!!\n");
						printf("\n-------------------------------\n");
					   break;
					   default:
						printf("\n¡¡¡Cliente eliminado con exito!!!\n");
						printf("\n-------------------------------\n");
					   break;
				   }
				}else{
					printf("Debe ingresar un cliente primero");
				}


				printf("\nPresione Enter para continuar\n");
				getchar();
				break;
			case 4:

				if(inicializado == 1)//original == 1 para hardcodeo == 0
				{
					 i =CrearPedidoDeRecoleccion(listaDeClientes, CLIENTES, listaDePedidos, PEDIDOS,listaLocalidad,4);
					   switch(i)
					   {
						   case 0:
							printf("¡¡¡Hubo un error o se cancelo el pedido!!!\n");
						   break;
						   default:
							printf("¡¡¡Pedido realizado!!!\n");
							pedidoInicado = 1;
						   break;
					   }
				}else{
					printf("Debe ingresar un cliente primero");
				}


				printf("\nPresione Enter para continuar\n");
				getchar();


				break;
			case 5:
				if(inicializado == 1 && pedidoInicado == 1)//original == 1 para hardcodeo == 0
				{
					 i =ProcesarResiduos(listaDePedidos, PEDIDOS, listaDeClientes, CLIENTES);
					   switch(i)
					   {
						   case 0:
							printf("¡¡¡Hubo un error o se cancelo el procesamiento!!!\n");
						   break;
						   default:
							printf("¡¡¡Procesamiento realizado!!!\n");
							pedidoCompletado = 1;
						   break;
					   }
				}else{
					printf("Debe ingresar un cliente y hacer un pedido primero");
				}

				printf("\nPresione Enter para continuar\n");
				getchar();


				break;
			case 6:

				if(inicializado == 1 && pedidoInicado == 1)//original == 1 para hardcodeo == 0
				{
					MostrarListaDeClientesConCantidadDePedidosPendientes(listaDeClientes, CLIENTES, listaDePedidos, PEDIDOS,listaLocalidad,4);
				}else{
					printf("Debe ingresar un cliente y hacer un pedido primero");
				}

				printf("\nPresione Enter para continuar\n");
				getchar();
				break;
			case 7:
				if(inicializado == 1 && pedidoInicado == 1)//original == 1 para hardcodeo == 0
				{
					ImprimirPedidosPendientes(listaDePedidos, PEDIDOS, listaDeClientes, CLIENTES);
				}else{
					printf("Debe ingresar un cliente y hacer un pedido primero");
				}



				printf("\nPresione Enter para continuar\n");
				getchar();

				break;
			case 8:
				if(inicializado == 1 && pedidoInicado == 1 && pedidoCompletado == 1)//original == 1 para hardcodeo == 0
				{
					ImprimirPedidosCompletados(listaDePedidos, PEDIDOS, listaDeClientes, CLIENTES);
				}else{
					printf("Debe ingresar un cliente, hacer un pedido y procesarlo primero");
				}



				printf("\nPresione Enter para continuar\n");
				getchar();

				break;
			case 9:

				if(inicializado == 1 && pedidoInicado == 1)//original == 1 para hardcodeo == 0
				{
					cantidadPedidosPendientes = PedidosPendientesParaDichaLocalidad(listaDeClientes,CLIENTES,listaDePedidos,PEDIDOS,listaLocalidad,4);
					printf("La cantidad de Pedidos Pendientes de la Localidad indicada es: %d", cantidadPedidosPendientes);
				}else{
					printf("Debe ingresar un cliente y hacer un pedido primero");
				}



				printf("\nPresione Enter para continuar\n");
				getchar();
				break;
			case 10:

				if(inicializado == 1 && pedidoInicado == 1 && pedidoCompletado == 1)//original == 1 para hardcodeo == 0
				{
					CantidadDeKilosDePolipropilenoRecicladoPromedioPorCliente(listaDeClientes, CLIENTES, listaDePedidos, PEDIDOS);
				}else{
					printf("Debe ingresar un cliente, hacer un pedido y procesarlo primero");
				}

				printf("\nPresione Enter para continuar\n");
				getchar();

				break;
			case 11:

				if(inicializado == 1 && pedidoInicado == 1 )//original == 1 para hardcodeo == 0
				{
					ClienteConMasPedidosPendientesOCompletos(listaDePedidos, PEDIDOS, listaDeClientes, CLIENTES, listaLocalidad,  4, "Pendiente");
				}else{
					printf("Debe ingresar un cliente, hacer un pedido y procesarlo primero");
				}


				printf("\nPresione Enter para continuar\n");
				getchar();

				break;
			case 12:

				if(inicializado == 1 && pedidoInicado == 1 && pedidoCompletado == 1)//original == 1 para hardcodeo == 0
				{
					ClienteConMasPedidosPendientesOCompletos(listaDePedidos, PEDIDOS, listaDeClientes, CLIENTES, listaLocalidad,  4, "Completado");
				}else{
					printf("Debe ingresar un cliente, hacer un pedido y procesarlo primero");
				}


				printf("\nPresione Enter para continuar\n");
				getchar();

				break;



		}
	}while(opcion != 13);

	printf("Gracias por usar la aplicacion\n");

	return EXIT_SUCCESS;
}

