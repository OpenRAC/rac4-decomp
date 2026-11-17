/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01ED9310(void *);
extern s32 func_01ED94F0(void *, s32);

// Sets the low nibble of the word at +0x24 to arg1, clears +0x2C when arg1 < 3, then calls func_01ED94F0 and flags +0x4 on success.
s32 func_01ED9A30(void *arg0, u32 arg1, s32 arg2) {
    s32 temp_a1;
    s32 r;

    if (func_01ED9310(arg0) == 0) {
        return -0x15;
    }
    temp_a1 = *(s32 *)((u8 *)arg0 + 0x24);
    if ((temp_a1 & 0xF) == arg1) {
        return 0;
    }
    *(s32 *)((u8 *)arg0 + 0x24) = (temp_a1 & ~0xF) | (arg1 & 0xF);
    if (arg1 < 3U) {
        *(s32 *)((u8 *)arg0 + 0x2C) = 0;
    }
    r = func_01ED94F0(arg0, arg2);
    if (r == 0) {
        *(s32 *)((u8 *)arg0 + 0x4) = 1;
    }
    return r;
}
