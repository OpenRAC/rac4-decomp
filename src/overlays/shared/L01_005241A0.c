#include "common.h"
extern u8 *D_00222990;
s32 func_L01_005241A0(u8 *actor)
{
    u8 *info = *(u8 **)(D_00222990 + *(s16 *)(actor + 0x84) * 32 + 0x1C);
    if (*(s32 *)(info + 0x108) != 0) {
        *(s32 *)(info + 0x108) = 0;
        return 1;
    }
    return 0;
}
