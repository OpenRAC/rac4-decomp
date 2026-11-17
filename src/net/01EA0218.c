/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 b[8]; } A8;
typedef struct { s32 f0; A8 f4; s32 fC; s32 f10; A8 f14; s32 f1C; } NetCfg;
typedef struct { char _p0[0x84]; s32 f84; } Iface;
extern s32 func_01EA8BA0(A8);
extern s32 func_01EA7D48(A8 *);
extern s32 func_01EA42D8(s32);
extern NetCfg D_001AF8F8;
extern Iface *D_00167F40;
s32 func_01EA0218(A8 *a) {
    s32 r;
    *a = D_001AF8F8.f14;
    if (func_01EA8BA0(*a) != 0) {
        r = func_01EA42D8(func_01EA7D48(a));
        if (r != 0) {
            return r;
        }
        D_001AF8F8.f14 = *a;
        D_001AF8F8.f10 = 2;
        if (D_00167F40 != 0) {
            D_001AF8F8.f1C = D_00167F40->f84;
        }
    }
    return 0;
}
