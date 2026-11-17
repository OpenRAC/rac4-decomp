/* cflags: @ee296 -O2 -G0 -fno-gcse */
#include "common.h"

extern s32 func_01EBD5E8(s32 a0, u8 *a1);

s32 func_01EBD678(s32 a0, u8 *a1, s32 a2) {
    u16 *p;
    u32 i;

    a2 &= 0xFFFF;
    p = *(u16 **)(a1 + 0x84);
    if (p == 0) {
        return 3;
    }
    i = 0;
    while (i < p[0]) {
        if (p[i + 1] == a2) {
            return 0;
        }
        i++;
    }
    if (p[0] < 0x200) {
        *(u16 *)((u8 *)p + (p[0] << 1) + 2) = a2;
        p[0] = p[0] + 1;
    } else {
        return func_01EBD5E8(a0, a1);
    }
    return 0;
}
