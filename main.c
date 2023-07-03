#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char marca[20];
    int anio;
    char ficha[10];
    char propietario[20];
}Carro;



typedef struct{
    int ID;
    char nombre[40];
    char trabajo[20];
    char celular[15];
    char comp_movil[20];
}Pasajeros;



typedef struct{
    int dia;
    int mes;
    int year;
    char hora[10]; // Hora, minuto y segundos
}Tiempo;



typedef struct{
    char ficha[10];
    Tiempo tiempo;
    int cliente;
    int pago;
    int devuelta;
    int cant_estimada;

}Servicio;


int MostrarMenu();
int MostrarMenu2();
int MostrarMenu3();
int MostrarMenu4();
void CapturarConcho(int, Carro*);
void CapturarPasajeros(int, Pasajeros*);
void CapturarServicio(int, Servicio*);
void VerPasajerosdeUnConcho(int, Servicio*, Pasajeros*, Carro*);
void VerPasajerosdeUnConcho_Trabajo(int, Servicio*, Pasajeros*, Carro*);
void VerPasajerosdeUnConcho_Telef(int, Servicio*, Pasajeros*, Carro*);
void VerPasajerosdeUnConcho_Tiempo(int, Servicio*, Pasajeros*, Carro*);
void VerPasajerosdeUnConcho_Monto(int, Servicio*, Pasajeros*, Carro*);
void VerPasajerosdeUnConcho_Monto_Devuelta(int, Servicio*, Pasajeros*, Carro*);
void VerPasajerosdeUnConcho_Fecha(int, Servicio*, Pasajeros* , Carro*);
void VerConchoqueMontaUnPasajero(int ind, Servicio* , Pasajeros* , Carro*);
void VerConchoModelo(int, Servicio*, Pasajeros*, Carro*);
void VerConchoMarca(int, Servicio*, Pasajeros* , Carro* );
void VerConchoPropietario(int, Servicio*, Pasajeros*, Carro*);
void VerConchoMonto(int, Servicio* , Pasajeros* , Carro* );
void VerConchoFecha(int, Servicio*, Pasajeros*, Carro*);
void VerFichaCarro(int, Servicio*, Pasajeros*, Carro*);
void VerIDPasajero(int, Servicio*, Pasajeros*, Carro*);
void VerRangoMonto(int, Servicio* , Pasajeros* , Carro*);
void VerRangoFecha(int, Servicio*, Pasajeros*, Carro*);
void VerRangoTiempo(int, Servicio*, Pasajeros*, Carro*);

int main()

