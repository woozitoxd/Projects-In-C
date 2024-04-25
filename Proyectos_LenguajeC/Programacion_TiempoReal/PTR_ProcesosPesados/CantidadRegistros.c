/*Desarrollar un programa que al ejecutarlo cuente la cantidad de registros con edad
mayor a 50 a�os que tiene el archivo �empleados�. Al mismo tiempo, debe permitir
que el usuario pueda buscar y acceder a la info de un determinado empleado
ingresando el n�mero de legajo. Cabe destacar que el usuario puede seguir
haciendo b�squedas hasta tanto ingrese el legajo 0. En ese momento, finalizar la
ejecuci�n e informar la cantidad de registros con edad mayor a 50 a�os.
NOTA: Deber� generar un archivo binario de empleados para poder realizar
pruebas. Queda a su criterio la definici�n del �struct� necesario.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

struct registro {
    char nombre[50];
    char apellido[50];
    int legajo;
    int edad;
};

int contarMayores50(const char* nombreArchivo);

int main() {
    const char* nombreArchivo = "empleados.txt";
    int cantidadMayores50;

    pid_t pidDevuelto=0;

    pidDevuelto = fork();

    if(pidDevuelto != 0){
        printf("Soy el proceso padre %d y creé a %d \n", getpid(),pidDevuelto);
        cantidadMayores50 = contarMayores50(nombreArchivo);
        
        waitpid(pidDevuelto, NULL, 0);
                    if (cantidadMayores50 >= 0) {
                printf("Cantidad de empleados mayores de 50 años: %d\n", cantidadMayores50);
            };
    }else{
        printf("Soy el proceso hijo %d y mi padre es %d \n", getpid(), getppid());
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
                    printf("No se logró grabar las líneas\n");
                    break;
                }
            }

            fclose(empleados);
            fclose(binario);

            // Buscar empleado por legajo
            do {
                contadorMayores = 0; // Reiniciar contador de empleados mayores de 50 años
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

                printf("\n¿Desea buscar otro empleado? (s/n): ");
                scanf(" %c", &opcion);
            } while (opcion == 's' || opcion == 'S');


            return 0;
    }
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
        if (datos.edad > 50) { // Corregido aquí, debe ser mayor que 50
            contador++;
        }
    }

    fclose(archivo);
    return contador; // Retorna el contador de registros mayores a 50 años
}
