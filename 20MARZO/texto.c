#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char tablero[5][5];
    char name[20] = "Roberto";
    int cadena;
    char palabra[20];
    int i = 0;

    FILE *archivo;
    archivo = fopen("tablero.txt","w");

    fprintf(archivo,"\n%s\n",name);

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

    printf("\n\n");

    // IMPRESION EN COSOLA DEL TABLERO
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            printf("%c\t",tablero[i][j]);
        }
        printf("\n");
    }
    printf("\n-------------------------------------\n");

    //IMPRESION EN EL ARCHIVO.TXT DEL TABLERO
    fprintf(archivo,"\n");
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            fprintf(archivo,"%c\t",tablero[i][j]);
        }
        fprintf(archivo,"\n");
    }

    fclose(archivo);

    archivo = fopen("tablero.txt","r");

    while ((cadena = fgetc(archivo)) != EOF){
        printf("%c", cadena);
        }
    fclose(archivo);

    archivo = fopen("tablero.txt","r");

    while( fscanf(archivo, "%s", palabra) != EOF){
        if (strcmp(palabra,"Roberto")==0){
            printf("\nEl nombre encontrado en el archivo fue: %s\n",palabra);
        }
    }
    fclose(archivo);

    return 0;
}
