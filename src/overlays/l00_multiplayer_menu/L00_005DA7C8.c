#include "common.h"

extern s32 func_005545E0();
extern s32 func_00554600();
extern s32 func_L00_00556ED8(s32, s32, void *);
extern s32 func_L00_00556F28(s32, u32, s32);
extern s32 func_L00_005D9D80(s32, u32);

// Validate a range, set up a two-word header at arg0 and report status via *err.
s32 func_L00_005DA7C8(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 *err) {
    u32 sp;
    s32 r = 0;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;

    if (arg1 - (s32)arg0 != 8 || ((u32)arg0 & 3)) {
        *err = 8;
        return 8;
    }
    arg0[0] = 0;
    t1 = func_005545E0();
    *err = t1;
    if (t1 == 0) {
        u32 m = 0x80000000;
        t2 = func_L00_00556ED8(arg2, arg1, &sp);
        *err = t2;
        if (t2 & m) {
            r = 2;
        } else if ((u32)(arg3 - 8) < sp) {
            *err = sp;
            r = 7;
        } else {
            t3 = func_L00_00556F28(arg2, sp, arg1);
            *err = t3;
            if (t3 & m) {
                r = 3;
            } else {
                arg0[0] = sp;
                arg0[1] = func_L00_005D9D80(arg1, sp);
                *err = sp + 8;
            }
        }
        t4 = func_00554600();
        if (t4 < 0 && r == 0) {
            *err = t4;
            r = 6;
        }
    } else {
        r = 1;
    }
    return r;
}
