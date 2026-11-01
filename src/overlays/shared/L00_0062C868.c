#include "common.h"

s32 func_L00_0062B4A8(s32);
s32 func_L00_0062C7C8();
s32 func_00699138(s32);
s32 func_0069DC48(s32);
s32 func_0069DC90();
s32 func_0069DE78(s32);
extern s32 D_0030D930[];
#define D_307B30 (D_0030D930[0])

void func_L00_0062C868(s32 a0) {
    s32 temp_s0;

    if (D_307B30 == 0) {
        func_L00_0062C7C8();
    }
    D_307B30 |= 1 << a0;
    temp_s0 = func_0069DC90();
    func_0069DC48(a0);
    func_00699138(func_L00_0062B4A8(a0));
    func_0069DE78(func_L00_0062B4A8(a0));
    func_0069DC48(temp_s0);
}
