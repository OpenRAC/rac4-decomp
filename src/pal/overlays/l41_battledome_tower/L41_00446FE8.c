#include "common.h"

extern u8 *D_0021E078;

extern void func_0046C6B0(u8 *);
extern void func_00474368(u8 *, s32, s32);
extern s32 func_00453DB8(void *);
extern void func_L41_00446F10(u8 *, s32);

// State 0: deletes the object unless one of two bytes of D_0021E078 is set, else shows it and sets
// state 1. State 1: when the timer at +0x44 of its block runs out, calls func_L41_00446F10 with
// +0x40 and restarts the timer at 8.666667.
void func_L41_00446FE8(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);

    switch (arg0[0x20]) {
    case 0:
        if (D_0021E078[9] == 0 && D_0021E078[0x2F] == 0) {
            func_0046C6B0(arg0);
            break;
        }
        arg0[0x30] = 0xFF;
        func_00474368(arg0, 1, -1);
        break;
    case 1:
        if (func_00453DB8(vars + 0x44) != 0) {
            func_L41_00446F10(arg0, *(s32 *)(vars + 0x40));
            *(f32 *)(vars + 0x44) = 8.666667f;
        }
        break;
    }
}
