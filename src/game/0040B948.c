/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 *buf; s32 len; } Req;
s32 func_0040BA40(s32, Req *);
s32 func_0040B948(s32 a0, u16 *out) {
    Req r;
    u8 b[2];
    s32 e;
    r.buf = b;
    r.len = 2;
    e = func_0040BA40(a0, &r);
    if (e == 0) {
        *out = (b[0] << 8) | b[1];
    }
    return e;
}
