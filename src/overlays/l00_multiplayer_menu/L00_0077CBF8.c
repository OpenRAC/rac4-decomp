#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern s32 D_172160[];

/* Returns a field of D_172160 plus the low word of a scaled time difference. */
s32 func_L00_0077CBF8(void) {
    u8 *g;
    u64 e;
    u64 t;

    e = func_0012E370();
    g = (u8 *)D_172160;
    t = func_0012FEB0(e, 0x24000);
    t = func_0012FEB0(t - *(u64 *)(g + 0x138), 0x3E8);
    return *(s32 *)(g + 0x130) + (s32)t;
}
