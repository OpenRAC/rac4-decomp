#include "common.h"

extern s32 func_004DFEC8(s32);
extern s32 func_004E1C00(s32, s32, void *, s32, s32);
extern char D_1D2200[];
extern char D_242C00[];
extern u8 D_243750[];

/* Reserves a slot for the entry at arg2 and records its fields, then returns func_004DFEC8 of the slot. */
s32 func_004E2038(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char *entry;
    char *base;
    s32 r;
    char *rec;

    if (arg2 == 0) {
        return -1;
    }
    if (arg3 < 0) {
        return -1;
    }
    if (D_243750[arg3] == 0xFF) {
        return -1;
    }
    entry = *(char **)(D_242C00 + (D_243750[arg3] << 2));
    if (entry == 0) {
        return -1;
    }
    base = *(char **)(entry + 0x28);
    if (base == 0) {
        return -1;
    }
    if (arg0 >= *(u8 *)(entry + 0xD)) {
        return -1;
    }
    r = func_004E1C00(base + (arg0 << 5), arg1, (void *)arg2, 0, 0x400);
    if (r >= 0) {
        rec = D_1D2200 + (r << 7);
        *(s32 *)(rec + 0x2DC) = arg2;
        *(s16 *)(rec + 0x2CA) = arg0;
        *(s32 *)(rec + 0x308) = arg3;
    }
    return func_004DFEC8(r);
}
