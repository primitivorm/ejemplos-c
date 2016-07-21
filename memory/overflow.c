/* overflow.c - demuestra un desbordamiento de buffer */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char buffer[10];
  if (argc < 2)
  {
    fprintf(stderr, "MODO DE USO: %s string\n", argv[0]);
    return 1;
  }
  /* //buffer overflow
  strcpy(buffer, argv[1]);
   */
  strncpy(buffer, argv[1], sizeof(buffer));
  buffer[sizeof(buffer) - 1] = '\0';
  printf("%s\n", buffer);
  return 0;
}
