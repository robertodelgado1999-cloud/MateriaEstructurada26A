#include<stdio.h>
int main(){
    int edad;
    printf("ingrese su edad:\n");
    scanf("%i",&edad);
    if(edad>=18){
        printf("eres mayor de edad");
    }
    else {
        printf("no eres mayor de edad");
    }
    return 0;
}

