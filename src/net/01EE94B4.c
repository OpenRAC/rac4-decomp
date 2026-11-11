/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -fno-gcse -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x5B0C];
    s32 f5B0C;
};

s32 func_01EF0BA8(s32);
s32 func_01EF0C54(s32);
s32 func_01EF0D24(s32);

void func_01EE94B4(Type1 *arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = (void *)((u8 *)arg0 + 0x5AFC);
    arg0->f5B0C = arg1;
    if (func_01EF0D24(temp_s0) != 0) {
        func_01EF0C54(temp_s0);
        func_01EF0BA8(temp_s0);
    }
}
