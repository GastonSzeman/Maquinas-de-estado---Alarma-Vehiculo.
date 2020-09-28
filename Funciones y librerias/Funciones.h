int principal(void){
	int opc;
	printf("***ESTADO INICIAL.***\n\n");
	printf("1 - Alarma en alerta.\n");
	printf("2 - Alarma apagada.\n");
 	printf("3 - Alarma disparada.\n");
 	printf("4 - Salir del programa.\n");
 	printf("\n\nElija una opcion.\n");
 	 scanf("%d",&opc);
 	  
	   return opc;
}

sensores_t apagada(void){
	int opc;
	sensores_t sensor;
	
	do{
	printf("***ALARMA APAGADA.***\n\n");
	printf("1 - Mostrar valores iniciales.\n");
	printf("2 - Modificar valores.\n");
	printf("3 - Salir.\n");
	printf("\nElija una opcion: ");
	 scanf("%d",&opc);
	 switch(opc){
	 	case 1:
	 		system("cls");
	 		if((p_alarma=fopen("config.conf","rb"))==NULL){
	 			printf("No se ha podido encontrar el archivo de configuracion inicial.\n");
	 			 exit(1);
			 }
	 		fread(&sensor,sizeof(sensores_t),1,p_alarma);
	 	   	 while(!feof(p_alarma)){
	 	    	printf(" 0 = SENSOR APAGADO --- 1 = SENSOR PRENDIDO.\n\n");
	 			 printf("Baul = %d.\n",sensor.baul);
				 printf("Capot = %d.\n",sensor.capot);
	 			 printf("Puertas = %d.\n",sensor.puertas);
	 			 printf("Velocidad = %d.\n",sensor.velocidad);
	 			 fread(&sensor,sizeof(sensores_t),1,p_alarma);
	 		  	  system("pause");
			  	}	
			  	fclose(p_alarma);
	 		 	 break;
		case 2:
			system("cls");
			 sensor = modificar(0);
			 break;
		case 3:
			system("cls");
		 	exit(1);
			  break;
		default:
			system("cls");
		  	printf("Opcion incorrecta. Vuelva a intentarlo.\n");
			  break;	  	  	
	 }
	 fclose(p_alarma);
	 }while(opc!=3);
	 
	return sensor;
}

sensores_t alerta(void){
	
	int opc;
	
	sensores_t sensor;
	
	 do{	
	   printf("***ALARMA EN ALERTA.***\n\n");
	   printf("1 - Mostrar valores iniciales.\n");
	   printf("2 - Modificar valores.\n");
	   printf("3 - Salir.\n");
	   printf("\nElija una opcion: ");
	    scanf("%d",&opc);
	 switch(opc){
	 	case 1:
	 		system("cls");
	 		if((p_alarma=fopen("config.conf","rb"))==NULL){
	 			printf("No se ha podido encontrar el archivo de configuracion inicial.\n");
	 			 exit(1);
			 }
	 		fread(&sensor,sizeof(sensores_t),1,p_alarma);
	 	   	 while(!feof(p_alarma)){
	 	    	printf(" 0 = SENSOR APAGADO --- 1 = SENSOR PRENDIDO.\n\n");
	 			 printf("Baul = %d.\n",sensor.baul);
				 printf("Capot = %d.\n",sensor.capot);
	 			 printf("Puertas = %d.\n",sensor.puertas);
	 			 printf("Velocidad = %d.\n",sensor.velocidad);
	 			 fread(&sensor,sizeof(sensores_t),1,p_alarma);
	 		  	  system("pause");
			  	}	
			  	fclose(p_alarma);
	 		 	 break;
		case 2:
			system("cls");
			 sensor = modificar(1);
			 break;
		case 3:
			system("cls");
		 	exit(1);
			  break;
		default:
			system("cls");
		  	printf("Opcion incorrecta. Vuelva a intentarlo.\n");
			  break;	  	  	
	 }
	 fclose(p_alarma);
	 }while(opc!=3);
	 
	return sensor;
}

