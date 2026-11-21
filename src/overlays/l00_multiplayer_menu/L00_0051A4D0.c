/* cflags: @ee29 -O2 -G0 -mcheck-zero-division */
#include "common.h"

extern void *func_0011A370(u8 *, u8 *, s32);

/* Queue n bytes into the object's block buffer, flushing whole blocks through its vtable. */
void func_L00_0051A4D0(u8 *arg0, s32 arg1, s32 *arg2, u8 *arg3, s32 arg4) {
    s32 blk;
    s32 fill;
    s32 src;
    u8 *dst;
    s32 n;
    s32 sub;
    s32 rem;

    src = arg1;
    dst = arg3;
    n = arg4;
    blk = *(s32 *)(*(s32 *)arg0 + 4);
    fill = *(s32 *)(arg0 + 8);
    *arg2 = 0;
    if (n != 0 || fill == blk) {
        if (fill != 0 && fill + n < blk) {
            func_0011A370((u8 *)(fill + (s32)arg0) + 0x4C, dst, n);
            *(s32 *)(arg0 + 8) += n;
        } else {
            if (fill != 0) {
                sub = blk - fill;
                if (sub != 0) {
                    func_0011A370((u8 *)(fill + (s32)arg0) + 0x4C, dst, sub);
                }
                n -= sub;
                dst += sub;
                ((void (*)(void *, s32, void *, s32))(*(s32 *)(*(s32 *)arg0 + 0x14)))(arg0, src, arg0 + 0x4C, blk);
                src += blk;
                *arg2 += blk;
            }
            rem = n % blk;
            n -= rem;
            if (n > 0) {
                ((void (*)(void *, s32, void *, s32))(*(s32 *)(*(s32 *)arg0 + 0x14)))(arg0, src, dst, n);
                *arg2 += n;
            }
            if (rem != 0) {
                func_0011A370(arg0 + 0x4C, dst + n, rem);
            }
            *(s32 *)(arg0 + 8) = rem;
        }
    }
}
