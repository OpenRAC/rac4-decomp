#include "common.h"

extern s32 D_0021DE40;
extern u8 D_0024B1A0[];

s32 func_L01_005751C8(void **out)
{
    s32 threshold;
    s32 index;
    u8 *row;

    if (out == NULL) {
        return 1;
    }
    threshold = D_0021DE40;
    for (index = 1; index < 8; index++) {
        row = D_0024B1A0 + index * 0x10;
        if (*(s32 *)(row + 0) < threshold ||
            *(u16 *)(row + 6) == 0 ||
            *(u16 *)(row + 0xC) == 0xFFFF) {
            *out = row;
            *(s16 *)(row + 4) = 0;
            *(s16 *)((u8 *)*out + 0xA) = 0;
            return 1;
        }
    }
    return 1;
}
