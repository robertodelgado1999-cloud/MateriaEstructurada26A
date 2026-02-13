#include<stdio.h>
int main(){
    int a;
    printf("Dame un numero:\n");
    scanf("%d",&a);
    a = a%2;
    if (a==1){
        printf("Tu numero es impar");
    }
    else{
        printf("Tu numero es par");
    }
    return 0;
}
