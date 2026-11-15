#include "common.h"

extern void func_0049BFC0(s32, s32, s32, f32, f32, f32, f32);
extern void func_0049C290(s32 param, s32 count);
extern void func_004A13A0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_00505B20(void);
extern u8 D_0030B9D8[];

// Fetches the current block's vector, passes it on, and clears bit 0 of the block's flag word.
void func_004C5FC8(void) {
    f32 v[4];
    s32 idx = func_00505B20();
    s32 off = idx * 0xB30;
    u8 *base = (u8 *)(off + (s32)D_0030B9D8);

    func_004A13A0(base + 0xAB4, &v[0], &v[1], &v[2], &v[3]);
    func_0049BFC0(idx, 0, 0, v[0], v[1], v[2], v[3]);
    func_0049C290(idx, 1);
    *(s32 *)(off + (s32)D_0030B9D8 + 0x10) &= ~1;
}
