#include "common.h"
extern void func_L00_007145E0(void *, s32);
extern u8 D_004B9F90[];
void func_L00_0071EDF0(void *arg0, s32 arg1) {
    s32 count;
    s32 *entry;
    *(s32 *)((s8 *)arg0 + 0xAC) = 0;
    *(s32 *)((s8 *)arg0 + 0x58) = (s32)D_004B9F90;
    count = 0x5F;
    entry = (s32 *)((s8 *)arg0 + 0x22C);
    do {
        *entry = 0;
        count -= 1;
        entry -= 1;
    } while (count >= 0);
    *(s32 *)((s8 *)arg0 + 0x230) = -1;
    func_L00_007145E0(arg0, arg1);
}
