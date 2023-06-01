#include <stdio.h>
#include <math.h>
#include <string.h>
//Ejercicio 12.5
#define N 4
#define M 5


//Ejercicio 12.6

double* funcion(double* arreglo01, int num){

    double *elem_menor = &arreglo01[0];

    for (int i = 1; i < num; i++){
        if(arreglo01[i] < *elem_menor){
            elem_menor = &arreglo01[i];
        }
    }
    return elem_menor;
}

//Problema 12.1

int vocal(char* linea){
int i = 0;

while(*linea != '\0') {
    if (*linea == 'a' || *linea == 'A' || *linea == 'e' || *linea == 'E' || *linea == 'i' || *linea == 'I' ||
        *linea == 'o'
        || *linea == 'O' || *linea == 'u' || *linea == 'U'){
    i++;
}
    linea++;
}
return i;
}

//Problema 12.4

double ff(double x) {
    return 3 * exp(x) - 2 * x;
}

double g(double x) {
    return -x * sin(x) + 1.5;
}

double z(double x){
    return pow(x, 2) - 2 * x + 3;
}

//Problema 12.5

void enteros_largos(char *num1, char *num2, char *resultado) {
    int c = 0;
    int suma;
    int i;

    int largo1 = strlen(num1);
    int largo2 = strlen(num2);
    for (i = largo1 - 1; i >= 0; i--) {
        suma = (num1[i] - '0') + (num2[i] - '0') + c; c = suma / 10;
        resultado[i] = (suma % 10) + '0';
    }
    resultado[largo1] = '\0';
}

//Problema 12.6

double cadena(const char *str) {
    double result;
    sscanf(str, "%lf", &result);
    return result;
}

//Problema 12.9

double rectangulo(double base, double altura){
    return (base * altura) / 2;
}

double isoceles(double base, double altura) {
    return (base * altura) / 2;
}

double cuadrado(double lado) {
    return lado * lado;
}

double trapecio(double base_mayor, double base_menor, double altura) {
    return ((base_mayor + base_menor) * altura) / 2;
}

double circulo(double radio) {
    return 3.14 * radio * radio;
}

//Problema 13.1

void eliminar_espacios(char* cadena) {
    int i, j = 0;
    for (i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] != ' ') {
            cadena[j] = cadena[i];
            j++;
        }
    }
    cadena[j] = '\0';
}

//Problema 13.2

int leer_num() {
    int numero;
    printf("Ingrese el número grande: ");
    scanf("%d", numero);
    return numero;
}

int sumar_num(int numero1, int numero2) {

    int resultado = numero1 + numero2;

    return resultado;
}

//Problema 13.4

void matriz_unicos(int matriz[20][20]){
    int matrizes[20][20] = {0};

    for (int n1 = 0; n1 < 20; n1++) {
        int indice = 0;

        for (int n2 = 0; n2 < 20; n2++) {
            int elemento = matrizes[n1][n2];
            int repetido = 0;


        for (int k = 0; k < indice; k++) {
            if (matrizes[n1][k] == elemento) {
                repetido = 1;
                break;
            }

        }
        if (!repetido) {
            matrizes[n1][indice] = elemento;
            indice++;
        }
    }

        for (int n1 = 0; n1 < 20; n1++) {

            for (int n2 = 0; n2 < 20; n2++) {

                if (matrizes[n1][n2] != 0) {

                    printf("%d ", matrizes[n1][n2]);
                }
            }
        }
        printf("\n"); }
}



int main() {


  //Ejercicio 12.4 Un array unidimensional se puede indexar con la aritmética de punteros.
  // ¿Qué tipo de puntero habra que definir para indexar un array bidimensional?

  //Respuesta: hay que definir un puntero a arrays para indexarlo.

    int matriz[3][4] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };
    int (*puntero)[4];
    puntero = matriz;

    int elemento = puntero[1][2];
    printf("El valor es: %d\n\n", elemento);


//Ejercicio 12.5 En el siguiente codigo se accede a los elementos de una matriz. Acceder a los mismos elementos con aritmetica
// de punteros. Codigo:

