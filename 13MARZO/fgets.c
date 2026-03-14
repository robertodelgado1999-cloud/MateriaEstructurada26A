#include <stdio.h>
#include <string.h>

int main(){

    /////////// COMO IMPRIMIR UN STRING ////////////
    char nombre[25] = "Roberto Delgado";
    //scanf("%s",nombre); scanf solo lee una palabra no espacios entre strings
    printf("nombre: %s\n",nombre);


    //////////////// FGETS /////////////////////////
    char nombre1[16];
    printf("\nDame el nombre del alumno: ");
    fgets(nombre1,sizeof(nombre1),stdin);
    //fgets pregunta donde?, cuanto? y de donde? sacara la informacion
    //nombre le dice donde guardar la entrada, sizeof el tamaño que se espera y stdin la fuente de entrada de la consola
    printf("El nombre completo del alumno es: %s\n",nombre1);


    ////////////// LISTA DE NOMBRES /////////////////
    char lista[3][20];
    int longitud;

    for (int i = 0; i<3; i++){
        printf("Dame el nombre del alumno %d: ",i+1);
        fgets(lista[i],sizeof(lista[i]),stdin);
        lista[i][strcspn(lista[i], "\n")] = '\0';

        ////////////// strcspn(string complementary span) /////////////////
        /*Mide el lapso del string hasta que te encuentres con alguno de los siguientes caractes.
        Lo que hace es que devuelve el numero de caracteres antes de toparse con una coincidencia.
        Se coloca como segunda coordenada del array para que compare cada letra hasta toparse con un
        salto de linea (/n) es ahi donde le decimos que lo cambie por '\0' que marca el fin del string*/

        printf("El nombre %d es: %s\n\n",i+1,lista[i]);
    }
    for (int i = 0; i<3; i++){

        longitud = strlen(lista[i]);

        ///////////////strlen//////////////////////
        //Mide el tamaño del string y lo devuelve, guradandose en la variable longitud

        printf("\nLongitud de %s es: %d",lista[i],longitud);
    }

    ////////////// STRCPY ///////////////////////
    char name[20];
    strcpy(name,lista[1]); //strcpy copia el string guardado en un arreglo y lo guarda en otro con la forma (destino,origen)
    printf("\n\nEl nombre copiado fue: %s\n",name);

    ////////////// STRCAT////////////////////
    char n_1[20] = "Linus ";
    char apellido[20] = "Torvalds";
    strcat(n_1,apellido);
    //strcat concatena strings, name ahora contiene contiene tambien apellido
    //NOTA: strcat no agrega espacios por lo que se tiene que considerar para que aparezca correctamente
    printf("\nMVP: %s\n",n_1);

    ///////////// STRCMP /////////////////////
    if(strcmp(name,lista[1]) == 0)
        printf("\nEl nombre %s es igual a %s",name,lista[1]);
    //strcmp compara dos strings y los compara caracter por caracter basandose en el codigo ASCII hasta toparse una diferencia
    //Devuelve 0 si son iguales, <0 si el primer caracter es mayor al segundo, >0 si es viceversa.

    if(strcmp(name,lista[0]) != 0)
        printf("\nPero %s no es igual a %s\n",name,lista[0]);

    return 0;
}
