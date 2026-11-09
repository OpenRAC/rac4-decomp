/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 func_L00_005E60D0(s32, s32);
extern void func_L01_0056E4B0(void *, void *, void *);
extern u8 *D_00222DA0[];

void func_L01_0056E200(void *arg0, void *arg1, void *arg2) {
    s32 count = *(s16 *)((u8 *)arg0 + 0x12);
    if (count > 0) {
        s32 index = func_L00_005E60D0(0, count - 1);
        s32 *entries = *(s32 **)((u8 *)arg0 + 0x20);
        s32 value = entries[index];
        func_L01_0056E4B0(D_00222DA0[0] + (value << 7), arg1, arg2);
    }
}
