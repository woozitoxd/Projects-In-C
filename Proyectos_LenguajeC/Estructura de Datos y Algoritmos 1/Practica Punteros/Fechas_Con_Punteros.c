#include <stdio.h>
#include <conio.h>
#define MAX 10


struct fecha{
    int dia;
    int mes;
    int anio;
};

void validar(struct fecha *hoy);

int main()
{
    struct fecha hoy;

    printf("\n ¡BIENVENIDO A MI PROGRAMA! %d\n\n", MAX);

    printf(" Ingrese el dia: ");
    scanf("%d", &hoy.dia);

    printf(" Ingrese numero del mes: ");
    scanf("%d", &hoy.mes);
    fflush(stdin);

    printf(" Ingrese el anio: ");
    scanf("%d", &hoy.anio);
    fflush(stdin);

    validar(&hoy);
}

void validar(struct fecha *hoy)
{
    switch(hoy->mes){
        case 1:
        printf("\n %d ", hoy->dia);
        printf(" de Enero del %d \n", hoy->anio);
        break;

        case 2:
        printf("\n %d ", hoy->dia);
        printf(" de Febrero del %d \n", hoy->anio);
        break;

        case 3:
        printf("\n %d ", hoy->dia);
        printf(" de Marzo del %d \n", hoy->anio);
        break;

        case 4:
        printf("\n %d ", hoy->dia);
        printf(" de Abril del %d \n", hoy->anio);
        break;

        case 5:
        printf("\n %d ", hoy->dia);
        printf(" de Mayo del %d \n", hoy->anio);
        break;

        case 6:
        printf("\n %d ", hoy->dia);
        printf(" de Junio del %d \n", hoy->anio);
        break;

        case 7:
        printf("\n %d ", hoy->dia);
        printf(" de Julio del %d \n", hoy->anio);
        break;

        case 8:
        printf("\n %d ", hoy->dia);
        printf(" de Agosto del %d \n", hoy->anio);
        break;

        case 9:
        printf("\n %d ", hoy->dia);
        printf(" de Septiembre del %d \n", hoy->anio);
        break;

        case 10:
        printf("\n %d ", hoy->dia);
        printf(" de Octubre del %d \n", hoy->anio);
        break;

        case 11:
        printf("\n %d ", hoy->dia);
        printf(" de Noviembre del %d \n", hoy->anio);
        break;

        case 12:
        printf("\n %d ", hoy->dia);
        printf(" de Diciembre del %d \n", hoy->anio);
        break;

        default:
            printf(" Fecha invalida! \n");
    }
}
