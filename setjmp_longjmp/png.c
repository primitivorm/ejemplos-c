#include <signal.h>
#include <setjmp.h>
#include "dllist.h"

int TIME = 0;
jmp_buf Env;

void alarm_handler(int dummy)
{
    TIME++;
    alarm(1);
    signal(SIGALRM, alarm_handler);
    longjmp(Env, TIME);
}

enumerate_primes1(int *current_test, int *largest_prime)
{
    int i;
    char s[1000];
    while (1) {
        for (i = 2; i * i < *current_test && *current_test % i != 0; i++) ;
        /* we could emit the prime number here */
        if (*current_test % i != 0) {
            *largest_prime = *current_test;
        }
        *current_test = *current_test + 1;
    }
}

enumerate_primes2(int *current_test, int *largest_prime, Dllist d)
{
    Dllist tmp;
    int i;
    char s[1000];
    int prime;
    while (1) {
        prime = 1;
        for (tmp = dll_first(d); prime && (tmp != d) &&
             (tmp->val.i) * (tmp->val.i) < *current_test;
             tmp = dll_next(tmp)) {
            if (*current_test % (tmp->val.i) == 0) {
                prime = 0;
            }
        }
        if (prime) {
            dll_append(d, new_jval_i(*current_test));
            *largest_prime = *current_test;
        }
        *current_test = *current_test + 1;
    }
}

main()
{
    int test1, largest_prime1;
    int test2, largest_prime2;
    Dllist d;
    int i;
    test1 = 2;
    test2 = 2;
    largest_prime1 = 2;
    largest_prime2 = 2;
    d = new_dllist();
    signal(SIGALRM, alarm_handler);
    alarm(1);
    i = setjmp(Env);
    printf("%4d   EP1: %10d        EP2: %10d\n", i,
           largest_prime1, largest_prime2);
    if (i % 2 == 0) {
        enumerate_primes1(&test1, &largest_prime1);
    } else {
        enumerate_primes2(&test2, &largest_prime2, d);
    }
}


