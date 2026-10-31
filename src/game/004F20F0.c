/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 func_004F1950(void *p, void *out);
extern s32 D_221ED4[];

/* Copies two words from a scratch record filled by func_004F1950 into obj, returns 1. */
s32 func_004F20F0(void *unused, u8 *obj) {
    u64 sp[4];

    func_004F1950((void *)(D_221ED4[0] + 0x48), sp);
    *(u64 *)(obj + 0x8) = sp[0];
    *(u64 *)(obj + 0x10) = sp[1];
    return 1;
}
