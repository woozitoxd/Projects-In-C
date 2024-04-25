#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct registro{
    int vocales;
    int consonantes;
    int numeros;
    int especiales;
    int totales;
    char linea[600];

};

int copiar_text_to_BD();
void grabar_to_bin(FILE *,struct registro);
int Leo_text(FILE *,FILE *);
void recorrer_bin();
void ingreso_manual();
void buscar_bin(int);
void buscar(int);
void Crear_mayuscula();

void main(){

    int opcion=0;
    int lineas=0;
    printf("BIENVENIDO...\n\n");

    // leo del archivo de texto y lo paso a la base interna
    lineas=copiar_text_to_BD();

    if(lineas==0){
        printf("No hay lineas para leer... verifique el archivo");
        exit(0);
    }


    while(opcion!=5){
        do{
            printf("\n1-Ingresar Manualmente\n2-Mostrar linea\n3-recorrer todo\n4-Crear archivo de texto mayuscula\n5-Salir\n\n");
            printf("Ingrese su opcion: ");
            fflush(stdin);
            scanf("%d",&opcion);
        }while(opcion>5||opcion<1);

        switch(opcion){
            case 1:
                //ingreso manual de nueva palabra por teclado
                ingreso_manual();
                break;
            case 2:
                //busqueda
                buscar(lineas);
                break;
            case 3:
                //recorro archivo binario para verificar
                recorrer_bin();
                break;
            case 4:
                //recorro archivo binario para verificar
                Crear_mayuscula();
                break;
        }
    }
}

void buscar(int lineas){
    int cantidad,opcion;
    cantidad=lineas;
    do{
        printf("\nCantidad de lineas: %d\n\nIngrese numero de linea a buscar (0 para salir): ",cantidad);
        fflush(stdin);
        scanf("%d",&opcion);
    }while(opcion>cantidad||opcion<0);
    if(opcion>0)
        buscar_bin(opcion);
}

void buscar_bin(int codigo){
    FILE *binario;
    struct registro Dato_leido;
    //a codigo le resto 1 para que el cero sea el primer registro
    codigo--;

    if((binario = fopen("BD-texto.bin", "rb"))==NULL){
        //archivo no existe y es el primer libro
        printf("Error al abrir el archivo binario..");
    }else{
        //muevo el puntero al archivo para ubicarme en el registro a leer
        fseek(binario,codigo*sizeof(struct registro),SEEK_SET);
        // con respecto al inicio
        fread (&Dato_leido,1,sizeof(struct registro),binario);

        printf("\nVocales: %d - ",Dato_leido.vocales);
        printf("Consonantes: %d - ",Dato_leido.consonantes);
        printf("Numeros: %d - ",Dato_leido.numeros);
        printf("Especiales: %d - ",Dato_leido.especiales);
        printf("Totales: %d - ",Dato_leido.totales);
        printf("Palabra: %s\n", Dato_leido.linea);

        fclose (binario); // cierro archivo
    }
}



int copiar_text_to_BD(){

    FILE *archivo,*binario;
    int lineas=0;

    if((archivo = fopen("input.txt", "r+"))==NULL){

        printf("Error al leer archivo input.txt...\n\n");
        printf("saliendo...\n\n");
    }else{
        printf("Leyendo archivo de texto...\n\n");
        if((binario = fopen("BD-texto.bin", "wb"))==NULL){
            printf("Error al leer archivo BD-texto.bin...\n\n");
            printf("saliendo...\n\n");
            fclose (archivo); // cierro archivo
        }else{
            // quiere decir que pude abrir todo bien
            lineas=Leo_text(archivo,binario);
            fclose (archivo); // cierro archivo
            fclose (binario); // cierro archivo

        }
    }
    return lineas;
}


