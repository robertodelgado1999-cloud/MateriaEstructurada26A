#include<stdio.h>
int main(){
    int promedio;
    int suma;
    int calificacion;
    int numero;
    int letra;
    char buffer;
    int porcentaje;
    int aprobadas;
    do{
        suma=0;
        aprobadas=0;
        printf("Cuantas calificaciones tienes: \n");
        printf("Para salir(0)\n");
        letra=scanf("%d",&numero);
        if(letra!=1){
            printf("\nEsa es una letra\n");
            scanf("%s",&buffer);
            printf("\nDesea continuar? Si(1) No(0): ");
            scanf("%d",&numero);
        }
        else{
            if(numero<0){
            printf("\nEsa entrada no es posible\n");
            }
            else if(numero>0){
            for (int i=0;i<numero;i++){
                printf("\nDame tu calificacion: \n");
                scanf("%d",&calificacion);
                if(calificacion<0||calificacion>100){
                    printf("\nEsa calificacion sale del rango permitido");
                    printf("\nPorfavor, introduzca otro numero\n");
                    i--;
                }
                else{
                    if(calificacion>60){
                        aprobadas++;
                    }
                    suma += calificacion;
                    promedio=suma/numero;
                    porcentaje=(aprobadas*100)/numero;

                }
            }
            printf("\nTu promedio es:%d",promedio);
            printf("\nTu porcentaje de materias aprobadas es: %d%%\n",porcentaje);
            printf("\nDesea continuar? Si(1) No(0): ");
            scanf("%d",&numero);
            }
        }
    }
    while(numero!=0);
    printf("\nPrograma concluido.");
    return 0;
}

