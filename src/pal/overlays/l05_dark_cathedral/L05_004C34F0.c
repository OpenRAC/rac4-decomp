#include "common.h"

extern void func_L05_004C37A0(u8 *);
extern void func_00474368(u8 *, s32, s32);
extern s32 func_00453CE8(s32 *);
extern void func_L05_004C3888(u8 *);
extern void func_004E2EF0(s32, s32, u8 *);

// Two-way mover driven by the byte at vars+0x18, like func_L05_004F59C8 but timed: state 0 sets
// it up; state 1 waits for 0 (and clears +0x2D when the level is 0 and +0x2C is 0) and goes to 3;
// state 2 waits for 1 and goes to 4; state 3 raises the level at vars+0x10 by 0.036 each time the
// timer at vars+0x28 runs out, up to 1.0 (then state 2), or goes to 4 when the byte is 1; state 4
// lowers it to 0 (then state 1), or goes to 3 when the byte is 0. Entering state 3 calls
// func_004E2EF0(1, 0).
void func_L05_004C34F0(u8 *moby) {
    u8 old = moby[0x20];
    u8 *vars = *(u8 **)(moby + 0xAC);
    s32 first;

    switch (old) {
    case 0:
        func_L05_004C37A0(moby);
        break;
    case 1:
        if (*(f32 *)(vars + 0x10) <= 0.0f && vars[0x2C] == 0) {
            vars[0x2D] = 0;
        }
        if (vars[0x18] == 0) {
            func_00474368(moby, 3, -1);
        }
        break;
    case 2:
        if (vars[0x18] == 1) {
            func_00474368(moby, 4, -1);
        }
        break;
    case 3:
        if (vars[0x18] == 1) {
            func_00474368(moby, 4, -1);
        } else {
            if (func_00453CE8((s32 *)(vars + 0x28)) != 0) {
                *(f32 *)(vars + 0x10) += 0.036000002f;
            }
            if (*(f32 *)(vars + 0x10) >= 1.0f) {
                *(f32 *)(vars + 0x10) = 1.0f;
                func_00474368(moby, 2, -1);
            }
            func_L05_004C3888(moby);
        }
        break;
    case 4:
        if (vars[0x18] == 0) {
            func_00474368(moby, 3, -1);
        } else {
            first = *(s32 *)(vars + 0x28) == 1;
            if (func_00453CE8((s32 *)(vars + 0x28)) != 0) {
                *(f32 *)(vars + 0x10) -= 0.036000002f;
            }
            if (*(f32 *)(vars + 0x10) <= 0.0f) {
                *(f32 *)(vars + 0x10) = 0.0f;
                func_00474368(moby, 1, -1);
            }
            if (first) {
                func_004E2EF0(0, 0, moby);
            }
            func_L05_004C3888(moby);
        }
        break;
    }
    if (moby[0x20] != old && moby[0x20] == 3) {
        func_004E2EF0(1, 0, moby);
    }
}
