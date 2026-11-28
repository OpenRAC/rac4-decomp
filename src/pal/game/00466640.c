#include "common.h"

extern s32 D_0021DB64;

// Clear the selected mode flags.
void func_00466640(s32 selector)
{
    switch (selector) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        D_0021DB64 &= ~8;
        break;
    case 6:
        break;
    case 7:
        D_0021DB64 &= ~0x200;
        break;
    case 0:
        D_0021DB64 &= ~2;
        D_0021DB64 &= ~4;
        D_0021DB64 &= ~0x1000;
        D_0021DB64 &= ~8;
        D_0021DB64 &= ~0x10;
        break;
    }
}