sensores_t disparada(void){
	
	sensores_t sensor;
	
	int opc;
	
	do{	
	 printf("***ALARMA DISPARADA.***\n\n");
	 printf("1 - Mostrar datos.\n");
	 printf("2 - Modificar datos.\n");
	 printf("3 - Salir.\n");
	  scanf("%d",&opc);
	 	switch(opc)
	 	{
	 	case 1:
	 		 	system("cls");
	 			if((p_alarma=fopen("config.conf","rb"))==NULL){
	 		    	printf("No se ha podido encontrar el archivo de configuracion inicial.\n");
	 			     exit(1);
					 }
	 			 fread(&sensor,sizeof(sensores_t),1,p_alarma);
	 	   		  while(!feof(p_alarma)){
	 	    	  printf(" 0 = SENSOR APAGADO --- 1 = SENSOR PRENDIDO.\n\n");
	 			  printf("Baul = %d.\n",sensor.baul);
				  printf("Capot = %d.\n",sensor.capot);
	 			  printf("Puertas = %d.\n",sensor.puertas);
	 			  printf("Velocidad = %d.\n",sensor.velocidad);
	 			   fread(&sensor,sizeof(sensores_t),1,p_alarma);
	 		  	    system("pause");
			  	}
			  	 fclose(p_alarma);
	 		 	  break;
	 	case 2:
	 		 system("cls");	
	 		 sensor = modificar(0);
		  	  break;
		case 3:
			  system("cls");	
			  exit(1);
			   break;
		default:
			 system("pause");	
			 printf("Opcion incorrecta. Vuelva a intentarlo nuevamente.\n");
			  	break;
			}
	    }while(opc!=3);
	    
	return sensor;
}

void historial(int x){
	
	time_t horario;
	time(&horario);
	FILE *p_historial;
	int opc;
	char causa[35];
	opc=x;
	
	switch(opc){
		 case 1:
		 	if((p_historial=fopen("Historial.txt","at"))==NULL){
		 		printf("No se ha podido crear el historial de la alarma.\n");
		 		 exit(1);
			 }
			 fputs("Se ha modificado el sensor BAUL.\n\n",p_historial);
			 fputs("Datos: ",p_historial);
			 fputs(ctime(&horario),p_historial);
			 fputs("\t----------------------------------------\n",p_historial);
			 system("pause");			 
			fclose(p_historial); 
		  	break;
		 case 2:
		 	if((p_historial=fopen("Historial.txt","at"))==NULL){
		 		printf("No se ha podido crear el historial de la alarma.\n");
		 		 exit(1);
			 }
			 fputs("Se ha modificado el sensor CAPOT.\n\n",p_historial);
			 fputs("Datos: ",p_historial);
			 fputs(ctime(&horario),p_historial);
			 fputs("\t----------------------------------------\n",p_historial);
			 system("pause");			 
			fclose(p_historial); 
		  	break;
		 case 3:
		 	if((p_historial=fopen("Historial.txt","at"))==NULL){
		 		printf("No se ha podido crear el historial de la alarma.\n");
		 		 exit(1);
			 }
			 fputs("Se ha modificado el sensor PUERTA.\n\n",p_historial);			 
			 fputs("Datos: ",p_historial);
			 fputs(ctime(&horario),p_historial);
			 fputs("\t----------------------------------------\n",p_historial);
			 system("pause");			 
			fclose(p_historial); 
		  	break;
		 case 4:
		 	if((p_historial=fopen("Historial.txt","at"))==NULL){
		 		printf("No se ha podido crear el historial de la alarma.\n");
		 		 exit(1);
			 }
			 fputs("Se ha modificado el sensor VELOCIDAD.\n\n",p_historial);			 
			 fputs("Datos: ",p_historial);
			 fputs(ctime(&horario),p_historial);
			 fputs("\t----------------------------------------\n",p_historial);
			 system("pause");			 
			fclose(p_historial); 
			 break;	 	  	   	
	}
}

