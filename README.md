# Maquinas-de-estado---Alarma-Vehiculo.
  Trabajo practico - Maquinas de estado.

  Aquí se verá como es la memoria descriptiva de mi trabajo practico.
  Este consiste en una alarma de un vehiculo.

Esta tendrá sensores las puertas, capót, baúl y un sensor de movimiento.

  El diagrama muestra el ejemplo de la alarma "activada". En el momento en que se llegue a activar uno de los sensores, por ejemplo el de una puerta, se esperará cinco segundos hasta que se dispare dicha alarma. Estos cinco segundos son solo para que "el dueño" tenga tiempo de desactivarla en el caso de abrir la puerta y no haberla desactivado antes, y que esta no llegue a sonar.
  
  La variable FLAG indicará cuando cuando la alarma está activada o cuando esté disparada. A este tambien se le agrega que el tiempo de espera el cual verifica que sea menor a cinco segundos antes de sonar.

  Luego de todo esto se pregunta si quiere volver a activar la alarma para que esten los sensores nuevamente "atentos".

---Faltó agregar el tiempo de espera para la desactivación de la alarma.
