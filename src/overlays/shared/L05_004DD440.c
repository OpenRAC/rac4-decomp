#include "common.h"

extern u8 *func_L00_005DEBD0(s32, s32, s32);

// Return 1 when every linked entry's callback succeeds, else 0.
s32 func_L05_004DD440(u8 *object) {
    u8 *linked = *(u8 **)(object + 0xAC);
    s32 i;

    for (i = 0; i < *(s32 *)(linked + 0xEC); i++) {
        u8 **e = (u8 **)(linked + 0x6C) + i;
        u8 *r = func_L00_005DEBD0(*(s16 *)(*e + 0xBC), 0xC, 0x28);
        if ((*(s32 (**)(u8 *))(r + 0xC))(*e) == 0) return 0;
    }
    return 1;
}
