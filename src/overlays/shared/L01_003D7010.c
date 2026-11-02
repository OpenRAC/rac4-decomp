#include "common.h"

extern void func_005AC748(s32, s32, void *, s32, s32, s32, f32);
extern void func_005B53B0(s32, s32, f32);
extern void D_003D7098(void);

// When arg1 is 0, calls func_005B53B0(arg0, 30, 0.0); when it is 4, calls func_005AC748 with 3 and
// D_003D7098, then func_005B53B0(arg0, 0, 1.0). Returns 1.
s32 func_L01_003D7010(s32 arg0, s32 arg1) {
    switch (arg1) {
    case 0:
        func_005B53B0(arg0, 0x1E, 0.0f);
        break;
    case 4:
        func_005AC748(arg0, 3, (void *)D_003D7098, 0, 0, 0, 0.0f);
        func_005B53B0(arg0, 0, 1.0f);
        break;
    }
    return 1;
}