{

    int CantPasajeros = 0, CantConcho = 0, CantServicio = 0;

    Carro *ListadoConcho = (Carro*)malloc(sizeof(Carro) *CantConcho);
    Pasajeros *ListadoPasajeros = (Pasajeros*)malloc(sizeof(Pasajeros) *CantPasajeros);
    Servicio *ListadoServicio = (Servicio*)malloc(sizeof(Servicio) *CantServicio);

    int option=0, option2=0, option3=0, option4=0;

    do {

        option = MostrarMenu();

        switch (option) {

            case 1:

                CantConcho++;
                ListadoConcho = (Carro *) realloc(ListadoConcho, sizeof(Carro) * CantConcho);
                CapturarConcho(CantConcho - 1, ListadoConcho);

                break;

            case 2:

                CantPasajeros++;
                ListadoPasajeros = (Pasajeros *) realloc(ListadoPasajeros, sizeof(Pasajeros) * CantPasajeros);
                CapturarPasajeros(CantPasajeros - 1, ListadoPasajeros);

                break;

            case 3:

                CantServicio++;
                ListadoServicio = (Servicio *) realloc(ListadoServicio, sizeof(Servicio) * CantServicio);
                CapturarServicio(CantServicio - 1, ListadoServicio);

                break;

            case 4:

                do {

                    option2 = MostrarMenu2();

                    switch (option2) {

                        case 1:

                            VerPasajerosdeUnConcho(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                            break;

                        case 2:

                            VerPasajerosdeUnConcho_Trabajo(CantServicio, ListadoServicio, ListadoPasajeros,
                                                           ListadoConcho);
                            break;

                        case 3:

                            VerPasajerosdeUnConcho_Telef(CantServicio, ListadoServicio, ListadoPasajeros,
                                                         ListadoConcho);
                            break;

                        case 4:

                            VerPasajerosdeUnConcho_Tiempo(CantServicio, ListadoServicio, ListadoPasajeros,
                                                          ListadoConcho);
                            break;

                        case 5:

                            VerPasajerosdeUnConcho_Monto(CantServicio, ListadoServicio, ListadoPasajeros,
                                                         ListadoConcho);
                            break;

                        case 6:

                            VerPasajerosdeUnConcho_Monto_Devuelta(CantServicio, ListadoServicio, ListadoPasajeros,
                                                                  ListadoConcho);
                            break;

                        case 7:
                            VerPasajerosdeUnConcho_Fecha(CantServicio, ListadoServicio, ListadoPasajeros,
                                                         ListadoConcho);
                            break;

                    }
                } while (option2 != 8);


            case 5:

                do {

                    option3 = MostrarMenu3();

                    switch (option3) {

                        case 1:
                            VerConchoqueMontaUnPasajero(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);

                            break;

                        case 2:
                            VerConchoModelo(CantServicio, ListadoServicio, ListadoPasajeros,ListadoConcho);

                            break;

                        case 3:
                          VerConchoMarca(CantServicio,  ListadoServicio,  ListadoPasajeros, ListadoConcho);

                            break;

                        case 4:
                            VerConchoMonto(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                            break;

                        case 5:
                            VerConchoPropietario(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                            break;

                        case 6:
                           VerConchoFecha(CantServicio,  ListadoServicio, ListadoPasajeros, ListadoConcho);
                            break;


                    }
                } while (option3 != 7);


            case 6:

                do {

                    option4 = MostrarMenu4();

                    switch (option4) {

                        case 1:

                            VerFichaCarro(CantServicio, ListadoServicio, ListadoPasajeros,ListadoConcho);

                            break;

                        case 2:

                            VerIDPasajero(CantServicio, ListadoServicio,  ListadoPasajeros,  ListadoConcho);

                            break;

                        case 3:
                            VerRangoMonto(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);

                            break;

                        case 4:

                            VerRangoFecha(CantServicio,  ListadoServicio, ListadoPasajeros,  ListadoConcho);
                            break;

                        case 5:
                                VerRangoTiempo(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                            break;

                        case 6:

                            break;


                    }
                } while (option3 != 7);

                break;


        }
    } while (option != 7);

    printf("\n=====Hasta luego!=====\n");

    return 0;

    }


int MostrarMenu()

{
    char opcion;

        printf("\n======DEPARTAMENTO DE TRANSPORTE PUBLICO DE CONCHOS======\n");
        printf("Elija las siguientes opciones para:\n\n");
        printf("1. Registar un carro publico.\n");
        printf("2. Registar un pasajero.\n");
        printf("3. Registrar un servicio de transporte.\n");
        printf("4. Mostrar pasajeros que un concho ha tomado.\n");
        printf("5. Mostrar datos de los conchos que un cliente especifico ha tomado. \n");
        printf("6. Mostrar servicios de transporte.\n");
        printf("7. Salir\n\n.");

        printf("RESPUESTA: ");

        fflush(stdin);
        opcion= getchar();

        switch(opcion)
        {
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;

            case '4':
                return 4;

            case '5':
                return 5;

            case '6':
                return 6;

            case '7':
                return 7;

            default:
                return 0;
        }
}


int MostrarMenu2()

{
    char opcion2;

    printf("Elija las siguientes opciones para mostrar:\n\n");
    printf("1. Todos los pasajeros (sin ningun criterio de filtrado).\n");
    printf("2. Todos los pasajeros cuyo lugar de trabajo sea especificado.\n");
    printf("3. Todos los pasajeros cuyo celular sea de una compania especificada.\n");
    printf("4. Todos los pasajeros cuyo tiempo de viaje promedio este en un rango especificado.\n");
    printf("5. Todos los pasajeros cuyo monto con el que pago este en un rango especificado. \n");
    printf("6. Todos los pasajeros cuyo monto del servicio (monto con el que pago menos la devuelta) este en un \n"
           "rango especificado.\n");
    printf("7. Todos los pasajeros cuya fecha y hora de servicio esta en un rango de fecha y hora especificado.\n.");
    printf("8. Salir.\n\n.");

    printf("RESPUESTA: ");

    fflush(stdin);
    opcion2= getchar();

    switch(opcion2)
    {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;

        case '4':
            return 4;

        case '5':
            return 5;

        case '6':
            return 6;

        case '7':
            return 7;

        case '8':
            return 8;
        default:
            return 0;
    }
}


int MostrarMenu3()
{
    char opcion3;

    printf("Elija las siguientes opciones para mostrar:\n\n");
    printf("1. Todos los carros publicos (sin ningun criterio de filtrado).\n");
    printf("2. Todos los carros cuyo anyo del modelo este en un rango.\n");
    printf("3. Todos los carros cuya marca sea la especificada por el usuario.\n");
    printf("4. Todos los carros a los que se les haya pagado con un monto que este en un rango especificado.\n");
    printf("5. Todos los carros de un propietario especificado.\n");
    printf("6. Todos los carros en los que se haya montado en una fecha dentro de un rango especificado.\n");
    printf("7. Salir.\n\n.");

    printf("RESPUESTA: ");

    fflush(stdin);
    opcion3= getchar();

    switch(opcion3)
    {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;

        case '4':
            return 4;

        case '5':
            return 5;

        case '6':
            return 6;

        case '7':
            return 7;

        case '8':
            return 8;
        default:
            return 0;
    }
}


int MostrarMenu4()

{
    char opcion4;

    printf("Elija las siguientes opciones para mostrar:\n\n");
    printf("1. Ficha del carro.\n");
    printf("2. Id del pasajero.\n");
    printf("3. Rango del monto del servicio.\n");
    printf("4. Rango de fecha y hora del servicio.\n");
    printf("5. Rango de tiempo estimado del viaje.\n");
    printf("6. Todos.\n");
    printf("7. Salir.\n.");

    printf("RESPUESTA: ");

    fflush(stdin);
    opcion4= getchar();

    switch(opcion4)
    {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;

        case '4':
            return 4;

        case '5':
            return 5;

        case '6':
            return 6;

        default:
            return 0;
    }
}





void CapturarConcho(int ind, Carro* ListadoConcho)

{

    printf("MARCA DEL VEHICULO: ");
    fflush(stdin);
    gets((ListadoConcho+ind)->marca);
    printf("\n");


    printf("ANYO DEL VEHICULO: ");
    scanf("  %d", &((ListadoConcho+ind)->anio));
    printf("\n");


    printf("FICHA: ");
    fflush(stdin);
    gets((ListadoConcho+ind)->ficha);
    printf("\n");


    printf("PROPIETARIO: ");
    fflush(stdin);
    gets((ListadoConcho+ind)->propietario);

    printf("\nAGREGADO EXITOSAMENTE.\n\n");

}



void CapturarPasajeros(int ind, Pasajeros* ListadoPasajeros)

{

    printf("ID DEL CLIENTE: ");
    scanf("%d", &((ListadoPasajeros+ind)->ID));
    printf("\n");


    printf("NOMBRE COMPLETO : ");
    fflush(stdin);
    gets((ListadoPasajeros+ind)->nombre);
    printf("\n");


    printf("LUGAR DE TRABAJO: ");
    fflush(stdin);
    gets((ListadoPasajeros+ind)->trabajo);
    printf("\n");


    printf("CELULAR: ");
    fflush(stdin);
    gets((ListadoPasajeros+ind)->celular);
    printf("\n");


    printf("COMPANIA MOVIL: ");
    fflush(stdin);
    gets((ListadoPasajeros+ind)->comp_movil);

    printf("\nAGREGADO EXITOSAMENTE\n\n");

}



void CapturarServicio(int ind, Servicio* ListadoServicio)

{

    printf("ID DEL CLIENTE: ");
    scanf("%d", &((ListadoServicio+ind)->cliente));
    printf("\n");

    printf("INDIQUE PAGO DEL SERVICIO: ");
    scanf("%d", &((ListadoServicio+ind)->pago));
    printf("\n");


    printf("INDIQUE PAGO DE LA DEVUELTA: ");
    scanf("%d", &((ListadoServicio+ind)->devuelta));
    printf("\n");

    printf("INDIQUE CANTIDAD ESTIMADA DEL SERVICIO: ");
    scanf("%d", &((ListadoServicio+ind)->cant_estimada));
    printf("\n");


    // int dia;
    // int mes
    // int anio;
    // char hora[10]; Hora, minuto y segundos


    printf("DIA DEL SERVICIO:");
    scanf("%d", &((ListadoServicio+ind)->tiempo.dia));

    printf("MES DEL SERVICIO:");
    scanf(" %d", &((ListadoServicio+ind)->tiempo.mes));

    printf("ANYO DEL SERVICIO:");
    scanf(" %d", &((ListadoServicio+ind)->tiempo.year));

    printf("HORA APROXIMADA DEL SERVICIO(HORA/MINUTO/SEGUNDO): ");
    fflush(stdin);
   gets((ListadoServicio+ind)->tiempo.hora);

    printf("FICHA: ");
    fflush(stdin);
    gets((ListadoServicio+ind)->ficha);
    printf("\n");


    printf("\nAGREGADO EXITOSAMENTE\n\n");
}

//PASAJEROS

void VerPasajerosdeUnConcho(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i =0;
    char fiches[10];

    printf("\nDIGITE LA FICHA DEL CONCHO QUE DESEA VER: ");
    fflush(stdin);
    gets(fiches);
    printf("\n");

    for(i = 0; i < ind; i++) {

        if (strcmp(fiches, (ListadoServicio + i)->ficha) == 0){  //AGREGAR EL LISTADOCONCHO -> && (ListadoConcho+i)->ficha ==(ListadoServicio+i)->ficha)

            if( (ListaPasajeros + i)->ID == (ListadoServicio + i)->cliente){

            printf("CLIENTE ID: %d\n", (ListaPasajeros+i)->ID);
            printf("NOMBRE: %s\n", (ListaPasajeros+i)->nombre);
            printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+i)->trabajo);
            printf("CEULAR: %s\n", (ListaPasajeros+i)->celular);
            printf("COMPANIA MOVIL: %s\n\n", (ListaPasajeros+i)->comp_movil);
            //rintf("%d\n", i);

        }
        }
    }
    }



void VerPasajerosdeUnConcho_Trabajo(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i =0;
    char fiches[10], trabajar[10];

    printf("\nDIGITE LA FICHA DEL CONCHO QUE DESEA VER: ");
    fflush(stdin);
    gets(fiches);
    printf("\n");

    printf("\nDIGITE EL TRABAJO DE LOS PASAJEROS QUE DESEA VER: ");
    fflush(stdin);
    gets(trabajar);
    printf("\n");

    for(i = 0; i < ind; i++) {

        if (strcmp(fiches, (ListadoServicio + i)->ficha) == 0){  //AGREGAR EL LISTADOCONCHO -> && (ListadoConcho+i)->ficha ==(ListadoServicio+i)->ficha)

            if(strcmp(trabajar, (ListaPasajeros + i)->trabajo) == 0){

                printf("CLIENTE ID: %d\n", (ListaPasajeros+i)->ID);
                printf("NOMBRE: %s\n", (ListaPasajeros+i)->nombre);
                printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+i)->trabajo);
                printf("CEULAR: %s\n", (ListaPasajeros+i)->celular);
                printf("COMPANIA MOVIL: %s\n\n", (ListaPasajeros+i)->comp_movil);
                //rintf("%d\n", i);

            }
        }
    }
}



