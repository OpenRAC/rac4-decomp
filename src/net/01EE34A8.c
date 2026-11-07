/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x4];
    s32 f4;
};

s32 func_01EE38C4(s32);

void func_01EE34A8(Type1 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->f4;
    if (temp_v0 != 0) {
        func_01EE38C4(temp_v0);
    }
    arg0->f4 = 0;
}
