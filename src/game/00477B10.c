#include "common.h"
extern char *D_002213F4;
/* Remove an object index from the short list by replacing it with the last. */
void func_00477B10(void *p, short *a)
{
    int i;
    for (i = 1; i <= a[0]; i++)
        if (D_002213F4 + a[i] * 256 == (char *)p) {
            a[i] = a[a[0]];
            a[0]--;
            return;
        }
}
