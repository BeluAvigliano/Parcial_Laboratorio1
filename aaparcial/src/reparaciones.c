/*
 * reparaciones.c
 *
 *  Created on: 15 oct. 2020
 *      Author: Belu
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "reparaciones.h"
#include "electro.h"


int crearId(eReparacion* reparaciones, int tam)
{
	int i;
	int contador = 0;

	for(i = 0;i < tam; i++)
	{
		if(reparaciones[i].idReparacion == 0)
		{
			contador = contador+1;
		}
	}
	contador = contador+1;

	return contador;
}

void listadoReparaciones(eReparacion* listaReparaciones, int tamR)
{
	int i;

	if(listaReparaciones != NULL && tamR > 0)
	{

		printf("\n***Listado de Reparaciones***\n");
		printf("\nidReparacion   serie  fechaIngreso\n");

		for(i = 0;i < tamR; i++)
		{
			printf("\n%d      %d          %d/%d/%d\n",listaReparaciones[i].idReparacion,
															listaReparaciones[i].serie,
															//listaReparaciones[i].idServicioRepa,
															listaReparaciones[i].fechaIngresada.dia,
															listaReparaciones[i].fechaIngresada.mes,
															listaReparaciones[i].fechaIngresada.anio);
		}
	}
}
void listadoServicio(eServicio* listaServicios, int tamS)
{
	int i;

	if(listaServicios != NULL && tamS > 0)
	{

		printf("\n***Listado de Servicios***\n");
		printf("\nDescripcion  precio\n");

		for(i = 0;i < tamS; i++)
		{
			printf("Descripcion   precio");
			printf("\n%s           %d      \n", //listaServicios[i].idServicio,
														listaServicios[i].descripcion,
														listaServicios[i].precio);
		}
	}
}

void listaReparacionServicio(eReparacion* listaReparaciones, int tamR, eServicio* listaServicios, int tamS)
{
	int i;
	int j;

	printf("\nListado de Reparaciones con su servicio realizado\n");

	for(i = 0; i < tamR; i++)
	{
		for(j = 0; j < tamS; j++)
		{
			if(listaReparaciones[i].idServicioRepa == listaServicios[j].idServicio)
			{
				printf("\n %d    %d    %d     %d     %d  %d   %s     %d\n", listaReparaciones[i].idReparacion,
																			listaReparaciones[i].serie,
																			listaReparaciones[i].fechaIngresada.dia,
																			listaReparaciones[i].fechaIngresada.mes,
																			listaReparaciones[i].fechaIngresada.anio,
																			listaServicios[j].idServicio,
																			listaServicios[j].descripcion,
																			listaServicios[j].precio);
				break;
			}
		}
	}
}

int crearIdElectro(eReparacion* reparaciones, int tamR)
{
	int i;
	int contador = 0;

	for(i = 0;i < tamR; i++)
	{
		if(reparaciones[i].idReparacion == 0)
		{
			contador = contador+1;
		}
	}
	contador = contador+1;

	return contador;
}


int cargarReparacion(eReparacion* reparaciones, int tamR)
{
	int idReparacion;
	int posicionLibre;
	int posicion;

	int auxServicio;
	int auxElectro;

	int dia;
	int mes;
	int anio;

	int serie;
	int idServicioRepa;
	eFecha fechaIngresada;

	idReparacion = crearIdElectro(reparaciones, tamR);

	posicionLibre = buscarLibre(reparaciones, tamR, &posicion);

	if(posicionLibre == 1)
	{
		 if(!getInt(&auxElectro,"Ingrese el  1000 para Wirpool. \n"
	 				 	 	 	 	 	 	 	 	"1001 para Liliana\n"
	 				 	 	 	 	 	 	 	 	"1002 para Gafa\n"
	 				 	 	 	 	 	 	 	 	"1003 para Philips\n","Error, ingrese el modelo\n", 1000, 1003, 3) == 0)
		 {
		 	 return 1;
		  }
		 	if(!getInt(&auxServicio,"Ingrese 2000.Garamtia \n"
		 			"2002 Repuesto"
		 			"2001 Mantenimiento"
		 			"2003 refaccion","Error, ingrese el numero de serie\n", 2000, 2003, 3) == 0)
		 	{
		 		 return 1;
		 	 }
		 	if(!getInt(&dia,"Ingrese el dia del mes de 01 al 31 \n","Error, ingrese el numero de serie\n", 01, 31, 3) == 0)
			 	{
			 		 return 1;
			 	 }
		 	if(!getInt(&mes,"Ingrese el mes de 01 al 12 \n","Error, ingrese el numero de serie\n", 01, 12, 3) == 0)
				 	{
				 		 return 1;
				 	 }
		 	if(!getInt(&anio,"Ingrese el anio a partir del 2000 \n","Error, ingrese el numero de serie\n", 2000, 9999, 3) == 0)
		 				 	{
		 				 		 return 1;
		 				 	 }

				 altaArrayReparacion(reparaciones, tamR, dia, mes, anio,idReparacion, &posicionLibre);
	 }else
		 {
			 printf("No hay posiciones libres");
		 }
		 printf("termino");
		return 0;


	}
}
/*
int altaArrayreparacion(ereparacion* reparaciones,int tamR, int dia int mes,int anio,int idReparacion,int* posicion)
{
	if(reparaciones != NULL && tamR > 0)
	{
		reparaciones[*posicion].fechaIngreso.dia = dia;
		reparaciones[*posicion].fechaIngreso.mes = mes;
		reparaciones[*posicion].fechaIngreso.anio = anio ;
		reparaciones[*posicion].idreparaciones = idReparaciones;

		return 0;
	}
*/
