


#include <stdio.h>

int main()
{

    int cant=0;  //Determina la cantidad de elementos por teclado
    float num[50];  //almacena los elementos en un vector de numeros flotantes
    int x=0;
    float max, min;
    int total=0;
    float promedio=0;

    scanf("%d", &cant);

    for(int x = 0; x<cant; x++){
        printf("Elemento Nro [%d]: ", x+1);
        scanf("%f", &num[x]);
    }

    max = num[0];
    min = num[0];

   for (int i=0; i<cant; i++ ){
        if ( num[i] > max ){
            max = num[i];
        }
        if ( num[i] < min){
            min = num[i];
        }
         total+=num[i];
    }

    promedio = total/cant;
    printf("\nEl numero %.2f es el mayor ", max);
    printf("\nEl numero %.2f es el es menor\n", min);
    printf("\nEl promedio es : %.2f ", promedio);

}