int f,c;
double mt[N][M] = {{1.1,1.2,1.3,1.4,1.5 },
                   {2.1,2.2,2.3,2.4,2.5 },
                   {3.1,3.2,3.3,3.4,3.5 },
                   {4.1,4.2,4.3,4.4,4.5 }
};

//Sin aritmetica de punteros:

for(f=0; f<N; f++){
    for(c=0; c<M; c++) {
        printf(" %.1lf ", mt[f][c]);
    }
    printf("\n");
}
    printf("------------------------------\n");
//Con aritmetica de punteros:

double (*puntero2)[5];
puntero2 = mt;

    for(f=0; f<N; f++){
        for(c=0; c<M; c++) {
            printf(" %.1lf ",  *(*(puntero2 + f) + c));
        }
        printf("\n");
    }


    // Ejercicio 12.6 Escribe una funcion con un argumento de tipo puntero a double y otro argumento de tipo int. El primer argumento
    //se debe de corresponder con un array y el segundo con el numero de elementos del array. La funcion ha de ser de tipo
    // puntero a double para devolver la direccion del elemento menor.

    double numeros[]= {1.3, 2.3, 3.3, 4.3};
    int num_tam = sizeof(numeros) / sizeof(numeros[0]);
    double* elemento02 = funcion(numeros, num_tam);
    printf("\n%.1lf\n\n", *elemento02);


//Ejercicio 12.8  Que diferencias se pueden encontrar entre estas dos declaraciones?

//float mt1[5][5];
//float *m[5];

//respuesta: El mt1 es un arreglo bidimensional mientras que el m es un array de punteros.

//Se podria hacer estas asignaciones? respuesta: no, ya que no se puede asignar directamente un arreglo bidimensional con
// array de punteros porque son diferentes.

//m = mt1;
//m[1] = mt1[1];
//m[2] = &mt1[2][0];


//Problema 12.1 Escribir un programa en el que se lean 20 lineas de texto, cada linea con un maximo de 80 caracteres.
//Mostrar por pantalla el numero de vocales que tiene cada linea.

char lineas[20][81];
int i, num_vocal;

    printf("\n Problema 12.1, Introduzca solo 20 lineas de texto (maximo 80 caracteres):");

    for(i = 0; i < 20; i++){
        gets(lineas[i]);
    }

    for(i=0; i < 20; i++){
        num_vocal = vocal(lineas[i]);
        printf("Linea %d: %d vocales\n", i+1, num_vocal);
    }

    //Problema 12.4 Se quiere evaluar las funciones f(x), g(x) y z(x) para todos los valores de x en el intervalo
    // 0 <= x < 3.5 con incremento de 0.2. Escribir un programa que evalue dichas funcione, utilizar un array de punteros
    //a funcion. Las funciones son las siguientes:
    //f(x) = 3*e^x-2x
    //g(x) = -x*sin(x)+1.5
    //z(x) = x^2 - 2x + 3

    double x;
    double (*funciones[3])(double) = {ff, g, z};

    printf("\nx              f(x)             g(x)             z(x)\n");

    for (x = 0; x < 3.5; x += 0.2) {
        printf("%.1f:\t\t", x);

        for ( i = 0; i < 3; i++) {
            printf("%.1f\t\t", funciones[i](x));
        }
        printf("\n");
    }


