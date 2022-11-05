Implementar los módulos registro y partición.

La partición es una instancia de la base de datos, un servidor etc
La partición tiene todo los estudiantes de algoritmos.
Cada estudiante es un registro.

En el main usa una función creacional para crear la partición.
 Crear(1000,1010)
Luego va agregando registros(estudiantes) a la partición.

Una partición tiene una colección de registros. La partición va a establecer el identificador de los registros 
a partir de un rango. Cuando se crea una partición se debe especificar el rango de la partición.
Entonces al crearse la partición está vacía pero conoce cual es su rango.


Consultas:

¿qué sería una partición no válida?

Una partición que los valores del rango tuvieron alguna inconsistencia que no permitió que la 
partición se genere. Por lo que entonces quedó en null. En realidad no hacía falta chequear
si el contenido es null porque en la función creacional ya directamente no llegaría a esa parte.

Otra es en la función de búsqueda.
Al usar inicioRango como índice de búsqueda, si se borra u