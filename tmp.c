/*
gcc -c tmp.c    # crea el archivo objeto tmp.o
objdump -xdst tmp.o    #muestra codigo objeto
gcc tmp.c -S    # crea el fichero en assembly tmp.s
*/
#include <stdio.h>

int main(int argc, char **argv)
{
    char nombre[] = "Mr. Robot";
    float numero = 3.14159;
    printf("%s\n", nombre);
    printf("%f", numero);
    return 0;
}
