#include "common.h"
typedef struct {
    s32 flags;
    char pad[0xD4];
    f32 timer;
    char rest[0x10];
} State;
extern u8 D_00307B58[];
extern s32 func_00505B20(void), func_00504F68(s32, s32), func_00505328(s32, u32), func_005049B8(s32, u32);
void func_004A4880(void)
{
    s32 offset = func_00505B20() * 0xEC;
    u8 *base = D_00307B58;
    f32 *first = &((State *)base)->timer;
    f32 *timer = (f32 *)((char *)first + offset);
    *timer -= 0.05f;
    if (*timer <= 0) {
        func_00504F68(0xE0007, 0);
        func_00504F68(0xE0008, 0);
        ((State *)(offset + base))->flags &= ~4;
    } else if (*timer < 1) {
        u32 color = (u32)(s32)(*timer * 128.0f) << 24;
        u32 shadow = (u32)(s32)(*timer * 64.0f) << 24;
        func_00505328(0xE0007, color | 0xD0D0D0);
        func_005049B8(0xE0007, shadow);
        func_00505328(0xE0008, ((u32)(s32)(*timer * 128.0f) << 24) | 0x20F0F0);
        func_005049B8(0xE0008, shadow);
    }
}
