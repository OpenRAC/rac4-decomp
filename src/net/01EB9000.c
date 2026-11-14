/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01EB8EB0(void *p, s32 *a, u16 *b);
extern s32 func_01EB9B08(s32 *p, s32 a1, s32 a2, void *a3, s32 a4, s32 a5);
extern void func_01EBE4D8();

/* Copies entries from a packed stream into the output buffer until the count runs out. */
void func_01EB9000(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 *arg6)
{
    u16 n;
    s32 x;
    s32 mask;
    s32 count;
    u8 *dst;

    dst = arg2;
    count = arg3;
    if (*arg6 == arg0 || (func_01EBE4D8(), *arg6 == arg0)) {
        mask = arg4 & 0xFFFF;
        do {
            func_01EB8EB0(dst, &x, &n);
            func_01EB9B08(arg6, mask, x, dst, n, arg5);
            count -= n;
            dst += n;
            if (n == 0) {
                break;
            }
        } while (count != 0);
    }
}
