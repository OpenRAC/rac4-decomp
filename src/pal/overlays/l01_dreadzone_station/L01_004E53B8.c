#include "common.h"

extern s32 func_L01_004E56E8(void);
extern void func_L01_0059F8F8(u8 *, u8 *, s32, f32, f32);
extern void func_00487920(u8 *);

// Unless func_L01_004E56E8 returns non-zero, counts up the halfword at +0x6A (stopping at
// 0xFFFF), calls func_L01_0059F8F8 on +0x4A0 of the object's +0xAC block, then func_00487920.
void func_L01_004E53B8(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);

    if (func_L01_004E56E8() == 0) {
        if (*(u16 *)(arg0 + 0x6A) <= 0xFFFE) {
            *(u16 *)(arg0 + 0x6A) += 1;
        }
        func_L01_0059F8F8(arg0, vars + 0x4A0, 2, 0.0432f, 0.43200004f);
        func_00487920(arg0);
    }
}
