#include <stdio.h>
void mostrar(int V[][3]);

int main(){
    int V[3][3] = {{1,2,3},{4,5,6}};
    mostrar(V);
}

void mostrar(int V[][3]){
    printf("Exito!\n");
    printf("%d",V[0][0]);
}
