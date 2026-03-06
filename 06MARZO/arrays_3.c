#include<stdio.h>
int main(){
    int x,z;
    int r,t;
    int N = 3;
    int M = 3;
    int i,y;

    int bote1 = 777;
    int bote2[2] = {555,555};
    int jugador1[N][M];
    int jugador2[N][M];

    for(i=0; i<N; i++){
        for(y=0; y<M; y++){
            jugador1[i][y] = 0;
        }
    }

    for(i=0; i<N; i++){
        for(y=0; y<M; i++){
            jugador2[i][y] = 0;
        }
    }

    printf("\nJugador 1 dime donde quieres el bote 1:");
    scanf("%d%d",&x,&z);
    jugador1[x][z] = bote1;

    printf("\nJugador 1 dime donde quieres la primera cordenada del bote 2: ");
    scanf("%d%d",&x,&z);
    jugador1[x][z] = bote2[0];

    printf("\nJugador 1 dime donde quieres la segunda cordenada del bote 2: ");
    scanf("%d%d",&r,&t);
    if(r==x || t==z){
        jugador1[r][t] = bote2[1];
    }
    else{
        printf("\nEsa cordenada no es posible.");
    }

    return 0;
}
