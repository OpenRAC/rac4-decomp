#include "common.h"

extern s32 func_00498D70(void);
extern s32 func_00498D90(void);
extern void func_004B15E8(void);
extern void func_004B1678(void);
extern void func_00501730(s32 *group, s32 a, f32 value);
typedef struct Type1 {
    int f0, f4, f8;
    char p[0x2C];
    unsigned char f38;
} Type1;
extern Type1 D_00309650[];
extern s32 D_221728;

void func_004B11B8(void)
{
    s32 temp_s0;

    if (func_00498D90() != 0) {
        D_00309650[0].f38 = 1;
        temp_s0 = func_00498D70();
        if (!(temp_s0 < 5))
            temp_s0 = 4;
        if (temp_s0 != D_00309650[0].f4) {
            func_00501730(&D_221728, -1, 0.0f);
            D_00309650[0].f4 = temp_s0;
            func_004B15E8();
        }
        func_004B1678();
    }
}
