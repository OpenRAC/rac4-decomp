#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 mode;
    u8 pad8[0x18];
    f32 f20;
    u8 f24;
    u8 f25;
    u8 pad26[6];
    u8 f2C;
} Type1;

extern Type1 D_00309840;
extern f32 func_004757E0(f32 *value, f32 target, f32 fraction, f32 minimum);
extern void func_004B5080(void);
extern void func_004B5250(void);
extern void func_004B5380(void);
extern void func_005014B0(s32 *a0);

void func_004B4F40(s32 *a0)
{
    switch (D_00309840.mode) {
    case 2:
        if (func_004757E0(&D_00309840.f20, 1.0f, 0.0f, 0.05f) == 0.0f)
            D_00309840.mode = 0;
        else
            func_004B5380();
        break;
    case 1:
        D_00309840.mode = 0;
        D_00309840.f20 = 1.0f;
        break;
    case 4:
        if (func_004757E0(&D_00309840.f20, 0.0f, 0.0f, 0.05f) != 0.0f)
            func_004B5380();
        else
            D_00309840.mode = 3;
        break;
    case 3:
        D_00309840.f20 = 0.0f;
        func_005014B0(a0);
        break;
    case 0:
        D_00309840.f25 = 0;
        if (D_00309840.f2C)
            func_004B5080();
        func_004B5250();
        break;
    }
}
