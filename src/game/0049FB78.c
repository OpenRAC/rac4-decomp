#include "common.h"

extern s32 func_004976C8(s32 *value_ptr, s32 param_a, s32 mode, void (*before)(void), void (*after)(void), s32 param_b);
extern void func_004E0858(void);
extern s32 func_004E21D8(u32 index, s32 param_a, s32 param_b);
extern s32 func_00505B20(void);
extern void func_0049FAE0(void);
extern void func_0049FA38(void);
extern u8 func_0049F9F0(s32 arg0);
extern u8 D_307254[];

// Picks the 512-byte entry from func_00505B20 and runs the scheduler on it, then calls two helpers on success.
void func_0049FB78(s32 arg0) {
    u8 *temp_v0;

    temp_v0 = (u8 *) D_307254 + (func_00505B20() << 9);
    if (func_004976C8((s32 *) (temp_v0 + 0x2C), *(s32 *) (temp_v0 + 0x30), arg0, func_0049FAE0, func_0049FA38, (s32) func_0049F9F0) != 0) {
        func_004E21D8(0, 0, 0);
        func_004E0858();
    }
}
