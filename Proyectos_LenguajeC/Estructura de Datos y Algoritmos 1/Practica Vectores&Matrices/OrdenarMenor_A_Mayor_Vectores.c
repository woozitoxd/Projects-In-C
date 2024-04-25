/* Ordenar los ingresos que se hicieron por pantalla de menor a mayor */

#include <stdio.h>

void funcionOrdenar();
void imprimir();
void ingresar();

int main()
{
    int vector[11];

    ingresar(vector);
    funcionOrdenar(vector);
    imprimir(vector);

    return 0;
}

void ingresar(int H[])
{
    int i;

    for( i = 0; i < 10; i++){
        printf("Introducir valor para vector: ");
        scanf("%d", &H[i]);
        fflush(stdin);
    }
}

void funcionOrdenar(int A[])
{
    int menor, mayor, aux;

    for ( menor = 0; menor < 10; menor++){
        for ( mayor = menor; mayor < 10; mayor++){
            if ( A[menor] > A[mayor]){
                aux = A[menor];
                A[menor] = A[mayor];
                A[mayor] = aux;
            }
        }
    }
}

void imprimir(int B[])
{
    int x;

    for ( x = 0; x < 10; x++){
        printf("%d, ", B[x]);
    }
    printf("\n");
}
