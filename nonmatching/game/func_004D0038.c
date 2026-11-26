/* Not matching yet: BYTES 11/232 (tools/try_func.py func_004D0038 --diff). Not part of the build. */
/* cflags: -O2 -G8 -fno-gcse */
#include "common.h"

extern u8 D_0021DE30[];
extern u8 D_0021DE50[];

s32 func_0045E038(s32);
s32 func_004A1A60(s32 *, s32);
s32 func_00505238(s32, s32);

void func_004D0038(u8 *arg0, s32 arg1) {
    u8 *base;
    u8 *p;

    p = *(s32 *)arg0 + D_0021DE30;
    base = D_0021DE30;
    if (arg1 != 0) {
        u8 v = *p;

        if (v == 0) {
            v = arg0[8];
        }
        *p = v - 1;
    } else {
        *p = *p + 1;
        *p = *p % *(s32 *)(arg0 + 8);
    }
    if (*(u8 *)(*(s32 *)arg0 + (s32)base) != 0) {
        *(u8 *)((s32)D_0021DE50 + *(s32 *)arg0) = 1;
    }
    if (*(s32 *)(arg0 + 0x70) != 0) {
        s32 r = func_004A1A60((s32 *)(*(s32 *)(arg0 + 0x70) + 4), 2);
        s32 off = *(u8 *)(*(s32 *)arg0 + (s32)base) * 4;

        func_00505238(r, func_0045E038(*(s32 *)(arg0 + off + 0x1C)));
    }
}
