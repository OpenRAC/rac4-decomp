#include "common.h"

extern void func_00522A30(s32 a0, s32 a1);
extern void func_00547A40(s32 a0, s32 a1, s32 a2);
extern void func_00548DF8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_00549458(s32 a0, s32 a1, s32 a2);
extern u8 *D_0021DFF0;
extern s32 D_0021EDD4;

void func_00522AF8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_a2;

    func_00522A30((s32)arg0, arg1);
    func_00548DF8(*(s32 *)(arg0 + 0x26E4), arg1, arg2, 1, 0);
    if (D_0021EDD4 == 1 && D_0021DFF0[0x32] != 0 &&
        *(s32 *)(arg0 + 0x2F14) == D_0021EDD4 && *(f32 *)(arg0 + 0x2F24) == 200.0f) {
        var_a2 = 0;
        if (*(s32 *)(arg0 + 0x2318) == arg1) {
            var_a2 = *(s32 *)(arg0 + 0x22F0);
        }
        func_00549458(*(s32 *)(arg0 + 0x26E4), arg1, var_a2);
    }
    if (arg0[0x266D] != 0) {
        s32 (*hook)(void *) = *(s32 (**)(void *))(*(u8 **)(arg0 + 0x14) + 0x4C);
        func_00547A40(hook(arg0), arg1, arg3);
    }
}
