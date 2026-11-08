#include "common.h"

extern f32 func_00453B10(f32, f32);
extern f32 func_00475C68(f32, f32, u8 *);
extern void func_00475740(f32 *vel, f32 d, f32 a, f32 b, f32 c);
extern f32 func_00453B10(f32 a, f32 b);

/* from rac3-decomp's func_L01_00448728 */
f32 func_00475D98(f32 *pos, f32 *vel, s32 mode, f32 target, f32 a, f32 b, f32 c) {
    f32 d;
    if (mode == 2) {
        if ((target > 0.0f && *pos < 0.0f) || (target < 0.0f && *pos > 0.0f)) {
            if (target < 0.0f) {
                mode = -1;
            } else {
                mode = 1;
            }
        } else {
            mode = 0;
        }
    }
    func_00475740(vel, ((f32 (*)(f32 target, f32 pos, s32 mode))func_00475C68)(target, *pos, mode), a, b, c);
    *pos = func_00453B10(*pos, *vel);
    d = ((f32 (*)(f32 target, f32 pos, s32 mode))func_00475C68)(target, *pos, mode);
    if (__builtin_fabsf(d) < c * 0.01f) {
        *pos = target;
        *vel = 0.0f;
        return *vel;
    }
    return d;
}
