/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    s32 f4;
};

s32 func_01EEE13C();
s32 func_01EF0550(s32, s32);

void func_01F09BC8(Type1 *arg0) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_01EEE13C();
    temp_v0_2 = arg0->f0;
    temp_a0 = temp_v0;
    if (temp_v0_2 != 0) {
        func_01EF0550(temp_a0, temp_v0_2);
        arg0->f0 = 0;
    }
    temp_a1 = arg0->f4;
    if (temp_a1 != 0) {
        func_01EF0550(temp_v0, temp_a1);
        arg0->f0 = 0;
    }
}
