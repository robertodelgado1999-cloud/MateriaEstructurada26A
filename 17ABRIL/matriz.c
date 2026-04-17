#include <stdio.h>

void mostrarMatriz(int m[2][3]){
    int i,j;
    for(i = 0; i<2; i++){
        for(j=0; j<3; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int d[2][3]={{0,0,0},{1,2,3}};
    mostrarMatriz(d);
    return 0;
}
