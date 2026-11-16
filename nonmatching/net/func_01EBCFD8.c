/* Not matching yet: BYTES 21/136 (tools/try_func.py func_01EBCFD8 --diff) (tools/try_func.py func_01EBCFD8 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;

struct Type1 {
    char _p0[0x184];
    u8 *f184;
    char _p188[0x19C - 0x188];
    u16 f19C;
};

s32 func_01EBCFD8(Type1 *arg0, u16 arg1, u16 arg2) {
    u32 a1 = arg1;
    u32 a2 = arg2;
    u16 n;
    u32 *p;
    u32 mask;
    u32 v;
    u32 i;
    s32 r = 2;

    if (arg0 != NULL) {
        n = arg0->f19C;
        if (a1 < n && a2 < n) {
            p = *(u32 **)((u8 *)arg0->f184 + ((a1 * 5) << 4) + 0x4C);
            mask = 1 << (a2 & 0x1F);
            i = (a2 >> 5) + 1;
            v = p[i];
            if (!(mask & v)) {
                p[i] = v | mask;
                p[0]++;
            }
            r = 0;
        }
    }
    return r;
}
