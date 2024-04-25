#include <stdio.h>

struct tienda
{
    int libros;
    char paginas;
    float precio;
};

int main()
{
    struct tienda libro[5];
    int a, b, c;

    for ( a = 0; a < 5; a++){
        libro[a].precio = 100 + a+2;
        printf("El libro %d cuesta %.2f \n", a+1, libro[a].precio);
    };
}
