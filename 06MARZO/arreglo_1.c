#include<stdio.h>
int main()
{
    float temp1, tem2;
    float temp[24];
    int dummy;

    printf("Direccion de memoria: &temp1: %i, \n&temp2: %i\n",&temp1,&tem2);
    printf("\nDireccion de temp[23]:%i,\n",temp);
    printf("\nDireccion de &temp[23]:%i,\n",&temp[23]);
    printf("\nDireccion de &dummy: %i\n",&dummy);

    temp[0] = 20.5;
    temp[1] = 19.2;
    printf("\nTemperatura 0: %f\n",temp[0]);
    printf("\nTemperatura 1: %f\n",temp[1]);

    return 0;
}

