/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0011AB04(u8 *);
extern s32 func_00122020(s8 *, void *);
extern s32 func_0012B740(s32, s32, s32);
extern s32 func_0012B980(s32, void *, s32);
extern s8 D_004B03F0[];

// Reads a line into arg1 from the handle at 0x1C, trims it at the first LF, and returns the length of the part it measured.
s32 func_L00_0053C7A0(void *arg0, s8 *arg1, s32 arg2) {
    s32 n;
    s32 base;
    s32 result = 0;

    *arg1 = 0;
    if (arg2 <= 0) {
        return 0;
    }
    base = func_0012B740(*(s32 *)((u8 *)arg0 + 0x1C), 0, 1);
    if (base == -1) {
        return 0;
    }
    if (func_0012B980(*(s32 *)((u8 *)arg0 + 0x1C), arg1, arg2 - 1) <= 0) {
        return 0;
    }
    n = func_00122020(arg1, D_004B03F0);
    if (arg1[n] == 10) {
        n++;
    }
    arg1[n] = 0;
    if (*arg1 != 0) {
        result = func_0011AB04(arg1);
    }
    return (~func_0012B740(*(s32 *)((u8 *)arg0 + 0x1C), base + n, 0) == 0) ? 0 : result;
}
