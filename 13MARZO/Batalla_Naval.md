# Batalla Naval
## Descripción
El siguente codigo es la creacion de un juego de batalla naval por turnos creado en C, los jugadores diran las coordenadas del oponente y se mostrara de forma grafica si se le dio o no al barco. 

## Requisitos
1. El tablero será de tamaño 5 x 5.
2. Cada posición puede representar:

    - 0 = agua
    - 1 = barco
    - 2 = disparo fallido
    - 3 = impacto

3. Pedir nombre del jugador
4. Mostrar nombre en cada turno
5. Asignar nombre a cada barco
6. Mostrar mensaje personalizado cuando impacte
7. Mostrar mensaje final

## Implementación

```C
#include<stdio.h>
#include<stdlib.h> // Se añadio esta libreria para hacer uso del valor absoluto abs()
#include<string.h> // Lo utilizamos para manejar cadenas de caracteres string

/////////////// VARIABLES ////////////////////

int N = 5;
int M = 5;

int W = 2;
int Z = 20;

char barco_chico[20]= "FRAGATA";
char barco_grande[20]= "DESTRUCTOR";
```
Las variables `N` y `M` dictaminan el tamaño del tablero para que si en el futuro se quiere expandir no se tenga que cambiar todas las variables de juego.

Las variable `W` dice el numero de jugadores mientras que `Z` es el tamaño del nombre que se guardara en la lista de jugadores.

Los dos posteriores arreglos solo guardan el nombre de los dos barcos disponibles durante en el juego.

```c
///////////// FUNCION INICIADOR /////////////////////

void iniciador(int N,int M,int tablero[N][M]){
    for(int i=0; i<N; i++){
        for(int l=0; l<M; l++){
            tablero[i][l] = 0;
        }
    }
    printf("Loading.....\n");
}
````
La funcion iniciador lo que hace es colocar el tablero del jugador en ceros, esto mediante un arreglo de bidimensional que sera por filas y columnas del tamaño antes definido, este arreglo se declaro como `int tablero [N][M]` como parametro formal.

Usando un `for` para las filas y otro `for` para las columnas con sus respectivas variables `i` y `l` pasamos por cada una de las coordenadas del arreglo guardando el valor 0, imprimiendo un mensaje `"Loading....."` cuando el proceso haya concluido.
````c
/////////////// FUNCION GRAFICA //////////////////////

void grafica(int N,int M,int tablero[N][M]){
    printf("\n");
    for(int i=0; i<N; i++){
        for(int l=0; l<M; l++){
            printf("\t%d",tablero[i][l]);
        }
        printf("\n");
    }
}
````
La funcion de la grafica funciona de forma similar a la funcion del iniciador con el uso de los `for` para pasar por todos los valores del arreglo `ìnt tablero [M][N]` e imprimirlos en pantalla. Usamos `printf("\t%d",tablero[i][l]);`para imprimir cada valor de la columna siendo sepadaro por un tab `\t` luego utilizamos un `printf(\n);` para dar un salto de linea cuando todos los valores de la columna han sido impresos, asi hasta completar las filas.

> [!NOTE]
Fijese que el for externo es el de las filas y el for interno es el de las columnas, de ser alreves se imprimiriá girado el tablero.

```
////////////// FUNCION DE VALIDACION DE COORDENADAS /////////////////

int validacion(int x,int y,int N,int M){
    if(x >= 0 && x < N && y >= 0 && y < M){
        return 1;
    } else {
        return 0;
    }
}
```




