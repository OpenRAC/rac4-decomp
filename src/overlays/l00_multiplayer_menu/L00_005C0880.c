#include "common.h"

extern void func_L00_005BD860(s32 arg0);
extern s32 func_L00_005BDC90(s32 arg0, s32 arg1, f32 arg2);
extern s32 D_0021DEC4;

/* Calls two helpers with the saved global as the last argument and returns the middle result. */
s32 func_L00_005C0880(s32 arg0, s32 arg1, f32 fparg0) {
    s32 temp_s0;
    s32 temp_s2;

    temp_s2 = D_0021DEC4;
    func_L00_005BD860(0);
    temp_s0 = func_L00_005BDC90(arg0, arg1, fparg0);
    func_L00_005BD860(temp_s2);
    return temp_s0;
}
