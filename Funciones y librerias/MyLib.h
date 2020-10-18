#ifndef MY_LIB
#define MY_LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

FILE *p_alarma;

typedef struct {
	int puertas,capot,baul,velocidad;
}sensores_t;

sensores_t apagada(void);
sensores_t alerta(void);
sensores_t disparada(void);
sensores_t modificar(int x);
sensores_t archivo(int x);
sensores_t (*operaciones[3])(void);


int principal(void);
int espera(void);
void historial(int x);

#endif

