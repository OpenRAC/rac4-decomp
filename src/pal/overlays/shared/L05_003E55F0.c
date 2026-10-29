#include "common.h"

extern void func_L05_003E5760(u8 *);
extern void func_L05_003E5790(u8 *);
extern void func_00474368(u8 *, s32, s32);

// State machine on the object's state: runs between 1 and 4 by the byte at +0xC of its +0xAC
// block, moving the float at +8 by 0.036 a frame towards 1 or 0 in states 2 and 4.
void func_L05_003E55F0(u8 *arg0) {
    u8 *vars;

    if (arg0[0x20] == 0) {
        func_L05_003E5760(arg0);
    }
    vars = *(u8 **)(arg0 + 0xAC);
    switch (arg0[0x20]) {
    case 1:
        if (vars[0xC] == 0) {
            func_00474368(arg0, 2, -1);
        }
        break;
    case 2:
        if (vars[0xC] == 1) {
            func_00474368(arg0, 4, -1);
            break;
        }
        *(f32 *)(vars + 8) += 0.036000002f;
        if (*(f32 *)(vars + 8) >= 1.0f) {
            *(f32 *)(vars + 8) = 1.0f;
            func_00474368(arg0, 3, -1);
        }
        func_L05_003E5790(arg0);
        break;
    case 3:
        if (vars[0xC] == 1) {
            func_00474368(arg0, 4, -1);
        }
        break;
    case 4:
        if (vars[0xC] == 0) {
            func_00474368(arg0, 2, -1);
            break;
        }
        *(f32 *)(vars + 8) -= 0.036000002f;
        if (*(f32 *)(vars + 8) <= 0.0f) {
            *(f32 *)(vars + 8) = 0.0f;
            func_00474368(arg0, 1, -1);
        }
        func_L05_003E5790(arg0);
        break;
    }
}
