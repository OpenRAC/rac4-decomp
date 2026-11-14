/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_005285C8(s32 a0);
extern void func_0052DD28(void *a0, s32 a1);
extern s32 func_L00_00528568(void);
extern void func_L00_0052DB78(void *a0, s32 a1, s32 a2);
extern void func_L00_0052DC08(void *a0, s32 a1, s32 a2, void *a3);
extern void func_L00_0052DCC0(void *a0);
extern s32 func_L00_0052E1A0(void *a0, s32 a1);

// Gathers a record for arg0 through the helpers, then calls the callback arg3 (or the default) on it and stores its 32-bit field into *arg5 when given.
s32 func_L00_00517130(s32 arg0, u8 *arg1, s32 arg2, s32 (*arg3)(void *, s32), s32 arg4, s64 *arg5) {
    s32 loc[0x10];
    s32 r;

    func_L00_0052DC08(loc, arg2, **(s32 **)(arg1 + 4), arg1);
    if (func_005285C8(arg0) >= 0) {
        func_0052DD28(loc, func_005285C8(arg0));
    }
    func_L00_0052DB78(loc, func_L00_00528568(), arg0);
    if (arg3 != 0) {
        r = arg3(loc, arg4);
    } else {
        r = func_L00_0052E1A0(loc, arg4);
    }
    if (arg5 != 0) {
        *arg5 = (s64) loc[9];
    }
    func_L00_0052DCC0(loc);
    return r;
}
