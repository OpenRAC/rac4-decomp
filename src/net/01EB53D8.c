/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_001694FC;
extern char D_001B26C0[];
extern char D_001B2700[];
extern s32 func_01E9CDC8(void *, void *, s32, s32, s32, s32 *, s32);
s32 func_01EB53D8(s32 a, s32 b, s32 c, s32 *out) {
    s32 local = 0;
    s32 r;
    if (D_001694FC == 0) {
        return 5;
    }
    if (a < 0) {
        return 2;
    }
    r = func_01E9CDC8(D_001B26C0, D_001B2700, a, b, c, &local, 0);
    if (r < 0) {
        return 50000;
    }
    *out = r;
    return 0;
}
