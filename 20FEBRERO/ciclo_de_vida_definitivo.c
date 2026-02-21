#include<stdio.h>
int main(){
    int promedio;
    int suma;
    int calificacion;
    int numero;
    int letra;
    char buffer[50];/*A lo largo del desarrollo de este programa sufrí bastante para solucionar el problema relacionado
    con la entrada incorrecta de caracteres al momento de pedir datos al usuario, es por ello que hice uso de un metodo
    que utilizamos en 1er semestre para solucionarlo. Basicamente se utiliza una variable de tipo caracter para guardar
    la entrada erronea del usuario,en este caso lo declare como un arreglo de caracteres para evitar el desbordamiento
    de buffer,esto es porque si lo declaro como un caracter el espacio de memoria seria solo para una sola letra y dado
    que existe la posibilidad que el usuario ingrese mas caracteres el programa fallaria al intentar escribir en la variable.
    Es por ello que lo declare arbitrariamente como un arreglo de longitud 50 para evitar este problema. Aun asi soy consciente
    de que no es la forma más optima de solucionarlo porque se desperdicia mucha memoria,pero por el momento lo tomare como
    solucion provicional. */
    int porcentaje;
    int aprobadas;

    printf("\n-----HOLA! BIENEVENIDO AL CALCULADOR DE PROMEDIOS-----\n");

    do{ //En esta parte igualo las variables en 0 por si el usuario para borrar los datos del anterior calculo.
        suma = 0;
        aprobadas = 0;
        porcentaje = 0;
        promedio = 0;

        printf("\nIngresa la cantidad de calificaciones que tienes actualmente [Salida(0)]: ");
        letra=scanf("%d",&numero); /*Aqui es donde determino si es un numero o un caracter lo que se ingreso. En C cuando se utiliza
        scanf basicamente se le trata como una funcion que le devuelve un valor a C para indicar si su tarea fue exitosa
        o no, en el caso de scanf este le dice el numero de datos que pudo leer correctamente,por ejemplo: si se esperaban leer 3
        datos y todos fueron correctos devolvera 3,en este caso si el usuario coloca un caracter scanf no podra leerlo y por lo tanto
        en la variable letra se guardará 0 y si es un numero si lo podra leer y lo guardará como 1.*/

        if(letra!=1){ //Siendo asi aqui nomas hago la condicional para validar que si es un numero.
            printf("\nEsa es una letra!!!, Favor de ingresar un numero.\n"); //Si es distinto de ello aparece un mensaje de error.
            scanf("%s",&buffer);//Aqui guardo los caracteres ingresados en la variable, leyendolos como un string.
        } else {
            if(numero < 0){//Como no puedes tener numeros negativos añado la condicional para que muestre un error si se introducen.
                printf("\nEsa entrada no es posible, Favor de ingresar un numero positivo.\n");
            } else if (numero > 0){//Aqui nos aseguramos que en caso de colocar la accion salir(0) no entre en el bucle for.
                for (int i = 0;i < numero; i++) {//Aqui comienzo con el contador para sumar todas las calificaciones
                    printf("\nIngrese la calificacion: ");
                    letra=scanf("%d",&calificacion);

                    if(letra != 1){ //Nuevamente aqui repito la condicional para cuando coloque un caracter enves de un numero.
                        printf("\nEsa es una letra!, Favor de ingresar una calificacion permitida.\n");
                        scanf("%s",&buffer);
                        i--;
                    } else if(calificacion<0 || calificacion>100){//Ademas añado la condicion else if para que este en el rango permitido.
                        printf("\nEsa calificacion sale del rango permitido!(0-100)");//En caso de ser negativo mayores a 100 mostrara un error.
                        printf("\nFavor de introducir otro numero.\n");
                        i--;
                    } else {
                        if(calificacion >= 60){//Aqui empieza el contador de materias aprobadas si son igual o superior a 60
                            aprobadas++;
                        }
                        suma += calificacion;
                    }
                }
                promedio=suma/numero; //Aqui uso la formula del promedio.
                porcentaje=(aprobadas*100)/numero;//Aqui uso la del porcentaje.

                printf("\nTu promedio es:%d",promedio); //Finalmente con un print muestro sus resultados.
                printf("\nTu porcentaje de materias aprobadas es: %d%%",porcentaje);
                printf("\nTienes un total de %d/%d de materias aprobadas\n",aprobadas,numero);

                printf("\nDesea continuar? Si(1) No(0): ");//aqui coloco la pregunta por si quiere repetir con otro calculo.
                scanf("%d",&numero);//aqui podria colocar nuevamente para detectar caracteres pero ya no lo vi necesario.
            }
        }
    } while(numero!=0);

    printf("\nGracias vuelva pronto!");
    return 0;
}


