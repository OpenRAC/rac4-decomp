#include "common.h"

extern void func_L04_003FF608(u8 *);
extern void func_L04_003FF6A0(u8 *);
extern void func_00474368(u8 *, s32, s32);
extern void func_L04_003FF860(u8 *);

// State machine on the object's state: runs between 1 and 4 by the byte at +0x88 of its +0xAC
// block, moving the float at +0x80 by 0.012 a frame towards 1 or 0, then calls
// func_L04_003FF860.
void func_L04_003FF490(u8 *arg0) {
    u8 *vars;

    if (arg0[0x20] == 0) {
        func_L04_003FF608(arg0);
    }
    vars = *(u8 **)(arg0 + 0xAC);
    switch (arg0[0x20]) {
    case 1:
        if (vars[0x88] == 0) {
            func_00474368(arg0, 2, -1);
        }
        break;
    case 2:
        if (vars[0x88] == 1) {
            func_00474368(arg0, 4, -1);
            break;
        }
        *(f32 *)(vars + 0x80) += 0.012f;
        if (*(f32 *)(vars + 0x80) >= 1.0f) {
            *(f32 *)(vars + 0x80) = 1.0f;
            func_00474368(arg0, 3, -1);
        }
        func_L04_003FF6A0(arg0);
        break;
    case 3:
        if (vars[0x88] == 1) {
            func_00474368(arg0, 4, -1);
        }
        break;
    case 4:
        if (vars[0x88] == 0) {
            func_00474368(arg0, 2, -1);
            break;
        }
        *(f32 *)(vars + 0x80) -= 0.012f;
        if (*(f32 *)(vars + 0x80) <= 0.0f) {
            *(f32 *)(vars + 0x80) = 0.0f;
            func_00474368(arg0, 1, -1);
        }
        func_L04_003FF6A0(arg0);
        break;
    }
    func_L04_003FF860(arg0);
}
