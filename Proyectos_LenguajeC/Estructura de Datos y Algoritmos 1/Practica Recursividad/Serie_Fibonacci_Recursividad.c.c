#include <stdio.h>

double fibonacci(int);

int main()
{
    int numer;

    printf("Ingresar un numero de elementos: ");
    scanf("%d", &numer);

    printf("Numero de Fibonacci en %d es:  %.0f\n", numer, fibonacci(numer));

    for( int x= 1; x<=numer; x++){
        printf( "%.0f ", fibonacci(x));// mostrará la cantidad de elementos que se ingresó
    }

}

double fibonacci(int A)
{
    if ( A == 0 ){  // Si A es igual a 0 o 1, retornara el mismo resultado que se ingresó por pantalla.
        return 0;
    }else{
        if( A == 1){
            return 1;
        }else{
            return (fibonacci(A -1) + fibonacci(A -2) );
        };
    }
}
