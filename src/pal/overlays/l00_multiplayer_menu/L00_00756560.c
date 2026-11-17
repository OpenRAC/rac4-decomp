#include "common.h"
extern s32 func_L00_0070D100(s32, s32, s32);
extern void func_L00_0070D160(s32, s32);
extern s32 func_L00_007566F0(s32, void *, s32);
extern s32 D_00223508;
void func_L00_00756560(void) {
    s32 handle = func_L00_0070D100((s32)func_L00_007566F0, 0, 0);
    D_00223508 = handle;
    func_L00_0070D160(handle, 1);
}
