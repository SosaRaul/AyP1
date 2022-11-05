Colecciones / Colecciones dinámicas
    - Listas -> Estructura de datos secuencial -> O(N)
    - Vectores red





Los diccionarios son estructuras de búsqueda.
Cuando necesitemos buscar items es lo más adecuado
Lo podemos implementar de distinas maneras:
-Implementaciones elementales : usas listas y vectores(búsqueda binaria).
-Implementaciones No elementales : usan tablas de hashing,árboles balanceados.

Los diccionarios realizan una abstracción sobre los conceptos clave y valor.

Como en toda colección queremos agregar un item.

Coleccion
-Agregar
-Quitar/Obtener/Están o no estan items.
Item Obtener()

Diccionario : colección de elementos del tipo key-value
donde cada clave es única. Los valores si pueden estar
repetidos.

**Los diccionarios(symbol tables) son una generalización de un vector**

Acceso aleatorio : la operación de acceder un elemento cuando se sabe donde está es de 0(1) cte.

Acceso secuencial : O(N)

El objetivo es acceder como un vector(rápido) en los diccionarios.

Acordarse que si un puntero no modifica nada poner "const" adelante de él en las firmas de las funciones.

--------------------
Vectores redimensionables (mejor implementación para tp) . Ellos buscan amortiguar el peor caso.
Al tener que redimensionar , redimensionan por el doble

Hacemos un vector que siempre tiene el mismo tamaño que la cantidad de elementos.

El mejor es búsqueda binaria.

---

Quedó pendiente para la clase del sábado 5 complementar la implmentación del diccionario.
Comparar como mejora con el algoritmo de búsqueda binaria la i
