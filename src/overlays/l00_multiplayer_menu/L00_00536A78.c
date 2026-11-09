#include "common.h"

extern s32 func_L00_00545F88(s32, s32, s32, s32, s32);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);

s32 func_L00_00536A78(s32 arg0, s32 arg1, s32 arg2) {
    s32 r = func_L00_00545F88(arg0, arg1, arg2, 4, 0);
    if (r == 0) {
        func_L00_004F84C8(0xD, 0x82, 4, 0, 0);
        return 0;
    }
    return r;
}
