/*./buggy `perl -e 'print "X"x2048'`
 * ulimit -c 09999999
 * gdb ./buggy core
 *(gdb) info registers eip
 * */
#include <stdio.h>
#include <string.h>
int main( int argc, char *argv[] )
{
  // Buffer estático en la pila.
  char buffer[1024];
  if ( argc != 2 )
  {
    printf("Uso: %s argumento\n", argv[0] );
    return( -1 );
  }
  // Copiado de cadenas sin control.
  strcpy( buffer, argv[1]);
  printf( "Argumento copiado\n" );
  return(0);
}
