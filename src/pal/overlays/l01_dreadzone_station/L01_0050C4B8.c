#include "common.h"

extern void func_L01_0050C350(u8 *);
extern void func_L01_005B00B8(u8 *, f32, f32);
extern void func_00481900(u8 *, s32, void *, s32, s32, s32, f32);
extern void func_00474368(u8 *, s32, s32);
extern void func_L01_0050C3F8(void);

// When arg1 is 0: calls func_L01_0050C350, func_L01_005B00B8 with the two floats at arg2
// times 0.02, registers func_L01_0050C3F8 through func_00481900 and sets state 0x18, 6.
void func_L01_0050C4B8(u8 *arg0, s32 arg1, f32 *arg2) {
    if (arg1 == 0) {
        func_L01_0050C350(arg0);
        func_L01_005B00B8(arg0, arg2[0] * 0.020000001f, arg2[1] * 0.020000001f);
        func_00481900(arg0, 2, (void *)func_L01_0050C3F8, 0, 0, 0, 0.0f);
        func_00474368(arg0, 0x18, 6);
    }
}
