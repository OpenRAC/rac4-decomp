#include "common.h"

extern s32 D_002215D8;

void func_00453F30(s32 arg0, s32 arg1, s32 arg2);
s32 func_0048C2D0(s32 arg0, s32 arg1, s32 arg2);

s32 func_0048C2F8(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 offset;

    func_00453F30(D_002215D8 + 0x300C, arg0, 4);
    arg0 += 4;
    *(s32 *)(D_002215D8 + 0x3010) = func_0048C2D0(*(s32 *)(D_002215D8 + 0x300C) * 0xC, arg1, arg2);
    if (*(s32 *)(D_002215D8 + 0x3010) == 0) {
        return 1;
    }
    if (*(s32 *)(D_002215D8 + 0x300C) <= 0) {
        return 0;
    }
    i = 0;
    offset = 0;
    do {
        if (*(s32 *)(D_002215D8 + 0x3000) >= 2) {
            func_00453F30(*(s32 *)(D_002215D8 + 0x3010) + offset, arg0, 0xC);
            arg0 += 0xC;
        } else {
            func_00453F30(*(s32 *)(D_002215D8 + 0x3010) + offset, arg0, 8);
            arg0 += 8;
            *(s16 *)(offset + *(s32 *)(D_002215D8 + 0x3010) + 8) = 0;
        }
        i++;
        offset += 0xC;
    } while (i < *(s32 *)(D_002215D8 + 0x300C));
    return 0;
}
