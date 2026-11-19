/* Not matching yet: BYTES 2/192 (tools/try_func.py func_01F06188 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xC0];
    s32 fC0[100];
    s32 f250;
    char _p254[0x4];
    s32 f258;
    s32 f25C;
};

void func_01F0C090(void *, s32);
extern s32 D_0019E200[];

s32 func_01F06188(Type1 *arg0, s32 arg1) {
    if (arg0->f250 >= 0x65) {
        func_01F0C090(D_0019E200, 0x290);
    }
    if (arg0->f258 > arg0->f250) {
        func_01F0C090(D_0019E200, 0x291);
    }
    if (arg1 >= arg0->f258) {
        func_01F0C090(D_0019E200, 0x292);
    }
    if (arg0->fC0[arg1] == 0) {
        func_01F0C090(D_0019E200, 0x293);
    }
    return arg1 == arg0->f25C;
}
