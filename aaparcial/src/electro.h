/*
 * electro.h
 *
 *  Created on: 15 oct. 2020
 *      Author: Belu
 */

#ifndef ELECTRO_H_
#define ELECTRO_H_

#include "reparaciones.h"

	typedef struct
	{
		int idElectro;
		int serie;
		 int idMarcaElectro;
		int modelo;
	}eElectro;

	typedef struct
		{
			int idMarca;
			char descripcionMarca[20];
		}eMarca;

#endif /* ELECTRO_H_ */

void harcodearMarcas(eMarca* listaMarca);

/* * \ brief Para indicar que todas las posiciones en la matriz están vacías,
* esta función pone la bandera (isEmpty) en VERDADERO en todas las  posiciónes de la matriz
* \ param aEmpleadoIngresado Employee * Puntero a la matriz de empleados
* \ param len int Longitud de la matriz
* \ return int Devuelve (-1) si Error [Longitud inválida o puntero NULO] - (0) si está bien
*/
int initArray(eElectro* electros, eReparacion* reparaciones, int tam, int tamR);
/* * \ brief crea el numero ID de manera secuencial y automatica
 * \param aEmpleadoIngresado employee*
 * \param len int
* \ return int Devuelve (-1) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (0) si está bien
*/
int crearIdElectro(eElectro* electros, int tam);

/* * \ brief hace una busqueda del id que nosotros le indicamos
 * \param electros eElectro*
 * \param tam int
 * \param valorBuscado int*
* \ return int Devuelve 1 si esta libre y 0 si no esta libre
*/
int buscarPorId(eElectro* electros, int tam,int valorBuscado);

/* * \ brief Indica que valores le diste de alta.
 * \param electros eElectro*
 * \param tam int
* \ return
* */
void listadoElectro(eElectro* listaElectro, int tam);

/* * \ brief Indica que valores le diste de alta.
 * \param listaMarca eMarca*
 * \param tam int
* \ return
* */
void listadoMarca(eMarca* listaMarca, int tamM);

/* * \ brief Indica que valores le diste de alta a esas dos estructuras.
 * \param listaelectros eElectro*
 * \param listaMarca eMarca*
 * \param tam int
* \ return
* */
void listarElectroConMarca(eElectro* listaElectro, int tam, eMarca* listaMarca, int tamM);

int buscarLibre(eElectro* electro, int tam, int* posicion);

int cargarArrayElectro(eElectro* electro, int tam);
int altaArrayElectro(eElectro* electro,int tam, int modelo, int idElectro,int serie,int idMarcaElectro,int* posicion);

void menuModificar(eElectro* electro, int tam,int* idElectro);
int modificarDatosElectro(eElectro* electro, int tam, int posicion);

void menuBorrarElectro(eElectro* electro, int tam);
int darDeBajaElectro(eElectro* electro, int tam, int idElectro);
//void mostrarElectro(eElectro* electro, int tam);

void ordenarArray(eElectro* electro, int tam, int orden);
