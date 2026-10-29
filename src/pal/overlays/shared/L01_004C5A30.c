#include "common.h"

extern void func_L01_005B00B8(f32, f32);
extern void func_L01_005B0178(f32, f32, f32);

// By arg1: 0 calls func_L01_005B00B8(-0.06, 0.02), 1 calls func_L01_005B0178(0, 3, 14).
// Returns 1.
s32 func_L01_004C5A30(u8 *arg0, s32 arg1) {
    switch (arg1) {
    case 0:
        func_L01_005B00B8(-0.060000002f, 0.020000001f);
        break;
    case 1:
        func_L01_005B0178(0.0f, 3.0f, 14.0f);
        break;
    case 4:
        break;
    }
    return 1;
}
