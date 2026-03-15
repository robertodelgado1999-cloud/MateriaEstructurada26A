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

```c
////////////// FUNCION DE VALIDACION DE COORDENADAS /////////////////

int validacion(int x,int y,int N,int M){
    if(x >= 0 && x < N && y >= 0 && y < M){
        return 1;
    } else {
        return 0;
    }
}
```

La funcion de validacion tiene como objetivo asegurase que el jugador en turno introduzca coordenadas validas dentro del juego pasando como parametros las variables `x` y `y` que representan las coordenadas x y y. Se pasan como parametros `N` y `M` que representan el tamaño del tablero.

Se utiliza un condicional `if(x >= 0 && x < N && y >= 0 && y < M)` que valida si las coordenadas son validas `x >= 0` primero valida que sean mayores o iguales a 0, `x < N` y luego que no sean mayores al tamaño del tablero, `y >= 0 && y < M` repitiendo lo mismo con el eje de las Y, se utiliza el operador `&&` para que se culmpla la condicional solo si todas se cumplen.

En caso de que las coordenadas sean validas la funcion regresara un 1 y de ser invalidas regresara un 0.

```c
//////////// FUNCION CAPTURA DE NOMBRES ///////////////
void nombres(char nombres[W][Z]){
    for (int i = 0; i < 2; i++){
        printf("\nIntroduce tu nombre jugador %d: ",i+1);
        fgets(nombres[i],sizeof(nombres[i]),stdin); 
        nombres[i][strcspn(nombres[i], "\n")] = '\0';
    }
}
```

Esta funcion se encarga de capturar los nombres de los jugadores en un arreglo llamado `char nombres[W][Z]` en un ciclo `for`.

Se imprime un mensaje para que los jugadores introduzcan sus nombres `printf("\nIntroduce tu nombre jugador %d: ",i+1);`

Despues se utiliza un `fgets(nombres[i],sizeof(nombres[i]),stdin);` para guardar los nombres en el arreglo `nombres[i]` le dice en que variable guardar lo capturado, `sizeof(nombres[i])` le dice el tamaño disponible de esa variable y `stdin` (input standard) de donde se obtendra los datos que en este caso se dice de los datos de la consola.

Para despues utilizar `nombres[i][strcspn(nombres[i], "\n")] = '\0';` para cambiar el salto de linea (enter) que fgets guarda al momento de que el jugador introduce su nombre. Basicamente `strcspn(nombres[i], "\n")`
escanea cada caracter introducido es decir `nombres[i]` y cuando encuentra el salto de linea `"\n"` lo que hace es devolver la posicion donde se encuentra ese salto del linea en el arreglo para posteriormente igualarlo a `'\0'` que es el caracter especial de c para terminar strings.

