/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x8AC4];
    s32 f8AC4;
};

extern s32 (*D_0016E390)(s32);

void func_01EE5930(Type1 *arg0) {
    D_0016E390(arg0->f8AC4);
    arg0->f8AC4 = 0;
}
