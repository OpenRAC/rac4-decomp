/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

typedef void (*Fn)(s32, s32, s32, s32, s32, s32, u8 *);
typedef struct {
    char _p0[0xA0];
    s32 fA0;
    char _pA4[0x10];
    Fn fB4;
} Type1;
s32 func_01EC6728(Type1 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    if (arg0->fB4 != NULL) {
        s32 a = arg2[0];
        s32 b = arg2[1];
        s32 c = arg2[2];
        s32 d = arg2[3];
        arg2 += 4;
        arg0->fB4(arg0->fA0, a, b, c, d, arg3 - 4, arg2);
    }
    return 0;
}
