#include "common.h"

extern s32 func_L01_006B1D68(s32 a0, void *a1, s32 a2, void *a3);
s32 D_00222540 = 0;

// Call the class callback for the object; if it yields a target, run func_L01_006B1D68 with flag 9 set.
void func_L01_004EFDB0(u8 *arg0) {
    s32 r = (*(s32 (**)(s32))(*(u8 **)(*(u8 **)(arg0 + 0xAC) + 0x4C) + 8))(*(s32 *)(arg0 + 0xB8));

    if (r != 0) {
        arg0[0x67] = 9;
        func_L01_006B1D68(r, arg0, 4, &D_00222540);
        arg0[0x67] = 0;
    }
}
