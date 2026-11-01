#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern f32 D_003A4EC8[][3];

extern f32 func_00454328(f32, f32);
extern void func_00470FD0(u8 *);

// For each part in the list at vars+0xE0 (count+1 entries, count at +0xF8), turns its two
// angles at +0xF8 and +0xF4 by the per-part speeds of the table D_003A4EC8 (degrees per frame,
// 1/50 s), copies the moby's position to it and updates it with func_00470FD0.
void func_L06_004C97B0(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    s32 i;

    for (i = 0; i <= *(s16 *)(vars + 0xF8); i++) {
        u8 *part = ((u8 **)(vars + 0xE0))[i];

        *(f32 *)(part + 0xF8) = func_00454328(*(f32 *)(part + 0xF8), D_003A4EC8[i][1] * 0.017453292f * 0.020000001f);
        *(f32 *)(part + 0xF4) = func_00454328(*(f32 *)(part + 0xF4), D_003A4EC8[i][2] * 0.017453292f * 0.020000001f);
        *(u128 *)(part + 0x10) = *(u128 *)(moby + 0x10);
        func_00470FD0(part);
    }
}
