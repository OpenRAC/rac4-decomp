#include "common.h"
typedef struct {
    u8 f0;
    char p1[11];
} Type1;
typedef struct {
    char p0[0x2C];
    s32 f2C;
    char p30[12];
    Type1 *f3C;
    char p40[0x1C0];
} Type2;
extern Type2 D_00307254[];
extern s32 func_00505B20(void);
extern s32 func_00505328(u32, u32);

static inline u32 add(u32 a, u32 b)
{
    return a + b;
}

/* Chooses a color from the selected entry flag. */
void func_0049FAE0(void)
{
    s32 i = func_00505B20();
    Type2 *p = &D_00307254[i];
    s32 n = p->f2C;
    if (p->f3C[n].f0)
        func_00505328(add((u32)i << 6, add((u32)n << 1, 0x14000E)),
                      0x80808080);
    else
        func_00505328(add((u32)i << 6, add((u32)n << 1, 0x14000E)),
                      0x80404040);
}
