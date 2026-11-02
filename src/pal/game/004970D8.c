#include "common.h"
s32 D_00221628 = 0;
void *D_00221624 = 0;
extern void *D_0023ACC4[];
extern void *func_0015DB90(s32, void *);

/* Caches the returned block on first use. */
void *func_004970D8(void)
{
    if (!D_00221628) {
        D_00221624 = func_0015DB90(0x39400, D_0023ACC4[0]);
        D_00221628 = 1;
    }
    return D_00221624;
}
