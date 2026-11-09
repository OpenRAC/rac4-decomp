/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xB4];
    s32 fB4;
};

s32 func_01EFCA14(Type1 *, s32, s32);
void func_01EFEDC8(s32, Type1 *);

void func_01EFCB48(Type1 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = func_01EFCA14(arg0, arg1, arg2);
    arg0->fB4 = temp_v0;
    if (temp_v0 != 0) {
        func_01EFEDC8(temp_v0, arg0);
    }
}
