/* cflags: @ee296 -O1 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xBC];
    s32 fBC;
    char _pC0[0x4];
    s32 fC4;
    s32 fC8;
};

void func_01F02AE0(Type1 *arg0, s32 arg1, s32 arg2) {
    if (arg1 == -1) {
        s32 v = arg0->fC8 - arg2;
        if (v < 0) {
            v = 0;
        }
        arg0->fC8 = v;
    } else if (arg1 == 1) {
        s32 v = arg0->fC8;
        s32 b = arg0->fBC;
        s32 c = arg0->fC4;
        s32 lim;
        v += arg2;
        lim = c - b;
        arg0->fC8 = v < lim ? v : lim;
    }
}
