/*
 * Clientes.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Martin Gonzalez
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Clientes.h"


/// Inicializa una lista de Clientes
///
/// @param listadoClientes la lista con la que vamos a trabajar
/// @param tamListadoClientes tamaño de la lista
void InicializarClientes(eCliente listadoClientes[], int tamListadoClientes)
{
    int i;
    for(i=0; i<tamListadoClientes; i++)
    {
    	listadoClientes[i].isEmpty = VACIO;
    }
}

/// Busca un lugar libre en una lista dada
///
/// @param listadoClientes la lista con la que vamos a trabajar
/// @param tamListadoClientes tamaño de la lista
/// @return int retorna el indice libre
int BuscarLibre(eCliente listadoClientes[], int tamListadoClientes)
{
    int i;
    int index;
    index = -1; //Si no encuentra espacio disponible

    for(i=0; i<tamListadoClientes; i++)
    {
        if(listadoClientes[i].isEmpty == VACIO)//Criterio de busqueda
        {
            index = i;
            break;
        }
    }

    return index;
}


/// Busca un ID y devuelve el siguiente de este.
///
/// @param listadoClientes la lista con la que vamos a trabajar
/// @param tamListadoClientes tamaño de la lista
/// @return retorno retorna el ID siguiente
int SiguienteId(eCliente listadoClientes[],int tamListadoClientes)
{
    int retorno = 0;
    int i;
    if(tamListadoClientes > 0 && listadoClientes != NULL)
    {
        for(i=0; i<tamListadoClientes; i++)
        {
            if(listadoClientes[i].isEmpty == OCUPADO)
            {
                    if(listadoClientes[i].idCliente>retorno)
                    {
                         retorno=listadoClientes[i].idCliente;
                    }

            }
        }
    }

    return retorno+1;
}


/// Pide al usuario los datos del cliente
///
/// @param listadoClientes la lista con la que vamos a trabajar
/// @param tamListadoClientes tamaño de la lista
/// @return retorna el cliente con sus datos cargados
eCliente PedirCliente(eCliente listadoClientes[], int tamListadoClientes, eLocalidad listadoLocalidades[], int tamListadoLocalidades)
{
	eCliente miCliente;

	char auxCuitCliente[14];
	int auxIdLocalidad;
	int estado = 0;

	int id;

	 id = SiguienteId(listadoClientes,tamListadoClientes);

	 PedirAlfanumericaConEspacio(miCliente.nombre, 25, "Ingrese el nombre de la empresa: ", "Ah ocurrido un error, reingrese: ");
	 //PedirAlfanumericaConEspacio(miCliente.cuit, 12, "Ingrese el CUIT de la empresa : ", "Ah ocurrido un error, reingrese: ");
	 do
	{
		printf("Ingrese el CUIT de la empresa: ");
		gets(auxCuitCliente);
		estado = VerificarCuit(auxCuitCliente);

	}while(estado == 0);

	 strcpy(miCliente.cuit,auxCuitCliente);

	 PedirAlfanumericaConEspacio(miCliente.direccion, 25, "Ingrese la direccion de la empresa: ", "Ah ocurrido un error, reingrese: ");

	 printf("\n-------------------------------------------------------------------\n");
	 MostrarListaDeLocalidades(listadoLocalidades, tamListadoLocalidades);
	 printf("\n-------------------------------------------------------------------\n");


		do
		{
			printf("Ingrese el ID de la localidad de la lista de arriba: ");
			scanf("%d", &auxIdLocalidad);
			estado = VerificarLocalidadID(listadoLocalidades,tamListadoLocalidades,auxIdLocalidad);


		}while(estado == 0);

	 		miCliente.idLocalidad = auxIdLocalidad;


	 //PedirStringCaracteresAlfabeticosEspaciados(miCliente.localidad, 25, "Ingrese la localidad de la empresa: ", "Ah ocurrido un error, reingrese: ");
	 miCliente.idCliente = id;

	 miCliente.isEmpty = OCUPADO;
	return miCliente;

}

int VerificarLocalidadID(eLocalidad listadoLocalidades[], int tamListadoLocalidades, int idLocalidades)
{
	int i;
	int estado = 0;
	for(i = 0; i < tamListadoLocalidades; i++)
	{
		if(listadoLocalidades[i].idLocalidad == idLocalidades)
		{
			estado = 1;
			break;
		}

	}
	return estado;
}

/// Verfica que el CUIT no sea mayor o menor a 11
///
/// @param cuitCliente el Cuit a ser analizado
/// @return estado retorna 0 si es mayor o menor a 11, retorna 1 si el tamaño es 11
int VerificarCuit(char cuitCliente[14])
{
	int estado = 1;
	if(strlen(cuitCliente) > 11 || strlen(cuitCliente) < 11)
	{
		estado = 0;

	}

	return estado;
}

/// Cargamos el cliente a la lista y lo mostramos
///
/// @param listadoClientes la lista con la que vamos a trabajar
/// @param tamListadoClientes tamaño de la lista
/// @return i -1 si no se pudo cargar
int CargarClienteALaLista(eCliente listadoClientes[], int tamListadoClientes,eLocalidad listadoLocalidades[], int tamListadoLocalidades )
{
    int i;
    i = BuscarLibre(listadoClientes, tamListadoClientes);
    if(i!=-1)
    {


    	listadoClientes[i] = PedirCliente(listadoClientes,tamListadoClientes, listadoLocalidades, tamListadoLocalidades);
    	printf("ID \t NOMBRE \t CUIT \t\t DIRECCION \t LOCALIDAD");
    	MostrarUnCliente(listadoClientes[i],listadoLocalidades, tamListadoLocalidades );

    }
    return i;//estado que devuelve la funcion respecto de lo que paso dentro de la carga
}


/// Muestra un solo cliente por pantalla
///
/// @param clienteParametro el cliente que vamos a mostrar
void MostrarUnCliente(eCliente clienteParametro, eLocalidad listadoLocalidades[], int tamListadoLocalidades)
{

	int i;
	for (i = 0; i<tamListadoLocalidades; i++)
	{
		if(listadoLocalidades[i].idLocalidad == clienteParametro.idLocalidad)
		{
			printf("\n%d \t %s \t\t %s \t %s \t %s\n", clienteParametro.idCliente,
																clienteParametro.nombre,
																clienteParametro.cuit,
																clienteParametro.direccion,
																listadoLocalidades[i].descripcion);
			break;
		}
	}



}


/// Muestra una lista de clientes por pantalla
///
/// @param listadoClientes lista con la que vamos a trabajar
/// @param tamListadoClientes tamaño de la lista
void MostrarListaDeClientes(eCliente listadoClientes[], int tamListadoClientes, eLocalidad listadoLocalidades[], int tamListadoLocalidades)
{
    int i;

    printf("ID \t NOMBRE \t CUIT \t\t DIRECCION \t LOCALIDAD");
    for(i=0; i<tamListadoClientes; i++)
    {
        if(listadoClientes[i].isEmpty != VACIO) // Solo vamos a mostrar los lugares ocupados
        {
        	MostrarUnCliente(listadoClientes[i], listadoLocalidades, tamListadoLocalidades);
        }
    }

}


/// Pide ID al usuario y pregunta que desea modificar del Cliente de la lista si su ID es igual al ingresado.
///
/// @param listadoClientes lista con la que vamos a trabajar
/// @param tamListadoClientes tamaño de la lista
/// @return retorna 0 si hubo un error, 1 si el cliente se modificó correctamente
int ModificarCliente(eCliente listadoClientes[], int tamListadoClientes,eLocalidad listadoLocalidades[], int tamListadoLocalidades)
{
    int auxIdLocalidad;
    char direccion[25];
    int i;
    int idIngresado;
    int opcion;
    char confirmar;
    int retorno = 0;
    int estado = 0;



    MostrarListaDeClientes(listadoClientes, tamListadoClientes, listadoLocalidades,  tamListadoLocalidades);

    PedirEntero(&idIngresado, "Ingrese el ID del cliente a modificar: ", "Error, ingrese un numero entre 1 y 100", 1, 100);

    printf("\n-------------------------------\n");

    for(i=0; i<tamListadoClientes; i++)
    {
        if(idIngresado == listadoClientes[i].idCliente)//Lo encontre
        {


            do
            {
            	opcion = menuEditarCliente();


                switch(opcion)
                {
                    case 1:


                    	 PedirAlfanumericaConEspacio(direccion, 25, "Ingrese la nueva direccion de la empresa: ", "Ah ocurrido un error, reingrese: ");
                    	confirmar = PedirRespuestaSN("¿Esta seguro que desea modificar? s=si n=no\n");

                        if(confirmar=='s')
                        {

                        	strcpy(listadoClientes[i].direccion, direccion);
                            retorno = 1;


                        }

                    break;
                    case 2:



                    	//PedirStringCaracteresAlfabeticosEspaciados(localidad, 25, "Ingrese la nueva localidad de la empresa: ", "Ah ocurrido un error, reingrese: ");
                    	printf("\n-------------------------------------------------------------------\n");
						 MostrarListaDeLocalidades(listadoLocalidades, tamListadoLocalidades);
						 printf("\n-------------------------------------------------------------------\n");


							do
							{
								printf("Ingrese el ID de la localidad a modificar de la lista de arriba: ");
								scanf("%d", &auxIdLocalidad);
								estado = VerificarLocalidadID(listadoLocalidades,tamListadoLocalidades,auxIdLocalidad);


							}while(estado == 0);


                    	confirmar = PedirRespuestaSN("¿Esta seguro que desea modificar? s=si n=no\n");

                        if(confirmar=='s')
                        {
                        	//strcpy(listadoClientes[i].localidad, localidad);
                        	listadoClientes[i].idLocalidad = auxIdLocalidad;
                            retorno = 1;

                        }

                    break;
                    case 3:

                    break;


                default:
                    printf("Opcion incorrecta, por favor elejir teclas del 1 al 3. \n\n");
                }
            }while(opcion!=3);




            break;
        }

    }
    return retorno;
}

/// Pide ID al usuario y elimina un cliente de la lista si su ID es igual al ingresado.
///
/// @param listadoClientes lista con la que vamos a trabajar
/// @param tamListadoClientes tamaño de la lista
/// @return retorna 0 si hubo un error, 1 si se pudo eleiminar el cliente
int EliminarCliente(eCliente listadoClientes[], int tamListadoClientes, eLocalidad listadoLocalidades[], int tamListadoLocalidades)
{
     int i;
    int idIngresado;
    int auxiliar=0;
    char confirmar;

    MostrarListaDeClientes(listadoClientes, tamListadoClientes, listadoLocalidades,  tamListadoLocalidades);
    PedirEntero(&idIngresado, "Ingrese el ID del cliente a eliminar: ", "Error, ingrese un numero entre 1 y 100", 1, 100);

    for(i=0; i<tamListadoClientes; i++)
    {
        if(idIngresado == listadoClientes[i].idCliente)//Lo encontre
        {
        	MostrarUnCliente(listadoClientes[i],listadoLocalidades, tamListadoLocalidades);
            confirmar = PedirRespuestaSN("¿Esta seguro que desea eliminar el cliente? s=si n=no\n ");

            if(confirmar=='s')
            {
            	listadoClientes[i].isEmpty = VACIO;
                auxiliar = 1;
                break;

            }

        }
    }
    return auxiliar;
}
