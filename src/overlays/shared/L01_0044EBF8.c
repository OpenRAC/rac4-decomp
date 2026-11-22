#include "common.h"

extern s32 D_00222B28;
extern f32 D_003A6910[];
extern void func_L01_0055A620(void *, void *, s32);
extern void func_L01_00559E08(void *, void *);

void func_L01_0044EBF8(void *obj) {
    u8 *p = *(u8 **)((u8 *)obj + 0xAC);
    if ((*(u16 *)((u8 *)obj + 0x34) & 1) == 0 && *((u8 *)obj + 0x23) != 0) {
        if (*((u8 *)obj + 0x20) == 2) {
            func_L01_0055A620(&D_00222B28, p + 0x380, 0x2D);
        } else {
            func_L01_0055A620(&D_00222B28, p + 0x380, 0x14);
        }
        D_003A6910[5] = *(f32 *)(p + 0x340) * 0.3f;
        D_003A6910[7] = *(f32 *)(p + 0x340) * 0.1f;
        func_L01_00559E08(&D_00222B28, p + 0x380);
    }
}
