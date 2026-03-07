#include<stdio.h>
#include<stdlib.h>

int N = 3;
int M = 3;

void iniciador(int N,int M,int tablero[N][M]);
void grafica(int N,int M,int tablero[N][M]);
void captura(int jugador,int N,int M,int tablero[N][M]);
int validacion(int x,int y,int N,int M);
void batalla(int N,int M,int tablero_jugador1[N][M],int tablero_jugador2[N][M]);


int main(){
    int tablero_jugador1[N][M];
    int tablero_jugador2[N][M];
    int eleccion = 1;

    iniciador(N,M,tablero_jugador1);
    iniciador(N,M,tablero_jugador2);
    printf("Inicio exitoso!\n");

    printf("\n--------!BIENVENIDO A BATTLESHIPS DE TEMU!-----------\n");
    do {
        captura(1,N,M,tablero_jugador1);
        printf("\nEste es tu tablero jugador 1:\n\n");
        grafica(N,M,tablero_jugador1);
        printf("\n---------------------------------------------------------\n");

        captura(2,N,M,tablero_jugador2);
        printf("\nEste es tu tablero jugador 2:\n\n");
        grafica(N,M,tablero_jugador2);
        printf("\n---------------------------------------------------------\n");

        printf("\nAmbos jugadores estan listos.\n");
        printf("\n---------------------------------------------------------\n");

        batalla(N,M,tablero_jugador1,tablero_jugador2);

        printf("\nDesea volver a jugar? SI(1) NO(0): ");
        scanf("%d",&eleccion);
    } while (eleccion=1);
    return 0;
}

void iniciador(int N,int M,int tablero[N][M]){
    for(int i=0; i<N; i++){
        for(int l=0; l<M; l++){
            tablero[i][l] = 0;
        }
    }
    printf("Loading.....\n");
}

void grafica(int N,int M,int tablero[N][M]){
    for(int i=0; i<N; i++){
        for(int l=0; l<M; l++){
            printf("\t%d",tablero[i][l]);
        }
        printf("\n");
    }
}

int validacion(int x,int y,int N,int M){
    if(x >= 0 && x < N && y >= 0 && y < M){
        return 1;
    } else {
        return 0;
    }
}

void captura(int jugador,int N,int M,int tablero[N][M]){
    int x, y, temp_x, temp_y;
    int flag = 0;
    int bote1 = 777;
    int bote2[2]= {555,555};
    printf("\n/////Jugador %d coloca tu flota/////\n",jugador);
    while(flag != 1){
        printf("\nJugador %d dime la coordenada (x) del primer bote: ",jugador);
        scanf("%d",&x);
        printf("Jugador %d dime la coordenada (y) del primer bote: ",jugador);
        scanf("%d",&y);
        if (validacion(x,y,N,M) == 1){
            tablero[x][y] = bote1;
            printf("\nBARCO CHICO COLOCADO.\n");
            flag = 1;
        } else {
            printf("\nERROR: Esa coordenada no es posible.\n");
        }
    }

    flag = 0;
    while(flag != 1){
        printf("\nJugador %d dime la primera coordenada (x) del segundo bote: ",jugador);
        scanf("%d",&x);
        temp_x = x;
        printf("Jugador %d dime la primera coordenada (y) del segundo bote: ",jugador);
        scanf("%d",&y);
        temp_y = y;
        if (validacion(x,y,N,M) == 1){
            if ((tablero[x][y]) == 0){
                tablero[x][y] = bote2[0];
                printf("\nPRIMERA COORDENADA GUARDADA!\n");
                flag = 1;
            } else {
                printf("\nESA COORDENADA YA ESTA OCUPADA!\n");
            }
        } else {
            printf("\nERROR: Esa coordenada no es posible.\n");
        }
    }
    flag = 0;
    while(flag != 1){
        printf("\nJugador %d dime la segunda coordenada (x) del segundo bote:",jugador);
        scanf("%d",&x);
        printf("Jugador %d dime la segunda coordenada (y) del segundo bote:",jugador);
        scanf("%d",&y);
        if (validacion(x,y,N,M) == 1  && abs(temp_x - x) + abs(temp_y - y) == 1){
            if ((tablero[x][y]) == 0){
                tablero[x][y] = bote2[1];
                printf("\nBARCO GRANDE COLOCADO.\n");
                flag = 1;
            } else {
                printf("\nESA COORDENADA YA ESTA OCUPADA!\n");
            }
        } else {
            printf("\nERROR: Esa coordenada no es posible.\n");
        }
    }
}

