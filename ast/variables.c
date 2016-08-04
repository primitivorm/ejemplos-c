#include <stdio.h>

int suma(int a, int b){
    return a+b;
}

int main(int argc, char *argv[])
{
    int entero = 10;
    double decimal = 3.1416;
    char* cadena = "esto es una cadena";

    printf("entero: %i\n", entero);
    printf("decimal: %.14g\n", decimal);
    printf("cadena: %s\n", cadena);
    if(entero == 0)
        printf("%s\n", "es verdad");
    else
        printf("%s\n", "es falso");

    int i;
    int enteros[10];
    for (i = 0; i < 10; ++i) {
        enteros[i] = i;
       printf("%i\n", i); 
    }
    printf("suma es: %i", suma(1,2));
    return 0;
}
