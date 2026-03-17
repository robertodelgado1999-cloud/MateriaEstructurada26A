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

## FUNCION INICIADOR
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

## FUNCION GRAFICA
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

## FUNCION DE VALIDACION DE COORDENADAS
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

## FUNCION CAPTURA DE NOMBRES
```c
//////////// FUNCION CAPTURA DE NOMBRES ///////////////
void names(char nombres[W][Z]){
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

## FUNCION CAPTURA DE BARCOS
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
```c
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
```
De la misma manera se obtiene la segunda coordenada con la unica diferencia que en la condicion de validacion `if (validacion(x,y,N,M) == 1  && abs(temp_x - x) + abs(temp_y - y) == 1)` ademas de usar la funcion de validacion, se utiliza el operador & para comprobar la siguiente condicion `abs(temp_x - x) + abs(temp_y - y) == 1)` la logica radica en que la coordenada del segundo barco tiene que ser adyacente a la primera coordenada y de forma perpendicular, esto es, no puede partirse el barco y no se puede colocar de forma diagonal.

Ahora bien, dado que se esta trabajando con numeros enteros unitarios la diferencia por alguno de los dos ejes (x) (y) tiene que ser de almenos una unidad y como se espera que este a la misma altura de al menos uno de los dos ejes estos terminarán restandose dando como resultado 0.

Se utiliza la función de valor absoluto `abs()` debido a que pueden ser menor la segunda coordenada ingresada, aunque bien puede sostituirse por la condicion: `(((temp_x - x) + abs(temp_y - y) == 1) || ((temp_x - x) + (temp_y - y) == -1))` en caso de no querer usar `abs()`.

## FUNCION DE BATALLA
```c
/////////////////////////// FUNCION DE BATALLA /////////////////////////////////
void batalla(int N,int M,int tablero_jugador1[N][M],int tablero_jugador2[N][M],char nombres[W][Z]){
    int vida_jugador1 = 3;
    int vida_jugador2 = 3;
    int turno = 1;
    int impactos1 = 0;
    int impactos2 = 0;
    int x,y;

    printf("\n\\\\\\\\\\\\\\\\-----------DUELO A MUERTE CON BARQUITOS-------------/////////////n");

    while(turno != 0){
        printf("---------------------------------------------------------------------");
        printf("\n-------- Turno de %s ---------\n",nombres[0]);
        while(turno == 1){
            printf("\nDime la coordenada (x): ");
            scanf("%d",&x);
            printf("Dime la coordenada (y): ");
            scanf("%d",&y);
            if (validacion(x,y,N,M) == 1){
                switch(tablero_jugador2[y][x]){

                    case 777:
                        printf("\n;%s le diste a un %s!. Lo haz destruido\n",nombres[0],barco_chico);
                        tablero_jugador2[y][x] = 1;
                        vida_jugador2--;
                        grafica(N,M,tablero_jugador2);
                        break;

                    case 555:
                        printf("\n%s le diste a un %s!\n",nombres[0],barco_grande);
                        impactos1++;
                        if(impactos1>1){
                            printf("Haz destruido un %s\n",barco_grande);
                            tablero_jugador2[y][x] = 1;
                        }
                        tablero_jugador2[y][x] = 3;
                        vida_jugador2--;
                        grafica(N,M,tablero_jugador2);
                        break;

                    case 2:
                        printf("\nYa te habia dicho que FALLASTE %s!!!\n",nombres[0]);
                        grafica(N,M,tablero_jugador2);
                        break;

                    case 3:
                        printf("\nYa habias impactado ahi %s!!!!\n",nombres[0]);
                        grafica(N,M,tablero_jugador2);
                        break;

                    case 1:
                        printf("\n%s esa cosa ya esta MUERTA!,YA DEJALA!\n",nombres[0]);
                        grafica(N,M,tablero_jugador2);
                        break;

                    default:
                        printf("\nFALLASTE! PIPIPIPI!\n");
                        tablero_jugador2[y][x] = 2;
                        grafica(N,M,tablero_jugador2);
                        break;
                }
                turno = 2;
            } else {
                printf("\nEsa coordenada no es posible!!\n");
            }
        }
        if(vida_jugador2 == 0){
            printf("\n--------------FATALITY! %s WINS---------------\n",nombres[0]);
            turno = 0;
        }
        else{
            printf("-----------------------------------------------------------------------");
            printf("\n---------- Turno de %s ----------\n",nombres[1]);
        }
        while(turno == 2){
            printf("\nDime la coordenada (x): ");
            scanf("%d",&x);
            printf("Dime la coordenada (y): ");
            scanf("%d",&y);
            if (validacion(x,y,N,M) == 1){
                switch(tablero_jugador1[y][x]){

                    case 777:
                        printf("\n%s le diste a un %s!. Lo haz destruido\n",nombres[1],barco_chico);
                        tablero_jugador1[y][x] = 1;
                        vida_jugador1--;
                        grafica(N,M,tablero_jugador1);
                        break;

                    case 555:
                        printf("\n%s le dista a un %s!\n",nombres[1],barco_grande);
                        impactos2++;
                        if(impactos2>1){
                            printf("Haz destruido un %s\n",barco_grande);
                            tablero_jugador1[y][x] = 1;
                        }
                        tablero_jugador1[y][x] = 3;
                        vida_jugador1--;
                        grafica(N,M,tablero_jugador1);
                        break;

                    case 2:
                        printf("\nYa te habia dicho que FALLASTE %s!!!\n",nombres[1]);
                        grafica(N,M,tablero_jugador1);
                        break;

                    case 3:
                        printf("\nYa habias impactado ahi %s!!!!\n",nombres[1]);
                        grafica(N,M,tablero_jugador1);
                        break;

                    case 1:
                        printf("\n%s esa cosa ya esta MUERTA!,YA DEJALA!\n",nombres[1]);
                        grafica(N,M,tablero_jugador1);

                        break;

                    default:
                        printf("\nFALLASTE! PIPIPIPI!\n");
                        tablero_jugador1[y][x] = 2;
                        grafica(N,M,tablero_jugador1);
                        break;
                }
                turno = 1;
            } else {
                printf("\nEsa coordenada no es posible!!\n");
            }
        }
        if(vida_jugador1 == 0){
            printf("\n--------------FELICIDADES %s, TE GANASTE UN POLLO-------------------\n",nombres[1]);
            turno = 0;
        }
    }
}

