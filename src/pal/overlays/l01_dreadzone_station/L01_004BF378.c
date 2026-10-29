#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 D_0039EC48[];

extern void func_00484A60(u8 *);
extern void func_00489328(u8 *, f32, f32, f32, f32);
extern void func_00489398(u8 *, f32, f32, f32, f32, f32, f32, f32);
extern void func_00489438(u8 *, f32, f32, f32);
extern void func_00484EB0(u8 *, void *, s32);
extern void func_00474368(u8 *, s32, s32);
extern s32 func_L01_004BFA10(u8 *);

// In state 0: sets up the object's movement and sound parameters, copies its position to +0x3B0
// of its block and sets state 1; when func_L01_004BFA10 is true, also clears +0x98, the byte at
// +0x31 and sets bits 0-1 of the halfword at +0x34. Returns 0 outside state 0, else 1.
s32 func_L01_004BF378(u8 *arg0) {
    u8 *vars;

    if (arg0[0x20] != 0) {
        return 0;
    }
    {
        vars = *(u8 **)(arg0 + 0xAC);
        func_00484A60(arg0);
        func_00489328(arg0, 0.7f, 0.1f, 0.8f, 1.5f);
        func_00489398(arg0, 0.0064000003f, 0.0064000003f, 0.026f, 0.11000001f, 0.0f, 0.0f, 0.0f);
        func_00489438(arg0, 0.0037699114f, 0.0037699114f, 0.06283186f);
        func_00484EB0(arg0, D_0039EC48, 0);
        *(s32 *)(vars + 0x50) |= 0x302;
        *(f32 *)(vars + 0x60) = 0.75f;
        *(f32 *)(vars + 0x64) = 1.25f;
        *(f32 *)(vars + 0x74) = 15.0f;
        *(u128 *)(vars + 0x3B0) = *(u128 *)(arg0 + 0x10);
        *(s32 *)(vars + 0x34C) = 0;
        arg0[0x30] = 0xFF;
        func_00474368(arg0, 1, 0);
        if (func_L01_004BFA10(arg0) != 0) {
            *(s32 *)(arg0 + 0x98) = 0;
            arg0[0x31] = 0;
            *(u16 *)(arg0 + 0x34) |= 3;
        }
    }
    return 1;
}
