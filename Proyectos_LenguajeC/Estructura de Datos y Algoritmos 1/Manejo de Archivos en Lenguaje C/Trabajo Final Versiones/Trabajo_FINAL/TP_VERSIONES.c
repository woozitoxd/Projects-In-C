#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM1 10
#define TAM2 100

struct registro{
    char numero_cuenta[250];
    float saldo_monto;
    int operacion;
    char name[50];
};

struct modificar{
    char numerodeecuenta[250];
    float saldos;
    int operaciones;
};

void cargar_operacion();
void modificaroperaciones();
void modificarbinario(struct modificar DATOS);

void listar_operaciones();
void modificar_nombre();
void mostrar_informacion(FILE *);
void top3_maximosaldo(FILE *);


void main()
{
    FILE * binario;
    binario = fopen("saldo_cuenta.bin","ab+"); // Primera ejecucion, se crea el archivo binario.

    int opcion = 0;

    while(opcion!=6){

        do{
            printf("\n1-Cargar Operacion\n2-Listar Operaciones\n3-Modificar Nombre\n4-Listar Cuentas\n5-Top 3 Saldo Maximo\n6-Salir\n\n");
            printf("Ingrese su opcion: ");
            fflush(stdin);
            scanf("%d",&opcion);
            fflush(stdin);
        }while(opcion>6||opcion<1);

            switch(opcion){
                case 1:
                    //
                    cargar_operacion(binario); //Leo archivo de texto, guardo en registro, actualizo el binario, le paso por parametro el binario
                    modificaroperaciones();
                    break;
                case 2:
                    //
                   listar_operaciones(); //

                    break;
                case 3:
                    //
                   modificar_nombre();
                    break;
                case 4:
                    //
                    mostrar_informacion(binario);
                    break;
                case 5:
                    top3_maximosaldo(binario);
                    break;
            }
    }
    fclose(binario); // cierro el archivo binario
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cargar_operacion(FILE * binario)
{
    FILE  *registrar, *movimientos;

    struct registro DATOS;
    char buffer[100], *ptr, *var_ptr, temporal[100];
    int contador= 0;

    registrar = fopen("registro.txt", "a+");
    movimientos = fopen("movimientos.txt", "r+");


    if(movimientos == NULL){
        printf("\nError al leer, no existe archivo");
    }else{
        printf("\nArchivo Existe, leyendo campos..\n");

        while(!feof(movimientos)){

        contador=1;                                 //pongo en 1 para analizar primer campo
        ptr=buffer;                                 // apunto al principio de lo que me traigo del archivo
        fgets(buffer,100,movimientos);               // leo una linea del archivo
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

                switch(contador){
                    case 1:

                    strcpy(DATOS.numero_cuenta,temporal);

                    break;

                    case 2:

                    DATOS.saldo_monto=atof(temporal);

                    break;
                    }
                contador++;                        //cuento varible utilizada
                var_ptr=temporal;                   // inicializo puntero a la variable temporal
                }
            }
                                    //copio la ultima variable leida porque llegue al '\0'
            *var_ptr='\0';
             DATOS.operacion=atoi(temporal);

         if(DATOS.operacion == 0){ // Si la operacion fue 0
            fprintf(registrar, "%s", DATOS.numero_cuenta); // Escribo el Numero de cuenta + el pipe
            fputs("0\n", registrar); // Escribo el numero de operacion realizada
         }


         if(DATOS.operacion == 1){ // Si la operacion fue 1
            fprintf(registrar, "%s", DATOS.numero_cuenta); // Escribo el Numero de cuenta + el pipe
            fputs("1\n", registrar); // Escribo el numero de operacion realizada
         }

         if(DATOS.operacion == 2){ // Si la operacion fue 2
            fprintf(registrar, "%s", DATOS.numero_cuenta); // Escribo el Numero de cuenta + el pipe
            fputs("2\n", registrar); // Escribo el numero de operacion realizada
         }

            if(fwrite(&DATOS,sizeof(struct registro),1,binario)){ //Copio toda la informacion que grabé al archivo binario
                printf("\nSe ha grabado las lineas del archivo movimientos.txt al archivo binario.");
            }else{
                printf("No se logró grabar las lineas\n");
            }
        }
    }

    fclose(movimientos);

    if(rename("movimientos.txt", "movimientos_proc.txt")==0) // Renombramos el archivo "movimientos" luego de haberlo utilizado para su lectura.
        printf("\nEl archivo se renombro satisfactoriamente\n");
    else
        printf("\nEl archivo //movimientos.txt// ya se renombro anteriormente.\n");

        fclose(registrar);      //Cierro los archivos que utilicé
        fclose(binario);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void listar_operaciones() // Con el formato de limitadores, uso el mismo metodo de lectura para comparar el numero de cuenta
{
    FILE * archivo;
    char cuenta[10];
    int linea=0;
    char buffer[500], *Puntero, *OchoDigitos;
    struct registro DATO;
    int Contar_LargoString;

        if((archivo = fopen("registro.txt", "r+"))==NULL){
            printf("\nError al leer el archivo registro.txt...\n");
        }else{

               while(!feof(archivo)){
                    Puntero = buffer;
                    fgets(buffer, 500, archivo);
                    Contar_LargoString = 0 ;

                    OchoDigitos = DATO.numero_cuenta;

                    while(Contar_LargoString < 9){
                        if(Contar_LargoString >=0 && Contar_LargoString < 8){
                            *OchoDigitos=*Puntero;
                            *OchoDigitos++;
                        }

                        if(Contar_LargoString == 8){
                            DATO.operacion = atoi(Puntero);
                        }
                        Contar_LargoString++;
                        Puntero++;
                    }

                    *OchoDigitos = '\0';

                    linea++;
                    printf("Cuenta %d: %s \n",linea, DATO.numero_cuenta);
                }
        fclose(archivo);
        }

        printf("Ingrese numero de cuenta existente: ");
        scanf("%s", cuenta);

            if(strcmp(cuenta,DATO.numero_cuenta)==0){
                        printf("\nLa cuenta existe..\n");

                    if(DATO.operacion == 0){
                        printf("La cuenta se creo. \n");
                        printf("Numero de cuenta: [%s]\n", DATO.numero_cuenta);
                     }

                     if(DATO.operacion == 1){
                        printf("Se ralizo la operacion de credito \n");
                        printf("Numero de cuenta: [%s]\n", DATO.numero_cuenta);
                     }

                     if(DATO.operacion == 2 ){
                        printf("La operacion realizada fue debito. \n");
                        printf("Numero de cuenta: [%s]\n", DATO.numero_cuenta);
                     }

            }else{
                        printf("\nLa cuenta no existe.");
            }

        fclose(archivo);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificar_nombre()
{
   FILE *arch;
   struct registro nuevo_nombre;
   char numerodecuenta[10];
   int existe=0;
   int posicion;

    arch=fopen("saldo_cuenta.bin","rb+");
    if (arch==NULL){
        printf("Error al abrir el archivo binario..");
    }else{

            printf("Leyendo archivo binario...\n\n");
            fread (&nuevo_nombre,sizeof(nuevo_nombre),1,arch);

            while(!feof(arch)){
                printf("Numero de las cuentas: [%s] - \n",nuevo_nombre.numero_cuenta);   //Imprimo por pantalla los datos de todas las cuentas guardadas
                fread (&nuevo_nombre,sizeof(nuevo_nombre), 1,arch);
            }
        fclose (arch); // cierro el archivo


        arch=fopen("saldo_cuenta.bin","rb+");

        printf("\nIngrese el numero de cuenta a modificar:");
        scanf("%s", &numerodecuenta);

        fread(&nuevo_nombre, sizeof(struct registro), 1, arch);
        while(!feof(arch)){

            if (strcmp(numerodecuenta,nuevo_nombre.numero_cuenta)==0){
               printf("%s %0.2f %s\n", nuevo_nombre.numero_cuenta, nuevo_nombre.saldo_monto, nuevo_nombre.name);
               printf("Ingrese nuevo nombre:");
               scanf("%s",&nuevo_nombre.name);


               int desp= 'a'-'A';
               for(int i=0; nuevo_nombre.name[i]!='\0';i++){
                    if(nuevo_nombre.name[i]>='a'&&nuevo_nombre.name[i]<='z'){
                        nuevo_nombre.name[i]=nuevo_nombre.name[i]-desp;
                    }
               }

               posicion=ftell(arch)-sizeof(struct registro);
               fseek(arch,posicion,SEEK_SET);
               fwrite(&nuevo_nombre, sizeof(struct registro), 1, arch);

               printf("Se cambio el nombre de la cuenta..\n");
               existe=1;
               break;
            }
            fread(&nuevo_nombre, sizeof(struct registro), 1, arch);
        }
        if (existe==0)
            printf("La cuenta ingresada no existe, saliendo..\n");
        fclose(arch);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrar_informacion(FILE * binario)
{

    struct registro lectura;
    int contar=0;
    if((binario = fopen("saldo_cuenta.bin", "rb"))==NULL){

            printf("\nError al leer el archivo saldo_cuentas.bin...\n");
        }else{

            printf("Leyendo archivo binario...\n\n");
            fread (&lectura,sizeof(lectura),1,binario);

            while(!feof(binario)){

                printf("\n %d ", contar+1);
                printf("Cuenta numero [%s] -",lectura.numero_cuenta);   //Imprimo por pantalla los datos de todas las cuentas guardadas
                printf("Saldo en la cuenta [$%.2f] - ",lectura.saldo_monto); // en el archivo binario
                printf("Operacion realizada [%d] - ",lectura.operacion);
                printf("Nombre de la cuenta %s\n\n", lectura.name);
                contar++;
                fread (&lectura,sizeof(lectura), 1,binario);
            }
        fclose (binario); // cierro el archivo
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void top3_maximosaldo(FILE * binario)
{
    struct registro * saldos;  // Creo un puntero a registro
    struct registro lectura;

    int i=1;
    int ordenado=0;
    int aux;

    saldos = (struct registro*)malloc(TAM1*sizeof(struct registro)); //Asigno memoria para el de struct

    if (saldos==NULL)
    {                                                   /*Verifico si hay memoria en la PC*/
        printf("\n\nProblemas reservando memoria...");
        exit (1);
    }else{
        printf("\nMemoria dinamica asignada.. continuando..\n");
        }

      if((binario = fopen("saldo_cuenta.bin", "rb"))==NULL){
            printf("\nNo se pudo abrir el archivo.\n");
       }else{
             printf("\nLeyendo archivo binario...\n\n");

            fread (&lectura,sizeof(struct registro),1,binario);

            while(!feof(binario)){
                                                // while con la condicion de que se ejecute mientras i sea menor a TAM1(500) y ordenado valga 0
                while(i<TAM1 && ordenado==0){       // Ordeno el vector cargado con el metodo de burbujeo
                    ordenado=1;

                    for(int j=0; j<TAM1-1; j++){
                        if((saldos+j)->saldo_monto < (saldos+j+1)->saldo_monto){     /*Si el elemento en la posicion de J es mayor que la siguiente posicion*/
                            ordenado=0;                                     /* La variable ordenado tma el valor de 0*/
                            aux = (saldos+j+1)->saldo_monto;                     /* "aux" pasa a ser la siguiente posicion (j+1)*/
                            (saldos+j+1)->saldo_monto = (saldos+j)->saldo_monto;      /* se intercambia la posicion con la anterior [j+1] = [j]*/
                            (saldos+j)->saldo_monto   = aux;                     /* la posicion [j] pasa a ser aux*/
                        }
                    }
                    i++;        /* Se incrementa el valor de i cada vez que se intercambien posiciones, esto para que siga comparando hasta que quede ordenado*/
                }
                fread (&lectura,sizeof(struct registro),1,binario);
            }

            free(saldos);       //Libero memoria
            fclose (binario); // cierro el archivo

        fread (&lectura,sizeof(struct registro),1,binario);

        for(int a=0; a<3; a++){
            printf("TOP'S %d Saldo maximo [$%.2f]\n", a+1, (saldos+a)->saldo_monto);
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificaroperaciones()
{
    FILE *movimientos;

    struct modificar DATOS;
    char buffer[100], *ptr, *var_ptr, temporal[100];
    int contador= 0;

    movimientos = fopen("movimientos_proc.txt", "r+");

    if(movimientos == NULL){
        printf("\nError al leer, no existe archivo");
    }else{
        printf("\nArchivo Existe, leyendo campos..\n");

        while(!feof(movimientos)){

        contador=1;                                 //pongo en 1 para analizar primer campo
        ptr=buffer;                                 // apunto al principio de lo que me traigo del archivo
        fgets(buffer,100,movimientos);               // leo una linea del archivo
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

                switch(contador){
                    case 1:

                    strcpy(DATOS.numerodeecuenta,temporal);

                    break;

                    case 2:

                    DATOS.saldos=atof(temporal);

                    break;
                    }
                contador++;                        //cuento varible utilizada
                var_ptr=temporal;                   // inicializo puntero a la variable temporal
                }
            }
                                    //copio la ultima variable leida porque llegue al '\0'
            *var_ptr='\0';
             DATOS.operaciones=atoi(temporal);
             modificarbinario(DATOS);
        }
       // modificarbinario(DATOS);
    }

    fclose(movimientos);
    //modificarbinario(DATOS);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificarbinario(struct modificar DATOS)
{

    FILE * arch;
    printf("\n[%s] -", DATOS.numerodeecuenta);
    printf("[$%.2f] -", DATOS.saldos);
    printf("[%d] \n", DATOS.operaciones);

   int existe=0;
   int posicion;

   struct registro lectura;
    int contar=0;
    if((arch = fopen("saldo_cuenta.bin", "rb+"))==NULL){
            printf("\nError al leer el archivo saldo_cuentas.bin...\n");
        }else{

            printf("Leyendo archivo binario...\n\n");

            fread (&lectura,sizeof(struct registro),1,arch);

            while(!feof(arch)){

                if(strcmp(DATOS.numerodeecuenta, lectura.numero_cuenta)==0 && DATOS.operaciones == 1){
                    lectura.saldo_monto = lectura.saldo_monto - DATOS.saldos;

               posicion=ftell(arch)-sizeof(struct registro);
               fseek(arch,posicion,SEEK_SET);
               fwrite(&lectura, sizeof(struct registro), 1, arch);

               printf("Se modifico el saldo segun operacion credito..\n");
               existe=1;
               break;
                }

                fread (&lectura,sizeof(struct registro), 1,arch);
            }
            fclose(arch);

        arch = fopen("saldo_cuenta.bin","rb+");


              fread (&lectura,sizeof(struct registro),1,arch);

            while(!feof(arch)){

                if(strcmp(DATOS.numerodeecuenta, lectura.numero_cuenta)==0 && DATOS.operaciones == 2){
                    lectura.saldo_monto = lectura.saldo_monto + DATOS.saldos;

               posicion=ftell(arch)-sizeof(struct registro);
               fseek(arch,posicion,SEEK_SET);
               fwrite(&lectura, sizeof(struct registro), 1, arch);

               printf("Se modifico el saldo segun operacion debito..\n");
               existe=1;
               break;
                }

                fread (&lectura,sizeof(struct registro), 1,arch);
            }
             fclose(arch);

       arch = fopen("saldo_cuenta.bin","rb+");


              fread (&lectura,sizeof(struct registro),1,arch);

            while(!feof(arch)){

                if(strcmp(DATOS.numerodeecuenta, lectura.numero_cuenta)==0 && DATOS.operaciones == 0){
                    lectura.saldo_monto = 0;

               posicion=ftell(arch)-sizeof(struct registro);
               fseek(arch,posicion,SEEK_SET);
               fwrite(&lectura, sizeof(struct registro), 1, arch);

               printf("Se modifico el saldo segun operacion crear cuenta..\n");
               existe=1;
               break;
                }

                fread (&lectura,sizeof(struct registro), 1,arch);
            }


        if (existe==0)
            printf("saliendo..\n");

        fclose (arch); // cierro el archivo
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*void nombres(FILE * binario)
{
    struct registro lectura;
    int contar=0;

    if((binario = fopen("saldo_cuenta.bin", "rb+"))==NULL){

            printf("\nError al leer el archivo saldo_cuentas.bin...\n");
        }else{

            printf("Leyendo archivo binario...\n\n");
            fread (&lectura,sizeof(lectura),1,binario);

            while(!feof(binario)){
                contar++;
                fread (&lectura,sizeof(lectura), 1,binario);
            }
            printf("\nCuentas existentes [%d]\n", contar);
        fclose (binario); // cierro el archivo
    }
     AgregarNombre(contar);
}

void AgregarNombre(int Cuentas){
    int cantidad,opcion;
    cantidad=Cuentas;
    do{
        printf("\nCantidad de cuentas [%d], Ingrese a cual cuenta desea agregarle nombre (0 para salir): ",cantidad);
        fflush(stdin);
        scanf("%d",&opcion);
    }while(opcion>cantidad||opcion<0);
    if(opcion>0)
        Busqueda_Binario(opcion);
}

void Busqueda_Binario(int codigo){
    FILE *binario;
    struct registro Dato_leido;
    int posicion;
    //a codigo le resto 1 para que el cero sea el primer registro
    codigo--;

    if((binario = fopen("saldo_cuenta.bin", "ab+"))==NULL){
        //archivo no existe y es el primer libro
        printf("Error al abrir el archivo binario..");
    }else{

        //muevo el puntero al archivo para ubicarme en el registro a leer
        fseek(binario,codigo*sizeof(struct registro),SEEK_SET);
        // con respecto al inicio
        fread (&Dato_leido,1,sizeof(struct registro),binario);

       // printf("\nNumero de Cuenta: [%s] - ",Dato_leido.numero_cuenta);
        printf("Nombre %s \n", Dato_leido.name);

        printf("\nIngresar nombre para la cuenta: ");
        scanf("%s", Dato_leido.name);
        fflush(stdin);

        fseek(binario,codigo*sizeof(struct registro), SEEK_SET); // En la posicion
        fwrite(&Dato_leido,1,sizeof(struct registro),binario);  // Escribo el nombre ingresado

        printf("\nNombre agregado a la cuenta correctamente.\n");

        //fread (&Dato_leido,1,sizeof(struct registro),binario);
        printf("\nNumero de Cuenta: [%s] - ",Dato_leido.numero_cuenta);
        printf("Nombre %s \n", Dato_leido.name);

        fclose (binario); // cierro archivo
    }
}*/
