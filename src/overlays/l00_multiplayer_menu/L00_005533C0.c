/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s64 f0;
    u8 *f8;
    u8 pad[0xA];
    u8 f16;
    u8 f17;
} Type1;

extern s32 func_L00_00553590(Type1 *arg0, s32 arg1);

/* Reads a big-endian signed integer of up to 8 bytes into *out. */
s32 func_L00_005533C0(Type1 *arg0, s64 *out) {
    s32 r;
    u32 n;
    u32 i;
    u8 *p;
    u8 c;
    s64 v;

    r = func_L00_00553590(arg0, 2);
    if (r != 0) {
        return r;
    }
    i = (arg0->f16 >> 2) & 1;
    n = arg0->f0;
    if (n == 0) {
        *out = 0;
        return 0;
    }
    if (n > 8) {
        return 9;
    }
    p = arg0->f8;
    if (i) {
        c = arg0->f17;
    } else {
        c = *p++;
    }
    v = (c & 0x80) ? -0x100 : 0;
    for (i = 1; v |= c, i < n; i++) {
        c = *p++;
        v <<= 8;
    }
    *out = v;
    return 0;
}
