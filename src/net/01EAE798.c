/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01EAE638(s32, s32, u8 *, u8 *);
u32 func_01EAE798(s32 a, s32 b, u8 *src, u8 *dst, u32 len) {
    u32 done = 0;
    while (len >= 64) {
        func_01EAE638(a, b, src, dst);
        src += 64;
        dst += 64;
        len -= 64;
        done += 64;
    }
    return done;
}
