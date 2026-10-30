#include "common.h"

extern s32 func_00497580(s32 *arg0, s32 arg1, s32 arg2);
extern void func_004A1240(void *arg0, s32 arg1);

// Passes &saved (the word at 0x54) to func_00497580 with the words at 0x50 and 0x44; if it returns nonzero, calls func_004A1240(arg0, saved).
void func_004A1358(void *arg0) {
    s32 sp0 = *(s32 *)((u8 *)arg0 + 0x54);
    if (func_00497580(&sp0, *(s32 *)((u8 *)arg0 + 0x50), *(s32 *)((u8 *)arg0 + 0x44)) != 0) {
        func_004A1240(arg0, sp0);
    }
}
