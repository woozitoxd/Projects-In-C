/* Comparar matrices ingresando valores por pantalla */

#include <stdio.h>

void ingresar();
void introducir();
void comparacion();
void mostrar();

int main()
{
    int matrizUno[2][2];
    int matrizDos[2][2];

    ingresar(matrizUno);
    introducir(matrizDos);
    comparacion(matrizUno, matrizDos);
    mostrar(matrizUno, matrizDos);

    return 0;
}

void ingresar(int matrizUno [2][2])
{
    int x, z;

    for ( x = 0; x < 2; x++){
        for ( z = 0; z < 2; z++){
            printf("Matriz Uno[%d][%d]: ", x+1, z+1);
            scanf("%d", &matrizUno[x][z]);
            fflush(stdin);
        }
    }
}

void introducir(int matrizDos[2][2])
{
    int i, j;

    for ( i = 0; i < 2; i++){
        for ( j = 0; j < 2; j++){
            printf("Matriz Dos[%d][%d]: ", i+1, j+1);
            scanf("%d", &matrizDos[i][j]);
            fflush(stdin);
        }
    }
}



void comparacion(int matrizUno[2][2], int matrizDos[2][2])
{
    int a, b, aux = 0;

    for ( a = 0; a < 2; a++){
        for (b = 0; b < 2; b++){
            if (matrizUno[a][b] != matrizDos[a][b]){
                aux = 1;
            }
        }
    }

    if ( aux == 0){
        printf ("Son iguales.\n\n");
    }else{
        printf("Son distintas.\n\n");
    }
}


void mostrar(int matrizUno[2][2], int matrizDos[2][2])
{
    int t, y;

    printf("Matriz Uno:\n");
    for ( t = 0; t < 2; t++){
        for ( y = 0; y  < 2; y++){
            printf("%d   ", matrizUno[t][y]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Matriz Dos:\n");
    for ( t = 0; t < 2; t++){
        for ( y = 0; y  < 2; y++){
            printf("%d   ", matrizDos[t][y]);
        }
        printf("\n");
    }
    printf("\n");
}
