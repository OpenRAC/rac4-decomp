#include "common.h"

extern s32 D_0021E6F4;

// While D_0021E6F4 is 1, sets bit 0 of the byte at +0xBE if it was clear, then sets bit 0 of the word at +0x8C of the object at +0xAC.
void func_L02_004CBF38(u8 *object) {
    u8 flags;
    s32 changed;
    u8 *linked;

    if (D_0021E6F4 == 1) {
        flags = object[0xBE];
        if ((flags ^ 1) & 1) {
            changed = 1;
            object[0xBE] = flags | 1;
        } else {
            changed = 0;
        }
        if (changed != 0) {
            linked = *(u8 **)(object + 0xAC);
            if (linked != 0) {
                *(s32 *)(linked + 0x8C) = *(s32 *)(linked + 0x8C) | 1;
            }
        }
    }
}
