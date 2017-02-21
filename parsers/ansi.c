#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    /*
    char * s = "9474624707";
    long long int lo = 55559474624707;
    lo = strtoll(s, NULL, 0);
    printf("%lld\n", lo);
    const char * str = "hola mundo";
    unsigned int l      = strlen(str);
    printf("lenght of str: %i\n", l);
    */
    //unsigned char c;
    
    setlocale(LC_ALL, "es_MX");

    printf("hola\nmundo");
    puts("hola\nmundo");
    printf("hola\nmundo");

    unsigned char c;
    unsigned int i;
    printf("\n%s\n", "unsigned========================================");
    for (i = 0; i < 256; i++)
    {
        printf("%i = %c\t", c, c);
        c = c+1;
    }    
    char euro[] = "€¶";
    int l = strlen(euro);
    printf("strlen: %d\n", l);
    printf("symbol: %s\n", euro);
    printf("symbol: %c\n", (unsigned char) euro[0]);
    printf("symbol: %u\n", (unsigned char) euro[1]);
    printf("symbol: %u\n", (unsigned char) euro[2]);
    printf("symbol: %u\n", (unsigned char) euro[3]);
    printf("symbol: %u\n", (unsigned char) euro[4]);
    /*
    printf("\n%s\n", "signed========================================");
    for (i = -128; i < 128; ++i)
    {
        printf("%i=%c\t", i, (unsigned char)i);
    } 
    */
    /*printf("\n%s\n", "hola?");*/
    return 0;
}
