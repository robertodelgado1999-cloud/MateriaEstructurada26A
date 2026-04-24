#include <stdio.h>
void capturar(int numeros[3][3]);
void mostrar(int numeros[3][3]);
int diagonal(int numeros[3][3]);
void archivo(int numeros[3][3],int suma);

int main(){
    int numeros[3][3];
    int suma = 0;
    capturar(numeros);
    printf("\nLos numeros ingresados son:\n");
    mostrar(numeros);
    suma = diagonal(numeros);
    printf("\nLa suma de la diagonal es: %d\n",suma);
    archivo(numeros,suma);

}

void capturar(int numeros[3][3]){
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("Dame un numero:");
            scanf("%d",&numeros[i][j]);
        }
    }
}

void mostrar(int numeros[3][3]){
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d ",numeros[i][j]);
        }
        printf("\n");
    }
}

int diagonal(int numeros[3][3]){
    int i,suma = 0;
    for(i=0; i<3; i++){
        suma += numeros[i][i];
    }
    return suma;
}

void archivo(int numeros[3][3],int suma){
    int i,j;
    FILE *f;
    f = fopen("tablero.txt","a");
    fprintf(f,("El tablero es:\n"));
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            fprintf(f,"%d ",numeros[i][j]);
        }
        fprintf(f,"\n");
    }
    fprintf(f,"La suma de la diagonal: %d",suma);
    fprintf(f,"\n\n");
    fclose(f);
}

