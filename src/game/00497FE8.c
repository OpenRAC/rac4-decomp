#include "common.h"

/* Stores the old head word of record arg0 into its slot list, bumps the count, then calls func_00497EB8 when arg1 differs. */
extern void func_00497EB8(s32 arg0, s32 arg1);
extern u8 D_2F32B8[];

void func_00497FE8(s32 arg0, s32 arg1) {
    s32 rec = arg0 * 0x54;
    s32 t0 = *(s32 *)(D_2F32B8 + rec);

    if (t0 != arg1) {
        *(s32 *)(D_2F32B8 + rec + *(s32 *)(D_2F32B8 + rec + 0x28) * 4 + 0x2C) = t0;
        *(s32 *)(D_2F32B8 + rec + 0x28) = *(s32 *)(D_2F32B8 + rec + 0x28) + 1;
        func_00497EB8(arg0, arg1);
    }
}
