//gcc -oleerlinea leerlinea.c -lreadline

#include <stdio.h>

#include <readline/readline.h>
#include <readline/history.h>

void *leer(char *arg){
   char *inpt;
   inpt = readline(NULL);
   add_history(inpt);
   return inpt;
}

int main()
{
   char *b;
   char *a = leer(b);
   printf("%s", a);
}
