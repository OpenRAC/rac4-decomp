/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x250];
    s32 f250;
    s32 f254;
    s32 f258;
    char _p25C[0x4];
    s32 f260;
};

void func_01F0C090(void *, s32);
extern s32 D_0019E200[];

s32 func_01F06248(Type1 *arg0) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v1;

    if (arg0->f250 >= 0x65) {
        func_01F0C090(D_0019E200, 0x29A);
    }
    if (arg0->f258 > arg0->f250) {
        func_01F0C090(D_0019E200, 0x29B);
    }
    temp_v1 = arg0->f258;
    temp_v0 = arg0->f254;
    temp_a1 = arg0->f260;
    if (temp_v0 < temp_v1) {
        if ((temp_v1 - temp_v0) < temp_a1) {
            func_01F0C090(D_0019E200, 0x29E);
        }
    } else if (temp_a1 >= temp_v1) {
        func_01F0C090(D_0019E200, 0x2A2);
    }
    return arg0->f260;
}
