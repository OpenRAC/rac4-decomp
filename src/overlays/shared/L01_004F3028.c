/* cflags: -ffast-math */
#include "common.h"
extern f32 func_00473FE8(s32, s32, s32, f32, f32);
extern s32 func_00445488(void);
extern s32 func_L01_004F3100(s32);
extern s32 func_L01_004F32A8(s32);
f32 func_L01_004F3028(s32 arg0, s32 *arg1, f32 arg2) {
    f32 r;
    s32 v;
    r = func_00473FE8(arg0, 0, 0, arg2, 4.0f);
    if (r == 0.0f) {
        if (arg1 != 0) *arg1 = -1;
        return 0.0f;
    }
    v = func_00445488();
    if (func_L01_004F3100(v)) {
        r -= 16.0f;
        r = r > 0.0f ? r : 0.0f;
    } else if (func_L01_004F32A8(v)) {
        r -= 0.3f;
        r = r > 0.0f ? r : 0.0f;
    }
    if (arg1 != 0) *arg1 = v;
    return r;
}
