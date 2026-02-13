#include<stdio.h>
int main(){
    int numero;
    printf("Dame un numero:\n");
    scanf("%d",&numero);
    numero = numero%2;
    if (numero==0){
        printf("Tu numero es par");
    }
    else{
        printf("Tu numero es impar");
    }
    return 0;
