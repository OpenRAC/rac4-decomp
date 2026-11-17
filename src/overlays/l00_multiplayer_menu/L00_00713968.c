#include "common.h"

extern s32 func_L00_00710858(void *object, s32 new_mode);

// Handles a mode change notification for a menu object.
s32 func_L00_00713968(u8 *p, s32 a1, s32 a2) {
    s32 r;

    r = func_L00_00710858(p, a1);
    if (p[0x10E79] == 1) {
        if (r != 5 && a1 == 5) {
            if (a2 == 1) {
                (*(void (**)(u8 *, s32))(*(u8 **)(p + 0x58) + 0xA4))(p, -2);
            } else if (a2 == 2 || *(s32 *)(p + 0x10A60) < 0) {
                (*(void (**)(u8 *, s32))(*(u8 **)(p + 0x58) + 0xA4))(p, -1);
            }
        }
    } else if (a1 < 5) {
        p[0x10E78] = 0;
    }
    return r;
}
