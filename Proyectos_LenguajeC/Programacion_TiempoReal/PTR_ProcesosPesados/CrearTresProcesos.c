/*
Desarrollar un programa que cree 3 procesos, espere a su finalización y
luego informe “en proceso” y, a continuación, cree 3 procesos más. Cada
proceso deberá informar su identificador por pantalla. Cuando estos procesos
finalicen, el proceso padre deberá informar “FIN” por pantalla y terminar
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <math.h>

int main(){
    pid_t proceso1 = 0, proceso2 = 0, proceso3 = 0, proceso4 = 0, proceso5 = 0, proceso6 = 0;
    printf("Soy %d\n", getpid());


    proceso1 = fork();
    if (proceso1 < 0){
        printf("Error al crear al proceso hijo");
    }else if (proceso1 == 0){
        printf("Soy el proceso hijo creado. %d\n", getpid());
    }else{
        //padre
        proceso2 = fork();

        if (proceso2 < 0 ){
            printf("Error al crear al proceso hijo 2");
        }else if (proceso2 == 0){
            printf("Soy el proceso hijo 2. %d\n", getpid());
        }else{
            //padre
            proceso3 = fork();

            if(proceso3 < 0){
                printf("ERROR");
            }else if(proceso3 == 0){
                printf("Soy el proceso hijo 3. %d\n", getpid());
            }else{
                waitpid(proceso1, NULL, 0);
                waitpid(proceso2, NULL, 0);
                waitpid(proceso3, NULL, 0);
                printf("EN PROCESO... Soy proceso padre %d\n", getpid());

                proceso4 = fork();

                if(proceso4 < 0){
                    printf("ERROR");
                }else if(proceso4==0){
                    printf("Soy proceso hijo 4 %d\n", getpid());
                }else{
                    //padre
                    proceso5 = fork();
                    if(proceso5< 0){
                        printf("Error");
                    }else if(proceso5 == 0){
                        printf("Soy proceso hijo 5 %d\n", getpid());
                    }else{
                        //Padre
                        proceso6 = fork();
                        if (proceso6 < 0){
                            printf("Error");
                        }else if (proceso6 == 0){
                            printf("Soy el proceso hijo 6 %d,\n", getpid());
                        }else{
                            //Padre
                            waitpid(proceso4,NULL,0);
                            waitpid(proceso5,NULL,0);
                            waitpid(proceso6,NULL,0);
                            printf("\nFIN\n");
                        }
                    }
                }
            }
        }
    }
}