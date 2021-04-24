| | |
| :-----------: | -------------: |
| ![](https://www.unirioja.es/imagenes/cabecera/cabecera_r1_c1.gif) | Metodologías avanzadas de programación para la ciencia de datos <br> Máster universitario en Ciencia de Datos y Aprendizaje Automático <br> Curso 2020 / 2021 |
| Fecha:   24 / 04 / 2021 | Nombre DIEGO POLO BENITO |

## Introduccion a OpenMP

OpenMP (Open MultiProcessing) es un modelo de programación paralela basado en directivas del compilador que permite añadir paralelismo al código.vConsiste en un conjunto de directivas del compilador #pragma, rutinas y variables de entorno que influyen en el comportamiento en tiempo de ejecución. Está disponible para Fortran, C y C++

La compilación se realiza con un compilador de C o C++ añadiendo el argumento `-fopenmp`

El código de la práctica esta disponible en [https://github.com/dpolob/mapcd-openmp.git](https://github.com/dpolob/mapcd-openmp.git)

### HelloWorld

Se usa la directiva #pragma omp parallel para indicar en comienzo de una sección de código que se ejecutará en N hilos paralelos. La gestion de las variables en la  memoria puede realizarse de las siguiente manera:

- `private`: cada hilo tiene una copia local
- `firstprivate`: la variable tiene una copia local pero es inicializada al principio
- `omp_set_num_threads` Define el numero de hilos a usar.
- `omp_get_num_threads` Obtiene el numero de hilos que se usan.
- `omp_get_thread_num` Devuelve el identificador del hilo actual.

## For paralelo

Es posible paralelizar un bucle for usando
`#pragma omp for` 
e indicando al compilador la forma de gestionar como se gestionan los hilos mediante schedule que puede ser de varios modos

- `static` recibe por parámetro el numero de iteraciones que reparte a cada hebra y reparte hasta que se queda sin iteraciones.
- `dinamic` recibe por parámetro el numero de iteraciones por bloque. Cuando una hebra se queda sin trabajo pide un nuevo bloque, así hasta que no hay mas iteraciones.
- `guidec` recibe por parámetro el numero mínimo de iteraciones por bloque. Actúa por demanda como el planificador dinamic pero el decide el tamaño de bloque inicial, y lo va reduciendo hasta el tamaño mínimo pasado por parametro.
- `auto` la planificación se deja en manos del sistema, no se pasan parametros.

## Calculando PI

En estos ejercicios se ve como compartir la memoria entre hebras algunas veces puede traer problems por lo que algunas veces es necesario indicar expresamente que zonas deben ejecutarse unicamente por una sola hebra, para ello se puede usar:
`# pragma opm critical` La construcción critital restringe la ejecución asociada al bloque por una sola hebra al mismo tiempo.
`# pragma opm atomic` La construcción atomic asegura que una variable se actualiza automáticamente, expone a la posibilidad de múltiples y simultáneas escrituras.
`# reduction` se usa de la misma forma que para definir variables. Declara una acumulación a partir de una lista de elementos usando un operador asociativo indicado. La acumulación ocurre en la copia privada de cada elemento de la lista cuales son combinados con el elemento original.

## Secciones

Hay que añadir `#include <unistd.h>` para que se pueda usar `sleep()`
Si un programa que realiza dos tareas ejecutadas secuencialmente, se puede  tener una ejecución mas rápida si ejecutamos las dos tareas a la vez, OpenMP permite esto mediante las _sections_, secciones de código ejecutadas por un único hilo.
OpenMP sincroniza los hilos hasta que terminen todos pero con la directiva _nowait_ se puede eliminar esta sincronizacion.

Si el numero de hilos es diferente al de sections el sistema reparte las sections. Si hilos es mayor sections hay hilos ociosos, si hilos es menor que sections se van ejecutando las sections a medida que van ejecutando a medida que otras van acabando.

## Coste de las hebras

A veces solo es necesario paralelizar aquellas operaciones que merezca la pena hacerse en paralelo por su coste computacional, teniendo en cuenta que la paralelización penaliza la ejecución al tener que crear los hilos y puede ser mas rapido no paralelizar.
En los ejemplos se puede ver con un ejemplo como para vectores de tamaño pequeño es mas costosa la parelelización que el proceso secuencial. Se puede controlar si un proceso se paraleliza o no mediante la directiva `#pragma omp parallel if (_variable condicion_)`

## Conclusiones
OpenMP me parece una forma cómoda de paralelizar código y parece bastante sencilla de usar. Parece versátil ya que dota de muchos mecanismos y funciones al programador y además de una forma transparente para este.
