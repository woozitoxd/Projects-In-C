/* Desarrollar el código de un programa C con comportamiento a su elección y que
utilice punteros y struct.
*/

#include <stdio.h>
#include <string.h>

struct envio{
    char nombre[50];
    int numero;
};

void funcionPuntero(struct envio *caja);

int main()
{
    struct envio caja;

    printf("Ingrese nombre: ");
    scanf("%s", &caja.nombre);
    printf("Ingrese numero: ");
    scanf("%s", &caja.numero);

    funcionPuntero(&caja);
   // printf("%s, %d", caja.nombre, caja.numero);
}

void funcionPuntero(struct envio * caja)
{
    if(!strcmp(caja->nombre, "nike")){
        printf("Bien");
    }else{
      printf("Mal");
    }
}
