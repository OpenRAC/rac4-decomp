#include "common.h"

extern s32 func_004AF740(s32);
extern void func_005014B0(s32);
extern u32 D_002216E0;

/* Passes func_004AF740(i) to func_005014B0 and clears bit i of D_002216E0. */
void func_004AF948(s32 i) {
    func_005014B0(func_004AF740(i));
    D_002216E0 &= ~(1 << i);
}
