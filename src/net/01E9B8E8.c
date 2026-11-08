/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 {
    u8 pad0[0x30];
    s32 f30;
} Type1;

s32 func_0011A9EC(s32, s32);
s32 func_0011AB04(s32);

s32 func_01E9B8E8(Type1 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 room = arg0->f30 - arg2 * 4;
    s32 len;
    if (arg3 == 0) {
        return 0;
    }
    len = func_0011AB04(arg3) + 1;
    if (len < 0 || room < len) {
        return -0x21F;
    }
    func_0011A9EC(arg1 + arg2 * 4, arg3);
    return len;
}
