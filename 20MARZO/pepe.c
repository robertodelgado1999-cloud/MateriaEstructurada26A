#include<stdio.h>
#include<stdlib.h>

int main(){
    char tablero[5][5];
    char name[20] = "Roberto\n";
    char cadena;
    char nombre[20];
    int i = 0;

    FILE *archivo;
    archivo = fopen("tablero.txt","w");

    fprintf(archivo,"\n%s",name);

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            tablero[i][j] = '~';
            printf("%c\t",tablero[i][j]);
        }
        printf("\n");
    }

    tablero[1][2] = 'B';
    tablero[3][4] = 'O';
    tablero[2][1] = 'X';

    printf("\n--------------------------------------------------\n\n");

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            printf("%c\t",tablero[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            fprintf(archivo,"%c\t",tablero[i][j]);
        }
        fprintf(archivo,"\n");
    }


    fclose(archivo);

    archivo = fopen("tablero.txt","r");

    while ((cadena = fgetc(archivo)) != EOF) {
        printf("%c", cadena);
        if (cadena = name[i]){
            nombre[i] = cadena;
            i++;
        }
    }
    printf("\nel nombre es %s",nombre);


    return 0;
}
