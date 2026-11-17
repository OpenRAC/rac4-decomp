/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x4];
    s32 f4;
};
struct Type1 {
    s32 f0;
    char _p4[0x7C];
    Type2 *f80;
};

void func_01F0C090(void *, s32);
extern s32 D_0019CAD0;

s32 func_01EF6228(Type1 *arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0->f80->f4;
    if (arg0->f0 == 0) {
        func_01F0C090(&D_0019CAD0, 0x59);
    }
    if (temp_s0 == 0) {
        func_01F0C090(&D_0019CAD0, 0x5A);
    }
    if (arg1 == 0) {
        func_01F0C090(&D_0019CAD0, 0x5B);
    }
    return 1;
}
