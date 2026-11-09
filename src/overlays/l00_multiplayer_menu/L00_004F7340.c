/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    char _p0[0xC];
    s32 fC;
    s32 f10;
    s32 f14;
    char _p18[0x1C - 0x18];
    s32 f1C;
} Type1;

void func_L00_00566440(s32, s32);

s32 func_L00_004F7340(Type1 *arg0) {
    if (arg0 == 0) {
        return 0;
    }
    if (arg0->f10 != 0) {
        if (arg0->fC != 0) {
            func_L00_00566440(arg0->f1C, 2);
            func_L00_00566440(arg0->f1C, 2);
        }
        arg0->fC = 0;
        arg0->f14 = 0;
    }
    return 1;
}