void VerPasajerosdeUnConcho_Telef(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i =0;
    char fiches[10], comp_telefonica[10];

    printf("\nDIGITE LA FICHA DEL CONCHO QUE DESEA VER: ");
    fflush(stdin);
    gets(fiches);
    printf("\n");

    printf("\nDIGITE LA COMPANIA TELEFONICA DE LOS PASAJEROS QUE DESEA VER: ");
    fflush(stdin);
    gets(comp_telefonica);
    printf("\n");

    for(i = 0; i < ind; i++) {

        if (strcmp(fiches, (ListadoServicio + i)->ficha) == 0){

            if(strcmp(comp_telefonica, (ListaPasajeros + i)->comp_movil) == 0){

                printf("CLIENTE ID: %d\n", (ListaPasajeros+i)->ID);
                printf("NOMBRE: %s\n", (ListaPasajeros+i)->nombre);
                printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+i)->trabajo);
                printf("CEULAR: %s\n", (ListaPasajeros+i)->celular);
                printf("COMPANIA MOVIL: %s\n\n", (ListaPasajeros+i)->comp_movil);
                //rintf("%d\n", i);

            }
        }
    }
}


//
void VerPasajerosdeUnConcho_Tiempo(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i =0;
    char tiempo[10], fiches[10];

    printf("\nDIGITE LA FICHA DEL CONCHO QUE DESEA VER: ");
    fflush(stdin);
    gets(fiches);
    printf("\n");

    printf("\nDIGITE UN RANGO PROMEDIO DEL VIAJE DE LOS PASAJEROS QUE DESEA VER: ");
    fflush(stdin);
    gets(tiempo);
    printf("\n");

    for(i = 0; i < ind; i++) {

        if (strcmp(fiches, (ListadoServicio + i)->ficha) == 0){

            if(strcmp(tiempo, (ListadoServicio+i)->tiempo.hora) == 0){

                printf("CLIENTE ID: %d\n", (ListaPasajeros+i)->ID);
                printf("NOMBRE: %s\n", (ListaPasajeros+i)->nombre);
                printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+i)->trabajo);
                printf("CEULAR: %s\n", (ListaPasajeros+i)->celular);
                printf("COMPANIA MOVIL: %s\n\n", (ListaPasajeros+i)->comp_movil);
                //rintf("%d\n", i);

            }
        }
    }
}



