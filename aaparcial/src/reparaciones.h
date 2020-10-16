/*
 * reparaciones.h
 *
 *  Created on: 15 oct. 2020
 *      Author: Belu
 */

#ifndef REPARACIONES_H_
#define REPARACIONES_H_

	typedef struct
	{
		int dia;
		int mes;
		int anio;
	}eFecha;

	typedef struct
	{
		int idReparacion;
		int serie;
		int idServicioRepa;
		eFecha fechaIngresada;
	}eReparacion;

	typedef struct
	{
		int idServicio;
		char descripcion[25];
		int precio;
	}eServicio;


#endif /* REPARACIONES_H_ */

void hardcodearServicios(eServicio* listaServicios);


/* * \ brief crea el numero ID de manera secuencial y automatica
 * \param aEmpleadoIngresado employee*
 * \param len int
* \ return int Devuelve (-1) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (0) si está bien
*/
int crearId(eReparacion* reparaciones, int tam);

/* * \ brief Indica que valores le diste de alta a esas dos estructuras.
 * \param listaReparaciones eReparacion*
 * \param tamR int
* \ return
* */
void listadoReparaciones(eReparacion* listaReparaciones, int tamR);

/* * \ brief Indica que valores le diste de alta a esas dos estructuras.
 * \param listaServicios eServicio*
 * \param tamS int
* \ return
* */
void listadoServicio(eServicio* listaServicios, int tamS);

/* * \ brief Indica que valores le diste de alta a esas dos estructuras.
 * \param listaReparaciones eReparacion*
 * \param listaServicios eServicio*
 * \param tamR int
 * \param tamS int
* \ return
* */
void listaReparacionServicio(eReparacion* listaReparaciones, int tamR, eServicio* listaServicios, int tamS);

int cargarReparacion(eReparacion* reparaciones, int tamR);
int altaArrayreparacion(ereparacion* reparaciones,int tamR, int dia int mes,int anio,int idReparacion,int* posicion);
