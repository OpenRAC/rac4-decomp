#include "common.h"

/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * rac3-decomp/src/levels/shared/L01_0046A938.c func_L01_0046ABC0.
 * Independently reconstructed from RAC4 PAL retail. */

typedef int Quad __attribute__((mode(TI)));
typedef struct {
    Quad direction;
    f32 rotation;
    f32 gravity;
    s32 lifetime;
} Motion;
extern u8 *func_00491450(s32);
extern s32 func_00472E40(s32);
extern f32 func_00472EB8(f32, f32);
extern u8 *D_00270AD0[];
u8 *func_00493D48(const Quad *position, const Quad *direction, s32 lifetime, f32 scale, f32 gravity)
{
    u8 *particle = func_00491450(46);
    Motion *motion;
    if (particle != 0) {
        *(Quad *)(particle + 0x10) = *position;
        motion = (Motion *)(particle + 0x20);
        *(u32 *)(particle + 4) = ((u32)(func_00472E40(10) + 38) << 24) | 0x808080;
        particle[9] = 33;
        particle[3] = 72;
        particle[1] = 1;
        particle[2] = *D_00270AD0[0];
        *(s16 *)(particle + 10) = 5;
        *(f32 *)(particle + 12) = scale * 210000.0f;
        motion->direction = *direction;
        motion->rotation = func_00472EB8(0.0f, 256.0f);
        particle[8] = (s32)motion->rotation;
        motion->gravity = gravity;
        motion->lifetime = lifetime;
    }
    return particle;
}
