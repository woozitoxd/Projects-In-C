// Elias Contrera
// 43239945
// Tec. Desarrollo de Software
// Estructura de Datos y Algoritmos I
// Fecha = 12/11/2021

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM1 1000  // Constantes declaradas para ser utilizadas en el programa
#define TAM2 100

struct registro{
    char numero_cuenta[250];
    float saldo_monto;
    int operacion;
    char name[50];
};

struct modificar{ // Struct para el archivo binario
    char numerodeecuenta[250];
    float saldos;
    int operaciones;
};

void cargar_operacion();
void modificaroperaciones();
void modificarbinario(struct modificar DATOS);
void listar_operaciones();
void modificar_nombre();
int ValidarNombre(char nombre[]);
void mostrar_informacion(FILE *);
void top3_maximosaldo(FILE *);

void main()
{

    printf("\n ----- Bienvenido a mi programa!! ----- \n");
    printf("\n    --- Mini cajero automatico ---\n");

    FILE * binario;
    binario = fopen("saldo_cuenta.bin","ab+"); // Primera ejecucion, se crea el archivo binario.

    int opcion = 0;

    while(opcion!=6){

        do{
            printf("\n 1) Cargar Operaciones\n 2) Mostrar Movimientos\n 3) Modificar Nombre de una cuenta\n 4) Listar todas las cuentas\n 5) TOP 3 Saldo Maximo\n 6) Salir del programa\n\n");
            printf("Ingrese su opcion: ");
            fflush(stdin);
            scanf("%d",&opcion);
            fflush(stdin);
        }while(opcion>6 || opcion<1); // Si la opcion ingresada no esta entre el 1 y el 6, el while no termina.

        switch(opcion){

                case 1:
                    //
                    cargar_operacion(binario); //Leo archivo de texto, guardo los datos en saldocuentas, le paso el archivo binario.
                    modificaroperaciones();  //Cargo las operaciones, modifico los datos de las cuentas segun que operaciones hay en movimientos
                    break;    // Ejemplo: Tengo la cuenta 123 con 100 de saldo y el movimiento es credito, resto el saldo que guarde en la cuenta.

                case 2:
                    //
                    listar_operaciones(); // Listo la operacion realizada de una cuenta existente ingresada por teclado
                    break;

                case 3:
                    //
                    modificar_nombre(); // Modifico el campo nombre del archivo binario
                    break;

                case 4:
                    //
                    mostrar_informacion(binario); // Muestro toda la informacion de todas las cuentas almacenadas, recibiendo el archivo binario
                    break;

                case 5:
                    top3_maximosaldo(binario);  // Muestro el top 3 de los saldos maximos, recibiendo el archivo binario
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
    int contador = 0;

    registrar = fopen("registro.txt", "a+");
    movimientos = fopen("movimientos.txt", "r+");


    if(movimientos == NULL){
        printf("\nError al leer, no existe archivo");
    }else{
        printf("\nArchivo Existe, leyendo campos..\n");

        while(!feof(movimientos)){

        contador=1;                                 //Analizo el primer campo
        ptr=buffer;
        fgets(buffer,100,movimientos);               //Leo linea del archivo
        var_ptr=temporal;                   //inicializo puntero a la variable temporal

        while(*ptr!='\n'&&*ptr!='\0'){

                            //Hasta no llegar al final, sigo leyendo los caracteres
            if(*ptr!='|'){

                *var_ptr=*ptr;                       //Mientras copio los caracteres
                var_ptr++;                       //Hago el incremento de los punteros
                ptr++;
            }else{
                                                    //Fin de la linea
                *var_ptr='\0';                     //La cadena que apunta a temporal la finalizo con el \0
                ptr++;                     //Incremento el puntero a buffer

                switch(contador){
                    case 1:

                    strcpy(DATOS.numero_cuenta,temporal);

                    break;

                    case 2:

                    DATOS.saldo_monto=atof(temporal); // Convierto el saldo a un numero float

                    break;
                    }
                contador++;
                var_ptr=temporal;
                }
            }

            *var_ptr='\0';
             DATOS.operacion=atoi(temporal);

            if(fwrite(&DATOS,sizeof(struct registro),1,binario)){ //Copio toda la informacion que grabé al archivo binario

            }else{
                printf("No se logró grabar las lineas\n");
            }
        }
    }

        fclose(movimientos);
        fclose(registrar);      //Cierro los archivos que utilicé
        fclose(binario);

    if(rename("movimientos.txt", "movimientos_proc.txt")==0) // Renombramos el archivo "movimientos" luego de haberlo utilizado para su lectura.
        printf("\nEl archivo se renombro satisfactoriamente\n");
    else
        printf("\nEl archivo //movimientos.txt// ya se renombro anteriormente.\n\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificaroperaciones() //Funcion para modificar el saldo de los numeros de cuenta segun que operacion se realizo, 0=se creo, 1= credito, 2=debito, 3=deposita.
{                           //Para ver reflejado el cambio, modificar los datos desde el archivo.txt 'movimientos_proc' luego de que se renombro.
    FILE *movimientos;

    struct modificar DATOS; // Tipo de dato struct 'DATOS' para guardar la informacion.
    char buffer[100], *ptr, *var_ptr, temporal[100];
    int contador = 0;
                                                            // Uso el archivo de movimientos_proc para modificar los datos del binario
    movimientos = fopen("movimientos_proc.txt", "r+"); // de lo contrario, se duplicarian los mismos. De esta forma si se desea cambiar la operacion y saldo de una cuenta, hacerlo desde el archivo.

    if(movimientos == NULL){
        printf("\n");
    }else{

        while(!feof(movimientos)){

        contador=1;
        ptr=buffer;
        fgets(buffer,100,movimientos);
        var_ptr=temporal;

        while(*ptr!='\n'&&*ptr!='\0'){

                                   //Hasta no llegar al final, sigo leyendo los caracteres
            if(*ptr!='|'){
                                                        //cargo en la variable correspondiente
                *var_ptr=*ptr;                      //Hago el incremento de los punteros
                var_ptr++;
                ptr++;
            }else{
                                                    //Fin de la linea
                *var_ptr='\0';                     //La cadena que apunta a temporal la finalizo con el \0
                ptr++;                                              // incremento puntero a buffer

                switch(contador){
                    case 1:

                    strcpy(DATOS.numerodeecuenta,temporal);

                    break;

                    case 2:

                    DATOS.saldos=atof(temporal);

                    break;
                    }
                contador++;
                var_ptr=temporal;
                }
            }

            *var_ptr='\0';
             DATOS.operaciones=atoi(temporal);
             modificarbinario(DATOS); // Llamo a la funcion que modifica los datos del binario pasandole por parametro la variable struct DATOS.
        }
    }
    fclose(movimientos);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void listar_operaciones() // Con el formato de limitadores, uso el mismo metodo de lectura para comparar el numero de cuenta
{

    FILE * archivo;

    char cuenta[10];
    int linea=0;
    char buffer[500], *ptr, *var_ptr,temporal[250];
    int contador= 0;
    struct registro DATO[TAM1]; // Vector de struct para guardar los numeros de cuenta en registro

    int i=0;  // Contador para guardar los numeros dentro del vector
    int a=0; // Contador para recorrer el vector

        if((archivo = fopen("registro.txt", "r+"))==NULL){ //Validacion para la apertura del registro
                printf("\nError al leer el archivo registro.txt...\n");
        }else{

                while(!feof(archivo)){
                i++;
                contador=1;
                ptr=buffer;                                 // Apunto al principio del archivo.
                fgets(buffer,100,archivo);               //Leo lineas del archivo
                var_ptr=temporal;

                while(*ptr!='\n'&&*ptr!='\0'){  // Leo hasta llegar al final

                    if(*ptr!=','){

                        *var_ptr=*ptr;                    //Copio los caracteres..
                        var_ptr++;                       //Incremento los punteros
                        ptr++;
                    }else{

                        *var_ptr='\0';
                        ptr++;

                        switch(contador){
                            case 1:

                            strcpy((DATO+i)->numero_cuenta,temporal);

                            break;
                            }
                        contador++;
                        var_ptr=temporal;             // Mi puntero toma el valor de la variable
                        }
                    }

                *var_ptr='\0';

                (DATO+i)->operacion=atoi(temporal);

                }

            for( a=1; a<i+1; a++){ // Muestro por pantalla todas las cuentas dentro del archivo de texto, no importa si se repiten.
                printf("Numero de cuentas en registro [%s]\n",(DATO+a)->numero_cuenta);
            }

            a=0;
            printf("\nIngrese numero de cuenta existente: ");
            scanf("%s",cuenta);

            printf("\n -- Mostrando historial de movimientos --\n\n");

            while(a < i+1){ // Recorro el vector, mientras el espacio donde recorro es menor al que guarde (i+1 para que no comience en 0)

                if(strcmp(cuenta,(DATO+a)->numero_cuenta)==0){ // Si la cuenta ingresada es igual a alguna de las cuentas dentro del registro.

                        if((DATO+a)->operacion == 0){
                            printf("La cuenta se creo. \n");
                        }

                        if((DATO+a)->operacion == 1){
                            printf("Se ralizo la operacion de credito \n");
                        }

                        if((DATO+a)->operacion == 2 ){
                            printf("La operacion realizada fue debito. \n");
                        }

                        if((DATO+a)->operacion == 9 ){
                            printf("Ocurrio un error al realizar la operacion credito, saldo insuficiente. \n");
                        }

                        if((DATO+a)->operacion == 8 ){
                            printf("Ocurrio un error al realizar la operacion debito, saldo insuficiente. \n");
                        }

                        if((DATO+a)->operacion == 3 ){
                            printf("Se ha depositado saldo en la cuenta. \n"); // Este arreglo es adicional a criterio propio para que las cuentas no esten saldo 0.
                        }
            }
            a++; // Incremento el contador para recorrer el vector.
        }
        fclose(archivo); // Cierro el archivo
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificar_nombre()
{
   FILE * binario;
   struct registro nuevo_nombre;
   char numerodecuenta[10]; // String para el ingreso del numero de la cuenta
   int existe=0;
   int posicion; // Variable posicion para ubicarme dentro del archivo
   int validacion;

    binario=fopen("saldo_cuenta.bin","rb+");

    if (binario==NULL){
        printf("Error al abrir el archivo binario..");
    }else{

            printf("Leyendo archivo binario...\n\n");
            fread (&nuevo_nombre,sizeof(nuevo_nombre),1,binario);

            while(!feof(binario)){
                printf("Numero de cuenta: [%s] - \n",nuevo_nombre.numero_cuenta);   //Imprimo por pantalla los datos de todas las cuentas guardadas
                fread (&nuevo_nombre,sizeof(nuevo_nombre), 1,binario);
            }

        rewind(binario);

        printf("\nIngrese el numero de cuenta a modificar:"); //Le pido al usuario que seleccione la cuenta para agregarle el nombre
        scanf("%s", &numerodecuenta);

        fread(&nuevo_nombre, sizeof(struct registro), 1, binario); // Comienzo la lectura del archivo binario

        while(existe==0){ // Bucle hasta llegar al final del archivo


            if (strcmp(numerodecuenta,nuevo_nombre.numero_cuenta)==0){                   // Comparo el numero de cuenta ingresada con los existentes
               printf("\nNombre actual de la cuenta: [%s]\n", nuevo_nombre.name);       // Imprimo el nombre de la cuenta (mostrara basura si no hubo antes algun nombre)

               do{

               printf("\nIngrese nuevo nombre: ");                                     //Se ingresa el nombre para la cuenta
               scanf("%s",&nuevo_nombre.name);
               validacion = ValidarNombre(nuevo_nombre.name);// Validacion toma el valor retornado de la funcion validar nombre.

               }while(validacion == 0); // El while se ejecuta mientras el valor retornado sea 0 (falso)

               for(int i=0; nuevo_nombre.name[i]!='\0';i++){                     // Itero dentro del string para pasar cada caracter a mayuscula
                    if(nuevo_nombre.name[i]>='a' && nuevo_nombre.name[i]<='z'){   // Si el caracter se encuentra entre las letras de la 'a' a la 'z'
                        nuevo_nombre.name[i] = nuevo_nombre.name[i]-32;          // Transformo a mayuscula (-32 espacios de la tabla ascii)
                    }
               }

               posicion=ftell(binario)-sizeof(struct registro);                //Posicion pasa a ser el valor devuelto de ftell (posicion actual del cursor en el archivo) menos el tamaño en memoria del struct registro.
               fseek(binario,posicion,SEEK_SET);                              //Usando fseek indicamos que nos queremos mover X bytes con respecto al inicio, segun el valor de "posicion".
               fwrite(&nuevo_nombre, sizeof(struct registro), 1, binario);   //Una vez posicionados en el campo de nombre, escribimos dentro del archivo.

               printf("Se cambio el nombre de la cuenta..\n");
               existe=1;  //La variable existe toma el valor de 1;
              // break;  // Break para poder salir del bucle una vez hice el cambio de nombre (fuerzo la salida del bucle).
            }
            fread(&nuevo_nombre, sizeof(struct registro), 1, binario);
        }

        if (existe==0) // Si nunca entro al if dentro del bucle, existe sigue valiendo 0, entonces significa que la cuenta no existe.
            printf("La cuenta ingresada no existe, saliendo..\n");

        fclose(binario);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ValidarNombre(char nombre[]) // Recibo por parametro el string
{
    for (int i=0; i<strlen(nombre); i++){ //Interpreto el string recibido como una cadena de un solo byte (funcion strlen)
        if(!(nombre[i]>= 65 && nombre[i]<=90 || nombre[i]>=97 && nombre[i]<=122)){ //Si lo ingresado es distinto al intervalo de letras (tabla asci) retornara 0 (falso)
           printf("Favor de ingresar solamente letras.");
           return 0;
        }
    }
    return 1; // Si no entro al if, retorna 1 (verdadero)
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrar_informacion(FILE * binario)
{
    struct registro lectura;

    if((binario = fopen("saldo_cuenta.bin", "rb"))==NULL){  // Abro en solo lectura, no se necesitan mas permisos.

            printf("\nError al leer el archivo saldo_cuentas.bin...\n");
        }else{

            printf("Leyendo archivo binario...\n\n");
            fread (&lectura,sizeof(lectura),1,binario);
            printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
            while(!feof(binario)){

                printf("Nro.Cuenta [%s] - ",lectura.numero_cuenta);        //Imprimo por pantalla los datos de todas las cuentas que estan guardadas en el archivo binario
                printf("Saldo en la cuenta [$%.2f] - ",lectura.saldo_monto);
                printf("Nombre de la cuenta [%s]\n\n", lectura.name);

                fread (&lectura,sizeof(lectura), 1,binario);
            }
            printf("////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
        fclose (binario); // cierro el archivo
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void top3_maximosaldo(FILE * binario) // Para mostrar el top 3 de los saldos, uso el metodo de ordenamiento burbuja
{
    struct registro * saldos;  // Creo un puntero a registro
    struct registro lectura;  // creo un tipo de variable registro

    int i=1;
    int ordenado=0;
    int aux;
    int posicion;

    saldos = (struct registro*)malloc(TAM2*sizeof(struct registro)); //Asigno memoria para el de struct

    if (saldos==NULL)
    {                                                   /*Verifico si hay memoria en la PC*/
        printf("\n\nProblemas reservando memoria...");
        exit (1);
    }else{

      if((binario = fopen("saldo_cuenta.bin", "rb"))==NULL){
            printf("\nNo se pudo abrir el archivo.\n");
       }else{

            fread (&lectura,sizeof(struct registro),1,binario);

            while(!feof(binario)){
                                                     // while con la condicion de que se ejecute mientras i sea menor a TAM2 y ordenado valga 0
                while(i<TAM2 && ordenado==0){       // Ordeno el vector cargado con el metodo de burbujeo
                    ordenado=1;

                    for(int j=0; j<TAM2-1; j++){
                        if((saldos+j)->saldo_monto < (saldos+j+1)->saldo_monto){         /*Si el elemento en la posicion de J es mayor que la siguiente posicion*/
                            ordenado=0;                                                 /* La variable ordenado tma el valor de 0*/
                            aux = (saldos+j+1)->saldo_monto;                           /* "aux" pasa a ser la siguiente posicion (j+1)*/
                            (saldos+j+1)->saldo_monto = (saldos+j)->saldo_monto;      /* se intercambia la posicion con la anterior [j+1] = [j]*/
                            (saldos+j)->saldo_monto   = aux;                         /* la posicion [j] pasa a ser aux*/
                        }
                    }
                    i++;        /* Se incrementa el valor de i cada vez que se intercambien posiciones, esto para que siga comparando hasta que quede ordenado*/
                }
                fread (&lectura,sizeof(struct registro),1,binario);
            }
        printf("\n");
        for(int a=0; a<3; a++){
            printf("TOP %d Mayor Saldo [$%.2f]\n", a+1, (saldos+a)->saldo_monto);
        }
        fclose (binario); // cierro el archivo
       }
    free(saldos);       //Libero memoria utilizada
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificarbinario(struct modificar DATOS) // Recibo el tipo de dato struct 'DATOS' de los datos guardados.
{
    FILE * arch, * registro;

   int existe=0;
   int posicion; // Variable posicion para ubicarme dentro del archivo
   struct registro lectura; // Tipo de dato struct 'lectura' para recorrer el archivo binario

    registro = fopen("registro.txt", "a+");   // Abro el archivo registro en formato añadir
    arch = fopen("saldo_cuenta.bin", "rb+"); // Abro el binario en formato leer y escribir.

    if(arch==NULL && registro==NULL){
            printf("\nError al leer el archivo saldo_cuentas.bin...\n");
        }else{

                    fread (&lectura,sizeof(struct registro),1,arch);

                    while(!feof(arch)){

                        if(strcmp(DATOS.numerodeecuenta, lectura.numero_cuenta)==0 && DATOS.operaciones == 0){ //Si el numero de cuenta es igual al que tengo guardado en el binario y existe una operacion.

                        lectura.saldo_monto = 0; // Si la cuenta se creo, corrijo el saldo copiado de movimientos a 0, porque una cuenta creada no puede tener saldo.

                        fprintf(registro, "%s,", DATOS.numerodeecuenta);                              // Escribo el Numero de cuenta + el separador ','
                        fputs("0\n", registro);                                                      // Escribo el numero de operacion realizada

                        posicion=ftell(arch)-sizeof(struct registro);                                  //Posicion pasa a ser el valor devuelto de ftell (posicion actual del cursor en el archivo) restandole el tamaño en memoria del struct registro.
                        fseek(arch,posicion,SEEK_SET);                                                //Usando fseek indicamos que nos queremos mover X bytes con respecto al inicio, segun el valor de "posicion".
                        fwrite(&lectura, sizeof(struct registro), 1, arch);                          //Una vez posicionados en el campo de nombre, escribimos dentro del archivo.

                        printf("Se modifico el saldo segun operacion crear cuenta..\n");
                        existe=1; // Existe pasa a valer 1, esto se repite en los siguientes bucles.
                       // break;   // Break para salir del bucle una vez modifique el saldo de la cuenta, sin esto sobreescribiria datos incorrectos.
                        }
                        fread (&lectura,sizeof(struct registro), 1,arch);
                    }


                    rewind(arch);  // Rebobino el archivo para empezar desde el inicio.
                    existe=0;

                    fread (&lectura,sizeof(struct registro),1,arch);
                    while(!feof(arch)){

                        if(strcmp(DATOS.numerodeecuenta, lectura.numero_cuenta)==0 && DATOS.operaciones == 1){

                            lectura.saldo_monto = lectura.saldo_monto - DATOS.saldos; //La operacion fue credito, entonces hago la resta entre el saldo solicitado y el saldo de la cuenta.

                            if(lectura.saldo_monto > 0){                                                          // Si el resultado es mayor a cero, significa que la operacion fue exitosa.
                                fprintf(registro, "%s,", lectura.numero_cuenta);                                 //Escribo el Numero de cuenta en el archivo registro.txt
                                fputs("1\n", registro);
                            }else{                                                                         //Sino, significa que el resultado es menor a cero, entonces..
                                lectura.saldo_monto = 0;                                                  //Corrijo el saldo en 0 para que no quede en negativo.
                                fprintf(registro, "%s,", lectura.numero_cuenta);                         //Escribo el Numero de cuenta en el archivo registro.txt
                                fputs("9\n", registro);                                                 // Escribo el numero 9, dandole el significado de que ocurrio un error en credito.
                            }

                        posicion=ftell(arch)-sizeof(struct registro);                     //Posicion pasa a ser el valor devuelto de ftell (posicion actual del cursor en el archivo) restandole el tamaño en memoria del struct registro.
                        fseek(arch,posicion,SEEK_SET);                                   //Usando fseek indicamos que nos queremos mover X bytes con respecto al inicio, segun el valor de "posicion".
                        fwrite(&lectura, sizeof(struct registro), 1, arch);             //Una vez posicionados en el campo de nombre, escribimos dentro del archivo.


                        printf("Se modifico el saldo segun operacion credito..\n"); // Indico por pantalla la operacion realizada.
                        existe=1;
                        break;   // Break para salir del bucle una vez modifique el saldo de la cuenta, sin esto sobreescribiria datos incorrectos.

                        }
                        fread (&lectura,sizeof(struct registro), 1,arch);
                    }


                    rewind(arch);  // Rebobino el archivo para empezar desde el inicio.


                    fread (&lectura,sizeof(struct registro),1,arch);
                    while(!feof(arch)){

                        if(strcmp(DATOS.numerodeecuenta, lectura.numero_cuenta)==0 && DATOS.operaciones == 2){

                            lectura.saldo_monto = lectura.saldo_monto - DATOS.saldos;                       //La operacion fue debito, entonces hago la resta entre el saldo solicitado y el saldo de la cuenta.

                            if(lectura.saldo_monto > 0){                                                          // Si el resultado es mayor a cero, significa que la operacion fue exitosa.
                                fprintf(registro, "%s,", lectura.numero_cuenta);                                 //Escribo el Numero de cuenta en el archivo registro.txt
                                fputs("2\n", registro);
                            }else{                                                                  //Sino, significa que el resultado es menor a cero, entonces..
                                lectura.saldo_monto = 0;                                           //Corrijo el saldo en 0 para que no quede en negativo.
                                fprintf(registro, "%s,", lectura.numero_cuenta);                  //Escribo el Numero de cuenta en el archivo registro.txt
                                fputs("8\n", registro);                                          // Escribo el numero 8, dandole el significado de que ocurrio un error en debito.
                            }

                        posicion=ftell(arch)-sizeof(struct registro);                         //Posicion pasa a ser el valor devuelto de ftell (posicion actual del cursor en el archivo) restandole el tamaño en memoria del struct registro.
                        fseek(arch,posicion,SEEK_SET);                                       //Usando fseek indicamos que nos queremos mover X bytes con respecto al inicio, segun el valor de "posicion".
                        fwrite(&lectura, sizeof(struct registro), 1, arch);                 //Una vez posicionados en el campo de nombre, escribimos dentro del archivo.

                        printf("Se modifico el saldo segun operacion debito..\n");
                        existe=1;
                        break;   // Break para salir del bucle una vez modifique el saldo de la cuenta, sin esto sobreescribiria datos incorrectos.

                        }
                        fread (&lectura,sizeof(struct registro), 1,arch);
                    }


                   rewind(arch);  // Rebobino el archivo para empezar desde el inicio.


                    fread (&lectura,sizeof(struct registro),1,arch);
                    while(!feof(arch)){

                        if(strcmp(DATOS.numerodeecuenta, lectura.numero_cuenta)==0 && DATOS.operaciones == 3){

                            lectura.saldo_monto = lectura.saldo_monto + DATOS.saldos; //La operacion fue depositar, entonces hago la suma entre el saldo depositado y el saldo de la cuenta.

                            if(lectura.saldo_monto > 0){                                                   // Si el resultado es mayor a cero, significa que la operacion fue exitosa.
                                fprintf(registro, "%s,", lectura.numero_cuenta);                          //Escribo el Numero de cuenta en el archivo registro.txt
                                fputs("3\n", registro);                                                  //El numero 3 significa que se ha depositado dinero en la cuenta correspondiente.
                            }

                        posicion=ftell(arch)-sizeof(struct registro);                  //Posicion pasa a ser el valor devuelto de ftell (posicion actual del cursor en el archivo) restandole el tamaño en memoria del struct registro.
                        fseek(arch,posicion,SEEK_SET);                                //Usando fseek indicamos que nos queremos mover X bytes con respecto al inicio, segun el valor de "posicion".
                        fwrite(&lectura, sizeof(struct registro), 1, arch);          //Una vez posicionados en el campo de nombre, escribimos dentro del archivo.

                        printf("Se modifico el saldo segun el saldo depositado..\n");
                        existe=1;
                        break;   // Break para salir del bucle una vez modifique el saldo de la cuenta, sin esto sobreescribiria datos incorrectos.

                        }
                        fread (&lectura,sizeof(struct registro), 1,arch);
                    }

        if (existe==0) // Si existe vale 0, significa que no se cumplio ninguna de las condiciones anteriores, por ende es un error.
            printf("Error al realizar operaciones, saliendo...\n");

        fclose(registro); // Cierro el archivo.txt
        fclose (arch); // cierro el archivo.bin
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