//
void VerPasajerosdeUnConcho_Monto(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i =0, monto_min, monto_max;
    char fiches[10];

    printf("\nDIGITE LA FICHA DEL CONCHO QUE DESEA VER: ");
    fflush(stdin);
    gets(fiches);
    printf("\n");

    printf("\nDIGITE UN RANGO MINIMO DEL PAGO DE LOS PASAJEROS QUE DESEA VER: ");
    fflush(stdin);
    scanf("%d", &monto_min);
    printf("\n");

    printf("\nDIGITE UN RANGO MAXIMO DEL PAGO DE LOS PASAJEROS QUE DESEA VER: ");
    fflush(stdin);
    scanf("%d", &monto_max);
    printf("\n");

    for(i = 0; i < ind; i++) {

        if (strcmp(fiches, (ListadoServicio+i)->ficha) == 0){

            if(monto_min <= (ListadoServicio+i)->pago &&  monto_max >= (ListadoServicio+i)->pago && (ListadoServicio+i)->cliente == (ListaPasajeros)->ID){

                printf("CLIENTE ID: %d\n", (ListaPasajeros+i)->ID);
                printf("NOMBRE: %s\n", (ListaPasajeros+i)->nombre);
                printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+i)->trabajo);
                printf("CEULAR: %s\n", (ListaPasajeros+i)->celular);
                printf("COMPANIA MOVIL: %s\n\n", (ListaPasajeros+i)->comp_movil);
                //rintf("%d\n", i);

            }
        }
    }
}



