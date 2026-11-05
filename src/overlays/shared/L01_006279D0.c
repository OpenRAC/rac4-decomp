#include "common.h"

extern u16 *func_L01_00627548();
extern void func_L01_00627610(u16 *, s32, s32);
extern u8 D_0034CF60[];

/* Allocate an entry, feed it count/2 key/value pairs, return its handle or -1. */
u32 func_L01_006279D0(s32 count, s32 *pairs)
{
    u16 *e;
    s32 i;
    u32 r;

    if (count & 1) {
        return 0xFFFFFFFF;
    }
    e = func_L01_00627548();
    if (e != 0) {
        for (i = 0; i < count; i += 2) {
            func_L01_00627610(e, pairs[0], pairs[1]);
            pairs += 2;
        }
    }
    r = 0xFFFFFFFF;
    if (e != 0) {
        r = *e | (((u32)((u8 *)e - D_0034CF60) / 80) << 16);
    }
    return r;
}
