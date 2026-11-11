#include "common.h"

/* Write the two values into every 0x40-stride entry of the slot, skipping the
   ones whose value is -1. */
void func_L01_00558718(s32 a0, char *p, s32 idx, s32 w1, s32 w2)
{
    s32 i;

    if (*(s32 *)(p + 0xA4) > 0) {
        i = 0;
        idx <<= 6;
        do {
            s32 base = *(s32 *)(p + 0x10 + i * 4);
            if (w1 != -1) {
                *(s32 *)(idx + base + 4) = w1;
            }
            if (w2 != -1) {
                *(s32 *)(idx + base) = w2;
            }
            i++;
        } while (i < *(s32 *)(p + 0xA4));
    }
}