//
void VerPasajerosdeUnConcho_Monto_Devuelta(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i =0, monto_min, monto_max;
    char fiches[10];

    printf("\nDIGITE LA FICHA DEL CONCHO QUE DESEA VER: ");
    fflush(stdin);
    gets(fiches);
    printf("\n");

    printf("\nDIGITE UN RANGO MINIMO DEL PAGO MENOS LA DEVUELTA DE LOS PASAJEROS QUE DESEA VER: ");
    fflush(stdin);
    scanf("%d", &monto_min);
    printf("\n");

    printf("\nDIGITE UN RANGO MAXIMO DEL PAGO MENOS LA DEVULETA DE LOS PASAJEROS QUE DESEA VER: ");
    fflush(stdin);
    scanf("%d", &monto_max);
    printf("\n");

    for(i = 0; i < ind; i++) {

        if (strcmp(fiches, (ListadoServicio+i)->ficha) == 0){

            if(monto_min <= (ListadoServicio+i)->cant_estimada <= monto_max && (ListadoServicio+i)->cliente == (ListaPasajeros)->ID){

                printf("CLIENTE ID: %d\n", (ListaPasajeros+i)->ID);
                printf("NOMBRE: %s\n", (ListaPasajeros+i)->nombre);
                printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+i)->trabajo);
                printf("CEULAR: %s\n", (ListaPasajeros+i)->celular);
                printf("COMPANIA MOVIL: %s\n\n", (ListaPasajeros+i)->comp_movil);
                //rintf("%d\n", i);

            }
        }
    }
}



