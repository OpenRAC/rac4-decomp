#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 *D_00270AA4[];

extern u8 *func_00491450(s32);
extern f32 func_00472EB8(f32, f32);

// Takes a particle of type 0x23 from func_00491450 and fills it: position from pos, colour
// 0x80808080, 0x12 at +9 and 0x44 at +3, a random size between 10500 and 16800, the byte the
// pointer D_00270AA4 points to, dir, type and arg3, and a random rate between 0.0042 and 0.0072.
// Type 2 clears +0x38. Returns the particle or NULL.
u8 *func_004938D0(u128 *pos, u128 *dir, s32 type, s32 arg3) {
    u8 *p = func_00491450(0x23);
    u8 *vars;

    if (p != NULL) {
        vars = p + 0x20;
        *(u128 *)(p + 0x10) = *pos;
        p[1] = 0;
        *(u32 *)(p + 4) = 0x80808080;
        p[9] = 0x12;
        p[3] = 0x44;
        *(f32 *)(p + 0xC) = func_00472EB8(10500.0f, 16800.0f);
        p[2] = *D_00270AA4[0];
        *(u128 *)(p + 0x20) = *dir;
        *(s32 *)(vars + 0x14) = arg3;
        *(s32 *)(vars + 0x10) = type;
        *(f32 *)(vars + 0x18) = *(f32 *)(p + 0x18);
        if (type == 2) {
            *(s32 *)(vars + 0x18) = 0;
        }
        *(f32 *)(vars + 0x1C) = func_00472EB8(0.0042000003f, 0.0072000003f);
    }
    return p;
}
