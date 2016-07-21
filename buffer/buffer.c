#include <stdio.h>
#include <stdlib.h>

char* leer_archivo(FILE *fp);

int main(int argc, char *argv[])
{
    FILE *fp = fopen("../hashtable/khash.h", "r");
    char *new = NULL;
    new = leer_archivo(fp);

    printf("%s\noutside leer_archivo\n", new);
    int i;
    for (i = 0; i < 100; ++i)
    {
        printf("%c", new[i]);
    }
    //free(source); /* Don't forget to call free() later! */
    free(new); /* Don't forget to call free() later! */
    return 0;
}

char* leer_archivo(FILE *fp){
    char *source = NULL;
    if (fp != NULL) {
        /* Go to the end of the file. */
        if (fseek(fp, 0L, SEEK_END) == 0) {
            /* Get the size of the file. */
            long bufsize = ftell(fp);
            if (bufsize == -1) {
                /* Error */
                fputs("Error al leer el archivo: ", stderr);
            }
            /* Allocate our buffer to that size. */
            source = malloc(sizeof(char) * (bufsize + 1));
            /* Go back to the start of the file. */
            if (fseek(fp, 0L, SEEK_SET) != 0) {
                /* Error */
                fputs("Error al leer el archivo: ", stderr);
            }
            /* Read the entire file into memory. */
            size_t newLen = fread(source, sizeof(char), bufsize, fp);
            if (newLen == 0) {
                fputs("Error al leer el archivo: ", stderr);
            } else {
                source[++newLen] = '\0'; /* Just to be safe. */
            }
        }
        fclose(fp);
        printf("%s\ninside leer_archivo\n", source);
    }
    return source;
}
