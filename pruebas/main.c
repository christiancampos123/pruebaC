#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//#define PI 3.14159

// Declaracion de funciones
void printPant();

void radios();

void buscaMaximo();

void ordenaNums();

void menu();

void params(int parametros[]);

void hacerMediaArgs(int max);

void hacerOrdenArgs(int max);

int NUM_PARAMETROS = 0;

// Main
int main(int argc, char **argv) {
    //menu();

    //printf("los argc son: %d\n",argc);
    int n;
    //printf("los argumentos son: \n");
    char cad[2];
    char orden[50];
    //printf("%s\n",argv[1]);
    //printf("%s\n",argv[2]);
    sprintf(cad, "%s", argv[2]);
    n = atoi(cad);
    sprintf(orden, "%s", argv[1]);
    //printf("%s\n",orden);
    //printf("%d",n);
    if ((strcmp(orden, "media")) == 0) {
        hacerMediaArgs(n);
    }

    if ((strcmp(orden, "ordena")) == 0) {
        hacerOrdenArgs(n);
    }

    //printPant();
    //radios();
    //buscaMaximo();
    //ordenaNums();

    /*
    //prueba con punteros
    int *a,b,c;
    b=15;
    a=&b;
    c=b;
    printf("%d y luego %d y asterisco de a %d",a,c,*a);
    */

    return 0;
}

void hacerMediaArgs(int max) {
    int numeros[max];
    int num;
    char val[50];
    printf("Introduzca %d numeros\n", max);
    for (int i = 0; i < max; i++) {
        scanf("%s", val);
        num = strtol(val, NULL, 10);
        numeros[i] = num;
    }
    /*for (int i=0; i<max; i++){
        printf("%d", numeros[i]);
    }*/
    float suma = 0;
    for (int i = 0; i < max; i++) {
        suma = (float) numeros[i] + suma;
    }
    printf("\n");
    printf(" la media es: %.2f", suma / (float) max);
    if ((suma / (float) max) < 5) {
        printf("Suspendido");
    } else {
        printf(" Aprobado");
    }

}

void hacerOrdenArgs(int max) {
    int numeros[max];
    int num;
    char val[50];
    printf("Introduzca %d numeros\n", max);
    for (int i = 0; i < max; i++) {
        scanf("%s", val);
        num = strtol(val, NULL, 10);
        numeros[i] = num;
    }
    int i, j;
    int n = max;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                // Intercambiar arr[j] y arr[j+1]
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < max; i++) {
        printf("%d ", numeros[i]);
    }
}

// Imprime un Hola mundo
void printPant() {
    //%d = enteros   %f = float  %lf = double  %c = caracteres  %s = cadenas
    printf("Hello, World!\n");
}

// Pide un valor por parametro del radio de un circulo y hace print de su area y perimetro
void radios() {
    //%d = enteros   %f = float  %lf = double  %c = caracteres  %s = cadenas
    double num;
    char val[50];
    double area;
    double perimetro;
    printf("Introduzca el valor del radio: \n");
    scanf("%s", val);
    num = strtol(val, NULL, 10);
    area = M_PI * (num * num);
    perimetro = 2 * M_PI * num;
    printf("El area del circulo es: %.2f y su perimetro es: %.2f", area, perimetro);
}

// Pide 10 numeros y te dice el maximo valor de ellos
void buscaMaximo() {
    int numeros[10];
    int num;
    char val[50];
    int mayor;
    printf("Introduzca 10 numeros\n");
    for (int i = 0; i < 10; i++) {
        scanf("%s", val);
        num = strtol(val, NULL, 10);
        numeros[i] = num;
    }

    mayor = numeros[0];
    for (int i = 0; i < 10; i++) {
        if (mayor < numeros[i]) {
            mayor = numeros[i];
        }
    }
    printf("El mayor es: ");
    printf("%d", mayor);
}

