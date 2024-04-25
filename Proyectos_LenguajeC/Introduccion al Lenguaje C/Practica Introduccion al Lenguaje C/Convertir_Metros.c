#include <stdio.h>
#include <math.h>

int main()
{

    int convertir;
    float metros, convertidos;
    printf("Ingrese los datos a convertir");
    printf("\n1_Convertir metros a kilometros.\n2_Convertir centimetros a decimetros.\n3_Convertir metros a centimetros\n");
    scanf("%d", &convertir);


   switch(convertir)
    {
    case 1:
        printf("Ingrese la cantidad de metros para convertir a kilometros: ");
        scanf("%f", &metros);

        convertidos= metros*0.001;
        printf("Los %.2f metros convertidos en KM corresponde a: %.2f ", metros, convertidos);
        break;
    case 2:
        printf("Ingrese la cantidad de metros para convertir a centimetros: ");
        scanf("%f", &metros);

        convertidos= metros*100;
        printf("Los %.2f metros convertidos a centimetros corresponde a: %.2f", metros, convertidos);
        break;
    case 3:
        printf(     "Ingrese la cantidad de metros para convertir a decimetros:"    );
        scanf("%f", &metros);

        convertidos= metros*10;
        printf("Los %.2f metros convertidos a decimetros son: %.2f ", metros, convertidos);
        break;
        default:
        printf("NOS RE VIMOS");
    }
    return 0;
}
