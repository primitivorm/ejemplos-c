/*
C:\windows\system32\cmd.exe /c (gcc -o goto goto.c)
goto.c: In function 'fun4':
goto.c:6:5: error: label 'abc' used but not defined
shell returned 1
*/

#include<setjmp.h>
#include<stdio.h>

int fun4(jmp_buf env , int i)
{
    if (i == 0) goto abc;
    return 10;
}
int fun3(jmp_buf env, int j)
{
    return fun4(env, j + 1);
}
int fun2(jmp_buf env, int p, int q)
{
    return fun3(env, p + q) + fun3(env, p - q);
}
int fun1(jmp_buf env, int l, int m, int n)
{
    return fun2(env, l + m, l + n);
}

int main()
{
    jmp_buf env;
    int s, l, m, n;
    printf("Enter values(integer) for l m and n please\n");
    scanf("%d%d%d", &l, &m, &n);
    fun1(env, l, m, n);
abc:
    printf("There is an error exiting gracefully\n");
    return 0;
}

