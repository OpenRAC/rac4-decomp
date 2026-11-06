/* cflags: -fno-opt-stack */
#include "common.h"

extern const f32 D_001A3A20[];
extern const f32 D_001A3A08[];
extern f32 func_00147DE0(f32 value);

f32 func_001501B0(f32 value, f32 scale)
{
    s32 band;
    for (band = 0; band < 5; ++band) {
        if (D_001A3A20[band] < value) {
            break;
        }
    }
    return (D_001A3A08[band] + func_00147DE0(scale) * 0.5f) +
           -5.045318603515625f;
}
