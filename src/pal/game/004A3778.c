#include "common.h"
int D_002216EC = 0, D_002216E0 = 0;
extern char D_003D1490[];
extern void *D_002216E4;
/* Initialize the shared descriptor and return it. */
void *func_004A3778(void)
{
    if (!D_002216EC) {
        D_002216E0 = 1;
        D_002216E4 = D_003D1490;
        D_002216EC = 1;
    }
    return &D_002216E0;
}
