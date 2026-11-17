/* cflags: -fno-gcse */
#include "common.h"

extern s32 func_01E9E5D0(void *arg0, s32 arg1);
extern u8 D_00172160[];
extern u8 D_00172170[];

void func_0015B2C8(s32 *arg0) {
    u8 *q;
    u8 *base;

    if (arg0 == 0 || *arg0 != 0) {
        *(s32 *)D_00172160 = 0xB;
        return;
    }
    q = D_00172170;
    base = q - 0x10;
    if (func_01E9E5D0(q, *(s32 *)(base + 8)) != 0) {
        *(s32 *)(q - 0x10) = 0xB;
        return;
    }
    *(s32 *)(q - 0x10) = 0xA;
    base[0x265] = 1;
    *(s32 *)(*(s32 *)(base + 0x1C) * 4 + 0x218 + (s32)D_00172170) = *(s32 *)(base + 0x10);
    *(u8 *)(*(s32 *)(base + 0x10) + 0x6B9 + (s32)D_00172170) = base[0x1C];
    *(s32 *)(base + 0x1C) = *(s32 *)(base + 0x1C) + 1;
}
