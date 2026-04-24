#include <stdio.h>
struct alumno{
    char nombre[20];
    float calificacion;
    int actividades;
    int derecho;
};
void captura(char n[20], float calificacion, int actividades, int derecho);

int main(){
    struct alumno grupo[3];
    int c = 0;
    for(int i = 0; i<3; i++){
        printf("El alumno %d\n",c+1);
        captura(grupo[i].nombre, grupo[i].calificacion, grupo[i].actividades, grupo[i].derecho);
        c++;
    }
}

void captura(char n[20], float calificacion, int actividades, int derecho){
    printf("Dame el nombre: ");
    fgets(n, sizeof(n), stdin);

    printf("Dame la calificacion: ");
    scanf("%f",&calificacion);

    printf("Cuantas Actividades: ");
    scanf("%d",&actividades);

    printf("Tiene Derecho(1 SI)(0 NO): ");
    scanf("%d",&derecho);

    printf("\n////Los datos ingresados////");
    printf("\nNombre:%s",n);
    printf("Calificacion: %.2f",calificacion);
    printf("\nActividades: %d",actividades);
    printf("\nDerecho: %d\n\n",derecho);
    getchar();
}
