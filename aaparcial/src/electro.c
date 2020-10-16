/*
 * electro.c
 *
 *  Created on: 15 oct. 2020
 *      Author: Belu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


#include "utn.h"
#include "electro.h"
#include "reparaciones.h"


void listadoElectro(eElectro* listaElectro, int tam)
{
	int i;

	if(listaElectro != NULL && tam > 0)
	{

		printf("\n***Listado de electrodomesticos\n***");
		printf("\nidElctro    Serie     idMarca     modelo\n");

		for(i = 0;i < tam; i++)
		{
			printf("\n%d      %d       %d       %d\n", listaElectro[i].idElectro,
														listaElectro[i].serie,
														listaElectro[i].idMarcaElectro,
														listaElectro[i].modelo);
		}
	}
}

void listadoMarca(eMarca* listaMarca, int tamM)
{
	int i;

	if(listaMarca != NULL && tamM > 0)
	{
		printf("\n***Listar marca\n***");
		printf("\nDescricion\n");

		for(i = 0; i < tamM; i ++)
		{

			printf("\n  %s\n",// listaMarca[i].idMarca,
								listaMarca[i].descripcionMarca);
		}
	}
}

void listarElectroConMarca(eElectro* listaElectro, int tam, eMarca* listaMarca, int tamM)
{
	int i;
	int j;

	printf("\n***Listado de electrodomesticos con su marca***\n");

	for(i = 0; i < tam; i++)
	{
		for(j = 0; j < tamM; j++)
		{
			if(listaElectro[i].idMarcaElectro == listaMarca[j].idMarca)
			{
				printf("\nId   Serie   Modelo Descripcion");
				printf("\n %d    %d    %d     %s\n", listaElectro[i].idElectro,
													 listaElectro[i].serie,
													 listaElectro[i].modelo,
													// listaElectro[i].idMarcaElectro,
													 listaMarca[j].descripcionMarca);
				break;
			}
		}
	}
}


int initArray(eElectro* electros, eReparacion* reparaciones, int tam, int tamR)
{
	int i;
	int j;
return -1; // si no hay elementos retorna -1

	for(i = 0;i < tam; i++)
	{
		//	electros[i].isEmpty = 0;
			electros[i].idElectro = 0;
			electros[i].serie = 0;
			electros[i].idMarcaElectro = 0;
			electros[i].modelo = 0;

	}


	for(i = 0; i < tamR; i++)
	{
		reparaciones[i].idReparacion = 0;
					reparaciones[i].serie = 0;
					reparaciones[i].idServicioRepa = 0;
					reparaciones[i].fechaIngresada.dia = 0;
					reparaciones[i].fechaIngresada.mes = 0;
					reparaciones[i].fechaIngresada.anio = 0;
	}
	return 0;
}

int crearIdElectro(eElectro* electros, int tam)
{
	int i;
	int contador = 0;

	for(i = 0;i < tam; i++)
	{
		if(electros[i].idElectro == 0)
		{
			contador = contador+1;
		}
	}
	contador = contador+1;

	return contador;
}
/*
int buscarPorId(eElectro* electros, int tam,int valorBuscado)
{

	int i;
	int posicion = 0;

	if(electros != NULL && tam >= 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(electros[i].isEmpty == 1)
			{ continue;

			}else if(electros[i].idElectro == valorBuscado)
				{
					posicion = i;
					return posicion;
				}
		}
	}
	return 0;
}*/


/***************Carga de datos - Alta***********/
int buscarLibre(eElectro* electro, int tam, int* posicion) // "1 ES LIBRE.
{
	int i;
	if(electro != NULL && tam >= 0 && posicion != NULL)
	{
		for (i = 0 ; i < tam; i ++)
		{
		   if (electro[i].idElectro == 0 )
		   {
		     *posicion = i;
		      return 1;
		   }
		}
	}
		   return 0;
}

int cargarArrayElectro(eElectro* electro, int tam)
{

	int posicionLibre;

	int idElectro = 0;

	int auxidMarcaElectro;

	int auxSerie;
	int auxModelo;

	 int posicion;


	// system("cls");
	 printf("\n***Alta ELECTRO ***\n");


	 idElectro = crearIdElectro(electro, tam);

	 posicionLibre = buscarLibre(electro, tam, &posicion);

	 if(posicionLibre == 1)
	 {

	 		 if(!getInt(&auxModelo,"Ingrese el modelo entre 700 y 703 \n","Error, ingrese el modelo\n", 700, 703, 3) == 0)
	 		 {
	 			 return 1;
	 		 }
	 		 if(!getInt(&auxSerie,"Ingrese la serie entre 100 y 103 \n","Error, ingrese el numero de serie\n", 100, 103, 3) == 0)
	 		 {
	 			 return 1;
	 		 }
	 		 if(!getInt(&auxidMarcaElectro,"Ingrese la marca\n "
	 				 	 	 	 	 	 	 	 	"1000 para Wirpool. \n"
	 				 	 	 	 	 	 	 	 	"1001 para Liliana\n"
	 				 	 	 	 	 	 	 	 	"1002 para Gafa\n"
	 				 	 	 	 	 	 	 	 	"1003 para Philips"
	 				 	 	 	 	 	 	 	 	,"Error, ingrese el numero de serie\n", 1000, 1003, 3) == 0)
	 		 {

	 			 return 1;
	 		 }
	 		 printf("salio del if");
	 		altaArrayElectro(electro, tam, auxModelo, idElectro, auxSerie,auxidMarcaElectro, &posicionLibre);

	 }else
	 {
		 printf("No hay posiciones libres");
	 }
	 printf("termino");
	return 0;
}

