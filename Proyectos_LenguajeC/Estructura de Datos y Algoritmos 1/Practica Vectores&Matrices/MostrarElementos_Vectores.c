/* Mostrar los ingresos que se le dieron al vector */

#include <stdio.h>

void funcion();
void imprimir();

int main()
{
    int vector[2];

    funcion(vector);

    imprimir(vector);
}

void funcion(int A[])
{
    int i;

    for( i = 0; i < 2; i++){
        printf("Introducir valor para vector: ");
        scanf("%d", &A[i]);
        fflush(stdin);
    }
}

void imprimir(int B[])
{
    int x;

    for ( x = 0; x < 2; x++){
        printf("%d, ", B[x]);
    }
    printf("\n");
}
