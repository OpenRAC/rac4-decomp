/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern void func_00481900(u8 *, s32, void *, s32, s32, s32, f32);
extern void func_L01_00591BD8(u8 *, s32, s32);
extern void func_L01_0046A638(u8 *);
s32 func_L01_0046AE68(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0xAC);
    if (arg1 == 4) {
        if (p[0x504]) {
            func_00481900(arg0, 11, 0, 0, 0, 0, 0.0f);
            func_L01_00591BD8(arg0, 24, -1);
        } else {
            func_L01_0046A638(arg0);
        }
    }
    return 1;
}
