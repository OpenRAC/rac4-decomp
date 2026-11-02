#include "common.h"

extern void func_L05_003E2578(u8 *);
extern void func_004E2EF0(s32, s32, u8 *);
extern void func_00474368(u8 *, s32, s32);
extern void func_L05_003E25D0(u8 *);

// Per-frame update of a two-way mover driven by the byte at vars+0xC: state 1 waits for 0 and
// goes to 2; state 2 raises the level at vars+4 by 0.012 a frame up to 1.0 (then state 3), or goes
// to 4 when the byte is 1; state 3 waits for 1 and goes to 4; state 4 lowers the level to 0 (then
// state 1), or goes to 2 when the byte is 0. States 2 and 4 call func_004E2EF0 once on entry (flag
// bit 0 of +0xBE) and func_L05_003E25D0 every frame they move.
void func_L05_003E2348(u8 *moby) {
    u8 *vars;
    s32 first;
    u8 f;

    if (moby[0x20] == 0) {
        func_L05_003E2578(moby);
    }
    vars = *(u8 **)(moby + 0xAC);
    switch (moby[0x20]) {
    case 1:
        if (vars[0xC] == 0) {
            func_00474368(moby, 2, -1);
        }
        break;
    case 2:
        f = moby[0xBE];
        if ((f ^ 1) & 1) {
            moby[0xBE] = f | 1;
            first = 1;
        } else {
            first = 0;
        }
        if (first) {
            func_004E2EF0(0, 0, moby);
        }
        if (vars[0xC] == 1) {
            func_00474368(moby, 4, -1);
        } else {
            *(f32 *)(vars + 4) += 0.012f;
            if (*(f32 *)(vars + 4) >= 1.0f) {
                *(f32 *)(vars + 4) = 1.0f;
                func_00474368(moby, 3, -1);
            }
            func_L05_003E25D0(moby);
        }
        break;
    case 3:
        if (vars[0xC] == 1) {
            func_00474368(moby, 4, -1);
        }
        break;
    case 4:
        f = moby[0xBE];
        if ((f ^ 1) & 1) {
            moby[0xBE] = f | 1;
            first = 1;
        } else {
            first = 0;
        }
        if (first) {
            func_004E2EF0(0, 0, moby);
        }
        if (vars[0xC] == 0) {
            func_00474368(moby, 2, -1);
        } else {
            *(f32 *)(vars + 4) -= 0.012f;
            if (*(f32 *)(vars + 4) <= 0.0f) {
                *(f32 *)(vars + 4) = 0.0f;
                func_00474368(moby, 1, -1);
            }
            func_L05_003E25D0(moby);
        }
        break;
    }
}
