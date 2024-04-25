/*
Desarrollar un sistema, que simule la carrera de caballos, de la línea de
partida tenemos un total de seis caballos.

La pista cuenta con 100 metros, cada caballo avanza de forma aleatoria entre
2 y 3 metros por salto.
Los caballos 1 y 5, son siempre favoritos, ellos avanzan entre 3 y 4 metros
por salto.

Cada caballo deberá ser considerado como un proceso o como un hilo.
Informar el tiempo de cada caballo hasta llegar a la meta. No es necesario
saber cuál fue el caballo ganador.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define DISTANCIA 100
#define CANTIDAD_CAB 6

struct caballoArgumento{
    int IDcaballo;
    int distancia;
};

void *metrosCaballo(void *arg) {
    struct caballoArgumento *argumentos = (struct caballoArgumento *)arg;
    srand(time(NULL) + argumentos->IDcaballo);
    pthread_t id = pthread_self();
    clock_t tiempo_inicio, tiempo_final;
    double segundos;
    tiempo_inicio = clock();

    while (argumentos->distancia < DISTANCIA) {
        int avance;
        if (argumentos->IDcaballo == 1 || argumentos->IDcaballo == 5) {
            avance = rand() % 2 + 3; // avanzo entre 3 y 4 metros.
        } else {
            avance = rand() % 2 + 2; // avanzo entre 2 y 3 metros.
        }
        argumentos->distancia += avance;
        printf("Caballo %d - ID[%d]: Ha avanzado %d metros\n", argumentos->IDcaballo, id, avance);
    }


    tiempo_final = clock();    // actualizo el tiempo de llegada
    segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC; // calcular tiempo en segundos

    printf("Caballo %d - ID[%d]: Ha llegado a la meta en %f segundos !!!!! \n", argumentos->IDcaballo, id, segundos);
    pthread_exit(NULL);
}

int main()
{
    pthread_t caballos[CANTIDAD_CAB];
    struct caballoArgumento args[CANTIDAD_CAB];

    printf("--- EMPIEZA LA CARRERA --- \n");
    for (int i = 0; i < CANTIDAD_CAB; i++){
        args[i].IDcaballo = i + 1;
        args[i].distancia = 0;
        pthread_create(&caballos[i], NULL, metrosCaballo, &args[i]);
    }

    for(int i = 0; i < CANTIDAD_CAB; i++){
        pthread_join(caballos[i], NULL);
    }

    return 0;
}