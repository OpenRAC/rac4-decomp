/* cflags: @ee296 -O2 -G0 -fno-gcse */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x11C];
    s8 f11C;
};

s32 func_0011AE00(void *, s8 *, s32);
extern s8 D_00169CF8[];
extern s8 D_00169D10[];
extern s32 D_001BC8C4[];
extern s32 D_001BC8C8[];
extern s32 (*D_001BCABC)(void *, s32);
extern s32 (*D_001BCAC0)(void *, s32);

s32 func_01EDC318(s32 arg0, s32 arg1, s32 arg2, Type1 *arg3) {
    if (func_0011AE00(arg3, D_00169CF8, 0x15) == 0) {
        if (arg3->f11C != 0) {
            D_00169CF8[0] = 0;
        }
        if (D_001BCABC != NULL) {
            D_001BCABC(arg3, D_001BC8C4[0]);
        }
    } else if (func_0011AE00(arg3, D_00169D10, 0x15) == 0) {
        if (arg3->f11C != 0) {
            D_00169D10[0] = 0;
        }
        if (D_001BCAC0 != NULL) {
            D_001BCAC0(arg3, D_001BC8C8[0]);
        }
    }
    return 0x120;
}
