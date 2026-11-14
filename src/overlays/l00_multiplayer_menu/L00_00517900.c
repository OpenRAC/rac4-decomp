/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type2 {
    s32 f0;
    s32 f4;
} Type2;

typedef struct Type1 {
    u8 pad0[0x14];
    s32 f14;
    s32 pad18;
    Type2 *f1C;
} Type1;

extern void func_L00_005195A8();
extern s32 func_L00_0051B210();

/* type 3 returns 10001 when the check on the child passes; other types forward to the child */
s32 func_L00_00517900(Type1 *arg0) {
    s32 result;

    result = 0;
    if (arg0->f14 == 3) {
        if (func_L00_0051B210(arg0->f1C) == 0) {
            result = 0x2711;
        }
    } else {
        func_L00_005195A8(arg0->f1C->f4);
    }
    return result;
}
