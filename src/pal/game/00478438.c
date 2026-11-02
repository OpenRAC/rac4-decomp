#include "common.h"
extern char *D_002214F4;
/* Remove an object index from the short list by replacing it with the last. */
void func_00478438(void *p, short *a)
{
    int i;
    for (i = 1; i <= a[0]; i++)
        if (D_002214F4 + a[i] * 256 == (char *)p) {
            a[i] = a[a[0]];
            a[0]--;
            return;
        }
}
