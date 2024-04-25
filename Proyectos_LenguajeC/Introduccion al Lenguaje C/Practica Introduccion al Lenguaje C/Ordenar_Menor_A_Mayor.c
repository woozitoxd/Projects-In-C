#include <stdio.h>

int main(void)
{
    float num1, num2, num3;
    printf("Ingresar tres numeros:\n");
    scanf("%f %f %f", &num1, &num2, &num3);

    if((num1 > num2) && (num1 > num3))
    {
        if( num2 > num3){
            printf("El orden es: %.1f --- %.1f --- %.1f\n", num3, num2, num1);
        }
        else{
            printf("El orden es: %.1f --- %.1f --- %.1f\n", num2, num3, num1);
        }
    }
    if((num2 > num1) && (num2 > num3))
    {
        if(num1 > num3)
        {
            printf("El orden es: %.1f --- %.1f --- %.1f\n", num3, num1, num2);
        }
        else
        {
            printf("El orden es: %.1f --- %.1f --- %.1f\n", num1, num3, num2);
        }
    }
    if((num3 > num1) && (num3 > num2))
    {
        if(num1 > num2)
        {
            printf("El orden es: %.1f --- %.1f --- %.1f\n", num2, num1, num3);
        }
        else
        {
            printf("El orden es: %.1f --- %.1f --- %.1f\n", num1, num2, num3);
        }
    }
    else
    {
        printf("Los numeros %.1f %.1f %.1f son iguales", num1, num2, num3);
    }
}
