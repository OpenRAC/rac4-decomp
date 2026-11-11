/* Not matching yet: BYTES 8/120 (tools/try_func.py func_01F0639C --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(char *msg, s32 line);
extern char D_0019E200[];

/* Progress of the 0x260 counter against the 0x258 total, clamped by 0x254;
   a negative counter raises the 0x2C5 message and reports 0. */
f32 func_01F0639C(char *obj)
{
    s32 total = *(s32 *)(obj + 0x258);
    s32 done = *(s32 *)(obj + 0x254);
    s32 n = *(s32 *)(obj + 0x260);
    f32 r;

    if (done < total) {
        total = done;
    }
    if (n < 0) {
        func_01F0C090(D_0019E200, 0x2C5);
    }
    n = *(s32 *)(obj + 0x260);
    r = 0.0f;
    if (n > 0) {
        r = (f32)n / (f32)total;
    }
    return r;
}
