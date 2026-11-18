/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(const char *, s32);
extern s32 D_0019E200[];

/* Stores arg1 in slot arg2 of the list at 0xC0 after range checks. */
s32 func_01F059A8(void *arg0, s32 arg1, s32 arg2) {
    u8 *a = (u8 *)arg0;
    s32 *slot;
    s32 off;

    if (*(s32 *)(a + 0x258) == 0) {
        return 0;
    }
    if (*(s32 *)(a + 0x250) >= 0x65) {
        func_01F0C090((const char *)D_0019E200, 0x1A0);
    }
    if (*(s32 *)(a + 0x258) > *(s32 *)(a + 0x250)) {
        func_01F0C090((const char *)D_0019E200, 0x1A1);
    }
    if (arg2 < 0 || arg2 >= *(s32 *)(a + 0x258)) {
        func_01F0C090((const char *)D_0019E200, 0x1A2);
    }
    off = arg2 * 4 + 0xC0;
    slot = (s32 *)(a + off);
    if (*slot == 0) {
        func_01F0C090((const char *)D_0019E200, 0x1A4);
    }
    if (arg1 == 0) {
        func_01F0C090((const char *)D_0019E200, 0x1A5);
    }
    *slot = arg1;
    return 1;
}
