#include<stdio.h>

int main(){

    FILE * archivo;
    float dato,maximo=0,acumulador=0;
    int cont_dias=0, cont_lluvia=0;
    archivo = fopen("lluvia.txt","r");

    if(archivo!=NULL){
        //todo bien
        while(!feof(archivo)){
            fscanf(archivo,"%f",&dato);
            printf("\nValor leido: %f", dato);
            if(cont_dias==0)
                maximo=dato;
            else{
                if(dato>maximo)
                    maximo=dato;
            }
            if(dato>0)
                cont_lluvia++;
            cont_dias++;
            acumulador+=dato;
        }


        if(acumulador==0){
            printf("\nNo se registraron lluvias en el mes...");
        }else{

            printf("\nCantidad de dias lluvia: %d", cont_lluvia);
            printf("\nCantidad de dias sin lluvia: %d", cont_dias-cont_lluvia);
            printf("\nCantidad acumulada: %f", acumulador);
            rewind(archivo);
            cont_dias=0;

            while(!feof(archivo)){
                fscanf(archivo,"%f",&dato);
                if(dato==maximo)
                    printf("\nDia %d con maximo.", cont_dias+1);
                cont_dias++;
            }
        }
        fclose(archivo);

    }else{
        printf("\nError no se pudo abrir el archivo...");
        return 0;
    }
    return 1;
}
