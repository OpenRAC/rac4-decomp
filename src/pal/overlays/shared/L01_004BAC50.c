#include "common.h"

extern void func_L01_004B86D0(u8 *);
extern void func_L01_005B00B8(u8 *, f32, f32);
extern void func_00481900(u8 *, s32, void *, s32, s32, s32, f32);
extern void func_00474368(u8 *, s32, s32);
extern void func_L01_004BA988(void);

// Calls func_L01_004B86D0; for arg1 1 (which also sets 0xC00 in +0x50 of the object's +0xAC
// block) and 0, calls func_L01_005B00B8 with the two floats at arg2 times 0.02, registers
// func_L01_004BA988 through func_00481900 and sets state 1, 1.
void func_L01_004BAC50(u8 *arg0, s32 arg1, f32 *arg2) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);

    func_L01_004B86D0(arg0);
    switch (arg1) {
    case 1:
        *(s32 *)(vars + 0x50) |= 0xC00;
        func_L01_005B00B8(arg0, arg2[0] * 0.020000001f, arg2[1] * 0.020000001f);
        func_00481900(arg0, 7, (void *)func_L01_004BA988, 0, 0, 0, 4.5f);
        func_00474368(arg0, 1, 1);
        break;
    case 0:
        func_L01_005B00B8(arg0, arg2[0] * 0.020000001f, arg2[1] * 0.020000001f);
        func_00481900(arg0, 7, (void *)func_L01_004BA988, 0, 0, 0, 4.5f);
        func_00474368(arg0, 1, 1);
        break;
    }
}
