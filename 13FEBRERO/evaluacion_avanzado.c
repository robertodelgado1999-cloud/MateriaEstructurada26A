#include<stdio.h>
int main(){
    int edad,reprobadas,faltas;
    float promedio;

    printf("Dame tu edad:\n");
    scanf("%d",&edad);

    printf("\nDame tu promedio(1-10):\n");
    scanf("%f",&promedio);

    printf("\nCuantas materias reprobastes?\n");
    scanf("%d",&reprobadas);

    printf("\nCuantas veces faltaste?\n");
    scanf("%d",&faltas);

    if(reprobadas>3 || promedio<6.0 || faltas>15){
        printf("Usted no puede reinscribirse, esta en una situacion critica!!!");
    }
    else if (reprobadas==3){
        printf("Usted necesita una revision de su caso especial");
    }
    else {
        printf("Usted puede reincribirse\n");
        if (promedio>=9.0 && faltas<5){
            printf("Y usted es elegible para aspirar a una beca!!!\n");
        }
    }
    return 0;
}
