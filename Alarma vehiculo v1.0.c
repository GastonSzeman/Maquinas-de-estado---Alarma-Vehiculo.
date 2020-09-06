#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int capot,baul,puertas;
	float velocidad;
}sensores_t;

int Menu(void);
void CreaArchivo(void);
void Agrega(void);
void Muestra(void);
void Modifica(void);

FILE *alarma;

sensores_t sensores;

int main(){
	int a;
	CreaArchivo();
	Agrega();
	a=Menu();
	do{
	if(a==3){
		return 1;
	}
	switch(a){
		case 1:
			system("cls");
			 Muestra();
			  break;
		case 2:
			system("cls");
			 Modifica();
			  break;
		default:
			system("cls");
			 printf("Opcion incorrecta.\n");
			  break;
		}
	  }while(a!=3);
	return 0;
}

void CreaArchivo(void){
	if((alarma=fopen("config.dat","wb"))==NULL){
		printf("No se ha podido crear el archivo de configuracion.\n");
		 return ;
	}
	fclose(alarma);
	}

void Agrega(void){
	if((alarma=fopen("config.dat","ab"))==NULL){
		printf("No se han podido cargar los datos iniciales.\n");
	}
	//0 = Sensores en alerta | 1 = Sensores activados.
	sensores.baul=0;
	sensores.capot=0;
	sensores.puertas=0;
	sensores.velocidad=0;
	fwrite(&sensores,sizeof(sensores_t),1,alarma);
	fclose(alarma);
}

int Menu(void){
	int opc;
	printf("---ALARMA DE VEHICULO.---\n");
	printf("1 - Mostrar valores iniciales.\n");
	printf("2 - Modificar algun parametro.\n");
	printf("3 - Salir del programa.\n");
	printf("Opcion: ");
	 scanf("%d",&opc);
	 return opc;
}

void Muestra(void){
	system("cls");
	if((alarma=fopen("config.dat","rb"))==NULL){
		printf("No se ha podido leer el archivo.\n");
	}
	fread(&sensores,sizeof(sensores_t),1,alarma);
	printf("---Valores iniciales.---\n");
	while(!feof(alarma)){
		printf("Puertas: %d.\nCapot: %d.\nBaul: %d.\nVelocidad: %.2f(km/h).\n",sensores.puertas,sensores.capot,sensores.baul,sensores.velocidad);
		 fread(&sensores,sizeof(sensores_t),1,alarma);
	}
	fclose(alarma);
	system("pause");
}

