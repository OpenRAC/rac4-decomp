#include "common.h"
f32 D_0021F738 = 0.0f;
s32 D_0021F73C = 0;
extern s32 D_002216B0;
extern s32 func_004A1A60(s32 *, s32);
extern s32 func_00505410(s32, f32), func_00504238(s32, f32, f32);
extern f32 func_004756D0(f32, f32, f32);
void func_004AF198(void)
{
    D_0021F738 -= 0.05f;
    func_00505410(func_004A1A60(&D_002216B0, 100), D_0021F738);
    if (D_0021F738 <= 0.0f)
        D_0021F73C &= ~8;
    else if (D_0021F738 < 1.0f) {
        s32 id = func_004A1A60(&D_002216B0, 100);
        f32 y = func_004756D0(0.74f, 0.7f, D_0021F738);
        func_00504238(id, 0.128f, y);
    }
}
