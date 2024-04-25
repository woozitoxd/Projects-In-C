#include <stdio.h>

int main()
{
    short num;
    float numero;
    char letra;
    printf("\nIngrese un short: ");
    scanf("%d",&num);
    fflush(stdin);
    printf("\nIngrese un float: ");
    scanf("%f",&numero);
    fflush(stdin);
    printf("\nIngrese un char: ");
    scanf("%c", &letra);
    fflush(stdin);

    printf("\n---------> Entero corto:%d --- Num float:%.2f --- Simbolo char: %c <---------", num, numero, letra);
    return 0;

}
