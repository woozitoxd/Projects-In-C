#include <stdio.h>
#define MAX 10

struct MaxMin
{
    float max;
    float min;
};

void buscar(struct MaxMin * pnumeros, float *vec, int cantidad);

int main()
{
    struct MaxMin resultado;

    int cant=0;  //Determina la cantidad de elementos por teclado
    float num[30];  //almacena los elementos en un vector de numeros flotantes

    printf("Ingresar cantidad de elementos: \n");
    scanf("%d", &cant);


    for(int x = 0; x<cant; x++){
    printf("Elemento Nro [%d]: ", x+1);
    scanf("%f", &num[x]);
    }

    buscar(&resultado, num, cant);
}

void buscar(struct MaxMin * pnumeros, float *vec, int cantidad)
{
    pnumeros->max = *(vec);
    pnumeros->min = pnumeros->max;

    int i;
    for ( i=0; i<cantidad; i++ ){
        if ( *(vec+i) > pnumeros->max ){
            pnumeros->max= *(vec+i);
        }
        if ( *(vec+i) < pnumeros->min){
            pnumeros->min = *(vec+i);
        }
    }
    printf("\nEl numero %.2f es el mayor ", pnumeros->max);
    printf("\nEl numero %.2f es el es menor\n", pnumeros->min);
}

