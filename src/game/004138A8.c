/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_004033B0(s32 value);
s32 func_00413980(s32, s32, s32);
extern s32 func_00403440(s32);
s32 func_004138A8(s32 a0, s32 a1, s32 *out) {
    s32 r;
    s32 p = func_004033B0(a1);
    *out = p;
    if (p == 0) {
        return 0x258;
    }
    r = func_00413980(a0, a1, p);
    if (r != 0) {
        func_00403440(*out);
    }
    return r;
}
