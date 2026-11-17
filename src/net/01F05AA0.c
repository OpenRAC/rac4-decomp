/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(const char *, s32);
extern s32 D_0019E200[];

/* Checks the bounds of the index against the count and stores it; 0 if the count is zero. */
s32 func_01F05AA0(void *arg0, s32 arg1) {
    u8 *a = (u8 *)arg0;

    if (*(s32 *)(a + 0x258) == 0) {
        return 0;
    }
    if (*(s32 *)(a + 0x250) >= 0x65) {
        func_01F0C090((const char *)D_0019E200, 0x1B3);
    }
    if (*(s32 *)(a + 0x258) > *(s32 *)(a + 0x250)) {
        func_01F0C090((const char *)D_0019E200, 0x1B4);
    }
    if (arg1 < 0 || arg1 >= *(s32 *)(a + 0x258)) {
        func_01F0C090((const char *)D_0019E200, 0x1B5);
    }
    *(s32 *)(a + 0x25C) = arg1;
    return 1;
}
