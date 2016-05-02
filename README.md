## Memoria Cache

Este proyecto consiste en una simulación de una memoria cache, que fue solicitada para el curso de Estructuras Digitales II de la Universidad de Costa Rica.

## Compilación

Para compilar se utlizó el complidador de GNU para C++ (GNU Compiler Collection). Se probó en una distribución de debian, pero debería funcionar en cualquier distribución de Linux (o incluso windows) utilizadonda las herramientas adecuadas.

Solo es necesario clonar el repositorio, y luego utlizar el comando **make**.

## Ejecución del código
Es necesario tener el archivo **aligned.trace** en el mismo directorio que el archivo compilado **mi_cache**
La sintaxis del código viene dado por ./mi_cache [Asociativadad] [Tamaño del caché] [Tamaño del bloque] donde la asociatividad está definida como la cantidad de bloques por cada set, el tamaño del cache como el número de sets en el bloque y el tamaño del bloque como la cantidad de direcciones que almacena el cache.
## Contribuidores
- Francisco Mata Marín
- David Martínez García.

## Licencia

Este código puede ser distribuido utilizando GPL v3 o superior (a su elección).
