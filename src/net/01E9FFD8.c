/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    u32 f0[8];
    s32 f20;
    s32 f24;
};

s32 func_01E9FFD8(Type1 *arg0, s32 arg1) {
    u32 i;

    if (arg0 == NULL) {
        return 0x17;
    }
    if (arg1 < arg0->f20 || arg1 >= arg0->f24) {
        return 0x17;
    }
    i = arg1 - arg0->f20;
    arg0->f0[i >> 5] |= 1 << (i & 0x1F);
    return 0;
}
