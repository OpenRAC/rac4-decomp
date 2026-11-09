/* cflags: @ee296 -O2 -G0 -fno-gcse */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x11C];
    s8 f11C;
};

extern s32 D_00169D28;
extern s32 D_001BC918;
extern s32 (*D_001BCB10)(void *, s32);

s32 func_01EDD4D0(s32 arg0, s32 arg1, s32 arg2, Type1 *arg3) {
    if (arg3->f11C == 1) {
        D_00169D28 |= 2;
    }
    if (D_001BCB10 != NULL) {
        D_001BCB10(arg3, D_001BC918);
    }
    return 0x120;
}
