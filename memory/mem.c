#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *xmalloc(size_t size);
void *xrealloc(void *ptr, size_t size);

int main(int argc, char *argv[])
{
    char src[] = "hola mundo";
    int size   = strlen(src) + 1;
    char *dest = xmalloc(size);
    /*for safe add null terminate string*/
    dest[size] = '\0';
    memcpy(dest, src, size);
    printf("%s\n", dest);
    return 0;
}

void *
xmalloc(size_t size)
{
    void *value = malloc(size);
    if (value == 0)
        fprintf(stderr, "%s\n", "virtual memory exhausted");
    return value;
}

void *
xrealloc(void *ptr, size_t size)
{
    void *value = realloc(ptr, size);
    if (value == 0)
        fprintf(stderr, "%s\n", "virtual memory exhausted");
    return value;
}

