#include <stdio.h>
#include <string.h>

int main(){
    /*char nombre [16];
    char apellido [16];*/

    char nombre1 [16];
    char lista [3][16];
    int longitud;

    /*printf("Dame el nombre alumno: ");
    scanf("%s",nombre);
    printf("\nDame el apellido del alumno: ");
    scanf("%s",apellido);
    printf("\nTu nombre completo es %s %s\n",nombre,apellido); */

    printf("Dame el nombre del alumno: ");
    fgets(nombre1,sizeof(nombre1),stdin);
    printf("El nombre completo del alumno es: %s\n",nombre1);

    for (int i = 0; i<3; i++){
        printf("Dame el nombre del alumno %d: ",i);
        fgets(lista[i],sizeof(lista[i]),stdin);
        printf("El nombre %d es: %s\n",i,lista[i]);
    }
    for (int i = 0; i<3; i++){
        longitud = strlen(lista[i]);
        printf("\nLa longitud de %s%d",lista[i],longitud);
    }

    return 0;
}
