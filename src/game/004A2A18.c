#include "common.h"
int D_002215EC = 0, D_002215E0 = 0;
extern char D_003D1420[];
extern void *D_002215E4;
/* Initialize the shared descriptor and return it. */
void *func_004A2A18(void)
{
    if (!D_002215EC) {
        D_002215E0 = 1;
        D_002215E4 = D_003D1420;
        D_002215EC = 1;
    }
    return &D_002215E0;
}
