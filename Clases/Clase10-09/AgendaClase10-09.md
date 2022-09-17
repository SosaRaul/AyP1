Obtener el máximo número de un vector usando recursividad y teniendo en cuenta indice inicial y final
Ejemplo: [2, 3, 10, 4, 11], 0, 4 => 11
Ejemplo: [3, 2, 18, 1, 11], 1, 4 => 18
Ejemplo: [3, 2, 18, 1, 2], 3, 4 => 2

El código cliente debe asegurarse de cumplir la precondición

Subir implementaciones de la recursividad de los ejercicios vistos en clase.

----

#### Agenda Clase10-09

Ejercicios Recursivdad 

Divide & conquer + recursividad ( Problema de la mochila )

Punteros I  
- Programa 
- Procesos


Invariantes

----

Problema de la mochila
Poscondición => Se asegura que el resultado es EL máximo botin.

El problema es que la única manera de establecer el mejor botin sería probando todas las combinaciones posibles de peso y valor de cada item.

Items
-int peso
-char codigoItem
-int valor ($)

Mochila soporta cierta cantidad de peso máximo.

Pensar cual sería la máxima ganancia con estos ejemplos.

Item A : 4Kg , $25
Item B : 10Kg, $80
Item C : 14Kg , $90
Item D : 2Kg, $1

----

Punteros I 

Definición de Bjarne : 


Para un tipo T , T* es una variable puntero a T que puede tener direcciones de memoria de instancias de tipo T.

- Un puntero es una variable que guarda direcciones de memoria.

Conceptos a definir : 
-Tiempo de ejecución : cuando se empieza a ejecutar
-Tiempo de compilación : 
-Programa : Código fuente que compila.
-Proceso : cuando el programa se está ejecutando. La instancia en tiempo de ejecución . El S.O toma proceso del proceso

## Administración de la memoria en tiempo de ejecución 
El sistema operativo le da al proceso un espacio de memoria para que utilice. El proceso no se puede salir de ese espacio -memoria protegida-

Programa de consola de aplicación si o si deben tener una firma como las siguientes para ejecutarse. Es la función que llama el intérprete de comando para que comience la ejecución
int main(void);
int main(char **argv, int argc);

En la declaración de la variable , lo que hace es reservar una dirección de memoria en el stack. En ese momento el contenido de es basura que había en ese instante. 

Cuando se llama a la función , se arma el "stack de la función". Reserva memoria para los parámetros.
En c y c++ todos los parámetros se pasan por valor , es decir se copia el valor de los pasajes(valores) pero la instancia es otra. Justamente por ello al armarse stack reserva memoria para los parámetros. Están en bloques de memoria distintos respecto a las variables que se pasaron como parámetro a esa función.


Al terminar de ejecutarse el algoritmo de la función , se libera el stack de la función.
El stack trabaja en tiempo de ejecución.

cout siempre muestra el valor que tiene una variable

Si declaro un puntero que a un tipo , no puedo asignarle la dirección de una variable de otro tipo.

Operación de fetch en memoria . Ir y traer el valor que está guardado en la dirección de memoria.

Con el puntero modificar variables que están en otro bloque del stack








