#include <stdio.h>

int main()
{
    int dia_a, mes_a, anio_a;
    int dia_n, mes_n, anio_n;

    printf("Ingresar dia actual: ");
    scanf("%d", &dia_a);
    fflush(stdin);
    printf("\nIngresar mes actual: ");
    scanf("%d", &mes_a);
    fflush(stdin);
    printf("\nIngresar anio actual: ");
    scanf("%d", &anio_a);
    fflush(stdin);
    printf("\nIngresar el dia de nacimiento: ");
    scanf("%d", &dia_n);
    fflush(stdin);
    printf("\nIngresar el mes de nacimiento: ");
    scanf("%d", &mes_n);
    fflush(stdin);
    printf("\nIngresar el anio de nacimiento: ");
    scanf("%d", &anio_n);

    //DIAS CONTADOS DESDE QUE NACIO EL WN
    if(dia_a < dia_n)
    {
        dia_a = dia_a + 30 - dia_n;
        mes_a = mes_a - 1;
    }else{
    dia_a = dia_a - dia_n;}
    //Meses contados del wn
    if (mes_a < mes_n)
    {
        mes_a = mes_a + 12 - mes_n;
        anio_n = anio_n + 1;
    }
    else
    {
        mes_a = mes_a - mes_n;
    }
    //años del wn ysi
    anio_a = anio_a - anio_n;

    printf("\nVos tenes %d dias %d meses %d anios", dia_a, mes_a, anio_a);
    return 0;

}
