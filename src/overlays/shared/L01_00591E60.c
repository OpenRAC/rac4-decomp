#include "common.h"
extern f32 func_L00_005BD030(f32, f32);
extern f32 func_L00_005BCE00(f32);
extern f32 func_L00_005BCFE8(f32, f32);
f32 func_L01_00591E60(f32 arg0, f32 arg1, f32 arg2) {
    f32 temp = func_L00_005BD030(arg1, arg0);
    f32 angle = func_L00_005BCE00(arg2 * 3.1415927f);
    return func_L00_005BCFE8(arg0, temp * ((1.0f - angle) * 0.5f));
}
