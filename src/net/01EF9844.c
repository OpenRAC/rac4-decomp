/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x8];
    s32 f8;
};
struct Type1 {
    char _p0[0x80];
    Type2 *f80;
    char _p84[0x30];
    s32 fB4;
    char _pB8[0x60];
    s32 f118;
};

s32 func_01EF0550(s32, s32);

void func_01EF9844(Type1 *arg0) {
    s32 temp_a1;
    s32 temp_v0;

    temp_v0 = arg0->fB4;
    if (temp_v0 != 0) {
        func_01EF0550(arg0->f80->f8, temp_v0);
        arg0->fB4 = 0;
    }
    temp_a1 = arg0->f118;
    if (temp_a1 != 0) {
        func_01EF0550(arg0->f80->f8, temp_a1);
        arg0->f118 = 0;
    }
}
