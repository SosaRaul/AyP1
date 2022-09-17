---
Agenda Clase 17-09

Punteros
-Memoria dinámica

Recursividad
--programación dinámica
--buen cierre


Tips para recursividad
-Asegurar que la recursividad termina
-Limitar la recursividad a una sola rutina

Tener en cuenta el stack
- No usar para fibonnaci o factorial o ....


Dynamic programming

---

Tiene que ver con tomar un algoritmo tonto que hace fuerza bruta (divide and conquer también) y agregarle un buffer o memorizador para
guardar las cosas para que no las vuelva a recaluclar.También se puede usar una pila.
La idea es transformar el algoritmo recursivo tonto en uno bueno si tener que sacar la recursividad


Hay punteros constantes y punteros a valores constantes
Los punteros constantes no sirven para nada

Los punteros a valores constante se declaran de la siguiente manera

const *pAlgo;

Nadie va a poder modificar lo que está apuntando el puntero

La función así garantiza que no modifica cosas con la firma void foo(const *namePointer);

En los lenguajes de programación de más alto nivel o más modernos aunque no se diga todo son punteros.

Funciones que reciben estructuras todas van con puntero a la estructura
Si esa función en su post condición no modifica , entonces tiene que ser const *namePointer
Si es puntero a constante, fijarse que adentro de esa función no se llama a algo que no es puntero a constante entonces no va a compilar.


Como tarea mejorar las funciones que tenian pasaje de puntero y pensar si realmente se necestia modificar lo que se pasa
como parametros . Sino se tiene que cambiar a puntero a const

Puntero es un tipo de variable que sirven para "traer" instancias

En el HEAP el programador puede controlar la memoria. Puede reservar y liberar la memoria.

Eso no pasa en el stack

New para un tipo de dato dado reserva esa cantidad de memoria en el heap.

Memory Leak : Cuando el programador se olvida de liberar cierta cantidad de memoria.

Cuando se acaba el programa se libera todo

Con delete se libera la memoria. La precondición para delete es que lo se esté tratando de liberar este asignado en el heap.
Con delete no se puede liberar cosas del stack. Tampoco dos delete a lo mismo. Por cada new tiene que haber un delete.

En los lenguajes modernos todo está en el heap. Y los lenguajes solos la liberan(Garbage collector)

Puntero es el tipo de dato más importante de C y C++

Hay que dominar punteros.

Poscondición para CrearCarta
Devuelve una instancia válida de Carta.(si o si siempre va a ser una variable de tipo Carta)

Un tipo de dato define los valores que se le puede asignar(valores válidos) y las operaciones que se pueden realizar sobre ellos

Patrón de funciones creacionales

Cuando se esta programando diseñando tipos de datos

Se necesita de funciones creacionales/factory methods(devuelve puntero a tipo de dato9 para saber que obtenemos un tipo de dato válido
Para indicar que no se pudo crear algo válido se devuelve NULL.
Puede también devolverse excepciones.

Patrón de diseño
-nombre
-descripcion de problematica que reseuvle
-descripcion de como encarar la solución

Acá el patrón diseño es :
- nombre : Factory method o Funciones creaciones
- problema que resuelve : Crear instancias válidas de un tipo de dato.
- solución : Resuelve el problema de tener muchos tipos de datos creados en muchos lados

guía de ejercicios tiene 2 partes : punteros en un stack
punteros en heap.

Dibujando en el stack sale todo

Los patrones de diseño están para resolver problemas que se repiten muchas veces.
la funcion creacional debe validar todas las reglas del dominio.

Para que tenga beneficio la idea es que

constructores -> funciones creacionales
objeto -> instancia

Hacer la función creacional para crear un comodin

constructor -> factory method

el constructor no puede devolver una instancia no valida

Eso no hay que hacerlo (mal programador)

Parcial el 6/10

Langford subir el domingo


