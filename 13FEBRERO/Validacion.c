#include<stdio.h>
int main(){
    int edad;
    float promedio;
    int materias;
    printf("Cual es su edad?\n");
    scanf("%d",&edad);
    printf("Ingrese su promedio actual:\n");
    scanf("%f",&promedio);
    printf("Cuantas materias reprobadas lleva en su actual ciclo?\n");
    scanf("%d",&materias);
    if(promedio>=90.0 && materias==0 && edad>=18){
        printf("Felicidades usted obtuvo una beca\n");
    }
    else if (materias<=2){
        printf("Usted puede reincribirse\n");
    }
    else {
        printf("Usted esta en una situacion critica\n");
    }
    return 0;
}
