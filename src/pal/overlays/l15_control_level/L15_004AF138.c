#include "common.h"

extern void func_L15_004AF290(u8 *);
extern f32 func_00454328(f32, f32);
extern void func_L15_004AF388(u8 *);
extern s32 func_L15_004AF2E0(u8 *);
extern void func_L15_004AF510(u8 *);
extern void func_00474368(u8 *, s32, s32);
extern void func_0046C6B0(u8 *);

// Per-frame update: sets the moby up in state 0, turns +0xF8 by 0.005235988 a frame,
// then state 1 waits for func_L15_004AF2E0 and goes to 2; state 2 counts +0x6A up to
// vars+0x80 * 50 frames and goes to 3; state 3 counts to vars+0x84 * 50 frames and
// calls func_0046C6B0. The * 50 may be seconds at 50 Hz.
void func_L15_004AF138(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);

    if (moby[0x20] == 0) {
        func_L15_004AF290(moby);
    }
    *(f32 *)(moby + 0xF8) = func_00454328(*(f32 *)(moby + 0xF8), 0.005235988f);
    func_L15_004AF388(moby);
    switch (moby[0x20]) {
    case 1:
        if (func_L15_004AF2E0(moby) != 0) {
            func_00474368(moby, 2, -1);
        }
        break;
    case 2:
        (*(u16 *)(moby + 0x6A))++;
        if (*(u16 *)(moby + 0x6A) >= (s32)(*(s32 *)(vars + 0x80) * 50.0f)) {
            func_L15_004AF510(moby);
            moby[0x31] = 0;
            *(s32 *)(moby + 0x98) = 0;
            *(u16 *)(moby + 0x34) |= 1;
            func_00474368(moby, 3, -1);
        }
        break;
    case 3:
        (*(u16 *)(moby + 0x6A))++;
        if (*(u16 *)(moby + 0x6A) >= (s32)(*(s32 *)(vars + 0x84) * 50.0f)) {
            func_0046C6B0(moby);
        }
        break;
    }
}