void Modifica(void){
	system("cls");
	int dato,opc;
	printf("---Modificacion de datos.---\n\n");
	printf("1 - Puertas.\n2 - Capot.\n3 - Baul.\n4 - Velocidad.\n5 - Salir.\n\nElija una opcion: ");
	 scanf("%d",&dato);
	 switch(dato){
		  	case 1://Puertas.
		  		system("cls");
		  		 if((alarma=fopen("config.dat","ab"))==NULL){
		  		 	printf("No se ha podido abrir el archivo de estado inicial.\n");
		  		 	 exit(1);
				   }
				  printf("(---Puertas abiertas = 1 | Puertas cerradas = 0.---)\n");
				  printf("---Modificacion de valores.---\n");
				   fread(&sensores,sizeof(sensores_t),1,alarma);
				    printf("\nEstado actual de las puertas = %d.\n",sensores.puertas);
					printf("1 - Modificar valor.\n");
					printf("Otro - Volver.\n");
					 scanf("%d",&opc);
					  if(opc==1){
					  	sensores.puertas=1;
					  	while(1){
					  	  if(opc!=1){
					  	  	 break;
							}
						  printf("***ALARMA SONANDO.***\n");
						  printf("\nCAUSA: Puerta/s abierta/s.\n\n");
						  printf("1 - Seguir sonando.\n");
					  	  printf("Otro - Detener alarma.\n");
					  	 scanf("%d",&opc);
					  		}
						  }
					  if(opc!=1){
					  	fclose(alarma);
					  	printf("***ALARMA EN ALERTA.***\n");
					  	 system("pause");
					  	break;
					  }
					fwrite(&sensores,sizeof(sensores_t),1,alarma);
					 fclose(alarma);
				break;
			case 2://Capot.
				system("cls");
		  		 if((alarma=fopen("config.dat","ab"))==NULL){
		  		 	printf("No se ha podido abrir el archivo de estado inicial.\n");
		  		 	 exit(1);
				   }
				  printf("(---Capot abierto = 1 | Capot cerrado = 0.---)\n");
				  printf("---Modificacion de valores.---\n");
				   fread(&sensores,sizeof(sensores_t),1,alarma);
				    printf("\nEstado actual del capot = %d.\n",sensores.capot);
					printf("1 - Modificar valor.\n");
					printf("Otro - Volver.\n");
					 scanf("%d",&opc);
					  if(opc==1){
					  	sensores.capot=1;
					  	while(1){
					  	  if(opc!=1){
					  	  	 break;
							}
						  printf("***ALARMA SONANDO.***\n");
						  printf("\nCAUSA: Capot abierto.\n\n");
						  printf("1 - Seguir sonando.\n");
					  	  printf("Otro - Detener alarma.\n");
					  	 scanf("%d",&opc);
					  		}
						  }
					  if(opc!=1){
					  	fclose(alarma);
					  	printf("***ALARMA EN ALERTA.***\n");
					  	 system("pause");
					  	break;
					  }
					fwrite(&sensores,sizeof(sensores_t),1,alarma);
					 fclose(alarma);
			 	break;
			case 3://Baul.
				system("cls");
		  		 if((alarma=fopen("config.dat","ab"))==NULL){
		  		 	printf("No se ha podido abrir el archivo de estado inicial.\n");
		  		 	 exit(1);
				   }
				  printf("(---Baul abierto = 1 | Baul cerrado = 0.---)\n");
				  printf("---Modificacion de valores.---\n");
				   fread(&sensores,sizeof(sensores_t),1,alarma);
				    printf("\nEstado actual del baul = %d.\n",sensores.baul);
					printf("1 - Modificar valor.\n");
					printf("Otro - Volver.\n");
					 scanf("%d",&opc);
					  if(opc==1){
					  	sensores.baul=1;
					  	while(1){
					  	  if(opc!=1){
					  	  	 break;
							}
						  printf("***ALARMA SONANDO.***\n");
						  printf("\nCAUSA: Baul abierto.\n\n");
						  printf("1 - Seguir sonando.\n");
					  	  printf("Otro - Detener alarma.\n");
					  	 scanf("%d",&opc);
					  		}
						  }
					  if(opc!=1){
					  	fclose(alarma);
					  	printf("***ALARMA EN ALERTA.***\n");
					  	 system("pause");
					  	break;
					  }
					fwrite(&sensores,sizeof(sensores_t),1,alarma);
					 fclose(alarma);
			 	break;
			case 4://Movimiento.
				system("cls");
		  		 if((alarma=fopen("config.dat","ab"))==NULL){
		  		 	printf("No se ha podido abrir el archivo de estado inicial.\n");
		  		 	 exit(1);
				   }
				  printf("(---Vehiculo estacionado = 0 | Vehiculo en movimiento = 1.---)\n");
				  printf("---Modificacion de valores.---\n");
				   fread(&sensores,sizeof(sensores_t),1,alarma);
				    printf("\nEstado actual del capot = %d.\n",sensores.velocidad);
					printf("1 - Modificar valor.\n");
					printf("Otro - Volver.\n");
					 scanf("%d",&opc);
					  if(opc==1){
					  	sensores.velocidad=1;
					  	while(1){
					  	  if(opc!=1){
					  	  	 break;
							}
						  printf("***ALARMA SONANDO.***\n");
						  printf("\nCAUSA: Vehiculo en movimiento.\n\n");
						  printf("1 - Seguir sonando.\n");
					  	  printf("Otro - Detener alarma.\n");
					  	 scanf("%d",&opc);
					  		}
						  }
					  if(opc!=1){
					  	fclose(alarma);
					  	printf("***ALARMA EN ALERTA.***\n");
					  	 system("pause");
					  	break;
					  }
					fwrite(&sensores,sizeof(sensores_t),1,alarma);
					 fclose(alarma);
				break;
			case 5:
			 	break;
			default:
				printf("Valor ingresado incorrecto.\n");
				 break;
	  		}
		}
