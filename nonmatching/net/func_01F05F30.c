/* Not matching yet: BYTES 10/188 (tools/try_func.py func_01F05F30 --diff). Not part of the build. */
/* cflags: @ee296 -Os -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

void func_01F0C090(const char *, s32);
extern s32 D_0019E200[];
extern s32 func_01EF04A4(s32, s32, s32, s32, s32);

s32 func_01F05F30(void *arg0, s32 arg1) {
    u8 *a = (u8 *)arg0;
    s32 *slot;
    s32 idx;

    if (arg1 == 0) {
        func_01F0C090((const char *)D_0019E200, 0x253);
    }
    if (*(s32 *)(a + 0x250) >= 0x65) {
        func_01F0C090((const char *)D_0019E200, 0x254);
    }
    if (*(s32 *)(a + 0x258) < *(s32 *)(a + 0x250)) {
        slot = (s32 *)func_01EF04A4(*(s32 *)(*(s32 *)(a + 0x80) + 8), 0x1C, 0, 0x258, (s32)D_0019E200);
        idx = *(s32 *)(a + 0x258);
        *(s32 *)(a + 0x258) = idx + 1;
        *slot = arg1;
        *(s32 **)(a + 0xC0 + idx * 4) = slot;
        return 1;
    }
    return 0;
}
