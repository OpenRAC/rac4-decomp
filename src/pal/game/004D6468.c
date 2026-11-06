#include "common.h"
extern char D_0031B9B8[];
extern s32 func_004E3138(s32, s32, void *);
extern void func_004E17B8(void);
extern s32 D_00171BC0[];
extern s32 func_00476138(f32, s32 *, s32, s32);
extern void func_00498618(void *, s32, s32);
extern void func_004E2938(s32, void *);
extern void func_004985F0(s32);
void func_004D6468(void)
{
    char *p = D_0031B9B8;
    if (*(u8 *)(p + 0x13B1)) {
        *(u8 *)(p + 0x13B1) = 0;
        *(s32 *)(p + 0x13AC) = func_004E3138(30, 4, 0);
        func_004E17B8();
    }
    if (func_00476138(0.1f, (s32 *)(p + 0x1388), D_00171BC0[0], 1)) {
        func_00498618(p + 0x1378, *(s32 *)(p + 0x1388), 0);
    } else {
        func_004E2938(30, 0);
        if (*(u8 *)(p + 0x13B0)) {
            func_004985F0(32);
            *(u8 *)(p + 0x13B0) = 0;
        }
        *(s32 *)(p + 4) &= ~4;
    }
}
