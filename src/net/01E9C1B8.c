/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01E9B788(void *, s32, void *, s32, s32);
s32 func_01E9C1B8(void *a, s32 *p, s32 *dst, s32 n, s32 cmd) {
    s32 i;
    if (func_01E9B788(a, cmd, p, 0, n * 4 + 4) < 0) {
        return -0x21E;
    }
    for (i = 0; i < n; i++) {
        dst[i] = p[i + 1];
    }
    return p[0];
}