int altaArrayElectro(eElectro* electro,int tam, int modelo, int idElectro,int serie,int idMarcaElectro,int* posicion)
{
	if(electro != NULL && tam > 0)
	{
		electro[*posicion].modelo = modelo;
		electro[*posicion].idElectro = idElectro;
		electro[*posicion].serie = serie;
		electro[*posicion].idMarcaElectro = idMarcaElectro;

		return 0;
	}
	return -1;
}

/**************Modificar electrodomesticos**********************/


void menuModificar(eElectro* electro, int tam,int* idElectro)
{
	int pedirId;
	int posicion;

	if(getInt(&pedirId,"Escribir el Id del electrodomestico\n","Error, ingrese un valor numerico",1,999,3)==0)
	    {
			posicion = crearIdElectro(electro, tam);
	        if(posicion == -1)
	        {
	        	printf("No existe el Legajo\n");
	        }else
	        {
	        	//modificarEmpleado(aEmpleadoIngresado, len, posicion);

	        }

	    }
}

int modificarDatosElectro(eElectro* electro, int tam, int posicion)
{
	char respuesta = 'n';
	int opcionModificar;
	int auxSerie;
	int auxModelo;

	if(!getInt(&opcionModificar,"1.Modificar - Serie"
								"\n2.Modificar - Modelo\n"
								"3.Salir\n"
								"Elija una opcion:"
								,"Error. Elija una de las opciones dadas.\n",1,5,3)==0)
	{

		return 1;
    }

		do
		{
			switch(opcionModificar)
			{
			case 1:
				if(!getInt(&auxSerie,"Ingrese la serie que quiere modificar entre 100 y 104 \n","Error, reingrese un numero entre 100 y 104 y 120\n", 100, 104, 3) == 0)
				{
					 return 1;
				}else
				{
					electro[posicion].serie = auxSerie;
					respuesta = 's';
				}
				break;
			case 2:
				if(!getInt(&auxModelo,"Ingrese el modelo que quiere modificar entre 2014 y 2017 \n","Error, reingrese un numero entre 2014 y 2017\n", 2014, 2017, 3) == 0)
				{
					 return 1;
				}else
				{
					electro[posicion].serie = auxSerie;
					respuesta = 's';
				}

				break;
			case 3:
				printf("\nDesea Seguir?\n");
				printf("\nSi=s");
				printf("\nNo=n\n");
				scanf("%c", &respuesta);
				fflush(stdin);
				break;
			}

		}while(respuesta == 'n');

		return EXIT_SUCCESS;
}

/******************baja del electrodomestico****************/

void menuBorrarElectro(eElectro* electro, int tam)
{
	int pedirId;
	int posicion;
	int respuesta;

	system("cls");
	printf("***Baja de electrodomestico***");

	if(getInt(&pedirId,"Escribir el numero de id del electrodomestico\n","Error, ingrese un valor numerico\n",1,5,3)==0)
	    {

			posicion = crearIdElectro(electro, tam);
	        if(posicion == -1)
	        {
	        	printf("No existe el id\n");
	        }else
	        {
	        //	 mostrarElectro(electro[posicion],tam);
	        	 if(getInt(&respuesta,"Ingrese 1 para confirmar que quiere eliminar o ingrese 2 para NO eliminar \n","Error, debe ingresar 1 o 2\n", 1, 2, 3) == 0)
	        	 {

	        		 if(respuesta == 1)
	        		 {
	        			 darDeBajaElectro(electro, tam, pedirId);
	        		 }else
	        		 {
	        			 printf("Se ha cancelado la baja\n");
	        		 }
	        	 }
	        }

	    }
}
int darDeBajaElectro(eElectro* electro, int tam, int idElectro)
{
	int i;

	for(i = 0;i < tam; i++)
	{
		if(electro[i].idElectro == idElectro)
		{
			electro[i].idElectro = 0;
			electro[i].serie = 0;
			electro[i].idMarcaElectro = 0;
			electro[i].modelo = 0;
		}
	}
 return -1;
}
/*
void mostrarElectro(eElectro* electro, int tam)
{
		printf("%d   %d   %d   %d   %d",electro->idElectro,
										electro->idMarcaElectro,
										electro->modelo,
										electro->serie);


}

*/

void ordenarArray(eElectro* electro, int tam, int orden)
{
	eElectro auxiliar;
	int i;
	int j;

	for(i = 0; i < tam - 1; i++)
	{
		for(j = i + 1; j < tam; j++)
		{
			if(electro[i].modelo > electro[j].modelo)
			{
				auxiliar = electro[i];
				electro[i] = electro[j];
				electro[j] = auxiliar;

			}else
			{
				if(electro[i].modelo == electro[j].modelo && electro[i].serie == electro[j].serie)
				{
					auxiliar = electro[i];
					electro[i] = electro[j];
					electro[j] = auxiliar;
				}
			}
		}
	}
}

