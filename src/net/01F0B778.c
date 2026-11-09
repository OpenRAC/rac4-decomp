/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xC4];
    s32 fC4;
    s32 fC8;
    s32 fCC;
};

s32 func_01F0C090(void *, s32);
extern s32 D_0019E698[];

s32 func_01F0B778(Type1 *arg0) {
    if (arg0->fCC > arg0->fC4) {
        func_01F0C090(D_0019E698, 0x211);
    }
    if (arg0->fC8 > arg0->fC4) {
        func_01F0C090(D_0019E698, 0x212);
    }
    return arg0->fC8;
}
