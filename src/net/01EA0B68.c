/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

void *func_0011A518(void *, s32, s32);
void *func_01EA47E8(void);

void *func_01EA0B68(void)
{
    void *p = func_01EA47E8();

    if (p != NULL) {
        p = func_0011A518(p, 0, 0x2C);
    }
    return p;
}
