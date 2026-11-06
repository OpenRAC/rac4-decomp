#include "common.h"
extern char *D_002213F4;
/* Append the object index when absent and space remains. */
void func_00477A98(void *p, short *a, short n)
{
    short k = ((int)p - (int)D_002213F4) >> 8;
    int i;
    for (i = 1; i <= a[0]; i++)
        if (a[i] == k)
            return;
    if (a[0] < n) {
        a[0]++;
        a[a[0]] = k;
    }
}
