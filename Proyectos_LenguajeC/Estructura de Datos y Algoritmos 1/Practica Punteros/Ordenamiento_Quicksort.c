#include <stdio.h>


void quicksort(int *,int,int);

int main(){
    int a[] = { 7, 12, 1, 2, 0, 15, 4, 11, 9};

	printf("\n\nVector desordenado:  ");
	for(int i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

	quicksort( a,0, 8);

	printf("\n\nVector ordenado:  ");
	for(int i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

    return 1;
}

void quicksort(int * vector, int primero, int ultimo)
{
    int i, j, central;
    int pivote, tmp;
    //calculo el pivote tomando el elemento central
    central = (primero + ultimo)/2;
    pivote = *(vector+central); // guardo el valor del pivote
    i = primero;
    j = ultimo;

    printf("\n%d, %d, %d, %d, %d, %d\n", pivote, central, primero, ultimo, i, j);
    do {
        while (*(vector+i) < pivote) i++;
        while (*(vector+j) > pivote) j--;
        if (i<=j){
            tmp = *(vector+i);
            *(vector+i) = *(vector+j);
            *(vector+j) = tmp; /* intercambia vector[i] con vector[j] */
            i++;
            j--;
        }
    }while (i <= j);

    if (primero < j)
        quicksort(vector, primero, j);// mismo proceso con sublista izqda
    if (i < ultimo)
        quicksort(vector, i, ultimo);  //mismo proceso con sublista drcha
}
