#include<stdio.h>
int main(){
    int promedio,suma,calificacion,numero;
    do{
        printf("Cuantas calificaciones tienes: \n");
        printf("Para salir(0)\n");
        scanf("%d",&numero);
        if(numero<0){
            printf("\nEse numero no es posible\n");
        }
        else if(numero>0){
            for (int i=0;i<numero;i++){
                printf("Dame tu calificacion: ");
                scanf("%d",&calificacion);
                if(calificacion<0||calificacion>100){
                    printf("\nEsa calificacion sale del rango permitido");
                    printf("\nPorfavor, introduzca otro numero\n");
                    i--;
                }
                else{
                    suma += calificacion;
                    promedio=suma/numero;
                }
            }
            printf("\nTu promedio es:%d\n",promedio);
            numero=0;
        }
    }
    while(numero!=0);
    printf("\nPrograma concluido.");
    return 0;
}
