#include<stdio.h>
int main(){
    int a;
    int b = 1;
    printf("Introduce un numero: \n");
    scanf("%d",&a);
    if (a<=1){
        b=0;
    }
    else {
        for(int i=2;i<=a/2;i++){
            if(a%i==0){
                b++;
                break;
            }
        }
    }
    if(b==1){
        printf("El numero %d es primo.\n",a);
    }
    else {
        printf("El numero %d no es primo.\n",a);
    }
    return 0;
}
