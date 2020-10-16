/*
 * utn.h
 *
 *  Created on: 1 oct. 2020
 *      Author: Belu
 */

#ifndef UTN_H_
#define UTN_H_

/** \brief La funcion se encarga de validar el numero ingresado, este numero es tomado como un caracter,
 *         se valida y convierte a tipo de dato entero.
 *
 * \param char* string
 * \param int cantidad es la cantidad de elementos que posee el string
 * \return int si retorna 1 hubo un error. si retorno 0 (cero) todo bien.
 *
 */
int valNumber(char* string,int cantidad);
/** \brief La funcion se encarga de validar el caracter ingresado,
 *         se valida y se devolvera si hubo o no hubo error.
 *
 * \param char* string
 * \param int cantidad es la cantidad de elementos que posee el string
 * \return int retorna 1 todo mal, 0 todo bien
 *
 */
int valirdarCaracter(char* string,int cantidad);

/** \brief La funcion se encarga de verifica si la cadena es un numero y despues lo convierte a numerico
 *
 * \param int input  Puntero a variable donde se escribirá el valor ingresado en el caso de ser
correcto.
 * \param  char message Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al
usuario datos por consola.
 * \param char eMessage  Puntero a cadena de caracteres con mensaje de error en el caso de que
el dato ingresado no sea válido.
 * \param  int minimo Valor mínimo admitido
 * \param int maximo Valor máximo admitido
 * \param  reintentos  Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato
en caso de error.
 * \return int retorna 1 esta mal, 0 esta bien
 *
 */
int getInt(int* input,char message[],char eMessage[],int minimo,int maximo,int reintentos);

/** \brief La funcion se encarga de verifica si es un numero decimal
 *
 * \param int input  Puntero a variable donde se escribirá el valor ingresado en el caso de ser
correcto.
 * \param  char message Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al
usuario datos por consola.
 * \param char eMessage  Puntero a cadena de caracteres con mensaje de error en el caso de que
el dato ingresado no sea válido.
 * \param  int minimo Valor mínimo admitido
 * \param int maximo Valor máximo admitido
 * \param  reintentos  Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato
en caso de error.
 * \return int retorna 1 esta mal, 0 esta bien
 *
 */
int getFloat(float* input,char message[],char eMessage[],float minimo,float maximo);


/** \brief La funcion se encarga de Convierte letra mayúscula a minúscula y si es caracter
 *
 * \param int input  Puntero a variable donde se escribirá el valor ingresado en el caso de ser
correcto.
 * \param  char message Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al
usuario datos por consola.
 * \param char eMessage  Puntero a cadena de caracteres con mensaje de error en el caso de que
el dato ingresado no sea válido.
 * \param  char minimo
 * \param  char maximo
 * \param  reintentos  Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato
en caso de error.
 * \return int retorna 1 esta mal, 0 esta bien
 *
 */
int getCaracter(char* input,char message[],char eMessage[],char minimo,char maximo);

/** \brief La funcion se encarga de verificar si la cadena es un string
 *
 * \param int input  Puntero a variable donde se escribirá el valor ingresado en el caso de ser
correcto.
 * \param  char message Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al
usuario datos por consola.
 * \param char eMessage  Puntero a cadena de caracteres con mensaje de error en el caso de que
el dato ingresado no sea válido.
 * \param  char minimo
 * \param  char maximo
 * \param  reintentos  Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato
en caso de error.
 * \return int retorna 1 esta mal, 0 esta bien
 *
 */
int getString(char* input,char message[],char eMessage[],int minimo,int maximo,int reintentos);

int NumeroSerie(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* input);

int validarSerie(char* stringRecibido);



#endif /* UTN_H_ */