// Pide 10 numeros y te los ordena de menor a mayor
void ordenaNums() {
    int numeros[10];
    int num;
    char val[50];
    printf("Introduzca 10 numeros\n");
    for (int i = 0; i < 10; i++) {
        scanf("%s", val);
        num = strtol(val, NULL, 10);
        numeros[i] = num;
    }
    int i, j;
    int n = 10;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                // Intercambiar arr[j] y arr[j+1]
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
}

void params(int parametros[]) {
    printf("Ingresa los valores de los parametros:\n");
    for (int i = 0; i < NUM_PARAMETROS; i++) {
        scanf("%d", &parametros[i]);
    }

}

void ordenaParams(int parametros[]) {

    int i, j;
    int n = NUM_PARAMETROS;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (parametros[j] > parametros[j + 1]) {
                // Intercambiar arr[j] y arr[j+1]
                int temp = parametros[j];
                parametros[j] = parametros[j + 1];
                parametros[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < NUM_PARAMETROS; i++) {
        printf("%d ", parametros[i]);
    }
}

void printParams(int parametros[]) {
    printf("Los parametros ingresados son:\n");
    for (int i = 0; i < NUM_PARAMETROS; i++) {
        printf("%d\n", parametros[i]);
    }
}

void mediaParams(int const parametros[]) {
    float suma = 0;
    for (int i = 0; i < NUM_PARAMETROS; i++) {
        suma = (float) parametros[i] + suma;
    }
    printf("\n");
    printf(" la media es: %.2f", suma / (float) NUM_PARAMETROS);
    if ((suma / (float) NUM_PARAMETROS) < 5) {
        printf("Suspendido");
    } else {
        printf(" Aprobado");
    }
}

// Imprime y llama a las funciones en un menu bucleado
void menu() {
    //int opcion
    char opcion[50];

    while (1) {
        printf("----- MENÚ -----\n");
        printf("1. Print\n");
        printf("2. Buscar circulos\n");
        printf("3. buscar maximo\n");
        printf("4. ordenar nums\n");
        printf("5. Hacer la media\n");
        printf("6. Hacer una ordenacion\n");
        printf("7. ordenar/media\n");
        printf("x. Salir\n");
        printf("Ingrese su opción: ");
        //scanf("%f", &opcion);
        scanf("%s", opcion);

        //compara strings con el import
        if ((strcmp(opcion, "1")) == 0) {
            printPant();
        } else if ((strcmp(opcion, "2")) == 0) {
            radios();
        } else if ((strcmp(opcion, "3")) == 0) {
            buscaMaximo();
        } else if ((strcmp(opcion, "4")) == 0) {
            ordenaNums();
        } else if ((strcmp(opcion, "5")) == 0) {
            printf("ingrese numero de parametros\n");
            scanf("%d", &NUM_PARAMETROS);
            int parametros[NUM_PARAMETROS];
            params(parametros);
            //printParams(parametros);
            mediaParams(parametros);
        } else if ((strcmp(opcion, "6")) == 0) {
            printf("ingrese numero de parametros\n");
            scanf("%d", &NUM_PARAMETROS);
            int parametros[NUM_PARAMETROS];
            params(parametros);
            ordenaParams(parametros);
        } else if ((strcmp(opcion, "7")) == 0) {
            printf("ingrese numero de parametros\n");
            scanf("%d", &NUM_PARAMETROS);
            int parametros[NUM_PARAMETROS];
            params(parametros);
            char accion[50];

            while (1) {
                printf("\nEscriba: (ordena) o (media) o cualquier cosa para salir\n");
                scanf("%s", &accion);
                if ((strcmp(accion, "ordena")) == 0) {
                    ordenaParams(parametros);
                } else if ((strcmp(accion, "media")) == 0) {
                    mediaParams(parametros);
                } else {
                    printf("no escibiste nada correcto");
                    break;
                }
            }
        } else if ((strcmp(opcion, "8")) == 0) {
            printf("nothing");
        } else if ((strcmp(opcion, "x")) == 0) {
            printf("Saliendo del programa.\n");
            break;
        } else {
            // en caso de no pulsar nada de lo anterior solo imprime un mensaje de error
            printf("Opción inválida. Por favor, ingrese una opción válida.\n");
        }

        printf("\n");
    }
}