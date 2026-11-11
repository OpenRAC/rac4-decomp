/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x17C];
    s32 f17C;
};

s32 func_01EFA484(Type1 *, s32, s32);
void func_01EFF048(s32, Type1 *);

void func_01EFA5C8(Type1 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = func_01EFA484(arg0, arg1, arg2);
    arg0->f17C = temp_v0;
    if (temp_v0 != 0) {
        func_01EFF048(temp_v0, arg0);
    }
}
