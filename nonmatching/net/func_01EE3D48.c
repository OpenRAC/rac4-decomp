/* Not matching yet: BYTES 10/104 (tools/try_func.py func_01EE3D48 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0, f4, f8, fC, f10; } Blk;
extern void *(*D_0016AC68)(s32);

void *func_01EE3D48(u32 n) {
    u32 v;
    s32 m;
    Blk *p;

    v = n;
    if (v < 0x20) {
        v = 0x20;
    }
    m = v - (v & 7);
    v = m + 8;
    p = D_0016AC68(m + 0x20);
    if (p == 0) {
        return 0;
    }
    p->f8 = -1;
    p->f10 = 0;
    p->f4 = 0;
    p->fC = -1;
    p->f0 = v;
    return p;
}