//////Funcion de batalla/////////
void batalla(int N,int M,int tablero_jugador1[N][M],int tablero_jugador2[N][M]){
    int vida_jugador1 = 3;
    int vida_jugador2 = 3;
    int turno = 1;
    int impactos1 = 0;
    int impactos2 = 0;
    int x,y;

    printf("\n--------DUELO A MUERTE CON BARQUITOS---------\n");

    while(turno != 0){
        printf("\n--------Turno del jugador 1---------");
        while(turno == 1){
            printf("\nDime la coordenada (x): ");
            scanf("%d",&x);
            printf("Dime la coordenada (y): ");
            scanf("%d",&y);
            if (validacion(x,y,N,M) == 1){
                switch(tablero_jugador2[x][y]){

                    case 777:
                        printf("\nTu barco chico ha sido BRUTALMENTE DESTRUIDO jugador 2!\n");
                        tablero_jugador2[x][y] = 1;
                        vida_jugador2--;
                        break;

                    case 555:
                        printf("\nTu barco ha sido partido BRUTALMENTE a la mitad jugador 2!\n");
                        impactos1++;
                        if(impactos1>1){
                            printf("No te creas esa cosa ya esta muerta jsjsjsj\n");
                            tablero_jugador2[x][y] = 1;
                        }
                        tablero_jugador2[x][y] = 3;
                        vida_jugador2--;
                        break;

                    case 2:
                        printf("\nMIRA NADA MAS! un PROFUGO del acido folico\n");
                        break;

                    case 3:
                        printf("\nEse barco ya habia sido IMPACTADO jugador 2\n");
                        break;

                    case 1:
                        printf("\nEsa madre ya esta MUERTA!\n");
                        break;

                    default:
                        printf("\nFallaste! PIPIPIPI!!!\n");
                        tablero_jugador2[x][y] = 2;
                        break;
                }
                turno = 2;
            } else {
                printf("\nEsa coordenada no es posible!!\n");
            }
        }
        if(vida_jugador2 == 0){
            printf("\n--------------FATALITY! PLAYER 1 WINS---------------\n");
            turno = 0;
        }
        else{
            printf("\n----------Turno del jugador 2---------");
        }
        while(turno == 2){
            printf("\nDime la coordenada (x): ");
            scanf("%d",&x);
            printf("Dime la coordenada (y): ");
            scanf("%d",&y);
            if (validacion(x,y,N,M) == 1){
                switch(tablero_jugador1[x][y]){

                    case 777:
                        printf("\nTu barco chico ha sido BRUTALMENTE DESTRUIDO jugador 1!\n");
                        tablero_jugador1[x][y] = 1;
                        vida_jugador1--;
                        break;

                    case 555:
                        printf("\nTu barco ha sido partido BRUTALMENTE a la mitad jugador 1!\n");
                        impactos2++;
                        if(impactos2>1){
                            printf("No te creas esa cosa ya esta muerta jsjsjsj\n");
                            tablero_jugador1[x][y] = 1;
                        }
                        tablero_jugador1[x][y] = 3;
                        vida_jugador1--;
                        break;

                    case 2:
                        printf("\nMIRA NADA MAS! un PROFUGO del acido folico\n");
                        break;

                    case 3:
                        printf("\nEse barco ya habia sido IMPACTADO jugador 1\n");
                        break;

                    case 1:
                        printf("\nEsa madre ya esta MUERTA!\n");
                        break;

                    default:
                        printf("\nFallaste! PIPIPIPI!!!\n");
                        tablero_jugador1[x][y] = 2;
                        break;
                }
                turno = 1;
            } else {
                printf("\nEsa coordenada no es posible!!\n");
            }
        }
        if(vida_jugador1 == 0){
            printf("\n--------------FELICIDADES JUGADOR 2, TE GANASTE UN POLLO-------------------\n");
            turno = 0;
        }
    }
}













