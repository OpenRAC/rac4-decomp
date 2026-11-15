#include "common.h"

extern u8 D_1EE600[];

// Toggle the flag byte of each of four slots whose entry is in use and has bit 0x40 set.
void func_L00_00747890(u8 *arg0) {
    u32 i = 0;
    u8 *tbl = (u8 *)D_1EE600;
    s32 stride = 0x5C0;
    u8 *f = arg0 + 0x294;
    s32 *p = (s32 *)(arg0 + 0x264);
    do {
        s32 v = *p;
        i += 1;
        if (~v != 0 && (*(s32 *)(tbl + v * stride + 0x1A8) & 0x40) && (v != 0 || arg0[0x298] != 0)) {
            *f ^= 1;
        }
        p += 1;
        f += 1;
    } while (i < 4);
}
