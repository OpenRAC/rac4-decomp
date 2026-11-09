/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x250];
    s32 f250;
    char _p254[0x4];
    s32 f258;
    s32 f25C;
};

void func_01F0C090(void *, s32);
extern s32 D_0019E200;

s32 func_01F060F4(Type1 *arg0) {
    s32 temp_v1;

    if (arg0->f250 >= 0x65) {
        func_01F0C090(&D_0019E200, 0x287);
    }
    if (arg0->f258 > arg0->f250) {
        func_01F0C090(&D_0019E200, 0x288);
    }
    temp_v1 = arg0->f258;
    if ((arg0->f25C >= temp_v1) && (temp_v1 != 0)) {
        func_01F0C090(&D_0019E200, 0x289);
    }
    return arg0->f25C;
}
