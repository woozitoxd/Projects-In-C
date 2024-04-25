#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// esta funcion es la q ejecutan los hilos
void *threadFunction(void *arg) {
    pthread_t tid = pthread_self(); // Obtenemos el identificador del hilo actual
    int numHilo = *((int *)arg); //castep el puntero void recibido a  entero para trabajar con el argumento q recibi
                                //y poder usarlo en el switch
    switch (numHilo) {
        case 1:
            printf("Hilo %d: Soy el primer hilo %d y estoy imprimiendo este mensaje.\n", numHilo, tid);
            break;
        case 2:
            printf("Hilo %d: Soy el segundo hilo %d y estoy imprimiendo este mensaje.\n", numHilo, tid);
            break;
        case 3:
            printf("Hilo %d: Soy el tercer hilo %d y estoy imprimiendo este mensaje.\n", numHilo, tid );
            break;
        case 4:
            printf("Hilo %d: Soy el cuarto hilo %d y estoy imprimiendo este mensaje.\n", numHilo, tid );
            break;
        case 5:
            printf("Hilo %d: Soy el quinto hilo %d y estoy imprimiendo este mensaje.\n", numHilo, tid );
            break;
        case 6:
            printf("Hilo %d: Soy el sexto hilo %d y estoy imprimiendo este mensaje.\n", numHilo, tid );
            break;
        default:
            printf("Hilo %d: No se asignó ninguna tarea específica.\n", numHilo);
            break;
    }
}

int main() {
    pthread_t threads[6]; // vector para almacenas los hilos
    int thread_arg[6] = {1,2,3,4,5,6};  //vector de argumentos para los hilos
    int i;

    // creo los primeros 3 hilos
    for (i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, threadFunction, &thread_arg[i]);//argumentos importantes: la dir_memoria en la que tenemos el ID del hilo, funcion que ejecutaremos y el argumento que le pasamos para que trabaje con la funcion
   
    }

    // espero que los primeros 3 hilos finalicen
    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("En proceso...\n");

    // siguientes 3 hilos
    for (i = 3; i < 6; i++) { //Inicializo i con 3 y recorro hasta 6, para asi crear los ultimos 3 hilos
        pthread_create(&threads[i], NULL, threadFunction, &thread_arg[i]); //argumentos importantes: la dir_memoria en la que tenemos el ID del hilo, funcion que ejecutaremos y el argumento que le pasamos para que trabaje con la funcion
    }

    // espero que finalicen todos los hilos creados
    for (i = 0; i < 6; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("FIN\n");

    return 0;
}