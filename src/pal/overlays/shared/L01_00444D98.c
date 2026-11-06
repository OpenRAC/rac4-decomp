#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 *func_0046C1F0(s32, s32);
extern f32 func_00472EB8(f32, f32);
extern void func_00470FD0(u8 *);
extern void func_L00_00621678(u8 *, s32);
extern void func_00479EB8(u8 *, u32);
extern void func_004778A8(u8 *, s32, u32, s32);

// Spawns a 0x20D6 moby owned by the first argument at *pos with a random
// rotation; sets its speed (0.0048 if not positive), colours and target.
u8 *func_L01_00444D98(u8 *owner, u128 *pos, u128 *dir, s32 flag, u128 *target, f32 speed, f32 arg6) {
    u8 *moby = func_0046C1F0(0x20D6, 0xA0);
    u8 *vars;
    f32 *rot;
    u8 *t;
    f32 x;
    f32 y;
    f32 z;

    if (moby != NULL) {
        *(u128 *)(moby + 0x10) = *pos;
        *(u8 **)(moby + 0xB8) = owner;
        moby[0x30] = 0xFF;
        *(s16 *)(moby + 0x32) = 0x40;
        moby[0x31] = 1;
        vars = *(u8 **)(moby + 0xAC);
        x = func_00472EB8(-3.1415927f, 3.1415927f);
        y = func_00472EB8(-3.1415927f, 3.1415927f);
        z = func_00472EB8(-3.1415927f, 3.1415927f);
        *(f32 *)(moby + 0xF0) = x;
        rot = (f32 *)(moby + 0xF0);
        rot[2] = z;
        rot[1] = y;
        *(f32 *)(moby + 0x70) = *(f32 *)(*(u8 **)(moby + 0x24) + 0x24) * 0.9f;
        *(u16 *)(moby + 0x34) |= 0x20;
        func_00470FD0(moby);
        func_L00_00621678(moby, 0);
        *(u128 *)(vars + 0x60) = *dir;
        *(s32 *)(vars + 0x80) = flag ^ 1;
        if (speed <= 0.0f) {
            *(f32 *)(vars + 0x84) = 0.0048f;
        } else {
            *(f32 *)(vars + 0x84) = speed;
        }
        *(s32 *)(vars + 0x88) = 0x7D;
        t = vars + 0x50;
        *(u8 **)(vars + 0x8C) = owner;
        *(u8 **)(vars + 0x34) = t;
        if (*(s32 *)(vars + 0x80) != 0) {
            func_00479EB8(moby, 0xFF808080);
            *(u32 *)(*(u8 **)(vars + 0x34) + 4) = 0xFF4080FF;
            *(u32 *)(*(u8 **)(vars + 0x34) + 8) = 0xFF808080;
            func_004778A8(moby, 4, 0xFF4080FF, 0);
            *(s32 *)(vars + 0x90) = 0;
        } else {
            *(u32 *)(t + 4) = 0xFF4080FF;
            *(s32 *)(*(u8 **)(vars + 0x34) + 8) = -0x7FC0;
            *(s32 *)(vars + 0x90) = 0;
        }
        *(s32 *)(vars + 0x98) = 0;
        *(u128 *)(vars + 0x70) = *target;
        *(f32 *)(vars + 0x9C) = arg6;
    }
    return moby;
}
