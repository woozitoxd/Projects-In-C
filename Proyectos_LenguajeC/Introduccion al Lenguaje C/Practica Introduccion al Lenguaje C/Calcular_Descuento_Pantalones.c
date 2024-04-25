#include <stdio.h>
int main(void) // 1 Pantalon = 100 pesos. mas de 5 y menos de 12 pantalones?=Descuento de 15%. mas de 12 descuento es = 30%
{
    int pantalones;
    float precio, descuento_menor, descuento_mayor;
    float pantalon = 100;

    printf(" -- EL COSTO DE CADA PANTALON ES DE $100 PESOS -- ");
    printf("\n --- SI COMPRA MAS DE 5, TIENE DESCUENTO DEL 15PORCIENTO --- ");
    printf("\n --- SI COMPRA MAS DE 12, TIENE DESCUENTO DEL 30PORCIENTO --- ");
    printf("\n Ingrese la cantidad de pantalones que desee comprar: ");
    scanf("%d", &pantalones);

    if(pantalones > 0 && pantalones < 5)
    {
        precio= pantalones*pantalon;
        printf("No hay descuento. El costo total es de: %.2f", precio);
    }
    else if(pantalones >= 5 && pantalones < 12)
        {
        descuento_menor = pantalon * 0.15;
        precio= (pantalon-descuento_menor)*pantalones;
        printf("\nDescuento del 15porciento. El costo es de: %.2f", precio);
        }
    else if(pantalones >= 12)
    {
        descuento_mayor = pantalon * 0.30;
        precio= (pantalon-descuento_mayor)*pantalones;
        printf("\nDescuento del 30porciento. El costo es de: %.2f", precio);
    }else{
    printf("Error, inicia denuevo gato o te surto");}
return 0;
}
