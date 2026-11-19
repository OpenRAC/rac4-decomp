/* Not matching yet: BYTES 50/124 (tools/try_func.py func_L01_005243A8 --diff). Not part of the build. */
/* cflags: -mno-split-addresses */
#include "common.h"

extern u8 *D_222990;
extern u8 *D_2302D0;

s32 func_L01_00524350(s32 arg0, u8 *arg1, s32 arg2);

s32 func_L01_005243A8(s32 arg0) {
    u8 *p;
    u8 *s0;
    s32 r = 0;

    if (*(s16 *)(D_2302D0 + 0x86) == 0x13) {
        p = *(u8 **)(D_222990 + arg0 * 0x20 + 0x1C);
        p = *(u8 **)(p + 4);
        s0 = *(u8 **)(p + 0x70) + 0x40;
        if (func_L01_00524350(arg0, p, arg0) != 0) {
            if (*(s16 *)(s0 + 0x14) >= 2) {
                r = 1;
            }
        }
    }
    return r;
}
