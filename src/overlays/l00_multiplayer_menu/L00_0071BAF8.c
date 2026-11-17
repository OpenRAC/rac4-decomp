#include "common.h"

extern s32 func_L00_0069EBA8(s32, s32, s32, s32);
extern s32 func_L00_0069DD58(s32, s32);
extern s32 D_004D76C0[];
s32 D_00220D6C = 0;

// Calls func_L00_0069EBA8 on the fields at 0x23C/0x240, pushes the D_004D76C0 entry at the counter, and steps the counter up.
void func_L00_0071BAF8(u8 *arg0) {
    func_L00_0069EBA8(*(s32 *)(arg0 + 0x23C), 1, 0, *(s32 *)(arg0 + 0x240));
    func_L00_0069DD58(D_004D76C0[D_00220D6C], *(s32 *)(arg0 + 0x240));
    D_00220D6C++;
}
