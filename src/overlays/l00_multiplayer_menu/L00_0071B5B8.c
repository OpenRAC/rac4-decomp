/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 func_L00_0071B7D0(void *, s32);
extern s32 func_L00_0071B850(void *, s32);
extern void func_L00_0071B8E8(void *, s32, s32);
extern s32 func_L00_0071B9B0(void *arg0);
extern void func_L00_0071C000(void *arg0, s32 arg1);
extern u8 *D_00220D14;

/* Handles a menu input event; returns whether it was consumed. */
s32 func_L00_0071B5B8(void *arg0, s32 arg1) {
    s32 r;
    func_L00_0071B9B0(arg0);
    if (arg1 == 2) {
        r = func_L00_0071B7D0(arg0, -1);
        if (r != -1) {
            func_L00_0071C000(arg0, 0);
        }
        func_L00_0071B8E8(arg0, r, 2);
        return 1;
    }
    if (arg1 == 1) {
        r = func_L00_0071B850(arg0, -1);
        if (r != -1) {
            func_L00_0071C000(arg0, 0);
        }
        func_L00_0071B8E8(arg0, r, 1);
        return 1;
    }
    if (arg1 == 5) {
        *(s32 *)(D_00220D14 + 0x118) = 0x2A;
        return 1;
    }
    return 0;
}
