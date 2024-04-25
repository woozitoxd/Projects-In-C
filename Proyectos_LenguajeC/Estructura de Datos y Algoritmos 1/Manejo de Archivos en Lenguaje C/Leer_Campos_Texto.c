#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct registro{
    char campo1[250];
    char campo2[250];
    char campo3[250];
    int num_cliente;
};

void main()
{

    FILE *archivo;

    char caja[500], *ptr, *var_ptr,temporal[250];
    struct registro Dato_grabar;
    int cont_variable;

    archivo = fopen("Leer_Campos_Con_Separador.txt", "r+");

    while(!feof(archivo)){

        cont_variable=1;                                 //pongo en 1 para analizar primer campo
        ptr=caja;                                 // apunto al principio de lo que me traigo del archivo
        fgets(caja,500,archivo);               // leo una linea del archivo
        var_ptr=temporal;                   //inicializo puntero a la variable temporal

        while(*ptr!='\n'&&*ptr!='\0'){

                            //hasta no llegar al final del registro, leo los caracteres
            if(*ptr!='|'){
                                                        //cargo en la variable correspondiente
                *var_ptr=*ptr;                       //voy copiando los caracteres
                var_ptr++;                       //incremento punteros
                ptr++;                       //incremento punteros
            }else{
                                                                                        //implica que termina la linea a copiar
                *var_ptr='\0';                                                  //finalizo string que apunta a temporal
                ptr++;                                              // incremento puntero a buffer

                switch(cont_variable){
                    case 1:
                    strcpy(Dato_grabar.campo1,temporal);break;
                    case 2:
                    strcpy(Dato_grabar.campo2,temporal);break;
                    case 3:
                    strcpy(Dato_grabar.campo3,temporal);break;
                    }
                cont_variable++;                        //cuento varible utilizada
                var_ptr=temporal;                   // inicializo puntero a la variable temporal
                }
            }
                                    //copio la ultima variable leida porque llegue al '\0'
            *var_ptr='\0';
                                    //printf("\n%s---",temporal);
            Dato_grabar.num_cliente=atoi(temporal);

            printf("Campo 1: %s \n", Dato_grabar.campo1);
            printf("Campo 2: %s \n", Dato_grabar.campo2);
            printf("Campo 3: %s \n", Dato_grabar.campo3);
            printf("Campo_Numerico: %d \n\n", Dato_grabar.num_cliente);

        }
    fclose (archivo); // cierro archivo

}
