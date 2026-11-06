#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 *func_0046C1F0(s32, s32);
extern f32 func_00472EB8(f32, f32);
extern void func_00470FD0(u8 *);
extern void func_L01_0050E3D8(u8 *, s32);

// Creates a moby of class 0x2683 with 0xA0 bytes of data at pos for owner, with a random
// rotation, 0.9 times its class scale and flag 0x20; then stores flag ^ 1, dir, the speed (0.0048 when
// speed <= 0), 0x7D, colour 0xFF4080FF, arg4 and arg6 in its data. Returns the moby or NULL.
u8 *func_L01_0050E208(u8 *owner, u128 *pos, u128 *dir, s32 flag, s32 arg4, f32 speed, f32 arg6) {
    u8 *moby = func_0046C1F0(0x2683, 0xA0);
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
        func_L01_0050E3D8(moby, 0);
        *(u128 *)(vars + 0x60) = *dir;
        *(s32 *)(vars + 0x70) = flag ^ 1;
        if (speed <= 0.0f) {
            *(f32 *)(vars + 0x74) = 0.0048f;
        } else {
            *(f32 *)(vars + 0x74) = speed;
        }
        *(s32 *)(vars + 0x78) = 0x7D;
        t = vars + 0x50;
        *(u8 **)(vars + 0x34) = t;
        *(u8 **)(vars + 0x7C) = owner;
        *(u32 *)(t + 4) = 0xFF4080FF;
        *(s32 *)(*(u8 **)(vars + 0x34) + 8) = -0x7FC0;
        *(s32 *)(vars + 0x98) = 0;
        *(s32 *)(vars + 0x80) = 0;
        *(s32 *)(vars + 0x88) = 0;
        *(f32 *)(vars + 0x8C) = arg6;
        *(s32 *)(vars + 0x90) = arg4;
    }
    return moby;
}
