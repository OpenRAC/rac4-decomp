/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x8AC4];
    s32 f8AC4;
    s32 f8AC8;
};

s32 func_01F0C090(void *, s32);
extern s32 (*D_0016E394)(s32 *, s32);
extern s32 D_0019B160;

void func_01EE5268(Type1 *arg0, s32 *arg1) {
    s32 temp_v0;
    s32 t;

    t = arg0->f8AC4;
    *arg1 = arg0->f8AC8;
    temp_v0 = D_0016E394(arg1, t);
    arg0->f8AC8 = (s32) *arg1;
    if (temp_v0 != 0) {
        func_01F0C090(&D_0019B160, 0x162);
    }
}
