#include "common.h"
typedef struct {
    s32 flags;
    char pad[0xD4];
    f32 timer;
    char rest[0x10];
} State;
extern u8 D_00307C58[];
extern s32 func_00506BB8(void), func_00506000(s32, s32), func_005063C0(s32, u32), func_00505A50(s32, u32);
void func_004A55F8(void)
{
    s32 offset = func_00506BB8() * 0xEC;
    u8 *base = D_00307C58;
    f32 *first = &((State *)base)->timer;
    f32 *timer = (f32 *)((char *)first + offset);
    *timer -= 0.05f;
    if (*timer <= 0) {
        func_00506000(0xE0007, 0);
        func_00506000(0xE0008, 0);
        ((State *)(offset + base))->flags &= ~4;
    } else if (*timer < 1) {
        u32 color = (u32)(s32)(*timer * 128.0f) << 24;
        u32 shadow = (u32)(s32)(*timer * 64.0f) << 24;
        func_005063C0(0xE0007, color | 0xD0D0D0);
        func_00505A50(0xE0007, shadow);
        func_005063C0(0xE0008, ((u32)(s32)(*timer * 128.0f) << 24) | 0x20F0F0);
        func_00505A50(0xE0008, shadow);
    }
}
