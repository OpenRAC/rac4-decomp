#include "common.h"
extern void func_L01_005ABD28(void *, f32, f32);
extern void func_L01_005ABDE8(void *, f32, f32, f32);
extern void func_00473A88(void *, s32, s32);
s32 func_L01_00492028(u8 *obj, s32 kind) {
    switch (kind) {
    case 0: func_L01_005ABD28(obj, 0.06666667f, 0.13333334f); break;
    case 1: func_L01_005ABDE8(obj, 9.0f, 27.0f, 31.0f); break;
    case 4: func_00473A88(obj, obj[0x68], -1); break;
    }
    return 1;
}
