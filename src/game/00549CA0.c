#include "common.h"
extern int func_00549BB8(char *, int), func_0054A0C0(int, int), func_0054A788(char *, int, int);
int func_00549CA0(char *a, int b)
{
    int sum = func_00549BB8(a, b);
    int i;
    for (i = 2; i < 20; i++) {
        if (func_0054A0C0(i, b))
            sum += func_0054A788(a, i, b);
    }
    return sum;
}
