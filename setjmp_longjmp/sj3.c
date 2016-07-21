#include <setjmp.h>
#include <stdio.h>

int a(char *s, jmp_buf env)
{
    int i;
    i = setjmp(env);
    printf("Setjmp returned -- i = %d, 0x%x\n", i, s);
    printf("s = %s\n", s);
    return i;
}

int b(int i, jmp_buf env)
{
    printf("In B: i=%d.  Calling longjmp(env, i)\n", i);
    longjmp(env, i);
}

int main(int argc, char **argv)
{
    jmp_buf env;
    if (a("Jim", env) != 0) exit(0);
    b(3, env);

    return 0;
}

