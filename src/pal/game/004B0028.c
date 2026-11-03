#include "common.h"
f32 D_0021F7D8 = 0.0f;
s32 D_0021F7DC = 0;
extern s32 D_002217B0;
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005064A8(s32, f32), func_005052D0(s32, f32, f32);
extern f32 func_00475FB0(f32, f32, f32);
void func_004B0028(void)
{
    D_0021F7D8 -= 0.05f;
    func_005064A8(func_004A2798(&D_002217B0, 100), D_0021F7D8);
    if (D_0021F7D8 <= 0.0f)
        D_0021F7DC &= ~8;
    else if (D_0021F7D8 < 1.0f) {
        s32 id = func_004A2798(&D_002217B0, 100);
        f32 y = func_00475FB0(0.74f, 0.7f, D_0021F7D8);
        func_005052D0(id, 0.128f, y);
    }
}
