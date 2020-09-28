#include "MyLib.h"
#include "funciones.h"

int main(){
	
	sensores_t sensores;
	
	int opc;	
	
	opc=principal();
	
	sensores = archivo(opc);
	
	do{
		switch(opc){
		case 1:
			system("cls");
 		 	 sensores = alerta();
			  break;
		case 2:
			system("cls");
			 sensores = apagada();
		 	  break;
		case 3:
		 	system("cls");
			 sensores = disparada();
			  break; 	
		case 4:
			exit(1);
			 break;	
		default:
			system("cls");
		     printf("Opcion incorrecta. Vuelva a intentarlo.\n");	 	
		 	  break;
		} 	
	}while(opc!=4);
	
	return 0;
}
