#include "common.h"

extern void *D_344C38[];

// Walks the 10-entry table at D_344C38 and clears one byte of the object's +0x2F10 block for each entry whose +0x2F14 key is arg1; the offset depends on arg2.
void func_L41_0040F438(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);
    u8 *base8 = vars + 8;
    u8 *base12 = vars + 0x12;
    u8 *base1C = vars + 0x1C;
    void **slot = D_344C38;
    u8 *obj = D_344C38[0];
    u8 *dst;
    s32 count = 0;

    do {
        if (obj != 0 && *(s32 *)(obj + 0x2F14) == arg1) {
            switch (arg2) {
            case 1:
                dst = base8 + *(s32 *)(obj + 0x2F10);
                goto clear;
            case 2:
                dst = base12 + *(s32 *)(obj + 0x2F10);
                goto clear;
            case 3:
                dst = base1C + *(s32 *)(obj + 0x2F10);
clear:
                *dst = 0;
            }
        }
        slot++;
        count++;
        obj = *slot;
    } while (count < 10);
}
