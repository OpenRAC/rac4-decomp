/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xF0];
    s32 fF0;
};

s32 func_01EF7CD0(Type1 *, s32);
void func_01EFEFC4(s32, Type1 *);

void func_01EF7DAC(Type1 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_01EF7CD0(arg0, arg1);
    arg0->fF0 = temp_v0;
    if (temp_v0 != 0) {
        func_01EFEFC4(temp_v0, arg0);
    }
}
