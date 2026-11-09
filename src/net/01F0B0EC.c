/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xC4];
    s32 fC4;
    char _pC8[0x4];
    s32 fCC;
};

s32 func_01F0C090(void *, s32);
extern s32 D_0019E698[];

s32 func_01F0B0EC(Type1 *arg0) {
    if (arg0->fCC > arg0->fC4) {
        func_01F0C090(D_0019E698, 0x113);
    }
    if (arg0->fCC < 0) {
        func_01F0C090(D_0019E698, 0x114);
    }
    return arg0->fCC;
}
