# Trabajo practico - Maquinas de estado.
# Alarma de vehículo.

  Aquí se verá cómo es la memoria descriptiva de mi trabajo practico.
  Este consiste en una alarma de un vehículo, y tendrá sensores las puertas, capot, baúl y un sensor de movimiento, los cuales se activarán mediante datos ingresados por teclado.

  La máquina de estado tendrá 3 opciones posibles, los cuales consistirán en:
 
 - Alarma en alerta: Aquí los sensores estarán en 0(cero), es decir, que no se han activado en algún momento anterior. El usuario podrá ver el estado inicial de la alarma en esta opción y podrá modificarlo a su gusto. Al estar en alerta, cuando uno de los sensores del vehículo cambia de estado (en este caso pasara de 0 a 1), la alarma comenzara a sonar y generara un archivo "historial.txt" con las modificaciones de los sensores mientras la alarma está en alerta, mostrando día y horario de la modificación de los sensores que han sido activados o desactivados. 

- Alarma apagada: Aquí, como en el caso anterior, los sensores también estarán inicialmente en 0(cero). El usuario podrá ver los estados de los sensores y podrá modificarlos a su gusto, pero no se generará un archivo que indique las modificaciones de los distintos sensores.	
- Alarma disparada: En este estado, los sensores del vehículo tendrán valores aleatorios. El usuario podrá ver los estados de los sensores para saber su causa de la activación de la alarma. Además, podrá modificarlos a su gusto también si lo desea.	

Dependiendo de la opción que el usiario desee, se creara un archivo de configuración inicial distinto.
