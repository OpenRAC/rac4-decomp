#include "common.h"

extern s32 func_00505B20(void);
extern void func_004A13A0(void *, f32 *, f32 *, f32 *, f32 *);
extern void func_0049BFC0(s32, s32, s32, f32, f32, f32, f32);
extern void func_0049C248(s32, s32);
extern char D_0031E898[];
u8 D_0021FC10 = 0;

/* Refresh or hide the current rectangle and clear its pending bit. */
void func_004D78F0(void)
{
    f32 a, b, c, d;
    s32 index = func_00505B20();
    char *p = D_0031E898 + index * 0x528;
    if (D_0021FC10) {
        func_004A13A0(p + 0x4BC, &a, &b, &c, &d);
        func_0049BFC0(index, 0, 0, a, b, c, d);
    } else {
        func_0049C248(index, 0);
    }
    *(s32 *)(p + 4) &= ~2;
}