sensores_t archivo(int x){
 	
	 int opcion;
	 
	sensores_t sensor;
 	
 	opcion=x;
	
	
	if((p_alarma=fopen("config.conf","wt"))==NULL){
		system("cls");
		printf("No se ha podido crear el archivo de configuracion.\n");
		 exit(1);
	}
	//Pongo valores iniciales en los sensores del vehiculo dependiendo de la opcion elegida.
	srand(time(NULL));
	 if(opcion == 1 || opcion == 2){
		sensor.baul = 0;
		sensor.capot = 0;
		sensor.puertas = 0;
		sensor.velocidad = 0;
	 	 fwrite(&sensor,sizeof(sensores_t),1,p_alarma);
	  	  fclose(p_alarma);
	  }
	  else if(opcion == 3){
	  	sensor.baul = rand()%2;;
	  	sensor.capot = rand()%2;;;
		sensor.puertas = rand()%2;;
		 if(sensor.baul && sensor.capot && sensor.puertas){
		 	sensor.velocidad=0;
		 }
		 else{
		sensor.velocidad = rand()%2;
	    }
		 fwrite(&sensor,sizeof(sensores_t),1,p_alarma);
	  	   fclose(p_alarma);
	  }
	  return sensor;
}

sensores_t modificar(int x){
	
	sensores_t sensores;
	
	int modificar,flag=x;
	
			printf("***MODIFICAR VALORES.***\n\n");
			printf(" 0 = SENSOR APAGADO --- 1 = SENSOR PRENDIDO.\n\n");
			printf("1 - modificar sensor de baul.\n");
			printf("2 - Modificar sensor de capot.\n");
			printf("3 - Modificar sensor de puertas.\n");
			printf("4 - Modificar sensor de velocidad.\n");	 
			printf("5 - Salir.\n");
			  scanf("%d",&modificar);
			   fflush(stdin);
			    if((p_alarma=fopen("config.conf","wb+"))==NULL){
			    	system("cls");
					printf("No se ha podido crear el archivo de configuracion inicial.\n");
			    	 exit(1);
				}
				if(flag){
				  historial(modificar);
				  }
			    	switch(modificar){
			    		case 1:
							system("cls");
							sensores.baul = !sensores.baul;
							printf("***SENSOR DEL BAUL MODIFICADO.***\n");
							fwrite(&sensores,sizeof(sensores_t),1,p_alarma);
							fclose(p_alarma);
							 system("pause");
							 system("cls");
							  break;
			    		case 2:
							system("cls");
							sensores.capot = !sensores.capot;
							printf("***SENSOR DEL CAPOT MODIFICADO.***\n");
							fwrite(&sensores,sizeof(sensores_t),1,p_alarma);
							fclose(p_alarma);
						 	 system("pause");
						 	 system("cls");
							  break;
						case 3:
							system("cls");
							sensores.puertas = !sensores.puertas;
							printf("***SENSOR DE LAS PUERTAS MODIFICADO.***\n");
							fwrite(&sensores,sizeof(sensores_t),1,p_alarma);
							fclose(p_alarma);
			    			 system("pause");
			    			 system("cls");
							  break;
						case 4:
							system("cls");
							sensores.velocidad = !sensores.velocidad;
							printf("***SENSOR DE VELOCIDAD MODIFICADO.***\n");
							fwrite(&sensores,sizeof(sensores_t),1,p_alarma);
							fclose(p_alarma);
							 system("pause");
							 system("cls");
							  break;
						case 5:
							system("cls");
							exit(1);
							break;
						default:
							system("cls");
							 printf("Opcion incorrecta. Vuelva a intentarlo.\n");
							 system("cls");
						   	  system("pause");
							   break;				 	
					}
			fclose(p_alarma);
			
	return sensores;
}
