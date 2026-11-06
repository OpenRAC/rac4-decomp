#include "common.h"

extern s32 D_001723B8[];
extern char D_003559E0[], D_003559C0[];
f32 D_00221030 = 65.0f, D_00221034 = 35.0f, D_00221038 = 56.0f, D_0022103C = 51.0f;
u64 D_00221040 = 0xFFFFFFFFFF696969ULL;
extern void func_00457648(f32, f32, u64, const void *, f32, s32);
void func_0054CE80(void)
{
    if (!D_001723B8[0])
        func_00457648(D_00221038, D_0022103C, D_00221040, D_003559E0, 1.0f, -1);
    func_00457648(D_00221030, D_00221034, D_00221040, D_003559C0, 1.0f, -1);
}
