#include "common.h"
s32 D_00221528 = 0;
void *D_00221524 = 0;
extern void *D_0023ABC4[];
extern void *func_0015DB80(s32, void *);

/* Caches the returned block on first use. */
void *func_00496480(void)
{
    if (!D_00221528) {
        D_00221524 = func_0015DB80(0x39400, D_0023ABC4[0]);
        D_00221528 = 1;
    }
    return D_00221524;
}
