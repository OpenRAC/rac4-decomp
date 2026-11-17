#include "common.h"

extern s32 func_004C0CD0(s32 arg0);
extern s32 func_004C0DD0(s32 arg0);
extern s32 func_004C0E80(u32 arg0);
extern s32 func_004C0F78(u32 value);
extern s32 func_00505B20(void);
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern u8 D_30B358[];

/* Return the first entry of the selected table whose two values are out of order, or -1. */
s32 func_004BF3A8(void)
{
    u8 *base;
    u8 *t;
    u8 *tbl;
    u8 *ent;
    u8 *el;
    s32 best;
    s32 first;
    s32 i;
    s32 k;
    s32 c;
    s32 s0;
    s32 s1;

    i = 0;
    first = 1;
    best = -1;
    base = D_30B358 + func_00505B20() * 0x258;
    tbl = base + 0x1EC;
    if (*(s32 *)(tbl + 0x50) > 0) {
        do {
            t = base + 0x1EC;
            k = i;
            if (k < 0) {
                k = *(s32 *)(t + 0x54);
            }
            if (k < 0) {
                ent = 0;
            } else {
                k *= 0x18;
                ent = *(u8 **)(t + 0x34) + k;
            }
            el = *(u8 **)(ent + 8);
            if (*el == 0) {
                s0 = *(s32 *)(el + 4);
                if (*(s32 *)(el + 8) == 0) {
                    if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
                        s0 += 0x14;
                    }
                    s1 = func_004C0DD0(s0);
                    c = func_004C0CD0(s0) < s1;
                } else {
                    s1 = func_004C0F78(s0);
                    c = func_004C0E80(s0) < s1;
                }
                if (c && first) {
                    best = i;
                    first = 0;
                }
            }
            i++;
        } while (i < *(s32 *)(t + 0x50));
    }
    return best;
}
