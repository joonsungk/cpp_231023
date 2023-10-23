// add.c

#include <stdio.h>

/*
0000000000000000 T _add
                 U _printf
*/

int add(int a, int b)
{
    printf("C Add\n");
    return a + b;
}
