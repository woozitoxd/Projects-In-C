#include <stdio.h>

int suma();

int main()
{
    int num, SumaTotal;

    printf(" Ingresar numero: ");
    scanf("%d", &num);
    fflush(stdin);

    SumaTotal=suma(num);

    printf("La suma de los digitos es: %d ", SumaTotal);

}

int suma(int x)

{
    if ( x == 0){
            return 0;
    }else{
        return x % 10 + suma(x / 10);   // el 10 porciento de X sumado a el valor de X divido 10, es la suma de los digitos
        }
}

