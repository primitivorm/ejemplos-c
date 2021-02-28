#include <stdio.h>

int main(int argc, char *argv[])
{
    double d = 0.6;
    printf("%f\n", d);
    printf("%ld\n", (long)d);
    printf("%.32g\n", d);
    printf("%.14g\n", d);
    printf("%.16g\n", d);
    return 0;
}
