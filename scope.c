#include <stdio.h>

int main()
{
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("dentro de for i vale: %i\n", i);
    }
    printf("fuera de for i vale: %i\n", i);
    if (i == 10)
    {
        i = 10 * 2;
        printf("dentro de if i vale: %i\n", i);
    }
    printf("fuera de if i vale: %i\n", i);
    return 0;
}