#include "common.h"

s32 D_002215D4 = 0;
s32 D_002215C8 = 0;
extern void *D_002215CC;
extern s32 D_002215D0;
extern char D_003D1480[];

/* Initialize the shared descriptor on its first request. */
void *func_004A2958(void)
{
    if (!D_002215D4) {
        D_002215C8 = 1;
        D_002215CC = D_003D1480;
        D_002215D4 = 1;
        D_002215D0 = 0;
    }
    return &D_002215C8;
}