//
void VerPasajerosdeUnConcho_Fecha(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i =0;
    char fiches[10], tiempo_rango[10];

    printf("\nDIGITE LA FICHA DEL CONCHO QUE DESEA VER: ");
    fflush(stdin);
    gets(fiches);
    printf("\n");

    printf("\nDIGITE UN RANGO DE FECHA DE LOS PASAJEROS QUE DESEA VER: ");
    fflush(stdin);
    gets(tiempo_rango);
    printf("\n");

    for(i = 0; i < ind; i++) {

        if (strcmp(fiches, (ListadoServicio+i)->ficha) == 0){

            if(strcmp(tiempo_rango, (ListadoServicio+i)->tiempo.hora) == 0){

                printf("CLIENTE ID: %d\n", (ListaPasajeros+i)->ID);
                printf("NOMBRE: %s\n", (ListaPasajeros+i)->nombre);
                printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+i)->trabajo);
                printf("CEULAR: %s\n", (ListaPasajeros+i)->celular);
                printf("COMPANIA MOVIL: %s\n\n", (ListaPasajeros+i)->comp_movil);

            }
        }
    }
}

//CARRO

void VerConchoqueMontaUnPasajero(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i =0, ids;

    printf("\nDIGITE EL ID DEL PASAJERO QUE DESEA VERIFICAR QUE CONCHOS HA TOMADO: ");
    fflush(stdin);
    scanf("%d", &ids);
    printf("\n");

    for(i = 0; i < ind; i++) {

        if(ids == (ListadoServicio)->cliente && ids == (ListaPasajeros)->ID){

            if (strcmp((ListadoConcho+i)->ficha, (ListadoServicio + i)->ficha) == 0){

                printf("FICHA: %s\n", (ListadoConcho+i)->ficha);
                printf("MARCA: %s\n", (ListadoConcho+i)->marca);
                printf("MODELO: %d\n", (ListadoConcho+i)->anio);
                printf("PROPIETARIO: %s\n\n", (ListadoConcho+i)->propietario);
            }
            }

    }
}



