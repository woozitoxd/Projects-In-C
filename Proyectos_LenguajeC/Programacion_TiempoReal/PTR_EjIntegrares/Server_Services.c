#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void agregarLog(const char *archivo, const char *mensaje) {


    FILE *file = fopen(archivo, "a");  // abro el archivo en modo append ("a")
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    fprintf(file, "%s\n", mensaje);  // escribo el mensaje en el archivo
    fclose(file);  // cierro el archivo
}

int main() {
    int num;

    do {
        printf("Ingrese el nuemro del cmd a ejecutar (0 para salir):\n");
        scanf("%d", &num);

        pid_t pid;
        char *comandoArgs[4]; //un puntero vector que tiene 4 posiciones, con esto puedo trabajar los comandos y  argumentos para los mismos
        switch (num) {
            case 1:
                comandoArgs[0] = "free"; //comando free para indicar la memoria utilizada en el momento. 
                comandoArgs[1] = NULL;
                agregarLog("memoria.log", "Se ejecuto el cmd de memoria.");//en "memoria.log" agrego que se ejecuto el comando
                break;
            case 2:
                comandoArgs[0] = "ping";  //comando ping para comprobar si existe conexion a la ip indicada
                comandoArgs[1] = "8.8.8.8"; //ip como argumento para ping
                comandoArgs[2] = NULL;
                agregarLog("ping.log", "Se ejecuto el cmd de ping.");
                break;
            case 3:
                comandoArgs[0] = "df";  //comando df para devolver el espacio utilizado en cada uno de los discos
                comandoArgs[1] = "-h"; //argumento del df para que el resultado devuelto se muestre en formato de Gigas
                comandoArgs[2] = NULL;
                agregarLog("disco.log", "Se ejecuto el cmd para saber el espacio en disco.");
                break;
            default:
                printf("Numero ingresado no es valido, seleccione entre 1 y 3 - (o se finalizó seleccionado Nro. 0)\n");
                continue;
        }

       pid = fork();
        if (pid == 0) {
            // Proceso hijo
            printf("Soy el proceso hijo [%d], fui creado por mi padre [%d]\n", getpid(), getppid());
            execvp(comandoArgs[0], comandoArgs);
            perror("execvp");
            return 1; 
        } else if (pid < 0) {
            // Error al crear el proceso hijo
            perror("fork");
            return 1; 
        } else {
            // Proceso padre
            waitpid(pid, NULL, 0); // Esperar a que el hijo termine
        }

    } while (num != 0);

    printf("Proceso finalizado.\n");
    return 0;
}