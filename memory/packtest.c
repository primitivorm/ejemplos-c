#include <stdio.h>
#include <stdbool.h>

struct foo1 {
    char *p;
    char c;
    long x;
};

struct foo2 {
    char c;      /* 1 byte */
    char pad[7]; /* 7 bytes */
    char *p;     /* 8 bytes */
    long x;      /* 8 bytes */
};

struct foo3 {
    char *p;     /* 8 bytes */
    char c;      /* 1 byte */
};

struct foo4 {
    short s;     /* 2 bytes */
    char c;      /* 1 byte */
};

struct foo5 {
    char c;
    struct foo5_inner {
        char *p;
        short x;
    } inner;
};

struct foo6 {
    short s;
    char c;
    int flip:1;
    int nybble:4;
    int septet:7;
};

struct foo7 {
    int bigfield:31;
    int littlefield:1;
};

struct foo8 {
    int bigfield1:31;
    int littlefield1:1;
    int bigfield2:31;
    int littlefield2:1;
};

struct foo9 {
    int bigfield1:31;
    int bigfield2:31;
    int littlefield1:1;
    int littlefield2:1;
};

struct foo10 {
    char c;
    struct foo10 *p;
    short x;
};

struct foo11 {
    struct foo11 *p;
    short x;
    char c;
};

struct foo12 {
    struct foo12_inner {
        char *p;
        short x;
    } inner;
    char c;
};


main(int argc, char *argv)
{
    printf("sizeof(char *)        = %u\n", sizeof(char *));
    printf("sizeof(long)          = %u\n", sizeof(long));
    printf("sizeof(int)           = %u\n", sizeof(int));
    printf("sizeof(short)         = %u\n", sizeof(short));
    printf("sizeof(char)          = %u\n", sizeof(char));
    printf("sizeof(float)         = %u\n", sizeof(float));
    printf("sizeof(double)        = %u\n", sizeof(double));
    printf("sizeof(struct foo1)   = %u\n", sizeof(struct foo1));
    printf("sizeof(struct foo2)   = %u\n", sizeof(struct foo2));
    printf("sizeof(struct foo3)   = %u\n", sizeof(struct foo3));
    printf("sizeof(struct foo4)   = %u\n", sizeof(struct foo4));
    printf("sizeof(struct foo5)   = %u\n", sizeof(struct foo5));
    printf("sizeof(struct foo6)   = %u\n", sizeof(struct foo6));
    printf("sizeof(struct foo7)   = %u\n", sizeof(struct foo7));
    printf("sizeof(struct foo8)   = %u\n", sizeof(struct foo8));
    printf("sizeof(struct foo9)   = %u\n", sizeof(struct foo9));
    printf("sizeof(struct foo10)   = %u\n", sizeof(struct foo10));
    printf("sizeof(struct foo11)   = %u\n", sizeof(struct foo11));
    printf("sizeof(struct foo12)   = %u\n", sizeof(struct foo12));
}
