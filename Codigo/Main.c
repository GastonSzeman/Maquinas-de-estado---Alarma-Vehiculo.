#include "MyLib.h"
#include "Funciones.c"

int main(){
	sensores_t (*operaciones[3])(void) = { alerta , apagada , disparada};
	(*operaciones[principal()-1])();
	return 0;
}