```
Esta funcion es el juego como tal, los jugadores diran coordenadas por turnos y se validará si se ha atinado a un barco, así hasta declarar un ganador.
### Variables
```c
void batalla(int N,int M,int tablero_jugador1[N][M],int tablero_jugador2[N][M],char nombres[W][Z]){
// Se pasan como parametros el tablero de los dos jugadores y las lista de sus nombres

    int vida_jugador1 = 3; // Vida del jugador 1
    int vida_jugador2 = 3; // Vida del jugador 2
    int turno = 1; // Es la señal que mantiene el while hasta que sea el turno del otro jugador
    int impactos1 = 0; // Impactos que ha recibido el barco grande del jugador 1
    int impactos2 = 0; // Impactos que ha recibido el barco grande del jugador 1
    int x,y; // Coordenadas x y y
```
### Turno jugador 1
```c
    printf("\n\\\\\\\\\\\\\\\\-----------DUELO A MUERTE CON BARQUITOS-------------/////////////n");

    while(turno != 0){
        printf("---------------------------------------------------------------------");
        printf("\n-------- Turno de %s ---------\n",nombres[0]);
        while(turno == 1){
            printf("\nDime la coordenada (x): ");
            scanf("%d",&x);
            printf("Dime la coordenada (y): ");
            scanf("%d",&y);
            if (validacion(x,y,N,M) == 1){
```
Primero se muestra un mensaje de inicio `printf("\n\\\\\\\\\\\\\\\\-----------DUELO A MUERTE CON BARQUITOS-------------/////////////n");` para despues pasar a un while que mantiene la condicion del turno `while(turno != 0){` seguido se le piden las coordenadas al primer jugador, guardandose en las variables x y y respectivamente con `scanf`. Seguido de la validacion de la coordenadas como se habi hecho anteriormente `if (validacion(x,y,N,M) == 1){`. Igualmente de ser invalidas las coordenadas se mostrara el siguiente mensaje `printf("\nEsa coordenada no es posible!!\n");`.
```c
                switch(tablero_jugador2[y][x]){

```
Seguido de eso dentro del `if` usamos un `switch` que valida las coordenadas introducidas en el tablero del jugador 2 `switch(tablero_jugador2[y][x]){`. 
#### Case 777 Barco chico
```c
                    case 777:
                        printf("\n%s le diste a un %s!. Lo haz destruido\n",nombres[2],barco_chico);
                        tablero_jugador2[y][x] = 1;
                        vida_jugador2--;
                        grafica(N,M,tablero_jugador2);
                        break;
```
Imprime un mensaje indicando que se destruyo el barco chico, en el arreglo del tablero del jugador 2 se cambia por el valor del barco en las coordenadas que introdujo el jugador 1 `tablero_jugador2[y][x] = 1;` y se le resta uno de vida al jugador 2 `vida_jugador2--;`, se imprime la grafica del otro jugador y se sale del switch con `break;`.

#### Case 555 Barco Grande
```c
                    case 555:
                        printf("\n%s le diste a un %s!\n",nombres[0],barco_grande);
                        impactos1++;
                        tablero_jugador2[y][x] = 3;
                        if(impactos1>1){
                            printf("Haz destruido un %s\n",barco_grande);
                            tablero_jugador2[y][x] = 1;
                        }
                        vida_jugador2--;
                        grafica(N,M,tablero_jugador2);
                        break;
```
Se imprime igualmente un mensaje de que se ha destruido un barco grande y se suma 1 a la variable de impactos del jugador contrario `impactos1++;` y cambiando el dato a 3 que es impacto `tablero_jugador2[y][x] = 3;`.pasando por una condicion donde se evalua si se han dado más de 1 impacto `if(impactos1>1){` de ser afirmativo significa que el barco grande ha sido destruido por lo que se imprime un mensaje extra que indica eso `printf("Haz destruido un %s\n",barco_grande);` y cambiando el valor de la coordenada a 1 `tablero_jugador2[y][x] = 1;` se le resta vida al jugador contrario y se imprime la grafica, saliendo con `break`.

#### Case 2
```c
                    case 2:
                        printf("\nYa te habia dicho que FALLASTE %s!!!\n",nombres[0]);
                        grafica(N,M,tablero_jugador2);
                        break;
```
Como dos es el valor de haber errado el tiro se presenta un mensaje recordando al jugador que ya se habia mencionado e imprimiendo la grafica del tablero.

#### Case 3
```c
                     case 3:
                        printf("\nYa habias impactado ahi %s!!!!\n",nombres[0]);
                        grafica(N,M,tablero_jugador2);
                        break;
```
Es tres el valor de impacto por lo que se le recuerda al jugador que ya habia impactado ahi, mostrando tambien la grafica.

#### Case 1
```c
                    case 1:
                        printf("\n%s esa cosa ya esta MUERTA!,YA DEJALA!\n",nombres[0]);
                        grafica(N,M,tablero_jugador2);
```
El uno es para los barcos hundidos por lo que se le muestra un mensaje personalizado.

#### Default
```c
                    default:
                        printf("\nFALLASTE! PIPIPIPI!\n");
                        tablero_jugador2[y][x] = 2;
                        grafica(N,M,tablero_jugador2);
                        break;
                }
                turno = 2;
```
Finalmente de forma predeterminada tenemos el mensaje de tiro errado mostrando un mensaje, cambiando el valor de la coordenada a dos `tablero_jugador1[y][x] = 2;` y cambiando la grafica.

Y tambien fuera del switch se cambia el turno a dos `turno = 2;` para salir pasar al bucle del siguiente jugador.

### Turno jugador 2
```c
        if(vida_jugador2 == 0){
            printf("\n--------------FATALITY! %s WINS---------------\n",nombres[0]);
            turno = 0;
        }
        while(turno == 2){
            printf("-----------------------------------------------------------------------");
            printf("\n---------- Turno de %s ----------\n",nombres[1]);
            printf("\nDime la coordenada (x): ");
            scanf("%d",&x);
            printf("Dime la coordenada (y): ");
            scanf("%d",&y);
            if (validacion(x,y,N,M) == 1){
                switch(tablero_jugador1[y][x]){ // Switch explicado anteriormente.
                turno = 1;
            } else {
                printf("\nEsa coordenada no es posible!!\n");
            }
        }
        if(vida_jugador1 == 0){
            printf("\n--------------FELICIDADES %s, TE GANASTE UN POLLO-------------------\n",nombres[1]);
            turno = 0;
        }
    }
}
```
Iniciamos con un condicional que verifica si el jugador 2 cuenta con vida `if(vida_jugador2 == 0){` si su vida llego a 0 se imprime un mensaje de victoria personalizado `printf("\n--------------FATALITY! %s WINS---------------\n",nombres[0]);` y se iguala el turno a 0 para salir del while.

De caso contrario se entra en el while del jugador 2 que igual al del jugador 1 solo que cambiando el tablero al del jugador 1 y el nombre el arreglo al del jugador 2, y cambiando al final al turno a 1 para pasar al jugador 1.
```c
while(turno == 2){
            printf("-----------------------------------------------------------------------");
            printf("\n---------- Turno de %s ----------\n",nombres[1]);
            printf("\nDime la coordenada (x): ");
            scanf("%d",&x);
            printf("Dime la coordenada (y): ");
            scanf("%d",&y);
            if (validacion(x,y,N,M) == 1){
                switch(tablero_jugador1[y][x]){ // Switch explicado anteriormente.
                turno = 1;
            } else {
                printf("\nEsa coordenada no es posible!!\n");
            }
```
Finalmente se pasa por una ultima condicon para evaluar si el jugador 1 cuenta con vida todavia `if(vida_jugador1 == 0){` y de ya no contar con vida imprimir un mensaje de victoria `printf("\n--------------FELICIDADES %s, TE GANASTE UN POLLO-------------------\n",nombres[1]);` y cambiando el turno a 0.

## FUNCION PRINCIPAL (MAIN)
```c
int main(){
    int tablero_jugador1[N][M];
    int tablero_jugador2[N][M];
    int eleccion = 1;
    char jugadores[W][Z];

    printf("\n\\\\\\\\\\\\\\--------!BIENVENIDO A BATTLESHIPS DE TEMU!-----------//////////////\n");
    while (eleccion == 1) {
        iniciador(N,M,tablero_jugador1);
        iniciador(N,M,tablero_jugador2);
        printf("Inicio exitoso!\n");

        names(jugadores);
        captura(0,N,M,tablero_jugador1,jugadores);
        printf("\nEste es tu tablero jugador 1:\n");
        grafica(N,M,tablero_jugador1);
        printf("\n---------------------------------------------------------\n");

        captura(1,N,M,tablero_jugador2,jugadores);
        printf("\nEste es tu tablero jugador 2:\n");
        grafica(N,M,tablero_jugador2);
        printf("\n---------------------------------------------------------\n");

        printf("\nAmbos jugadores estan listos.\n");
        printf("\n---------------------------------------------------------\n");
        printf("\nREGLAS:\n");
        printf("0 = AGUA\n");
        printf("1 = BARCO\n");
        printf("2 = DISPARO FALLIDO\n");
        printf("3 = IMPACTO\n");

        batalla(N,M,tablero_jugador1,tablero_jugador2,jugadores);

        printf("\nDesea volver a jugar? SI(1) NO(0): ");
        scanf("%d",&eleccion);
        while(getchar() != '\n');
    } 
    return 0;
}
```
### Variables
- `int tablero_jugador1[N][M];` Tablero del jugador 1
- `int tablero_jugador2[N][M];` Tablero del jugador 2
- `int eleccion = 1;` Señal que mantiene el juego hasta que el jugador decida salir
- `char jugadores[W][Z];` Lista de los nombres de los jugadores

### Inicio
Primero se realiza el inicio del juego con un mensaje de bienvenida para despues entrar en el while con la condicion `while (eleccion == 1)`, se utiliza la funcion del iniciador para poner el tablero de ambos jugadores en 0s, imprimiendo un mensaje cuando se ejecuto correctamente.
```c
    printf("\n\\\\\\\\\\\\\\--------!BIENVENIDO A BATTLESHIPS DE TEMU!-----------//////////////\n");
    while (eleccion == 1) {
        iniciador(N,M,tablero_jugador1);
        iniciador(N,M,tablero_jugador2);
        printf("Inicio exitoso!\n");
```
### Captura
Se realiza la captura de los nombres de los jugadores con la funcion `names` para despues usar la funcion captura con el primer jugador. Despues se imprime su tablero y una linea divisorara. Se repite el proceso con el segundo jugador cambiando unicamente los parametros actuales.
```c
        names(jugadores);
        captura(0,N,M,tablero_jugador1,jugadores);
        printf("\nEste es tu tablero jugador 1:\n");
        grafica(N,M,tablero_jugador1);
        printf("\n---------------------------------------------------------\n");

        captura(1,N,M,tablero_jugador2,jugadores);
        printf("\nEste es tu tablero jugador 2:\n");
        grafica(N,M,tablero_jugador2);
        printf("\n---------------------------------------------------------\n");
```
### Batalla
Una vez terminado la captura de los datos se imprime un mensaje de confirmacion y se imprimen las reglas del juego, para despues parasa con la funcion `batalla` con los datos recolectados anteriormente como parametros.
```c
        printf("\nAmbos jugadores estan listos.\n");
        printf("\n---------------------------------------------------------\n");
        printf("\nREGLAS:\n");
        printf("0 = AGUA\n");
        printf("1 = BARCO\n");
        printf("2 = DISPARO FALLIDO\n");
        printf("3 = IMPACTO\n");

        batalla(N,M,tablero_jugador1,tablero_jugador2,jugadores);
```
### Reinicio
Una vez terminado la batalla se pregunta al usuario si desea volver a jugar y se graba su respuesta con `scanf` guardando su respuesta en la variable `eleccion`. 
```c
        printf("\nDesea volver a jugar? SI(1) NO(0): ");
        scanf("%d",&eleccion);
        while(getchar() != '\n');
    } 
    return 0;
}
```
> [!NOTE]
Debido a que usamos fgets para introducir los nombres de los jugadores y scanf para guardar la eleccion, scanf solo guarda el valor del numero pero no el salto de linea`\n`, es por ello que usamos `while(getchar() != '\n');` para consumir ese salto de linea. `getchar() ` es una funcion de la libreria `stdio.h` y se encarga de leer el caracter de la entrada estandar `stdin` y convertirlo a un entero (ASCII)







