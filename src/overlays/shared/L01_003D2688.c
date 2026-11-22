#include "common.h"

extern s32 D_002202CC;
extern s32 D_0021DE10;
extern f32 D_00222B8C;
extern void func_00414628(void *, s32);
extern s32 func_0043E130(void *);
extern s32 func_00472560(s32);
extern void func_00473A88(void *, s32, s32);
extern void func_0046BDD0(void *);

void func_L01_003D2688(void *arg0) {
    u8 *o = arg0;
    u8 *p;
    if (D_002202CC != 0) {
        func_00414628(o, D_002202CC);
    }
    p = *(u8 **)(o + 0xB8);
    if (p != 0) {
        u8 k = p[0x20];
        if (k == 0xFE) {
            *(u8 **)(o + 0xB8) = 0;
        } else if (k == 0xFD) {
            *(u8 **)(o + 0xB8) = 0;
        } else if (p[0x30] < o[0x30]) {
            *(u8 **)(o + 0xB8) = 0;
        }
    }
    switch (o[0x20]) {
    case 0:
        func_0043E130(o);
        if ((u32)(D_0021DE10 - 0x256B) >= 2) {
            if (func_0043E130(o) != 0 || (D_00222B8C > 0.95f && func_00472560(10) == 0)) {
                func_00473A88(o, 1, -1);
                *(u16 *)(o + 0x34) |= 0x2800;
            }
        }
        break;
    case 1:
        func_0043E130(o);
        if (o[0x23] < 2) {
            func_0046BDD0(o);
        } else {
            o[0x23] -= 2;
        }
        break;
    }
}
