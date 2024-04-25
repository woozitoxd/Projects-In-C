#include <stdio.h>
#include <string.h>

struct libro
{
    int paginas;
    char nombres[50];
    float precio;
};

int main()
{
    struct libro tienda, negocio;

    tienda.paginas = 100;
    strcpy(tienda.nombres, "'Harry Potter'");
    tienda.precio = 250.50;

    printf("Los libros de la tienda tienen %d paginas\n", tienda.paginas);
    printf("El nombre del libro principal en la tienda es %s.\n", tienda.nombres);
    printf("El precio del libro Harry Potter es: %.2f\n\n", tienda.precio);

    negocio.paginas = 50;
    strcpy(negocio.nombres, "'El Sr. de los Anillos'");
    negocio.precio = 150;

    printf("Los demas de la tienda tienen %d paginas\n", negocio.paginas);
    printf("El nombre de los demas libros en la tienda es %s.\n", negocio.nombres);
    printf("El precio del libro %s es de: %.2f\n", negocio.nombres, negocio.precio);

    return 0;
}
