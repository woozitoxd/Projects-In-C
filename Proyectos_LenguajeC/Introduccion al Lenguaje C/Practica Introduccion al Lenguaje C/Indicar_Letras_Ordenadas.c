#include <stdio.h>

int main(void)
{
    char letra1, letra2; //Saber si las letras ingresadas estan en orden, desorden o son iguales.
    printf("Ingrese dos letras minusculas del abecedario porfis:\n");
    scanf("%c %c",&letra1, &letra2);


   if ((letra1 >= 'a' && letra1 <= 'z') && (letra2 >= 'a' && letra2 <= 'z'))
    {
        if((letra1 > letra2) && (letra2 < letra1))
        {
            printf("Letras DESORDENADAS.\n");
        }
        else
        {
            if ((letra1 < letra2) && (letra2 > letra1))
            {
                printf("Letras ORDENADAS.\n");
            }
            else
            {
                if(letra1 == letra2)
                {
                    printf("Letras IGUALES.\n");
                }
            }
        }
    }
}
