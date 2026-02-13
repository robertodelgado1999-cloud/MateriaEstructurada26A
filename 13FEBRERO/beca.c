#include<stdio.h>
int main(){
    int promedio;
    int reprobada;
    printf("Cuantas materias reprobadas tienes?\n");
    scanf("%d",&reprobada);
    if (reprobada>0){
        printf("no puedes postularte a la beca");
    }
    else{
        printf("Dame tu promedio\n");
        scanf("%d",&promedio);
        if (promedio>=85){
            printf("Felicidades tienes una beca!!!\n");
        }
        else {
            printf("Lo lamentamos no obtuvo la beca");
        }
    }
    return 0;
}