void VerConchoModelo(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i =0, ids, p_rango, ul_rango;

    printf("\nDIGITE EL ID DEL PASAJERO QUE DESEA VERIFICAR: ");
    fflush(stdin);
    scanf("%d", &ids);
    printf("\n");

    printf("\nDIGITE El PRIMER RANGO DE MODELO: ");
    fflush(stdin);
    scanf("%d", &p_rango);
    printf("\n");

    printf("\nDIGITE El PRIMER RANGO DE MODELO: ");
    fflush(stdin);
    scanf("%d", &ul_rango);
    printf("\n");

    for(i = 0; i < ind; i++) {

        if(ids == (ListadoServicio)->cliente && ids == (ListaPasajeros)->ID){

            if (strcmp((ListadoConcho+i)->ficha, (ListadoServicio + i)->ficha) == 0){

                if(p_rango <= (ListadoConcho+i)->anio && ul_rango >= (ListadoConcho+i)->anio){

                printf("FICHA: %s\n", (ListadoConcho+i)->ficha);
                printf("MARCA: %s\n", (ListadoConcho+i)->marca);
                printf("MODELO: %d\n", (ListadoConcho+i)->anio);
                printf("PROPIETARIO: %s\n\n", (ListadoConcho+i)->propietario);

                }
            }
        }

    }
}



void VerConchoMarca(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i =0, ids;
    char marcas[10];

    printf("\nDIGITE EL ID DEL PASAJERO QUE DESEA VERIFICAR QUE CONCHOS HA TOMADO: ");
    fflush(stdin);
    scanf("%d", &ids);
    printf("\n");

    printf("\nDIGITE LA MARCA DEL CARRO: ");
    fflush(stdin);
    gets(marcas);
    printf("\n");

    for(i = 0; i < ind; i++) {

        if(ids == (ListadoServicio)->cliente && ids == (ListaPasajeros)->ID){

            if (strcmp((ListadoConcho+i)->ficha, (ListadoServicio + i)->ficha) == 0) {

                if (strcmp(marcas, (ListadoConcho + i)->marca) == 0) {

                    printf("FICHA: %s\n", (ListadoConcho + i)->ficha);
                    printf("MARCA: %s\n", (ListadoConcho + i)->marca);
                    printf("MODELO: %d\n", (ListadoConcho + i)->anio);
                    printf("PROPIETARIO: %s\n\n", (ListadoConcho + i)->propietario);
                }
            }
        }

    }
}



void VerConchoPropietario(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i =0, ids;
    char dueno[10];

    printf("\nDIGITE EL ID DEL PASAJERO QUE DESEA VERIFICAR QUE CONCHOS HA TOMADO: ");
    fflush(stdin);
    scanf("%d", &ids);
    printf("\n");

    printf("\nDIGITE EL NOMBRE DEL PROPIETARIO DE CARROS: ");
    fflush(stdin);
    gets(dueno);
    printf("\n");

    for(i = 0; i < ind; i++) {

        if(ids == (ListadoServicio)->cliente && ids == (ListaPasajeros)->ID){

            if (strcmp((ListadoConcho+i)->ficha, (ListadoServicio + i)->ficha) == 0) {

                if (strcmp(dueno, (ListadoConcho + i)->propietario) == 0) {

                    printf("FICHA: %s\n", (ListadoConcho + i)->ficha);
                    printf("MARCA: %s\n", (ListadoConcho + i)->marca);
                    printf("MODELO: %d\n", (ListadoConcho + i)->anio);
                    printf("PROPIETARIO: %s\n\n", (ListadoConcho + i)->propietario);
                }
            }
        }

    }
}



void VerConchoMonto(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i =0, ids, p_rango, ul_rango;

    printf("\nDIGITE EL ID DEL PASAJERO QUE DESEA VERIFICAR: ");
    fflush(stdin);
    scanf("%d", &ids);
    printf("\n");

    printf("\nDIGITE El PRIMER RANGO DE MONTO: ");
    fflush(stdin);
    scanf("%d", &p_rango);
    printf("\n");

    printf("\nDIGITE El PRIMER RANGO DE MONTO: ");
    fflush(stdin);
    scanf("%d", &ul_rango);
    printf("\n");

    for(i = 0; i < ind; i++) {

        if(ids == (ListadoServicio)->cliente && ids == (ListaPasajeros)->ID){

            if (strcmp((ListadoConcho+i)->ficha, (ListadoServicio + i)->ficha) == 0){

                if(p_rango <= (ListadoServicio+i)->pago && ul_rango >= (ListadoServicio+i)->pago){

                    printf("FICHA: %s\n", (ListadoConcho+i)->ficha);
                    printf("MARCA: %s\n", (ListadoConcho+i)->marca);
                    printf("MODELO: %d\n", (ListadoConcho+i)->anio);
                    printf("PROPIETARIO: %s\n\n", (ListadoConcho+i)->propietario);

                }
            }
        }

    }
}

