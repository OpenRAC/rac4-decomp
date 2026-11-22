#include "common.h"

extern void func_00473A88(void *, u8, s32);
extern void func_L01_005ABD28(f32, f32);
extern void func_L01_005ABDE8(f32, f32, f32);

s32 func_L01_0043AF78(u8 *obj, s32 k) {
    switch (k) {
    case 0:
        func_L01_005ABD28(0.06666667f, 0.13333334f);
        break;
    case 1:
        func_L01_005ABDE8(7.0f, 19.0f, 31.0f);
        break;
    case 4:
        func_00473A88(obj, obj[0x68], -1);
        break;
    }
    return 1;
}
