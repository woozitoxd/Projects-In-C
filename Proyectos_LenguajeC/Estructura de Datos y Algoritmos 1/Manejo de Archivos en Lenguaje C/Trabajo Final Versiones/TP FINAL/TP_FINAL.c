#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct registro{
    char numero_cuenta[250];
    char saldo_monto[250];
    char operacion[250];
};

int leer_movimientos(FILE * movements,FILE *binario);
void grabar_to_bin(FILE * binario,struct registro DATO);
int copiar_text_to_BD();
void buscar_bin(int codigo);
void menu();



void cargaroperacion();
void listar_operaciones();
void modificar_nombre();
void mostrar_informacion();
void top3_maximosaldo();

void main(){

    printf("BIENVENIDO...\n\n");

    int lineas=0;

    FILE * archivo;

    archivo = fopen("saldo_cuentas.bin","wb"); //Si no existe, se crea el archivo binario

    menu();

    fclose(archivo);
}

void menu()
{
    int opcion= 0;

    while(opcion!=6){
        do{
            printf("\n1-Cargar Operacion\n2-Listar Operaciones\n3-Modificar Nombre\n4-Listar Cuentas\n5-Top 3 Saldo Maximo\n6-Salir\n\n");
            printf("Ingrese su opcion: ");
            fflush(stdin);
            scanf("%d",&opcion);
        }while(opcion>6||opcion<1);

        switch(opcion){
            case 1:
                //
                cargaroperacion(); //recorrer binario
                break;
            case 2:
                //
             //   listar_operaciones(); //

                break;
            case 3:
                //
             //   modificar_nombre();  //
                break;
            case 4:
                //
                mostrar_informacion();
                break;
            case 5:
             //   top3_maximosaldo();
                break;
        }
    }

}

void cargar_operacion()
{
    FILE * movimientos;


    int lineas=0;


    movimientos = fopen("movimientos.txt", "r");

    lineas=copiar_text_to_BD();

    if(lineas==0){
        printf("No hay lineas para leer... verifique el archivo");
        exit(0);
    }


     fclose(movimientos);

}



int leer_movimientos(FILE * movements,FILE *binario)
{
    int leyendo = 0;

    struct registro Dato_grabar;
    char caja[500], *ptr, *var_ptr,  temporal[250];
    int cont_variable;

        while(!feof(movements)){

            leyendo++;
            cont_variable=1;                                 //pongo en 1 para analizar primer campo
            ptr=caja;                                 // apunto al principio de lo que me traigo del archivo
            fgets(caja,500,movements);               // leo una linea del archivo
            var_ptr=temporal;                   //inicializo puntero a la variable temporal

            while(*ptr!='\n' && *ptr!='\0'){

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
                        strcpy(Dato_grabar.numero_cuenta,temporal);break;
                        case 2:
                        strcpy(Dato_grabar.saldo_monto,temporal);break;
                        case 3:
                        strcpy(Dato_grabar.operacion,temporal);break;
                        }
                    cont_variable++;                        //cuento varible utilizada
                    var_ptr=temporal;                   // inicializo puntero a la variable temporal
                    }
                }
                                        //copio la ultima variable leida porque llegue al '\0'

              /*  printf("Numero de Cuenta: %s \n", Dato_grabar.numero_cuenta);
                printf("Monto: %s \n", Dato_grabar.saldo_monto);
                printf("Operacion: %s \n\n", Dato_grabar.operacion);*/

        grabar_to_bin(binario, Dato_grabar);

        }

    fclose(movements);


    return leyendo;
}


int copiar_text_to_BD()
{

    FILE *archivo,*binario;

    int copiando=0;

    if((archivo = fopen("movimientos.txt", "r+"))==NULL){

        printf("Error al leer archivo movimientos.txt...\n\n");
        printf("saliendo...\n\n");
    }else{
        printf("Leyendo archivo de texto...\n\n");
        if((binario = fopen("saldo_cuentas.bin", "wb"))==NULL){
            printf("Error al leer archivo saldo_cuentas.bin...\n\n");
            printf("saliendo...\n\n");
            fclose (archivo); // cierro archivo
        }else{
            // quiere decir que pude abrir todo bien

            copiando=leer_movimientos(archivo, binario);

            fclose (archivo); // cierro archivo
            fclose (binario); // cierro archivo

        }
    }
    return copiando;
}



void grabar_to_bin(FILE * binario,struct registro DATO){

    if(fwrite (&DATO,sizeof(struct registro),1,binario)){
        printf("Campos grabados correctamente.\n");
    }else{
        printf("FALLA al grabar en el archivo... saliendo..\n");
    }
}


void mostrar_informacion(){

    FILE * binario;
    int contador=1;
    struct registro Dato_leido;
    // abro de nuevo el archivo para no modificar si el puntero esta al final
    if((binario = fopen("saldo_cuentas.bin", "rb"))==NULL){
            //archivo no existe y es el primer libro
            printf("Error al leer archivo binario...");
        }else{

            printf("Leyendo archivo binario...\n\n");
            fread (&Dato_leido,sizeof(Dato_leido),1,binario);

            while(!feof(binario)){

                printf("%d: ",contador);
                printf("%s - ",Dato_leido.numero_cuenta);
                printf("%s - ",Dato_leido.saldo_monto);
                printf("%s - \n",Dato_leido.operacion);

                fread (&Dato_leido,1,sizeof(Dato_leido),binario);
                contador++;
            }
        fclose (binario);
    }
}


void buscar_bin(int codigo)
{

    FILE *binario;
    struct registro Dato_leido;
    //a codigo le resto 1 para que el cero sea el primer registro
    codigo--;

    if((binario = fopen("saldo_cuentas.bin", "rb"))==NULL){
        //archivo no existe y es el primer libro
        printf("Error al abrir el archivo binario..");
    }else{
        //muevo el puntero al archivo para ubicarme en el registro a leer
        fseek(binario,codigo*sizeof(struct registro),SEEK_SET);
        // con respecto al inicio
        fread (&Dato_leido,1,sizeof(struct registro),binario);

   //     printf("\Numero de Cuenta: %s - ",Dato_leido.numero_cuenta);
        printf("\nNumero de Cuenta: %s - ",Dato_leido.numero_cuenta);
        printf("Saldo de Cuenta: %s - ",Dato_leido.saldo_monto);
        printf("Modo de Afiliado: %s - ",Dato_leido.operacion);


        fclose (binario); // cierro archivo
    }
}
