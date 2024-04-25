#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

//

// Función para obtener el CUIL de la empresa desde el archivo "cuil.txt"
char *obtenerCUIL() {
    FILE *file = fopen("cuil.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo cuil.txt\n");
        exit(EXIT_FAILURE);
    }

    char *cuil = malloc(sizeof(char) * 20);
    if (cuil == NULL) {
        printf("Error de asignación de memoria\n");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%s", cuil);
    fclose(file);

    return cuil;
}


// Función para simular el guardado de la compra en la base de datos

void *enviarAFIP(void *arg) {
    int afipID = *(int *)arg;
    pthread_t id = pthread_self();

    printf("AFIP HILO Nro.: %d  - ID: [%d]\n", afipID, id);
    //  demora aleatoria entre 2 y 4 segundos
    srand(time(NULL));
    int demora = rand() % 3 + 2;  // Demora aleatoria entre 2 y 4 segundos
    sleep(demora);

    printf("Se ha enviado la notificación a la AFIP.\n");
    return NULL;
}


// Función para simular el guardado de la compra en la base de datos
void *guardarCompra(void *arg) {
int afipID = *(int *)arg;
    pthread_t id = pthread_self();
    printf("Guardar en Base HILO Nro.: %d - ID: [%d]\n", afipID, id);
    srand(time(NULL));
    int demora = rand() % 3 + 1;  // espero  entre 1 y 3 segundos
    sleep(demora);

    printf("Se ha guardado la compra en la base de datos.\n");
}


int main() {
    // Leer el CUIL de la empresa desde el archivo cuil.tx
    char *cuilObtenido = obtenerCUIL();
    
    int iva =0;
    float montoTotal = 0;
    // Solicitar datos del cliente
    char clienteDNI[20];
    printf("Ingrese DNI del cliente: ");
    scanf("%s", clienteDNI);
    printf("¿Corresponde IVA? (1: Sí, 0: No): ");
    scanf("%d", &iva);
    printf("Ingrese el monto a cobrar: ");
    scanf("%f", &montoTotal);

    pthread_t afipThread, dbThread; // Hilos para notificar a la AFIP y guardar en la base de datos
    int afipID = 1, dbID = 2; // numero de los procesos hijos

    // creo los hilos para las acciones concurrentes de simular q se envia al afip y se guarda en la base
    pthread_create(&afipThread, NULL, enviarAFIP, &afipID);
    pthread_create(&dbThread, NULL, guardarCompra, &dbID);



    // imprimo la factura si se han realizado las acciones concurrentes
    printf("\n------ FACTURA ------\n");
    printf("DNI del cliente: %s\n", clienteDNI);
    printf("CUIL de la empresa: %s\n", cuilObtenido);
    printf("Monto total: %.2f\n", montoTotal);
    if (iva==1) { //Si se ingresó q corresponde al IVA, entonces hago la matematca y muestrro por pantalla el ersultado
        float montoIVA = montoTotal * 0.21;
        printf("Monto IVA (21%%): %.2f\n", montoIVA);
        montoTotal += montoIVA;
        printf("Monto total con IVA: %.2f\n", montoTotal);
    }
    // esperar a que los hilos terminen
    pthread_join(afipThread, NULL);
    pthread_join(dbThread, NULL);
    return 0; //finalizo el proceso
}