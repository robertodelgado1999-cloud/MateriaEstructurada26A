#include<stdio.h>
int main(){
    int x = 5;
    int *p = &x;
    int **c = &p;
    printf("%d",**c);
    return 0;
}
