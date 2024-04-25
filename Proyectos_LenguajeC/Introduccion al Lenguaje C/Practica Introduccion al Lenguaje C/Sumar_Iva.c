#include <stdio.h>

int main(void) //CALCULAR EL COSTO DE UN PRODUCTO POR LA CANTIDAD DEL MISMO Y LUEGO DIVIDIRLO POR EL 21% DEL IVA
{
    float costo, cantidad, iva, precio, total;
    printf("Ingrese el costo de un producto: ");
    scanf("%f", &costo);
    fflush(stdin);
    printf("\nIngrese la cantidad de productos: ");
    scanf("%f", &cantidad);

    precio= costo*cantidad;
    iva= (precio*21)/100;
    total= precio + iva;

    printf("\nEl precio normal es de: %.2f ", precio);
    printf("\nAplicando el IVA de 21porciento el total seria: %.2f", total);
    return 0;
}
