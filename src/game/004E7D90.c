#include "common.h"

extern void func_00138FF0(void *, s16, s32, s32, s32, s32, s32, s32);
extern void func_00126E20(s32);
extern void func_001392B0(void *, s32);
extern void func_00131A08(s32, s32);

/* from rac3-decomp's func_L01_004C5F70 */
void func_004E7D90(s32 dst, s32 src, s32 size) {
    u8 buf[112];
    s32 n = (size + 16383) & ~16383;
    s32 s = 0;
    s32 d = 0;
    while (n > 0) {
        func_00138FF0(buf, (src + s) >> 8, 1, 1, 0, 0, 64, 64);
        s += 16384;
        func_00126E20(0);
        func_001392B0(buf, dst + d);
        d += 12288;
        func_00131A08(0, 0);
        n -= 16384;
    }
}
