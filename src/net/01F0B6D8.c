/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xC4];
    s32 fC4;
    s32 fC8;
    s32 fCC;
    char _pD0[0x4];
    s32 fD4;
};

void func_01F0C090(void *, s32);
extern s32 D_0019E698;

s32 func_01F0B6D8(Type1 *arg0) {
    s32 temp_a1;
    s32 temp_v0;

    if (arg0->fCC > arg0->fC4) {
        func_01F0C090(&D_0019E698, 0x202);
    }
    temp_v0 = arg0->fC8;
    temp_a1 = arg0->fD4;
    if (temp_v0 < arg0->fCC) {
        if ((arg0->fCC - temp_v0) < temp_a1) {
            func_01F0C090(&D_0019E698, 0x205);
        }
    } else if (temp_a1 >= arg0->fCC) {
        func_01F0C090(&D_0019E698, 0x209);
    }
    return arg0->fD4;
}
