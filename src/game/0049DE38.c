#include "common.h"

extern u8 D_3070A8[];
extern u8 D_3072A8[];
extern void func_0049B568(void *p, s32 deltas, f32 a, f32 b, f32 c, f32 d);
extern s32 func_00505AD8(s32 a);
extern s32 func_00505B20(void);

// Calls func_0049B568 on the 0x30-byte entry of a player, flagging it when byte 0x24 or float 0x28 is set.
void func_0049DE38(s32 mode, s32 index, f32 a, f32 b, f32 c, f32 d)
{
    s32 saved;
    u8 *target;
    s32 flag;

    saved = func_00505B20();
    func_00505AD8(mode);
    if (mode == 4) {
        target = &D_3070A8[index * 0x30];
    } else {
        s32 row = index * 0x30;
        u8 *base = D_3072A8 + (mode << 9);
        target = base + row;
    }
    flag = 0;
    if (target[0x24] != 0 || *(f32 *)(target + 0x28) != 0.0f) {
        flag = 1;
    }
    func_0049B568(target, flag, a, b, c, d);
    func_00505AD8(saved);
}
