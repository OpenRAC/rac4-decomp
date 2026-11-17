#include "common.h"

extern s32 func_L00_0051A3D0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);

/* Checks arg1's first word against the field at 0x80 of arg0's 0x1C object, then calls func_L00_0051A3D0 and maps its result to 0 or 0x2711. */
s32 func_L00_00517CF8(u8 *arg0, u8 *arg1, u8 *arg2) {
    s32 a2 = 0;
    s32 r;

    if (arg1 != NULL) {
        a2 = *(s32 *)(arg1 + 4);
        if (a2 != 0) {
            if (*(s32 *)arg1 != *(s32 *)(*(u8 **)(arg0 + 0x1C) + 0x80)) {
                return 0x2727;
            }
        }
    }
    r = func_L00_0051A3D0(*(u8 **)(arg0 + 0x1C), 0, a2, *(s32 *)(arg2 + 4));
    return (r != 0) ? 0 : 0x2711;
}