int Leo_text(FILE * archivo,FILE *binario)
{

    struct registro Dato_grabar;
    char buffer[600], *ptr;
    int cont_lineas=0,cont_vocal,cont_cons,cont_espe,cont_num, cont_cxlinea;


    while((fgets(buffer,600,archivo))!=NULL){
        cont_lineas++;
        cont_vocal=0,cont_cons=0,cont_espe=0,cont_num=0,cont_cxlinea=0;
        ptr=buffer; // apunto al principio de lo que me traigo del archivo
        ; // leo una linea del archivo
        //var_ptr=temporal; //inicializo puntero a la variable temporal
        printf("\nlinea: %d - %s\n",cont_lineas, buffer);
        while(*ptr!='\n'&&*ptr!='\0'){
            //hasta no llegar al final del registro, leo los caracteres
            if(*ptr=='A'|| *ptr=='a'|| *ptr=='E'|| *ptr=='e'|| *ptr=='I'|| *ptr=='i'|| *ptr=='O'|| *ptr=='o'|| *ptr=='U'|| *ptr=='u'){
                cont_vocal++;
            }else{
                if((*ptr>='A'&& *ptr<='Z' )||(*ptr>='a'&& *ptr<='z') ||  *ptr== 'ñ' || *ptr == 'Ñ'){
                    cont_cons++;
                }else{
                    if(*ptr>='0'&& *ptr<='9' ){
                        cont_num++;
                    }else{
                        cont_espe++;
                    }
                }
            }
            ptr++; // incremento puntero a buffer
            cont_cxlinea++; // cuenta caracteres y lo uso para ver si la linea esta en blanco
        }
            //si no hay letras en la linea debe quedar todo en cero

            if(cont_cxlinea!=0){
                Dato_grabar.vocales=cont_vocal;
                Dato_grabar.consonantes=cont_cons;
                Dato_grabar.numeros=cont_num;
                Dato_grabar.especiales=cont_espe;
                Dato_grabar.totales=cont_cxlinea;
            }else{
                Dato_grabar.vocales=0;
                Dato_grabar.consonantes=0;
                Dato_grabar.numeros=0;
                Dato_grabar.especiales=0;
                Dato_grabar.totales=0;
            }
            strcpy(Dato_grabar.linea, buffer);
            grabar_to_bin(binario,Dato_grabar);
        }
    return cont_lineas;
}


void grabar_to_bin(FILE * binario,struct registro DATO){

    if(fwrite (&DATO,sizeof(struct registro),1,binario)){
        printf("Linea grabada correctamente.\n");
    }else{
        printf("FALLA al grabar en el archivo... saliendo..\n");
    }
}


void recorrer_bin(){

    FILE * binario;
    int contador=1;
    struct registro Dato_leido;
    // abro de nuevo el archivo para no modificar si el puntero esta al final
    if((binario = fopen("BD-text.bin", "rb"))==NULL){
            //archivo no existe y es el primer libro
            printf("Error al leer archivo binario...");
        }else{

            printf("Leyendo archivo binario...\n\n");
            fread (&Dato_leido,sizeof(Dato_leido),1,binario);

            while(!feof(binario)){

                printf("%d: ",contador);
                printf("%d - ",Dato_leido.vocales);
                printf("%d - ",Dato_leido.consonantes);
                printf("%d - ",Dato_leido.numeros);
                printf("%d - ",Dato_leido.especiales);
                printf("%d - ",Dato_leido.totales);
                printf("%s\n", Dato_leido.linea);


                fread (&Dato_leido,1,sizeof(Dato_leido),binario);
                contador++;
            }
        fclose (binario);
    }
}

void Crear_mayuscula()
{
    FILE *archivo,*archivo2;
    char caracter;
    if((archivo = fopen("input.txt", "r+"))==NULL){
        printf("Error al leer archivo input.txt...\n\n");
        printf("saliendo...\n\n");
    }else{
        printf("\nLeyendo archivo de texto...\n");
        if((archivo2 = fopen("output.txt", "w"))==NULL){
            printf("Error al leer archivo output.txt...\n\n");
            printf("saliendo...\n\n");
            fclose (archivo); // cierro archivo
        }else{
            // quiere decir que pude abrir todo bien

            while((caracter=fgetc(archivo))!=EOF){
                if((caracter>='a'&& caracter<='z')){
                    caracter=caracter-32;
                }
                fputc(caracter,archivo2);
            }
            printf("Archivo creado correctamente.\n");
            fclose (archivo); // cierro archivo
            fclose (archivo2); // cierro archivo

        }
    }
}


void ingreso_manual()
{
    printf("\n\nINGRESAR PALABRA\n");

    FILE * archivo;
    char palabra[50];

    archivo = fopen("input.txt", "a"); //Abro en modo solo añadir
    printf("\nAbriendo Archivo..\n");

    if (archivo!=NULL){ // Compruebo que exista el archivo

        printf("\nIntroducir nueva frase: "); //Ingresa nueva palabra desde el teclado
       // scanf("%50s",palabra);
        fflush(stdin);
        fgets(palabra,50,stdin); //Omite el ingreso por teclado, no encuentro solucion :( . */
        fflush(stdin);
        fputs(palabra, archivo);    //Se escribe la palabra ingresada en el archivo (al final del mismo)
        fclose(archivo);
    }else{
        printf("No existe el archivo..\n");
    }
    printf("\nTerminando funcion..\n");
}
