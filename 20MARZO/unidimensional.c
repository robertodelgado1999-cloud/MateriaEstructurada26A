#include <stdio.h>
#include <string.h>

int main(){
    char names[4][20];
    int numero[5]; //identificador mas el indice o offset o desplazador
    char mana[5];

    for(int i = 0; i<5; i++){
        printf("Dame un numero:");
        scanf("%d",&numero[i]);
    }

    for(int i = 0; i<5; i++){
        printf("\n%d y la memoria es %d",numero[i],&numero[i]);
    }

    printf("\n--------------------------------------------------\n");
    for (int i = 0; i < 4; i++){
        printf("\nIntroduce los datos: ");
        fgets(names[i], sizeof(names) ,stdin);
    }

    printf("\nTu nombre es: %s",names[0]);
    printf("Tu apodo es: %s",names[1]);
    printf("Tu apellido es: %s",names[2]);
    printf("Tu segundo apellido es: %s",names[3]);

    printf("\n%d",&numero[0]); //Es el direccion de memoria
    printf("\n%d",&numero[1]); //Es el direccion de memoria
    printf("\n%d",&numero[2]); //Es el direccion de memoria
    printf("\n%d",&numero[3]); //Es el direccion de memoria
    printf("\n%d",numero); //Imprime el apuntador de memoria

    printf("\n--------------------------------------------------\n");

    printf("%c\n",&mana[0]);
    printf("%d\n",&mana[1]);
    printf("%d\n",&mana[2]);
    printf("%d\n",mana);

    printf("\n--------------------------------------------------\n");

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 20; j++){
            printf("\n%d",&names[i][j]);
        }
        printf("\n");
    }
    return 0;
}
