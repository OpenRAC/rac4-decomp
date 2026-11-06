#include "common.h"

s32 D_002216D4 = 0;
s32 D_002216C8 = 0;
extern void *D_002216CC;
extern s32 D_002216D0;
extern char D_003D14F0[];

/* Initialize the shared descriptor on its first request. */
void *func_004A36B8(void)
{
    if (!D_002216D4) {
        D_002216C8 = 1;
        D_002216CC = D_003D14F0;
        D_002216D4 = 1;
        D_002216D0 = 0;
    }
    return &D_002216C8;
}
