#include "common.h"

extern s32 func_0045D888(s16);
extern void func_0045E3D0(s16, s16, s16, s32, f32, f32, f32, f32);
extern s16 D_0023F2AC[];

/* Queue an effect if its id is inactive and a free slot remains. */
s32 func_0045D7B0(s16 id, s16 a, s16 b, s32 c, f32 x, f32 y, f32 z, f32 w)
{
    if (!func_0045D888(id)) {
        if (id != -1 && D_0023F2AC[0] < 16) {
            func_0045E3D0(id, a, b, c, x, y, z, w);
            return 1;
        }
        return 0;
    }
    return 0;
}