```c
////////////// FUNCION DE CAPTURA DE LOS BARCOS ////////////////////
void captura(int i,int N,int M,int tablero[N][M],char nombres[W][Z]){
    int x, y, temp_x, temp_y;
    int flag = 0;
    int bote1 = 777;
    int bote2[2]= {555,555};

    printf("\n--------------- %s coloca tu flota ----------------\n",nombres[i]);
    while(flag != 1){
        printf("\n%s dime la coordenada (x) del %s: ",nombres[i],barco_chico);
        scanf("%d",&x);
        printf("%s dime la coordenada (y) del %s: ",nombres[i],barco_chico);
        scanf("%d",&y);
        if (validacion(x,y,N,M) == 1){
            tablero[y][x] = bote1;
            printf("\nBARCO %s COLOCADO.\n",barco_chico);
            grafica(N,M,tablero);
            flag = 1;
        } else {
            printf("\nERROR: Esa coordenada no es posible.\n");
        }
    }

    flag = 0;
    while(flag != 1){
        printf("\n%s dime la primera coordenada (x) del %s: ",nombres[i],barco_grande);
        scanf("%d",&x);
        temp_x = x;
        printf("%s dime la primera coordenada (y) del %s: ",nombres[i],barco_grande);
        scanf("%d",&y);
        temp_y = y;
        if (validacion(x,y,N,M) == 1){
            if ((tablero[y][x]) == 0){
                tablero[y][x] = bote2[0];
                printf("\nPRIMERA COORDENADA GUARDADA!\n");
                grafica(N,M,tablero);
                flag = 1;
            } else {
                printf("\nEsa coordenada ya esta en uso!\n");
                grafica(N,M,tablero);
            }
        } else {
            printf("\nERROR: Esa coordenada no es posible.\n");
            grafica(N,M,tablero);
        }
    }
    flag = 0;
    while(flag != 1){
        printf("\n%s dime la segunda coordenada (x) del segundo bote:",nombres[i]);
        scanf("%d",&x);
        printf("%s dime la segunda coordenada (y) del segundo bote:",nombres[i]);
        scanf("%d",&y);
        if (validacion(x,y,N,M) == 1  && abs(temp_x - x) + abs(temp_y - y) == 1){
            if ((tablero[y][x]) == 0){
                tablero[y][x] = bote2[1];
                printf("\nBARCO %s COLOCADO.\n",barco_grande);
                flag = 1;
            } else {
                printf("\nEsa coordenada ya esta en uso!\n");
                grafica(N,M,tablero);
            }
        } else {
            printf("\nERROR: Esa coordenada no es posible.\n");
            grafica(N,M,tablero);
        }
    }
}
```
Esta funcion tiene como objetivo guardar las coordenadas donde cada jugador colocará sus barcos antes de empezar el juego.
### Variables 
```c
////////////// FUNCION DE CAPTURA DE LOS BARCOS ////////////////////
void captura(int i,int N,int M,int tablero[N][M],char nombres[W][Z]){
    int x, y, temp_x, temp_y;
    int flag = 0;
    int bote1 = 777;
    int bote2[2]= {555,555};
```
- `int i` Se pasa como parametro que le dice cual es el jugador que esta colocando su flota.
- `int tablero [N][M]` Es el tablero del jugador donde se guardaran los barcos.
- `char nombres[W][Z])` Es la lista de los nombres de los jugadores.
- `int x,y,` Son las variables donde se guardaran las coordenadas.        
- `temp_x,temp_y` Estas variables guardaran temporalmente las coordenadas x y y.
-`int flag = 0` Es la variable que mantiene el `while` hasta que se coloquen las coordenadas correctamente.
-`int bote1 = 777;` Es el valor del bote chico.
-`int bote2[1] = {555,555}` Es el valor del bote grande que en este caso se trata de un arreglo de tamaño 2.

### Colocación Barco Chico
```c
printf("\n--------------- %s coloca tu flota ----------------\n",nombres[i]);
    while(flag != 1){
        printf("\n%s dime la coordenada (x) del %s: ",nombres[i],barco_chico);
        scanf("%d",&x);
        printf("%s dime la coordenada (y) del %s: ",nombres[i],barco_chico);
        scanf("%d",&y);
        if (validacion(x,y,N,M) == 1){
            tablero[y][x] = bote1;
            printf("\nBARCO %s COLOCADO.\n",barco_chico);
            grafica(N,M,tablero);
            flag = 1;
        } else {
            printf("\nERROR: Esa coordenada no es posible.\n");
        }
    }
```
Se incia con un mensaje personalizado con el nombre del jugador para despues entrar en el ciclo `while flag != 1`
```c
        printf("\n%s dime la coordenada (x) del %s: ",nombres[i],barco_chico);
        scanf("%d",&x);
        printf("%s dime la coordenada (y) del %s: ",nombres[i],barco_chico);
        scanf("%d",&y);
```
Se le piden las coordenadas X y Y mostrando un mensaje personalizado,se usa el nombre del jugador `nombres[i]` y el nombre del barco `barco_chico`, despues guardando las varibles con scanf.
```c
if (validacion(x,y,N,M) == 1){
            tablero[y][x] = bote1;
            printf("\nBARCO %s COLOCADO.\n",barco_chico);
            grafica(N,M,tablero);
            flag = 1;
        } else {
            printf("\nERROR: Esa coordenada no es posible.\n");
            grafica(N,M,tablero);
        }
```
Despues se utiliza un `if` en donde se hace uso de la funcion `validacion` en caso de ser valido, el valor del bote 1 se guardara en la coordenada establecida `tablero[y][x] = bote1;` se mostrara un mensaje de confirmacion junto con la funcion `grafica` para que el jugador vea como esta su tablero, despues se iguala `flag` a 1 para salir del bucle while.

