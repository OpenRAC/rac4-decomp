#include "common.h"

extern u8 *D_0021E070;
extern s32 func_0054BA08(void *, s32, s32, s32);
extern s32 func_0054BAE8(void *, s32, s32);
extern s32 func_0054A308(void *, s32);
extern void func_005491F8(void *, s32, s32);
extern void func_00162768(s32);

void func_00517210(u8 *player)
{
    f32 value;
    s32 i;
    s32 j;
    s32 next;
    s32 retries;

    /* Retry removal at most ten times for each inventory slot. */
    if (1 == *(s32 *)(player + 0x2F14)) {
        for (i = 1; i < 0x14; i = next) {
            retries = 10;
            next = i + 1;
            while (--retries != -1) {
                if (func_0054BA08(*(void **)(player + 0x26E4), i, 2, 0) == 0) {
                    break;
                }
            }
            func_0054BAE8(*(void **)(player + 0x26E4), i, 0);
        }
        for (j = 2; j < 0x14; j++) {
            if ((u8)func_0054A308(*(void **)(player + 0x26E4), j) != 0) {
                func_005491F8(*(void **)(player + 0x26E4), j, 0);
            }
        }
    }
    *(D_0021E070 + *(s32 *)(player + 0x2F10) + 0xFA) = 0;
    *(s32 *)(player + 0x2F14) = 0;
    (*(u8 **)(player + 0x2EF0))[0xBE] |= 0x10;
    *(u8 *)(*(u8 **)(player + 0x2EF0) + 0xBE) &= 0xF7;
    *(u16 *)(player + 0x1FCA) = *(u16 *)(player + 0x2F14);
    if (*(u8 **)(player + 0x2F28) != 0) {
        if (*(u8 **)(*(u8 **)(player + 0x2F28) + 4) != 0) {
            *(s32 *)(*(u8 **)(*(u8 **)(player + 0x2F28) + 4) + 0x40) =
                *(s32 *)(player + 0x2F14);
        }
    }
    value = 50.0f;
    *(f32 *)(player + 0x2F24) = value;
    if (player[0x266D] != 0) {
        func_00162768(1);
    }
    (*(u8 **)(player + 0x2EF0))[0x23] = 0x80;
    *(u16 *)(*(u8 **)(player + 0x2EF0) + 0x34) &= 0xDFFF;
    *(u16 *)(*(u8 **)(player + 0x2EF0) + 0x36) &= 0xFFF7;
}
