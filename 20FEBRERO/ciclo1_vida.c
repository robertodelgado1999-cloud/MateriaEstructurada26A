#include<stdio.h>
int main(){
    int promedio,suma,calificacion,numero;
    do{
        printf("\nCuantas calificaciones tienes: \n");
        printf("Para salir(0)\n");
        scanf("%d",&numero);
        if(numero<0){
            printf("Ese numero no es posible\n");
        }
        else if(numero>0){
            for (int i=0;i<numero;i++){
                printf("Dame tu calificacion: ");
                scanf("%d",&calificacion);
                suma += calificacion;
                promedio=suma/numero;
            }
            printf("Tu promedio es:%d\n",promedio);
            numero=0;
        }
    }
    while(numero!=0);
    printf("\nPrograma concluido.\n");
    return 0;
}
