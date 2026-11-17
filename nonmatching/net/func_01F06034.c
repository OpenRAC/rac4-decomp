/* Not matching yet: BYTES 74/192 (tools/try_func.py func_01F06034 --diff) (tools/try_func.py func_01F06034 --diff). Not part of the build. */
/* cflags: -fno-gcse */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xc0];
    s32 fC0[0x64];
    s32 f250;
    char _p254[0x4];
    s32 f258;
};

void func_01F0C090(void *, s32);
extern s32 D_0019E200;

s32 func_01F06034(Type1 *arg0, s32 arg1) {
    s32 n;
    s32 i;
    s32 *p;
    s32 m;

    if (arg0->f250 >= 0x65) {
        func_01F0C090(&D_0019E200, 0x273);
    }
    n = arg0->f258;
    if (arg1 < n) {
        if (arg0->fC0[arg1] == 0) {
            return 0;
        }
        p = &arg0->fC0[arg1];
        for (i = arg1; i < n - 1; i++) {
            *p = p[1];
            p++;
        }
        m = arg0->f258;
        arg0->f258 = m - 1;
        arg0->fC0[m] = 0;
        return 1;
    }
}
