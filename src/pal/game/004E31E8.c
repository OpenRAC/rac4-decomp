#include "common.h"

extern s32 func_004E2B60(u8 *, s32, void *, void *, s32);
extern s32 func_004E0E28(s32);
extern s32 D_0021EE60;
extern s32 D_00221408;
extern u8 D_001D2280[];

u8 *D_0022140C = 0;

s32 func_004E31E8(s32 a0, s32 a1, s32 a2, s32 a3, void *a4, s32 a5)
{
    s32 value;
    u8 *entry;

    if (a0 == 0xFFFFFFFFu) {
        return -1;
    }
    value = a0 * 4 + a1 * 2 + a2 + D_0021EE60;
    if (value >= D_00221408) {
        return -1;
    }
    a0 = func_004E2B60(D_0022140C + value * 32, a3, a4, 0, a5);
    if (a0 >= 0) {
        entry = D_001D2280 + a0 * 128;
        *(void **)(entry + 0x2DC) = a4;
        *(s16 *)(entry + 0x2CA) = value;
    }
    return func_004E0E28(a0);
}
