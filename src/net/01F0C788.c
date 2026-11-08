/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x8];
    s32 f8;
    char _pC[0x4];
    s32 f10;
    s32 f14;
    char _p18[0x8];
    s32 f20;
};

s32 func_01F06FB4(s32, s32, s32);

void func_01F0C788(Type1 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->f10;
    if ((u32) (temp_v0 - 1) < 3U) {
        func_01F06FB4(arg0->f8, arg0->f14, temp_v0);
    }
    arg0->f20 = 1;
}
