#include "common.h"
extern int func_0054B120(char *, int), func_0054B628(int, int), func_0054BCF0(char *, int, int);
int func_0054B208(char *a, int b)
{
    int sum = func_0054B120(a, b);
    int i;
    for (i = 2; i < 20; i++) {
        if (func_0054B628(i, b))
            sum += func_0054BCF0(a, i, b);
    }
    return sum;
}
