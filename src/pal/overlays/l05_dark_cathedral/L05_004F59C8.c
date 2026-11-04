#include "common.h"

extern void func_L05_004F5B08(u8 *);
extern void func_00474368(u8 *, s32, s32);
extern void func_L05_004F5B98(u8 *);

// Per-frame update of a two-way mover like func_L05_003E2348, driven by the byte at vars+0x11:
// state 0 sets it up (func_L05_004F5B08); state 1 waits for 0 and goes to 2; state 2 raises the
// level at vars+0x14 by 0.036 a frame up to 1.0 (then state 3), or goes to 4 when the byte is 1;
// state 3 waits for 1 and goes to 4; state 4 lowers the level to 0 (then state 1), or goes to 2
// when the byte is 0. Then func_L05_004F5B98 every frame.
void func_L05_004F59C8(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);

    switch (moby[0x20]) {
    case 0:
        func_L05_004F5B08(moby);
        break;
    case 1:
        if (vars[0x11] == 0) {
            func_00474368(moby, 2, -1);
        }
        break;
    case 2:
        if (vars[0x11] == 1) {
            func_00474368(moby, 4, -1);
        } else {
            *(f32 *)(vars + 0x14) += 0.036000002f;
            if (*(f32 *)(vars + 0x14) >= 1.0f) {
                *(f32 *)(vars + 0x14) = 1.0f;
                func_00474368(moby, 3, -1);
            }
        }
        break;
    case 3:
        if (vars[0x11] == 1) {
            func_00474368(moby, 4, -1);
        }
        break;
    case 4:
        if (vars[0x11] == 0) {
            func_00474368(moby, 2, -1);
        } else {
            *(f32 *)(vars + 0x14) -= 0.036000002f;
            if (*(f32 *)(vars + 0x14) <= 0.0f) {
                *(f32 *)(vars + 0x14) = 0.0f;
                func_00474368(moby, 1, -1);
            }
        }
        break;
    }
    func_L05_004F5B98(moby);
}
