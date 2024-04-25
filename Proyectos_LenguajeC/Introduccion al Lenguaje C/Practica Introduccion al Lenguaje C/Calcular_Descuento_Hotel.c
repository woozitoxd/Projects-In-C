#include <stdio.h>

int main ()
{
    int estadia;
    float precio, km, descuento, total;

    printf("Indique la distancia que se recorrera en KM: ");
    scanf("%f", &km);

    printf("Cuantos dias estara alli: ");
    scanf("%d", &estadia);

    precio = km * 35.5;

    if(km > 800 && estadia > 7 )
    {
        printf("El costo normal es: %.2f\n", precio);

        descuento = (precio*30)/100;
        total = precio - descuento;
        printf("El descuento aplicable es del 30porciento. Entonces el costo final es de: %.2f", total);
        }
        else
        {
            printf("El precio del viaje es de %.2f", precio);
        }
    return 0;
}
