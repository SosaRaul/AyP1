#include <iostream>
using namespace std;

int main(void){

	/* Formas de declarar e inicializar arrays */

	/* Declaración e inicialización al mismo tiempo : No hace especificar el tamaño del array
	 * entre [] puesto que el compilador lo determina en base a contar la cantidad de elementos
	 * con que lo estamos inicializando.
	 */
	char arrayCaracteres[] = {'a','r','y','\0'};
	// Se puede también especificar el tamaño al mismo tiempo que se lo inicializa, solo que si
	// es menor que la cantidad de elementos con los que se inicializa es mayor dara error.
	// En cambio si es más grande no dará error (prestar atención a esto y la basura que quede).

	/* Otra forma de declarar e inicializar una cadena de caracteres: Mediante string "Literales"
	 * Las secuencias encerradas entre "" son constantes literales.Estas agregan automáticamente
	 * el '\0' al final.
	 */
	char arrayCaracteresLiteral[] = "How are u doin'?";

	// Por lo que estas dos declaraciones y asignaciones son equivalentes
	char saludo[] = {'H','o','l','a','\0'};
	char saludo2[] = "Hola";

	// Recordemos que el unico momento que podemos asignar todos los elementos al array es solo
	// si lo hacemos al momento de la declaración. Luego solo es posible hacer de a un elemento
	// por vez!.

	cout << saludo <<endl;
	cout << saludo2;

	/* Las cadenas de caracteres tipo C y los strings de C++ son intercambiables entre sí
	 * y ambas se pueden usar con cin y cout . La ventaja es que usando string no necesitamos
	 * especificar la cantidad de caracteres ya que esto se determina dinámicamente al momento
	 * de ejecución . En cambio las cadenas tipo C , necesitan establecer su cantidad al
	 * momento de compilación ( antes de que se ejecute el programa.)
	 */

	return 0;
}

