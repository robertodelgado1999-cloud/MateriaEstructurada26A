#include<stdio.h>
int suma(int a,int b);

int main(){
    int a;
    int b;
    int c;
    printf("Dame un numero:");
    scanf("%d",&a);
    printf("\nDame un numero:");
    scanf("%d",&b);
    c = suma(a,b);
    printf("\nLa suma es: %d",c);
}
int suma(int a,int b){
    return a+b;
}
