/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x5B0C];
    s32 f5B0C;
};

s32 func_01EF0C54(s32);
s32 func_01EF0C84(s32);
s32 func_01EF0D18(s32);

s32 func_01EE944C(Type1 *arg0) {
    s32 temp_s0;

    temp_s0 = (void *)((u8 *)arg0 + 0x5AFC);
    if ((func_01EF0D18(temp_s0) != 0) && (func_01EF0C84(temp_s0) >= arg0->f5B0C)) {
        func_01EF0C54(temp_s0);
        return 1;
    }
    return 0;
}
