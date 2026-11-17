#include "common.h"

extern s32 func_L00_00710858();

// Calls func_L00_00710858, then when mode 1 is set and arg1 is 5 steps the +0x58 handler; otherwise clears +0x530 for arg1 < 5.
s32 func_L00_00712B28(void *arg0, s32 arg1, s32 arg2) {
    u8 *p = (u8 *)arg0;
    s32 result = func_L00_00710858();
    u8 mode = p[0x531];

    if (mode == 1) {
        if (result != 5) {
            if (arg1 == 5) {
                if (arg2 == mode) {
                    (*(void (**)(void *, s32))(*(u8 **)(p + 0x58) + 0xA4))(arg0, -2);
                } else if (arg2 == 2 || *(s32 *)(p + 0x524) < 0) {
                    (*(void (**)(void *, s32))(*(u8 **)(p + 0x58) + 0xA4))(arg0, -1);
                }
            }
        }
    } else if (arg1 < 5) {
        p[0x530] = 0;
    }
    return result;
}
