#include <stdio.h>
#include <math.h>


int main()
{
    int numA, numB, intervalo = 0;
printf("Ingrese dos números para calcular la suma del intervalo entre ellos: \n");
scanf("%d", &numA);
scanf("%d", &numB);



if (numA == 0 && numB == 0)
{
    printf("Los números ingresados son 0, inválidos para el cálculo.");
}
else
{
    if (numA > numB)
    {
        for (int i = numB; i <= numA; i++)
        {
            intervalo += i;
        }
    }
    else if (numB > numA)
    {
        for (int i = numA; i <= numB; i++)
        {
            intervalo += i;
        }
    }
    else
    {
        intervalo = numA; // Si los números son iguales, el intervalo es el propio num
    }

    printf("La suma del intervalo entre %d y %d, es: %d", numA, numB, intervalo - (numA + numB));
}


}
