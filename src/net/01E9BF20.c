/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01E9B788(void *,s32,void *,s32,s32);
extern s32 func_01E9B890(void *,s32,void *,s32,s32);

/* Stores a word count, sends a request with command 0xB and reads the reply word back. */
s32 func_01E9BF20(void *a0, s32 *a1, s32 a2, s32 a3) {
    s32 r;
    s32 n;
    s32 m;

    r = a3;
    *a1 = r;
    r = func_01E9B788(a0, 0xB, a1, 4, (r << 4) + 4);
    if (r < 0) {
        return -0x21E;
    }
    n = *a1;
    m = n << 4;
    if (n < 0) {
        return n;
    }
    r = func_01E9B890(a0, a2, a1, 1, m);
    if (r >= 0) {
        r = *a1;
    }
    return r;
}
