/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    u32 f0[8];
    s32 f20;
    s32 f24;
};

/* Reads the bit for slot arg1 of the bitmap at arg0 into *arg2; returns 0, or 0x17 when arg0 is NULL or the slot is out of range. */
s32 func_01E9FF68(Type1 *arg0, s32 arg1, s32 *arg2) {
    u32 i;

    if (arg0 == NULL) {
        return 0x17;
    }
    if (arg1 < arg0->f20 || arg1 >= arg0->f24) {
        return 0x17;
    }
    i = arg1 - arg0->f20;
    *arg2 = (arg0->f0[i >> 5] & (1 << (i & 0x1F))) != 0;
    return 0;
}
