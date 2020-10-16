/*
 ============================================================================
 Name        : aaparcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stddef.h>

#include "menu.h"

int main(void) {
	setbuf(stdout, NULL);

	menuDeIngreso();
	return EXIT_SUCCESS;
}
