#include "common.h"

extern void func_L04_00487CC8(u8 *);
extern void func_L04_00487EB8(u8 *);
extern void func_00474368(u8 *, s32, s32);
extern void func_L04_00488068(u8 *);

// State machine on the object's state: runs between 1 and 4 by the word at +0x94 of its +0xAC
// block, moving the float at +0x90 by 0.048 a frame towards 1 or 0, then calls
// func_L04_00488068.
void func_L04_00487B50(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);

    if (arg0[0x20] == 0) {
        func_L04_00487CC8(arg0);
    }
    switch (arg0[0x20]) {
    case 1:
        if (*(s32 *)(vars + 0x94) == 0) {
            func_00474368(arg0, 2, -1);
        }
        break;
    case 2:
        if (*(s32 *)(vars + 0x94) == 1) {
            func_00474368(arg0, 4, -1);
            break;
        }
        *(f32 *)(vars + 0x90) += 0.048f;
        if (*(f32 *)(vars + 0x90) >= 1.0f) {
            *(f32 *)(vars + 0x90) = 1.0f;
            func_00474368(arg0, 3, -1);
        }
        func_L04_00487EB8(arg0);
        break;
    case 3:
        if (*(s32 *)(vars + 0x94) == 1) {
            func_00474368(arg0, 4, -1);
        }
        break;
    case 4:
        if (*(s32 *)(vars + 0x94) == 0) {
            func_00474368(arg0, 2, -1);
            break;
        }
        *(f32 *)(vars + 0x90) -= 0.048f;
        if (*(f32 *)(vars + 0x90) <= 0.0f) {
            *(f32 *)(vars + 0x90) = 0.0f;
            func_00474368(arg0, 1, -1);
        }
        func_L04_00487EB8(arg0);
        break;
    }
    func_L04_00488068(arg0);
}
