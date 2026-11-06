#include "common.h"
extern char *D_002214F4;
/* Append the object index when absent and space remains. */
void func_004783C0(void *p, short *a, short n)
{
    short k = ((int)p - (int)D_002214F4) >> 8;
    int i;
    for (i = 1; i <= a[0]; i++)
        if (a[i] == k)
            return;
    if (a[0] < n) {
        a[0]++;
        a[a[0]] = k;
    }
}
