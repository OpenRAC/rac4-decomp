#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 *func_0046C1F0(s32, s32);
extern f32 func_00472EB8(f32, f32);
extern void func_00474368(u8 *, s32, s32);

// Creates a moby of class 0x2455 with 0x20 bytes of data at pos, scales +0x70 by 0.4 * scale,
// stores dir, speed and arg frames converted with (n * 5 + 2) / 6 (and that minus 15), two
// random values from func_00472EB8, and sets state 0. Returns the moby or NULL.
u8 *func_L01_00464780(u128 pos, u128 dir, s32 frames, f32 speed, f32 scale) {
    u8 *moby = func_0046C1F0(0x2455, 0x20);
    u8 *vars;
    s32 n;

    if (moby == NULL) {
        return NULL;
    }
    n = (frames * 5 + 2) / 6;
    vars = *(u8 **)(moby + 0xAC);
    *(s16 *)(moby + 0x32) = 0x20;
    moby[0x30] = 0xFF;
    *(u128 *)(moby + 0x10) = pos;
    *(f32 *)(moby + 0x70) *= scale * 0.4f;
    *(u128 *)(vars + 0) = dir;
    *(f32 *)(vars + 0x10) = speed;
    *(s16 *)(vars + 0x14) = n;
    *(s16 *)(vars + 0x16) = n - 15;
    *(f32 *)(vars + 0x18) = func_00472EB8(0.12566371f, 0.25132743f);
    *(f32 *)(vars + 0x1C) = func_00472EB8(0.12566371f, 0.25132743f);
    func_00474368(moby, 0, -1);
    return moby;
}