//
void VerConchoFecha(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i =0, ids;
    char p_rango[10], ul_rango[10];

    printf("\nDIGITE EL ID DEL PASAJERO QUE DESEA VERIFICAR: ");
    fflush(stdin);
    scanf("%d", &ids);
    printf("\n");

    printf("\nDIGITE El PRIMER RANGO DE FECHA: ");
    fflush(stdin);
    gets(p_rango);
    printf("\n");

    printf("\nDIGITE El PRIMER RANGO DE FECHA: ");
    fflush(stdin);
    gets(ul_rango);
    printf("\n");

    for(i = 0; i < ind; i++) {

        if(ids == (ListadoServicio)->cliente && ids == (ListaPasajeros)->ID){

            if (strcmp((ListadoConcho+i)->ficha, (ListadoServicio + i)->ficha) == 0){

                if(p_rango <= (ListadoServicio+i)->tiempo.hora && ul_rango >= (ListadoServicio+i)->tiempo.hora){

                    printf("FICHA: %s\n", (ListadoConcho+i)->ficha);
                    printf("MARCA: %s\n", (ListadoConcho+i)->marca);
                    printf("MODELO: %d\n", (ListadoConcho+i)->anio);
                    printf("PROPIETARIO: %s\n\n", (ListadoConcho+i)->propietario);

                }
            }
        }

    }
}

//SERVICIOS

void VerFichaCarro(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i ;

    for(i = 0; i < ind; i++) {
            if (strcmp((ListadoConcho+i)->ficha, (ListadoServicio + i)->ficha) == 0){

                printf("FICHA DE CARRO: %s\n", (ListadoServicio+i)->ficha);
            }
    }
}

void VerIDPasajero(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i ;

    for(i = 0; i < ind; i++) {
        if ((ListaPasajeros+i)->ID == (ListadoServicio + i)->cliente){

            printf("ID DEL PASAJERO: %d\n", (ListadoServicio+i)->cliente);
        }
    }
}


void VerRangoMonto(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i, p_rango, ul_rango;

    printf("\nDIGITE El PRIMER RANGO DE MONTO: ");
    fflush(stdin);
    scanf("%d", &p_rango);
    printf("\n");

    printf("\nDIGITE El PRIMER RANGO DE MONTO: ");
    fflush(stdin);
    scanf("%d", &ul_rango);
    printf("\n");

    for(i = 0; i < ind; i++) {
        if (p_rango <= (ListadoServicio)->pago && ul_rango >= (ListadoServicio)->pago){

            printf("MONTO: %d\n", (ListadoServicio+i)->pago);
        }
    }
}


void VerRangoFecha(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i;
    char p_rango[10], ul_rango[10];

    printf("\nDIGITE El PRIMER RANGO DE FECHA: ");
    fflush(stdin);
    gets(p_rango);
    printf("\n");

    printf("\nDIGITE El SEGUNDO RANGO DE FECHA: ");
    fflush(stdin);
    gets(ul_rango);
    printf("\n");

    for(i = 0; i < ind; i++) {
        if (p_rango <= (ListadoServicio)->tiempo.hora && ul_rango >= (ListadoServicio)->tiempo.hora){

            printf("FECHA: %s\n", (ListadoServicio+i)->tiempo.hora);
        }
    }
}



void VerRangoTiempo(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho){

    int i;
    for(i = 0; i < ind; i++) {

            printf("TIEMPO ESTIMADO: %s\n", (ListadoServicio+i)->tiempo.hora);
        }
    }
