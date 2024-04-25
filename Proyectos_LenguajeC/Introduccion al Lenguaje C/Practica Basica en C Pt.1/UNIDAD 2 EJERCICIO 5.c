#include <stdio.h>
#define NUMERO "\Ingresar un numero entero: "
#define REAL "\nIngresar un numero real: "
#define SIMBOLO "\nIngresar un caracter: "
#define SHORT "\nIngresar un entero corto: "

int main()
{
    int entero;
    float real;
    char letra;
    short corto;

    printf(NUMERO);
    scanf("%d", &entero);
    fflush(stdin);

    printf(REAL);
    scanf("%f",&real);
    fflush(stdin);

    printf(SHORT);
    scanf("%s", &corto);
    fflush(stdin);

    printf(SIMBOLO);
    scanf("%c", &letra);
    fflush(stdin);

    return 0;
}
