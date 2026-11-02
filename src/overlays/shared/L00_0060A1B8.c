#include "common.h"

extern s32 func_005BC980(void *);
extern void func_00607960(void *);

// When func_005BC980 on the block at +0x20 returns 0, adds the block's float at +0x4 to the float
// at +0xC and, while the block's first word is below 6, sets the top byte of +0x4 to n * 127 / 6;
// otherwise calls func_00607960.
void func_L00_0060A1B8(u8 *arg0) {
    s32 *timer = (s32 *)(arg0 + 0x20);
    s32 t;

    if (func_005BC980(timer) != 0) {
        func_00607960(arg0);
        return;
    }
    t = timer[0];
    *(f32 *)(arg0 + 0xC) = *(f32 *)(arg0 + 0xC) + *(f32 *)&timer[1];
    if (t < 6) {
        *(s32 *)(arg0 + 4) = (*(s32 *)(arg0 + 4) & 0xFFFFFF) | (((t * 0x7F) / 6) << 24);
    }
}
