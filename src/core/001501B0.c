/* cflags: -fno-opt-stack */
#include "common.h"

extern const f32 D_001A39A0[];
extern const f32 D_001A3988[];
extern f32 func_00147DE0(f32 value);

f32 func_001501B0(f32 value, f32 scale)
{
    s32 band;
    for (band = 0; band < 5; ++band) {
        if (D_001A39A0[band] < value) {
            break;
        }
    }
    return (D_001A3988[band] + func_00147DE0(scale) * 0.5f) +
           -5.045318603515625f;
}
