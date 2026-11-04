#include "common.h"

extern s32 func_L01_0058A760(u8 *);
extern void func_00474260(u8 *, s32, s32, f32, s32);
extern void func_00474368(u8 *, s32, s32);
extern void func_L01_0058A700(u8 *, s32);
extern void func_004E2EF0(s32, s32, u8 *);

// State machine of a level object: state 0 picks state 4 or 1 from func_L01_0058A760 (calling
// func_00474260 first); state 1 waits for flag 4 of +0xBE and goes to 2; state 2 counts 75
// frames in +0x6A, calls func_004E2EF0(0, 0x130) and goes to 3; state 3 sets bit 0x10 of +0x55
// and, once bit 2 is set, stops (+0x48 = 0) and goes to 4; state 4 clears +0x98 and sets flag 2.
void func_L13_004BEF98(u8 *moby) {
    switch (moby[0x20]) {
    case 0:
        if (func_L01_0058A760(moby) != 0) {
            func_00474260(moby, 2, 0, 0.0f, 0);
            func_00474368(moby, 4, -1);
        } else {
            func_00474260(moby, 0, 0, 0.0f, 0);
            func_00474368(moby, 1, -1);
        }
        break;
    case 1:
        if (moby[0xBE] & 4) {
            func_L01_0058A700(moby, 1);
            func_00474368(moby, 2, -1);
        }
        break;
    case 2:
        if (++*(u16 *)(moby + 0x6A) == 75) {
            func_004E2EF0(0, 0x130, moby);
            func_00474260(moby, 1, 0, 0.0f, 0);
            func_00474368(moby, 3, -1);
        }
        break;
    case 3:
        moby[0x55] |= 0x10;
        if (moby[0x55] & 2) {
            func_00474260(moby, 2, 0, 0.0f, 0);
            *(f32 *)(moby + 0x48) = 0.0f;
            func_00474368(moby, 4, -1);
        }
        break;
    case 4:
        *(s32 *)(moby + 0x98) = 0;
        *(u16 *)(moby + 0x34) |= 2;
        break;
    }
}