En caso de ser invalidas las coordenadas se mostrara el mensaje de error: `printf("\nERROR: Esa coordenada no es posible.\n");` junto con la funcion `grafica(N,M,tablero);` y se repetira el while.

### Colocación Barco Grande primera coordenada
```c
    flag = 0;
    while(flag != 1){
        printf("\n%s dime la primera coordenada (x) del %s: ",nombres[i],barco_grande);
        scanf("%d",&x);
        temp_x = x;
        printf("%s dime la primera coordenada (y) del %s: ",nombres[i],barco_grande);
        scanf("%d",&y);
        temp_y = y;
        if (validacion(x,y,N,M) == 1){
            if ((tablero[y][x]) == 0){
                tablero[y][x] = bote2[0];
                printf("\nPRIMERA COORDENADA GUARDADA!\n");
                grafica(N,M,tablero);
                flag = 1;
            } else {
                printf("\nEsa coordenada ya esta en uso!\n");
                grafica(N,M,tablero);
            }
        } else {
            printf("\nERROR: Esa coordenada no es posible.\n");
            grafica(N,M,tablero);
        }
    }
```
Se iguala `flag` a 0 para entrar al siguiente bucle while `while(flag != 1)`, se piden igualmente las coordenadas X y Y con la diferencia que se crean una copia en las variables temporales de las coordenadas.
```c
        printf("\n%s dime la primera coordenada (x) del %s: ",nombres[i],barco_grande);
        scanf("%d",&x);
        temp_x = x;
        printf("%s dime la primera coordenada (y) del %s: ",nombres[i],barco_grande);
        scanf("%d",&y);
        temp_y = y;
```
Despues se entra en un condicional `if` que evalua si las coordenadas son validas `if (validacion(x,y,N,M) == 1)` igualmente de no ser correctas se mostrara un mensaje de error `printf("\nERROR: Esa coordenada no es posible.\n");` y se ejecutara la funcion de la grafica `grafica(N,M,tablero);`.
```c
        if (validacion(x,y,N,M) == 1){
            if ((tablero[y][x]) == 0){
                tablero[y][x] = bote2[0];
                printf("\nPRIMERA COORDENADA GUARDADA!\n");
                grafica(N,M,tablero);
                flag = 1;
            } else {
                printf("\nEsa coordenada ya esta en uso!\n");
                grafica(N,M,tablero);
            }
        } else {
            printf("\nERROR: Esa coordenada no es posible.\n");
            grafica(N,M,tablero);
        }
    }
```
Despues, si las coordenadas son validas se pregunta la siguiente condicion `if ((tablero[y][x]) == 0){` lo que hace es evaluar si la coordenada que se ingreso esta vacio (es decir 0).
```c
                tablero[y][x] = bote2[0];
                printf("\nPRIMERA COORDENADA GUARDADA!\n");
                grafica(N,M,tablero);
                flag = 1;
```
De estar vacio se guarda el valor del bote 2 `tablero[y][x] = bote2[0];` se imprime un mensaje de confirmacion, la grafica y se iguala `flag` a 1 para salir del while.

En caso contrario se moatrara un mensaje que indique que esa coordenada ya esta en uso `printf("\nEsa coordenada ya esta en uso!\n");` y se imprimira la grafica.

### Colocacion Barco Grande segunda coordenada


