#include<stdio.h>
int main()
{
    int x,y,r;
    int opcionC;
    char opcionP;
do{
    printf("------Bienvenido------\n");
    printf("Escoje una opcion:\n");
    printf("(a)Analizar numero.\n");
    printf("(b)Calculadora.\n");
    printf("(c)Salir.\n");
    scanf("%c",&opcionP);

    switch(opcionP)
    {
        case 'a':
            printf("Seleccionaste analizar numero.\n");
            printf("Dame un numero: ");
            scanf("%d",&x);
            if (x%2==0)
                printf("Tu numero es %d es par.\n",x);
            else
                printf("Tu numero es %d es impar.\n",x);
            break;
        case 'b':
            printf("Seleccionaste calculadora.\n");
            printf("Dame dos numeros enteros\n");
            scanf("%d \n %d",&x,&y);
            printf("Dime que operacion quieres:\n");
            printf("(1)Suma\n");
            printf("(2)Resta\n");
            printf("(3)Multiplicación\n");
            printf("(4)Division\n");
            printf("(5)Salir\n");
            scanf("%d",&opcionC);

            switch(opcionC)
            {
                case 1:
                    r = x+y;
                    printf("\nLa suma es:%d",r);
                    break;
                case 2:
                    r = x-y;
                    printf("\nLa resta es:%d",r);
                    break;
                case 3:
                    r = x*y;
                    printf("\nLa multiplicacion es:%d",r);
                    break;
                case 4:
                    r = x/y;
                    printf("\nLa division es:%d",r);
                    break;
                case 5:
                    break;
                default:
                    printf("\nEsa funcion no es posible");
                    return 0;
            }

            break;
        case 'c':
            printf("------Vuelva pronto!------");
            return 0;
        default:
            break;
    }
} while(opcionP!='c');
    return 0;
}
