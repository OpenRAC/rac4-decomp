#include "common.h"

/* Writes a four-word display list entry pair and advances the list pointer. */
extern u8 D_20BCB0[];
extern s32 *D_221E20;

void func_00459758(void) {
    D_221E20[0] = 0x30000026;
    D_221E20[1] = (s32) D_20BCB0;
    D_221E20[2] = 0;
    D_221E20[3] = 0x50000026;
    D_221E20 += 4;
}
