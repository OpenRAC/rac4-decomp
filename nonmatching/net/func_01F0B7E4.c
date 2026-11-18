/* Not matching yet: BYTES 7/180 (tools/try_func.py func_01F0B7E4 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xC0];
    s32 *fC0;
    s32 fC4;
    s32 fC8;
    s32 fCC;
};

s32 func_01F0C090(void *, s32);
extern s32 D_0019E698[];

s32 func_01F0B7E4(Type1 *arg0, s32 arg1) {
    if (arg0->fCC > arg0->fC4) {
        func_01F0C090(D_0019E698, 0x219);
    }
    if ((arg1 < 0) || (arg1 >= arg0->fCC)) {
        func_01F0C090(D_0019E698, 0x21A);
    }
    if (arg0->fC0[arg1] == 0) {
        func_01F0C090(D_0019E698, 0x21B);
    }
    return arg0->fC0[arg1];
}
