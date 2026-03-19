#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N = 5;
int M = 5;

int W = 2;
int Z = 20;

char barco_chico[20]= "FRAGATA";
char barco_grande[20]= "DESTRUCTOR";

void iniciador(int N,int M,int tablero[N][M]);
void grafica(int N,int M,int tablero[N][M]);
int validacion(int x,int y,int N,int M);
void names(char nombres[W][Z]);
void captura(int jugador,int N,int M,int tablero[N][M],char nombres[W][Z]);
void batalla(int N,int M,int tablero_jugador1[N][M],int tablero_jugador2[N][M],char nombres[W][Z]);

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

void names(char nombres[W][Z]){
    for (int i = 0; i < 2; i++){
        printf("\nIntroduce tu nombre jugador %d: ",i+1);
        fgets(nombres[i],sizeof(nombres[i]),stdin);
        nombres[i][strcspn(nombres[i], "\n")] = '\0';
    }
}

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
                        printf("\n%s le diste a un %s!. Lo haz destruido\n",nombres[0],barco_chico);
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