//Problema 12.5 Se quiere sumar enteros largos, con un numero de digitos que supera el maximo entero largo. Los enteros
//tienen un maximo de 40 digitos. Para solventar el problema se utilizan cadenas de caracteres para guardar cada entero y realizar
//la suma. Escribir un programa que lea dos enteros largos y realice la suma.

    char numero1[41];
    char numero2[41];
    char resultado[41];

    printf("\nIngrese el primer entero largo: ");
    scanf("%s", numero1);
    printf("\nIngrese el segundo entero largo: ");
    scanf("%s", numero2);
    enteros_largos(numero1, numero2, resultado);
    printf("\nSuma: %s\n", resultado);


    //Problema 12.6 Escribir una funcion que tenga como entrada una cadena y devuelva un numero real. La cadena contiene
    //los caracteres de un numero real en formato decimal (por ejemplo, la cadena "25.56" se ha de convertir en el correspondiente
    //valor real).

    const char *num = "25.56";
    double number = cadena(num);
    printf("\nNumero: %lf\n", number);


    //Problema 12.9 Escribir un programa que permita calcular el area de diversas figuras: un triangulo rectangulo, un
    //triangulo isoceles, un cuadrado, un trapecio y un circulo. Utilizar un array de punteros de funciones, siendo las
    //funciones, siendo las funciones las que permiten calcular el area.


    //double (*calcularArea[5])(double, double) = { rectangulo,isoceles,cuadrado,trapecio,circulo };
    printf("Circulo: %.1lf\n", circulo(4));
    printf("Rectangulo: %.1lf\n", rectangulo(4,6));
    printf("Isoceles: %.1lf\n", isoceles(6, 8));
    printf("trapecio: %.1lf\n", trapecio(12, 4, 8));



    //Ejercicio 13.1 Encuentre los errores en las siguientes declaraciones y sentencias

    //int n, *p;
    //char** dob= "Cadena de dos punteros"; en esta linea hay un error, porque se esta asignando una cadena de caracteres
    //directamente a un puntero a puntero
    //p=n* malloc(sizeof(int)); aqui hay un error de sintaxis. En realidad deberia estar asi: p = malloc(sizeof(int));


    //Ejercicio 13.6 Que diferencias existen entre las funciones malloc(), calloc(), y realloc()?
    //respuesta: malloc() se utiliza para asignar memoria dinámica en el montón (heap) durante la ejecución del programa,
   // se utiliza para asignar y también inicializar memoria dinámica en el montón. Y el realloc se utiliza para cambiar
   // el tamaño de un bloque de memoria previamente asignado. Toma dos argumentos: un puntero al bloque de memoria
   // existente y el nuevo tamaño deseado en bytes.



//Ejercicio 13.11 Que diferencias existe entre las siguientes declaraciones?
//char *c[15];     este crea un arreglo de 15 punteros.
//char **c,         este crea un puntero a puntero de caracteres
//char c[15][12]    este crea un arreglo bidimensional de caracteres


//Problema 13.1  Escriba un programa para leer n cadenas de caracteres. Cada cadena tiene una longitud variable y esta
//formada por cualquier caracter. La memoria que ocupa cada cadena se ha de ajustar al tamano que tiene. Una vez leidas las cadenas
//se debe realizar un proceso que consiste en eliminar todos los blancos, siempre manteniendo el espacio ocupado ajustado
//al numero de caracteres. El programa debe mostrar las cadenas leidas y las cadenas transformadas

int n;

    printf("\nIntroduzca la cantidad de cadenas de caracter a leer: ");
    scanf("%d", &n);

    char cadenas[n][100];
    for(i=0; i < n; i++){
        printf("\nIntroduzca la cadena %d: ", i + 1);
        scanf("%s", cadenas[i]);
    }

    for (i = 0; i < n; i++) {
        eliminar_espacios(cadenas[i]);
    }

    printf("\nCadenas originales:\n");

    for (i = 0; i < n; i++) {
        printf("%s\n", cadenas[i]);
    }


    printf("\nCadenas transformadas:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", cadenas[i]);
    }


    //Problema 13.2 Se desea escribir un programa para leer numeros grandes (de tantos digitos que no entran en variables
    // long) y obtener la suma de ellos. El almacenamiento de un numero grande se ha de hacer en una estructura que tenga un
    //array dinamico y otro campo con el numero de digitos. La suma de dos numeros grandes dara como resultado otro numero
    //grande representando en su correspondiente estructura.



    int num1, num2;
    printf("Ingrese el primer numero grande:\n");
    scanf("%d", &num1);
    num1 = leer_num();
    printf("\nIngrese el segundo numero grande:\n");
    scanf("%d", &num2);
    num2 = leer_num();
    printf("Resultado: %d\n", sumar_num(num1, num2));



    //Problema 13.4 Se tiene una matriz de 20 x 20 elementos enteros. En la matriz hay un elemento repetido muchas veces.
    //Se quiere generar otra matriz de 20 filas y que en cada fila esten solo los elementos no repetidos. Escribir un programa
    //que tenga como entrada la matriz de 20 x 20, genere la matriz dinamica pedida y que se muestre en pantalla.


    int matriz01[20][20];
    matriz_unicos(matriz01);
    

    return 0;
}
