#include<stdio.h>
int main()
{
    float temp1, tem2;
    int N = 2;
    float temp[N];
    int dummy;


    printf("Direccion de memoria: &temp1: %i, \n&temp2: %i\n",&temp1,&tem2);
    printf("\nDireccion de temp[23]:%i,\n",temp);
    printf("\nDireccion de &temp[23]:%i,\n",&temp[3]);
    printf("\nDireccion de &dummy: %i\n\n",&dummy);

    for(int i = 0; i<N; i++){
        printf("Dame una temperatura: ");
        scanf("%f",&temp[i]);
    }

    for(int i = 0; i<N; i++){
        printf("\nTemperatura %d es: %f",i,temp[i]);
    }

    printf("\n");
    for(int i = 0; i<N; i++){
        printf("\nDireccion de %d: %d",i,&temp[i]);
    }

    return 0;
}

