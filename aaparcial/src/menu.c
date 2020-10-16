/*
 * menu.c
 *
 *  Created on: 27 sep. 2020
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

#define tam 4
#define tamR 4
#define tamM 4
#define tamS 4
int opcion(void)
{
    int opcion=0;
    int auxOpcion;

    if(getInt(&auxOpcion,"\n1.Alta \n"
    						"2.Modificar\n"
    						"3.Baja - Borrar \n"
    						"4.Listar\n"
    						"5.Salir\n\n"
    						"Elija una opcion:","Error. Elija una de las opciones dadas.\n",1,5,3)==0)
    {

        opcion=auxOpcion;

    }


    return opcion;
}

int menuDeIngreso(void)
{
	char respuesta = 's';
	int banderaDelPrimero = 1;
	int idElectro;

		eElectro electro[tam];
		eReparacion reparaciones[tamR];

		initArray(electro, reparaciones, tam, tamR);

		eMarca listaMarca[4] = {{1000, "Wirpool"},{1001,"Liliana"},{1002,"Gafa"},{1003,"Philips"}};

		eServicio listaServicios[4] = {{2000, "Garantia:", 250},{2001, "Mantenimiento:", 500},{2002, "Repuestos:", 400},{2003, "Refaccion:", 600}};
		//eElectro listaElectro[4] = {{1,100,1000,2014},{2,101,1001,2015},{3,102,1002,2016},{4,103,1003,2017}};

		//eReparacion listaReparaciones[4] ={{500,600,2000,{19,12,2020}},{501,601,2001,{17,11,2014}},{502,602,2002,{25,10,2016}},{503,603,2003,{29,11,2012}}};

		do
		{
			printf("sentro DO");
			switch(opcion())
			{
			case 1:
				banderaDelPrimero = 1;
				cargarArrayElectro(electro, tam);
				printf("salio del funcion");
				break;
			case 2:
				if(banderaDelPrimero == 1)
				{
					banderaDelPrimero = 1;
					menuModificar(electro, tam, &idElectro);

				}else
				{
					printf("\nPrimero debe ingresar un empleado .\n");
				}

				break;
			case 3:
				if(banderaDelPrimero == 1)
				{
					banderaDelPrimero = 1;
					menuBorrarElectro(electro, tam);
				}else
				{
					printf("\nPrimero debe ingresar un empleado .\n");
				}

				break;
			case 4:

				if(banderaDelPrimero == 1)
				{
					banderaDelPrimero = 1;
				listarElectroConMarca(electro, tam,listaMarca, tamM);
				listadoMarca(listaMarca, tamM);
				listadoServicio(listaServicios, tamS);
				listadoReparaciones(reparaciones, tamR);


				}else
				{
					printf("\nPrimero debe ingresar un empleado .\n");
				}


				break;
			case 5:
				printf("\nDesea Seguir?\n");
				printf("\nSi=s");
				printf("\nNo=n\n");
				scanf("%c", &respuesta);
				fflush(stdin);
				break;
			}
			//system("CLS");
			printf("final while");
		}while(respuesta == 's');
		printf("%C",respuesta);
		return EXIT_SUCCESS;

}
