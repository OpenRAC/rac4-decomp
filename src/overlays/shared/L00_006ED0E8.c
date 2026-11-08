#include "common.h"

extern s32 func_L00_00607768();
extern u8 D_004C8A98[];

// Report whether the object's 0x1A0 mask still has a bit of the mask that
// func_L00_00607768(0x10, ...) returns, unless its 0x1C-stride slot holds a
// state of 0 or 0x12.
s32 func_L00_006ED0E8(u8 *arg0) {
    s32 mask;

    if (*(s32 *)(arg0 + 0x2EE0) != 0) {
        return 0;
    }
    mask = func_L00_00607768(0x10, *(s32 *)(arg0 + 0x2F10));
    if ((mask & 0x10) != 0) {
        s32 v = *(s32 *)((u8 *)D_004C8A98 + *(s32 *)(arg0 + 0x2F10) * 0x1C);

        if (v != 0 && v != 0x12) {
            mask &= ~0x10;
        }
    }
    return (*(s32 *)(*(s32 *)(arg0 + 0x2F00) + 0x1A0) & mask) != 0;
}
