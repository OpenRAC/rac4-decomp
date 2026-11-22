#include "common.h"
extern f32 (**func_0046D428(s32, s32, s32))(u8 *);
f32 func_L01_0056DF50(u8 *p) {
    f32 (**t)(u8 *);
    f32 r;
    if (p == 0) return 0.0f;
    t = func_0046D428(*(s16 *)(p + 0xBC), 0x14, 8);
    if (t != 0) return (*t)(p);
    r = 0.0f;
    if (p[0xBE] & 4) r = 1.0f;
    return r;
}
