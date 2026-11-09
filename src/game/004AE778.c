#include "common.h"
extern s32 D_002216B0;
extern u8 D_003092A0[];
extern s32 func_00504238(s32 handle, f32 a, f32 b);
extern void func_00504550(s32, void *, f32 *);
extern s32 func_00505410(u32 id, f32 amount);
extern s32 func_00505B20(void);

void func_004AE778(void)
{
    f32 *entry = (f32 *)(D_003092A0 + func_00505B20() * 0x64);
    f32 v = entry[1] * entry[2];
    f32 pos[2];

    func_00505410(D_002216B0, v);
    func_00504550(D_002216B0, &pos[0], &pos[1]);
    func_00504238(D_002216B0, pos[0], (1.0f - v) * 0.2f + 0.5f);
}
