#include "common.h"
extern char D_0031B9B8[];
extern s32 func_004E21D8(s32, s32, void *);
extern void func_004E0858(void);
extern s32 D_00171B40[];
extern s32 func_00475858(f32, s32 *, s32, s32);
extern void func_004979A8(void *, s32, s32);
extern void func_004E19D8(s32, void *);
extern void func_00497980(s32);
void func_004D5550(void)
{
    char *p = D_0031B9B8;
    if (*(u8 *)(p + 0x13B1)) {
        *(u8 *)(p + 0x13B1) = 0;
        *(s32 *)(p + 0x13AC) = func_004E21D8(30, 4, 0);
        func_004E0858();
    }
    if (func_00475858(0.1f, (s32 *)(p + 0x1388), D_00171B40[0], 1)) {
        func_004979A8(p + 0x1378, *(s32 *)(p + 0x1388), 0);
    } else {
        func_004E19D8(30, 0);
        if (*(u8 *)(p + 0x13B0)) {
            func_00497980(32);
            *(u8 *)(p + 0x13B0) = 0;
        }
        *(s32 *)(p + 4) &= ~4;
    }
}
