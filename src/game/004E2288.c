#include "common.h"

extern s32 func_004E1C00(u8 *, s32, void *, void *, s32);
extern s32 func_004DFEC8(s32);
extern s32 D_0021EDE0;
extern s32 D_00221308;
extern u8 D_001D2200[];

u8 *D_0022130C = 0;

s32 func_004E2288(s32 a0, s32 a1, s32 a2, s32 a3, void *a4, s32 a5)
{
    s32 value;
    u8 *entry;

    if (a0 == 0xFFFFFFFFu) {
        return -1;
    }
    value = a0 * 4 + a1 * 2 + a2 + D_0021EDE0;
    if (value >= D_00221308) {
        return -1;
    }
    a0 = func_004E1C00(D_0022130C + value * 32, a3, a4, 0, a5);
    if (a0 >= 0) {
        entry = D_001D2200 + a0 * 128;
        *(void **)(entry + 0x2DC) = a4;
        *(s16 *)(entry + 0x2CA) = value;
    }
    return func_004DFEC8(a0);
}
