#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datos{
    char nombre[15];
    char apellido[15];
};
int main()
{
    struct datos persona; // variable persona tipo struct
    FILE * archivo; // Puntero a FILE de nomber "archivo" (puede llamarse de cualquier forma, le pongo archivo para que no haya confusiones
    char string[500]; // String que uso como buffer para usarlo asi puedo leer y mostrar por pantalla el archivo

    archivo = fopen("pruebaescribir.txt","wa"); // Abro el archivo en "wa" para crearlo si no existe y añadirle texto

    if(archivo==NULL){
         printf("\nError no se pudo crear el archivo"); // Si es NULL, muestro mensaje

    }else{
        strcpy(persona.nombre, "fabiana\n"); // declaro que los string nombre y apellido tomen los valores Fabiana Pacheco
        strcpy(persona.apellido, "pacheco"); //
        fprintf(archivo,"%s %s", persona.nombre, persona.apellido); // Escribo los string que declare en el archivo
    }

    fclose(archivo); // cierro archivo

    fopen("pruebaescribir.txt", "r"); // lo abro en solo lectura

        while(!feof(archivo)){ // mientras no este en el final del archivo
            fscanf(archivo,"%s",&string); //Leo el contenido en formato string
            printf("\n%s", string); // Muestro por pantalla el contenido del archivo
        }
        fclose(archivo); // cierro archivo
    return 0;
}
