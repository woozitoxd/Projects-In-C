#include <stdio.h>
#include <string.h>

struct planilla
{
    int edad;
    char nombre[50];
    char empleo[50];
    int dni;
};

int main()
{
    struct planilla work, job;


    printf("-- 'Rellenar los datos de la planilla Nro 1.' --\n");
    printf("Ingresa tu nombre: ");
    fgets(work.nombre,50, stdin);

    printf("Ingresa tu empleo: ");
    fflush(stdin);
    fgets(work.empleo, 50, stdin);

    printf("Ingresa tu edad: ");
    scanf("%d", &work.edad);

    printf("Ingresa tu dni: ");
    fflush(stdin);
    scanf("%d", &work.dni);

///////////////////////////////////////////////////////////////////////////////////////
    printf("-- 'Rellenar los datos de la planilla Nro 2.' -- \n");
    printf("Ingresa tu nombre: ");
    fflush(stdin);
    fgets(job.nombre,50, stdin);

    printf("Ingresa tu empleo: ");
    fflush(stdin);
    fgets(job.empleo, 50, stdin);

    printf("Ingresa tu edad: ");
    fflush(stdin);
    scanf("%d", &job.edad);

    printf("Ingresa tu dni: ");
    fflush(stdin);
    scanf("%d", &job.dni);




    printf("\n --- Los datos de la primer planilla son los siguientes: ---\n");
    printf("Nombre de la primer persona: %s ", work.nombre);
    printf("Empleo de la primer persona: %s ", work.empleo);
    printf("Edad de la primer persona: %d \n", work.edad);
    printf("DNI de la primer persona: %d \n\n", work.dni);

    printf("\n --- Los datos de la Segunda planilla son los siguientes: ---\n");
    printf("Nombre de la segunda persona: %s ", job.nombre);
    printf("Empleo de la segunda persona: %s ", job.empleo);
    printf("Edad de la segunda persona: %d \n", job.edad);
    printf("DNI de la segunda persona: %d ", job.dni);

    return 0;
}
