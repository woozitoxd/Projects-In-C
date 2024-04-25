/*Desarrollar un programa que al ejecutarlo cuente la cantidad de registros con edad
mayor a 50 a�os que tiene el archivo �empleados�. Al mismo tiempo, debe permitir
que el usuario pueda buscar y acceder a la info de un determinado empleado
ingresando el n�mero de legajo. Cabe destacar que el usuario puede seguir
haciendo b�squedas hasta tanto ingrese el legajo 0. En ese momento, finalizar la
ejecuci�n e informar la cantidad de registros con edad mayor a 50 a�os.
NOTA: Deber� generar un archivo binario de empleados para poder realizar
pruebas. Queda a su criterio la definici�n del �struct� necesario.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct registro {
    char nombre[50];
    char apellido[50];
    int legajo;
    int edad;
};

int contarMayores50(const char* nombreArchivo);

int main() {
    const char* nombreArchivo = "empleados.txt";
    int cantidadMayores50 = contarMayores50(nombreArchivo);




    FILE *empleados, *binario;
    struct registro DATOS;
    int  contadorMayores = 0, legajoBuscar;
    char opcion;
    empleados = fopen("empleados.txt", "r");
    binario = fopen("empleados.bin", "wb");

    if (empleados == NULL || binario == NULL) {
        printf("\nError al abrir los archivos");
        return 1;
    }
    while (fscanf(empleados, "%49[^|]|%49[^|]|%d|%d\n", DATOS.nombre, DATOS.apellido, &DATOS.legajo, &DATOS.edad) == 4) {//Con la funcion fscanf, leo el empleados.txt especificando el formato del archivo, siguiendo la estructura "49caracteres|49caracteres|entero|entero"
        if (fwrite(&DATOS, sizeof(struct registro), 1, binario) != 1) { //Mientras leo el .TXT, escribo en el archibo .BIN, sin embargo si la condicion no se cumple, muestro en pantalla el error
            printf("No se logr� grabar las lineas\n");
            break;
        }
    }

    fclose(empleados);
    fclose(binario);

    // Buscar empleado por legajo
    do {
        contadorMayores = 0; // Reiniciar contador de empleados mayores de 50 a�os
        printf("\nIngrese el numero de legajo a buscar (ingrese 0 para salir): ");
        scanf("%d", &legajoBuscar);

        if (legajoBuscar == 0) {
            break;
        }

        binario = fopen("empleados.bin", "rb"); // Abrir archivo binario para lectura

        if (binario == NULL) {
            printf("\nError al abrir el archivo binario");
            return 1;
        }

        while (fread(&DATOS, sizeof(struct registro), 1, binario) == 1) {

            if (DATOS.legajo == legajoBuscar) {
                printf("Empleado encontrado:\n");
                printf("Nombre: %s\n", DATOS.nombre);
                printf("Apellido: %s\n", DATOS.apellido);
                printf("Legajo: %d\n", DATOS.legajo);
                printf("Edad: %d\n", DATOS.edad);

                break; // Salir del bucle al encontrar el empleado
            }
        }

        fclose(binario); // Cerrar archivo binario

        printf("\n�Desea buscar otro empleado? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');

        if (cantidadMayores50 >= 0) {
        printf("Cantidad de empleados mayores de 50 anios: %d\n", cantidadMayores50);
    };
    return 0;
}



int contarMayores50(const char* nombreArchivo) {


  FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de texto\n");
        return -1; // Retorna -1 en caso de error
    }

    struct registro datos;
    int contador = 0;

    while (fscanf(archivo, "%49[^|]|%49[^|]|%d|%d\n", datos.nombre, datos.apellido, &datos.legajo, &datos.edad) == 4) {
        if (datos.edad > 50) {
            contador++;
        }
    }

    fclose(archivo);
    return contador; // Retorna el contador de registros mayores a 50 a�os
}






//////////////////////*
/*while (!feof(empleados)) {


        while (fscanf(empleados, "%49[^|]|%49[^|]|%d|%d\n", datos.nombre, datos.apellido, &datos.legajo, &datos.edad) == 4) {

                switch (contador) {
                    case 1:
                        strcpy(DATOS.nombre, temporal);
                        break;
                    case 2:
                        strcpy(DATOS.apellido, temporal);
                        break;
                    case 3:
                        DATOS.legajo = atoi(temporal);
                        break;
                    case 4:
                        DATOS.edad = atoi(temporal);
                        break;
                }
                contador++;

            }
        }


    while (!feof(empleados)) {
        contador = 1; // Analizo el primer campo
        ptr = buffer;
        fgets(buffer, 100, empleados); // Leo linea del archivo
        var_ptr = temporal; // inicializo puntero a la variable temporal

        while (*ptr != '\n' && *ptr != '\0') {
            // Hasta no llegar al final, sigo leyendo los caracteres
            if (*ptr != '|') {
                *var_ptr = *ptr; // Mientras copio los caracteres
                var_ptr++; // Hago el incremento de los punteros
                ptr++;
            } else {
                // Fin de la linea
                *var_ptr = '\0'; // La cadena que apunta a temporal la finalizo con el \0
                ptr++; // Incremento el puntero a buffer

                switch (contador) {
                    case 1:
                        strcpy(DATOS.nombre, temporal);
                        break;
                    case 2:
                        strcpy(DATOS.apellido, temporal);
                        break;
                    case 3:
                        DATOS.legajo = atoi(temporal);
                        break;
                    case 4:
                        DATOS.edad = atoi(temporal);
                        break;
                }
                contador++;
                var_ptr = temporal;
            }
        }

        if (fwrite(&DATOS, sizeof(struct registro), 1, binario)) { // Copio toda la informacion que grab� al archivo binario
        } else {
            printf("No se logr� grabar las lineas\n");
        }
*/
