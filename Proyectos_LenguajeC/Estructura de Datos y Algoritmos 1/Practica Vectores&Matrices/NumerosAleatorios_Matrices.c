/* Mostrar matriz 3x3 de numeros aleatorios */

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void ingresar();
void imprimir();

int main()
{
    int matriz[3][3];

    ingresar(matriz);
    imprimir(matriz);

    return 0;
}


void ingresar(int matriz[3][3])
{
    int a, b;

    srand(time(NULL));

    for ( a = 0; a < 3; a++){
        for ( b = 0; b  < 3; b++){
            matriz[a][b] = rand()%10;
        }
    }
}

void imprimir(int matriz[3][3])
{
    int i, j;

    for ( i = 0; i < 3; i++){
        for ( j = 0; j  < 3; j++){
            printf(" %d  ", matriz[i][j]);
        }
        printf("\n");
    }
}
