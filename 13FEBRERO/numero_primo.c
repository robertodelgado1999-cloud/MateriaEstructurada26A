#include<stdio.h>
int main(){
    int numero;
    printf("Dame un numero:\n");
    scanf("%d",&numero);
    if(numero==2){
        printf("Tu numero es primo");
    }
    else if(numero%2==0 && numero%1==0){
        printf("Tu numero no es primo\n");
    }
    else {
         printf("Tu numero es primo\n");
    }
    return 0;
}
