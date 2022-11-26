En el grupo se usa la la función CrearVectorRegistros(CapacidadInicial) para obtener un vector de punteros a registros, con el fin de usarlo para cargar la partición con el al crearla , o bien cuando haga falta redimensionar y se necesite tener el vector redimensionado.

Yo no hago y esas dos líneas de código las pongo directamente.

En ObtenerRegistro() el grupo usa ObtenerRanking , que lo hace es justamente realizar la búsqueda binaria sobre el array de registros y devolver el indice del registro que tenga el identficador buscado.  Eso me parece bien

### Análisis de ObtenerRanking.

Chequear por registros marcados como NULL:
Si se usa la idea de marcar con null aquellas elementos del vector de registros que ya se eliminaron, entonces antes de hacer la busqueda si tendria que chequear esto para no intentar consultar por el campo identificador de un registro que sea null porque se 
eliminó

Sacando esto la busqueda estaría bien.

### Otras dudas más de diseño.

ObtenerRanking está bien que se agregue al TDAParticion? . ¿No es en realidad una función "interna" que usamos para las otras operaciones del TDA  , la pregunta es si es necesario que este disponible para el cliente eso (en la interfaz).

OTra ¿ puedo dejar un espacio de vector con null y reasignarlo?
Podria ser y cuando vamos a eliminar el registro guardar su id en un vector de id libres.

Cuestion :

Cuando se llama a destruir un registro , tenemos que hacer una redimension a un tamaño menor por un elemento.
Es decir copiamos lo que estaba antes y despues del registro a eliminar en otro vector de una unidad menos.




