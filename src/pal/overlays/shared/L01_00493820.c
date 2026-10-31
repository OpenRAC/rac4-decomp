#include "common.h"

extern void func_L01_005B00B8(f32, f32);
extern void func_L01_005B0178(f32, f32, f32);
extern void func_00474368(u8 *, s32, s32);

// By arg1: 0 calls func_L01_005B00B8(0.08, 0.16) (each one ulp above: (1/15) * 1.2 and
// (2/15) * 1.2 in single precision), 1 calls func_L01_005B0178(9.0f, 27.0f, 31.0f), 4 calls
// func_00474368 with the object's byte at +0x68. Returns 1.
s32 func_L01_00493820(u8 *arg0, s32 arg1) {
    switch (arg1) {
    case 0:
        func_L01_005B00B8(0.080000006f, 0.16000001f);
        break;
    case 1:
        func_L01_005B0178(9.0f, 27.0f, 31.0f);
        break;
    case 4:
        func_00474368(arg0, arg0[0x68], -1);
        break;
    }
    return 1;
}
