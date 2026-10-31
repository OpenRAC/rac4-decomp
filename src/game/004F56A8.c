#include "common.h"

extern void func_004F2680();
extern s32 func_004534D0(void *);
extern u8 D_328990[];

// Run func_004F2680 once and set the flag at +0x50, then return whether the masked result is nonzero.
s32 func_004F56A8(s32 arg0) {
    u8 *p = D_328990;
    if (p[0x50] == 0) {
        func_004F2680();
        p[0x50] = 1;
    }
    return (func_004534D0(p + 0x4C) & arg0) != 0;
}
