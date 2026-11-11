#include "common.h"

typedef int u128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x1C];
    f32 (*getA)(s32);
    u8 pad20[0x18];
    f32 (*getB)(s32);
} Ops;

extern s16 func_00472590(s32, s32);
extern void func_L01_00591C70(u8 *, s32);
extern void func_L01_00501078(u128 *, u8 *);
extern f32 func_00453B10(f32, f32);
extern f32 func_00453BF8(f32, f32);
extern s32 func_00453508(s16 *);
extern void func_L01_00500888(u8 *);

void func_L01_005008D8(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    u128 v;
    s32 first;
    u8 f;
    f32 a;
    f32 b;

    f = moby[0xBE];
    if ((f ^ 1) & 1) {
        moby[0xBE] = f | 1;
        first = 1;
    } else {
        first = 0;
    }
    if (first) {
        *(s32 *)(vars + 0x174) = 0;
        *(s16 *)(vars + 0x1F6) = func_00472590(2, 4);
        func_L01_00591C70(moby, 0);
    }
    switch (moby[0x67]) {
    case 0:
        f = moby[0xBE];
        if (!(f & 0x20)) {
            moby[0xBE] = f | 0x20;
            first = 1;
        } else {
            first = 0;
        }
        if (first) {
            func_L01_00501078(&v, moby);
            *(u128 *)(vars + 0x190) = v;
        }
        a = (*(Ops **)(vars + 0x204))->getA(*(s32 *)(vars + 0x1D8));
        if (func_00453BF8(a, func_00453B10(*(f32 *)(vars + 0x178), *(f32 *)(vars + 0x198))) < 0.034906585f) {
            b = (*(Ops **)(vars + 0x204))->getB(*(s32 *)(vars + 0x1D8));
            if (func_00453BF8(b, func_00453B10(*(f32 *)(vars + 0x174), *(f32 *)(vars + 0x194))) < 0.034906585f) {
                func_L01_00591C70(moby, 1);
            }
        }
        break;
    case 1:
        f = moby[0xBE];
        if (!(f & 0x20)) {
            moby[0xBE] = f | 0x20;
            first = 1;
        } else {
            first = 0;
        }
        if (first) {
            *(s16 *)(vars + 0x1F4) = func_00472590(0x14, 0x5A);
        }
        if (func_00453508((s16 *)(vars + 0x1F4)) != 0) {
            if (func_00453508((s16 *)(vars + 0x1F6)) != 0) {
                func_L01_00500888(moby);
            } else {
                func_L01_00591C70(moby, 0);
            }
        }
        break;
    }
}
