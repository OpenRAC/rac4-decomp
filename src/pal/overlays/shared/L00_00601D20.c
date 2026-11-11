#include "common.h"

extern u8 D_002069D0[];

/* PAL: from rac2-decomp's func_L01_00323310, constants adapted */
void func_L00_00601D20(int a0, int a1)
{
    u8 *b = D_002069D0;
    if (*(short *)(b + 0x48) == a0 && *(short *)(b + 0x3C) == -1)
        return;
    if (a0 != -1)
        a0 &= 0xFF;
    if (a1 != -1)
        a0 &= 0xFF;
    if (*(short *)(b + 0x4E) == 0 && *(short *)(b + 0xc6) == 0) {
        *(short *)(b + 0x48) = a0;
        return;
    }
    {
        u8 *c = D_002069D0;
        *(short *)(c + 0x3C) = a0;
        *(short *)(c + 0x3E) = a1;
    }
}
