/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 (*D_001681A4)();
extern s32 func_0011EF60(s32 id);

s32 func_01EA94D0(s32 *out, s64 id)
{
    s32 v;

    if (D_001681A4 == 0) {
        v = func_0011EF60((s32)id);
        *out = v;
        if (v != 0) {
            goto zero;
        }
        return 0x64;
    }
    v = D_001681A4((s32)id);
    *out = v;
    if (v == 0) {
        return 0x64;
    }
zero:
    return 0;
}
