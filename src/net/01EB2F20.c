/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA94D0(s32 *out, s64 id);

/* Allocate a 0x20-byte record through func_01EA94D0 and set its fields; NULL on failure. */
s32 *func_01EB2F20(void) {
    s32 *out;
    s32 *p;

    func_01EA94D0(&out, 0x20);
    p = out;
    if (p != 0) {
        p[0] = 0;
        p[3] = 1;
        p[1] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        p[2] = 0;
    }
    return p;
}
