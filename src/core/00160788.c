#include "common.h"

extern s32 func_0011AB04(u8 *);
extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);

extern u8 D_00172160[];
u8 *D_0021DFE8 = 0;
extern u8 D_0021E008[];

s32 func_00160788(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    u8 *base;
    s32 i;

    base = D_00172160;
    if (*(s32 *)(base + 0x10) == arg3[4]) {
        s32 v;
        v = *(s32 *)arg3;
        base[0x634] = 0;
        *(s32 *)(base + 0x638) = v;
    }
    if (*(s32 *)arg3 == 1) {
        for (i = 0; i < 10; i++) {
            if (func_0011AB04(arg3 + 5 + i * 16) != 0) {
                func_0011D920(D_0021DFE8 + i * 16, D_0021E008, arg3 + 5 + i * 16);
                func_0011D920(D_0021DFE8 + 0xA0 + i * 8, D_0021E008, arg3 + 0xA5 + i * 8);
            }
        }
    }
    return 0xF8;
}
