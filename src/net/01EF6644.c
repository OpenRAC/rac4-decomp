/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
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
    char _p84[0x30];
    s32 fB4;
};

s32 func_01EE94B4(s32, s32);
s32 func_01F0C090(void *, s32);
extern s32 D_0019CB38[];

s32 func_01EF6644(Type1 *arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0->f80->f4;
    if (arg0->f0 == 0) {
        func_01F0C090(D_0019CB38, 0x5D);
    }
    if (temp_s0 == 0) {
        func_01F0C090(D_0019CB38, 0x5E);
    }
    if (arg1 == 0) {
        func_01F0C090(D_0019CB38, 0x5F);
    }
    temp_v0 = arg0->fB4;
    if (temp_v0 > 0) {
        func_01EE94B4(arg1, temp_v0);
    }
    return 1;
}
